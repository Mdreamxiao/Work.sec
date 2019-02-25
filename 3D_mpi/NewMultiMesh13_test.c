#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<mpi.h>

typedef struct
{
	double x;
	double y;
	double z;
}Point3d;

typedef struct
{
	int id;							//格点编号
	Point3d coordinate;				//格点坐标(中心点)
	int neighbour[18];				//格点18个方向的邻居  自身为0 0 0没有存储	//{0, 1,-1, 0, 0, 0, 0, 1,-1, 1,-1, 1,-1, 1,-1, 0, 0, 0, 0};
																				//{0, 0, 0, 1,-1, 0, 0, 1,-1,-1, 1, 0, 0, 0, 0, 1,-1, 1,-1};
																				//{0, 0, 0, 0, 0, 1,-1, 0, 0, 0, 0, 1,-1,-1, 1, 1,-1,-1, 1};
	char style;						//格点类型
									// f 流体点
									// s 固体点
									// b 边界点
									// o 下面 down
									// p 上面 up
									// e 左面 left
									// i 右面 right
									// r 前面 front
									// a 后面 back
	char movestyle;					//粗细交换，缓冲区类型
									// f 流体
									// b 边界
									// d 粗到细，最外粗
									// e 粗到细，次外粗
									// u 细到粗，最外细
									// v 细到粗，次外细
									// s 固体或其他
	char mpistyle;					//MPI发送与接收，缓冲区类型
									// r 左 接收缓冲区
									// m 左 发送与接收中间层
									// s 左 发送缓冲区
									// j 右 接收缓冲区
									// z 右 发送与接收中间层
									// f 右 发送缓冲区
									// a 父格点属于缓冲区
									// o 其他
    int level;						//格点所在网格层数
	int father_id;					//父格点编号
	int son_id[8];					//8个子格点编号
									//若值为-1表示不存在父格点或子格点
	int yesorno;					//是否加密 0 未  1 加密
	double distance[18];			//与三角形相交的距离
	double rho;						//格点的宏观密度
	double p;
	Point3d u;						//格点的宏观速度
	double tau;						//格点的松弛因子
	double f[19];					//格点的密度分布函数
	double fcol[19];				//格点碰撞后的密度分布函数
	double feq[19];					//格点的平衡态值
	Point3d uerror;					//格点的速度误差    可以不要
}Lattice3d;

typedef struct
{
	Point3d min;						//网格的最小点
	Point3d max;						//网格的最大点
	int level;							//网格所在的层数
	double space;						//网格的尺寸
	Lattice3d lattice3d[400000];		//由格点组成的网格, 量太大，这样存不妥
	int length;							//网格中格点数量
	double uerror;						//网格点中所有点的误差
	int NX, NY, NZ;         			//各个方向的格子数
	int xid, yid, zid;					//多维划分时，x, y, z 三个方向的id
	int numOfPx, numOfPy, numOfPz;		//多维划分时，x, y, z 三个方向的进程数
	double tau;							//网格中所有格点的BGK模型的tau值, 在大涡模拟中需要使用
	int leftsend;						//左侧发送缓冲区格子数
	int leftrecv;						//左侧接收缓冲区格子数
	int rightsend;						//右侧发送缓冲区格子数
	int rightrecv;						//右侧接收缓冲区格子数
}Mesh;

int minInt(int a, int b);
void SetFirstLevelMesh( Mesh* M, Point3d min1, Point3d max1, double space, int myid, int numprocs );
void JudgeMeshNeighbourId( Mesh* M, double space );
void SetSecondLevel( Mesh* M1, Mesh* M2, Point3d min2, Point3d max2, double space );
void SetSecondlevelMesh( Mesh* M1, Mesh* M2, int N );
void SearchNeighbourInformation( Mesh* M1,  Mesh* M2 );
void WriteMultiMeshLattice( Mesh* M[10], int N, double space, char name[30] );
void WriteMultiMeshLatticeMpiStyle( Mesh* M[10], int N, double space, char name[30], char ch );
//void SetMpiMesh( Mesh* M3, Point3d min1, Point3d max1, double space, int myid, int numprocs );
void SetMpiMesh( Mesh* M[] , double space, int myid, int numprocs , int level);
void JudgeMeshStyle( Mesh* M );
void ComputeLatticeFeq( Lattice3d* latt );
void InitialFlowField( Mesh* M[10], int N, double Rho,Point3d U, double P, double L, double Umax, double Re );
void InitialMpiStyle( Mesh* M[10], int N, int myid, int numprocs );
void WriteMpiStylePoint( Mesh* M, double space, int myid, char ch );
void WriteMultiMeshLatticeFlowPointD3Q19( Mesh* M[10], int N, double space, int n, int myid );
void ComputeMultipleMeshCollisionLBGKD3Q19( Mesh* M, int n );
void DoubleMeshCollisionStreamLBGKD3Q19( Mesh* M1, Mesh* M2, int myid, int numprocs );
void ComputeMultipleMeshMoveLBGKD3Q19( Mesh* M, int n );
void PassDownDataHalfLBGKD3Q19( Mesh* M1, Mesh* M2, int n );
void PassUpDataLBGKD3Q19( Mesh* M1, Mesh* M2, int n );
void PassDownDataAllLBGKD3Q19( Mesh* M1, Mesh* M2, int n );
void MultiMeshDataTransfer( Mesh* M, int myid, int numprocs );
void WriteMultiMeshLatticeOneLayerXYZ( Mesh* M[10], int N, double space, char name[50], double xyz, int flag );//1,yz;  2,xz;  3,xy
void WriteMultiMeshLatticeBforCP( Mesh* M[10], int N, double space, char name[50], double xyz, int flag );
void SetInterOneLevel( Mesh* M1, Mesh* M2 );
void SetInterLevel( Mesh* M1, Mesh* M2, int layer );
int DivideTwo(int Number);
void MultipleMeshCollisionStreamLBGKD3Q19( Mesh* M[10], int N, int myid, int numprocs );

int main( int argc,char **argv )
{
	int myid,numprocs,i;
	MPI_Request *request;
	
	MPI_Status status;
    MPI_Init(&argc,&argv);

	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	
	Point3d min1, max1, min2, max2, min3, max3, min4, max4;
	double space;
//	char name1[30];
//	sprintf( name1,"OnlyMesh.dat" );
	char name2[30];
	sprintf( name2,"OnlyMeshMPI_%d.dat", myid );

	Mesh mesh1;
	Mesh mesh2;
	Mesh mesh3;
	Mesh mesh4;

	Mesh* M[5];
	M[0] = &mesh1;
	M[1] = &mesh2;
	M[2] = &mesh3;
	M[3] = &mesh4;
	
	double eps = 1e-8;
	
	min1.x = 0.0;
	min1.y = 0.0;
	min1.z = 0.0;
	max1.x = 28.0;
	max1.y = 12.0;
	max1.z = 12.0;

	min2.x = 2.0;
	min2.y = 2.0;
	min2.z = 2.0;
	max2.x = 20.0 + eps;
	max2.y = 10.0;
	max2.z = 10.0;
	
	min3.x = 4.0;
	min3.y = 4.0;
	min3.z = 4.0;
	max3.x = 15.0;
	max3.y = 8.0;
	max3.z = 8.0;

	space = 0.2;
	int MeshNum = 3;

//  ********************测试用，，，用完删除***************************
	mesh1.min.x = min1.x = 0.0;
	mesh1.min.y = min1.y = 0.0;
	mesh1.min.z = min1.z = 0.0;
	mesh1.max.x = max1.x = 28.0;
	mesh1.max.y = max1.y = 12.0;
	mesh1.max.z = max1.z = 12.0;

	mesh2.min.x = min2.x = 2.0;
	mesh2.min.y = min2.y = 2.0;
	mesh2.min.z = min2.z = 2.0;
	mesh2.max.x = max2.x = 20.0 + eps;
	mesh2.max.y = max2.y = 10.0;
	mesh2.max.z = max2.z = 10.0;
	
	mesh3.min.x = min3.x = 4.0;
	mesh3.min.y = min3.y = 4.0;
	mesh3.min.z = min3.z = 4.0;
	mesh3.max.x = max3.x = 15.0;
	mesh3.max.y = max3.y = 8.0;
	mesh3.max.z = max3.z = 8.0;

	SetMpiMesh( M, space, myid, numprocs , 3);
	MPI_Barrier(MPI_COMM_WORLD);
	printf("finish of thread %d\t\n",myid);
	MPI_Finalize();
	return 0;
	//SetMpiMesh( &mesh1, min1, max1, space, myid, numprocs );	//划分每个进程范围	

	SetFirstLevelMesh( &mesh1, mesh1.min, mesh1.max, space, myid, numprocs );	//第一重网格
	JudgeMeshStyle( &mesh1 );													//判断网格点类型

	SetSecondLevel( &mesh1, &mesh2, min2, max2, space );						//第二重网格
	JudgeMeshStyle( &mesh2 );													//判断网格点类型
	
	SetSecondLevel( &mesh2, &mesh3, min3, max3, space );						//第二重网格
	JudgeMeshStyle( &mesh3 );
	
	// SetSecondLevel( &mesh3, &mesh4, min4, max4, space );						//第二重网格
	// JudgeMeshStyle( &mesh4 );
	
	// SetInterLevel( &mesh2, &mesh3, 3 );
	// JudgeMeshStyle( &mesh3 );
	
	// SetInterLevel( &mesh3, &mesh4, 3 );
	// JudgeMeshStyle( &mesh4 );
	
	//printf("myid=%d, M1:%d, M2:%d\n", myid, mesh1.length, mesh2.length );
	
	WriteMultiMeshLattice( M, MeshNum, space, name2 );		//输出体网格，不含流场信息，不含固体点
	
	int NumOfIteration = 50001;
	double Ma = 0.2;
	double Umax = Ma/sqrt(3.0);
	int Re = 1000;
	double L = 2.0;
	double Rho = 1.0;
	double P = 1.0/3.0;
	Point3d U = {Umax, 0.0, 0.0};
	
	InitialFlowField( M, MeshNum, Rho, U, P, L, Umax, Re );	//流场信息初始化 & 粗细交换类型判断
	InitialMpiStyle( M, MeshNum, myid, numprocs );
	
	//printf("myid=%d,m1.leftsend=%d,m1.leftrecv=%d,m1.rightsend=%d,m1.rightrecv=%d\n",myid,mesh1.leftsend, mesh1.leftrecv, mesh1.rightsend, mesh1.rightrecv);
	//printf("myid=%d,m2.leftsend=%d,m2.leftrecv=%d,m2.rightsend=%d,m2.rightrecv=%d\n",myid,mesh2.leftsend, mesh2.leftrecv, mesh2.rightsend, mesh2.rightrecv);
	
	for ( i=0; i<=NumOfIteration; i++)
	{
		if( i%100 == 0 )
		{
			printf( "%d\r", i );
		}
		
		//DoubleMeshCollisionStreamLBGKD3Q19( &mesh1, &mesh2, myid, numprocs );
		MultipleMeshCollisionStreamLBGKD3Q19( M, MeshNum, myid, numprocs );

		if (i!=0 && i%400==0 && i!=NumOfIteration)
		{
			//WriteMultiMeshLatticeFlowPointD3Q19( M, MeshNum, space, i ,myid );
			char xyzname[50];
			sprintf( xyzname,"LayerDataXYZ_step_%d_myid_%d.dat", i, myid );
			WriteMultiMeshLatticeOneLayerXYZ( M, MeshNum, space, xyzname, max1.z/2.0, 3 );	//1,yz;  2,xz;  3,xy
		}
		// if(i!=0 && i%50==0 && i!=NumOfIteration)
		// {
		// 	char cpname[50];
		// 	sprintf( cpname,"B_for_CP_step_%d_myid_%d.dat", i, myid );
		// 	WriteMultiMeshLatticeBforCP( M, MeshNum, space, cpname, max1.z/2.0, 3  );
		// }
	}
	
	MPI_Finalize();
	return 0;
}

void SetFirstLevelMesh( Mesh* M, Point3d min1, Point3d max1, double space, int myid, int numprocs )
{
	double xx = (max1.x-min1.x)/space - (int)((max1.x-min1.x)/space+0.5f);
	double yy = (max1.y-min1.y)/space - (int)((max1.y-min1.y)/space+0.5f);
	double zz = (max1.z-min1.z)/space - (int)((max1.z-min1.z)/space+0.5f);

	if ( !( xx<1.e-10 && yy<1.e-10 && zz<1.e-10 ) )
	{
		printf("Max/Min != Integer!!! Please input new Max and Min Point!!!\n");
		abort();
	}

	int nx = (int)((max1.x-min1.x)/space+0.5f);// + 1;	//x方向网格总数
	int ny = (int)((max1.y-min1.y)/space+0.5f);// + 1;	//y方向网格总数
	int nz = (int)((max1.z-min1.z)/space+0.5f);// + 1;	//z方向网格总数
	
	(*M).NX = nx;
	(*M).NY = ny;
	(*M).NZ = nz;
	
	//printf("myid=%d, nx = %d\n",myid,nx);

	int sum = 0;	//网格编号
	int i,j,k;
	Point3d p;
	Lattice3d latt;

	(*M).min = min1;
	(*M).max = max1;
	(*M).level = 0;
	(*M).space = space;

	latt.father_id = -1;	//第0重网格父格子编号初始化为-1
	latt.level = 0;			//设置第0重网格的重数为0
	latt.yesorno = 0;		//未加密

	for ( i=0; i<nx; i++)
	{
		p.x = min1.x+i*space;	//格点x的坐标
		for ( j=0; j<ny; j++)
		{
			p.y = min1.y+j*space;	//格点y的坐标
			for ( k=0; k<nz; k++)
			{
				p.z = min1.z+k*space;	//格点z的坐标

				latt.coordinate = p;
				latt.id =sum;
				latt.movestyle = 's';
				latt.mpistyle = 'o';

				//网格18个方向的邻居编号
				latt.neighbour[0] = (i==nx-1?-1:sum+ny*nz);
				latt.neighbour[1] = (i==0?-1:sum-ny*nz);
				latt.neighbour[2] = (j==ny-1?-1:sum+nz);
				latt.neighbour[3] = (j==0?-1:sum-nz);
				
				//latt.neighbour[4] = (k==nz-1?-1:sum+1);
				latt.neighbour[4] = (k==nz-1?sum-nz+1:sum+1);
				
				//latt.neighbour[5] = (k==0?-1:sum-1);
				latt.neighbour[5] = (k==0?sum+nz-1:sum-1);
				
				latt.neighbour[6] = ((i==nx-1||j==ny-1)?-1:sum+ny*nz+nz);
				latt.neighbour[7] = ((i==0||j==0)?-1:sum-ny*nz-nz);
				latt.neighbour[8] = ((i==nx-1||j==0)?-1:sum+ny*nz-nz);
				latt.neighbour[9] = ((i==0||j==ny-1)?-1:sum-ny*nz+nz);
				
				//latt.neighbour[10] = ((i==nx-1||k==nz-1)?-1:sum+ny*nz+1);
				if (i==nx-1  )
					latt.neighbour[10] = -1;
				else if( k==nz-1 )
					latt.neighbour[10] = sum + ny*nz -nz +1;
				else
					latt.neighbour[10] = sum+ny*nz+1;
				
				//latt.neighbour[11] = ((i==0||k==0)?-1:sum-ny*nz-1);
				if (i==0 )
					latt.neighbour[11] = -1;
				else if( k==0 )
					latt.neighbour[11] = sum -ny*nz + nz -1;
				else
					latt.neighbour[11] = sum-ny*nz-1;
				
				//latt.neighbour[12] = ((i==nx-1||k==0)?-1:sum+ny*nz-1);
				if (i==nx-1 )
					latt.neighbour[12] = -1;
				else if( k==0 )
					latt.neighbour[12] = sum + ny*nz + nz -1;
				else
					latt.neighbour[12] = sum+ny*nz-1;
				
				//latt.neighbour[13] = ((i==0||k==nz-1)?-1:sum-ny*nz+1);
				if (i==0 )
					latt.neighbour[13] = -1;
				else if( k==nz-1 )
					latt.neighbour[13] = sum - ny*nz - nz + 1;
				else
					latt.neighbour[13] = sum-ny*nz+1;
				
				//latt.neighbour[14] = ((j==ny-1||k==nz-1)?-1:sum+nz+1);
				if(j==ny-1 )
					latt.neighbour[14] = -1;
				else if( k==nz-1 )
					latt.neighbour[14] = sum + 1;
				else
					latt.neighbour[14] = sum + nz + 1;
				
				//latt.neighbour[15] = ((j==0||k==0)?-1:sum-nz-1);
				if (j==0 )
					latt.neighbour[15] = -1;
				else if( k==0 )
					latt.neighbour[15] = sum - 1;
				else
					latt.neighbour[15] = sum - nz - 1;
				
				//latt.neighbour[16] = ((j==ny-1||k==0)?-1:sum+nz-1);
				if(j==ny-1 )
					latt.neighbour[16] = -1;
				else if( k==0 )
					latt.neighbour[16] = sum + nz + nz - 1;
				else
					latt.neighbour[16] = sum + nz - 1;	
				
				//latt.neighbour[17] = ((j==0||k==nz-1)?-1:sum-nz+1);
				if (j==0 )
					latt.neighbour[17] = -1;
				else if( k == nz -1 )
					latt.neighbour[17] = sum -nz - nz + 1;
				else
					latt.neighbour[17] = sum -nz + 1;
				

				// if (k == 0)
				// {
					// latt.style = 'o';	//包围盒下边界d o wn
				// }
				// else if (k==nz-1)
				// {
					// latt.style = 'p';	//包围盒上边界u p
				// }
				// else 
					if (j==0)
				{
					latt.style = 'a';	//包围盒后边界b a ck
				}
				else if (j==ny-1)
				{
					latt.style = 'r';	//包围盒前边界f r ont
				}
				else if (i==1 && myid ==0)
				{
					latt.style = 'e';	//包围盒左边界l e ft
				}
				else if (i==nx-2 && myid == numprocs-1)
				{
					latt.style = 'i';	//包围盒右边界r i ght
				}
				else
				{
					latt.style = 'f';	//流域内flow
				}

				(*M).lattice3d[sum] = latt;
				sum++;
			}
		}
	}
	(*M).length = sum;
}

void JudgeMeshNeighbourId( Mesh* M, double space )
{
	//18个邻居方向
	int ex[18]={1,-1, 0, 0, 0, 0, 1,-1, 1,-1, 1,-1, 1,-1, 0, 0, 0, 0};
    int ey[18]={0, 0, 1,-1, 0, 0, 1,-1,-1, 1, 0, 0, 0, 0, 1,-1, 1,-1};
    int ez[18]={0, 0, 0, 0, 1,-1, 0, 0, 0, 0, 1,-1,-1, 1, 1,-1,-1, 1};

	double eps = 1.0e-10;
	int i,k;
	int flag = 1;

	for ( i=0; i<(*M).length; i++)
	{
		Point3d p = (*M).lattice3d[i].coordinate;
		for ( k=0; k<18; k++)
		{
			int id = (*M).lattice3d[i].neighbour[k];
			if (id != -1)
			{
				Point3d v = (*M).lattice3d[id].coordinate;;
				double xspace = v.x - p.x;
				double yspace = v.y - p.y;
				double zspace = v.z - p.z;
				if ( !( (xspace-ex[k]*space<=eps) && (yspace-ey[k]*space<=eps) && (zspace-ez[k]*space<=eps) ) )
				{
					flag = 0;
					printf("Mesh Neighbour id has error!!!\n");
					printf("pointid=%d,x=%f,y=%f,z=%f,direction=%d,neighbour_id=%d\n",i,p.x,p.y,p.z,k,id);
					abort();
				}
			}
		}
	}
	if(flag)
	{
		printf("Set Mesh Neighbour id successful!\n");
	}
}

void SetSecondLevel( Mesh* M1, Mesh* M2, Point3d min2, Point3d max2, double space )
{
	int i,j,k;
	Point3d p;

	(*M2).min = min2;
	(*M2).max = max2;
	(*M2).length = 0;
	(*M2).level = (*M1).level + 1;

	for( i=0; i<(*M1).length; i++ )
	{
		p = (*M1).lattice3d[i].coordinate;
		if( p.x>=min2.x && p.x<=max2.x && p.y>=min2.y && p.y<=max2.y && p.z>=min2.z && p.z<=max2.z )
		{
			SetSecondlevelMesh( M1, M2, i );
		}
	}
	
	SearchNeighbourInformation( M1, M2 );
}

void SetSecondlevelMesh( Mesh* M1, Mesh* M2, int N )
{ 
	// 8个子格点的位置
	// 0 1         4 5
	// 2 3 (下层)  6 7 (上层)	
	double space = (*M1).space;
	int level = (*M1).level;
	int e[8][3] = {{-1,-1,-1},{1,-1,-1},{-1,1,-1},{1,1,-1},{-1,-1,1},{1,-1,1},{-1,1,1},{1,1,1}};
	(*M2).space = space/2.0;
	(*M2).level = level + 1;
	space = space/4.0;
	Point3d p1,p2;
	char sty;

	if( (*M1).lattice3d[N].yesorno == 0 )		//未加密
	{
		(*M1).lattice3d[N].yesorno = 1;		//已加密
		Lattice3d latt;
		p1 = (*M1).lattice3d[N].coordinate;
		sty = (*M1).lattice3d[N].style;

		latt.style = sty;
		latt.level = level + 1;
		latt.father_id = N;
		latt.movestyle = 's';
		latt.mpistyle = 'o';
		latt.yesorno = 0;

		//插入第0个子格点******************************************************
		(*M1).lattice3d[N].son_id[0] = (*M2).length;
		p2.x = p1.x + e[0][0]*space;
		p2.y = p1.y + e[0][1]*space;
		p2.z = p1.z + e[0][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] = (*M2).length + 1;
		latt.neighbour[1] = -1;
		latt.neighbour[2] = (*M2).length + 2;
		latt.neighbour[3] = -1;
		latt.neighbour[4] = (*M2).length + 4;
		latt.neighbour[5] = -1;
		latt.neighbour[6] = (*M2).length + 3;
		latt.neighbour[7] = -1;
		latt.neighbour[8] = -1;
		latt.neighbour[9] = -1;
		latt.neighbour[10] = (*M2).length + 5;
		latt.neighbour[11] = -1;
		latt.neighbour[12] = -1;
		latt.neighbour[13] = -1;
		latt.neighbour[14] = (*M2).length + 6;
		latt.neighbour[15] = -1;
		latt.neighbour[16] = -1;
		latt.neighbour[17] = -1;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;

		//插入第1个子格点******************************************************
		(*M1).lattice3d[N].son_id[1] = (*M2).length;
		p2.x = p1.x + e[1][0]*space;
		p2.y = p1.y + e[1][1]*space;
		p2.z = p1.z + e[1][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] = -1;
		latt.neighbour[1] = (*M2).length - 1;
		latt.neighbour[2] = (*M2).length + 2;
		latt.neighbour[3] = -1;
		latt.neighbour[4] = (*M2).length + 4;
		latt.neighbour[5] = -1;
		latt.neighbour[6] = -1;
		latt.neighbour[7] = -1;
		latt.neighbour[8] = -1;
		latt.neighbour[9] = (*M2).length + 1;
		latt.neighbour[10] = -1;
		latt.neighbour[11] = -1;
		latt.neighbour[12] = -1;
		latt.neighbour[13] = (*M2).length + 3;
		latt.neighbour[14] = (*M2).length + 6;
		latt.neighbour[15] = -1;
		latt.neighbour[16] = -1;
		latt.neighbour[17] = -1;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;

		//插入第2个子格点******************************************************
		(*M1).lattice3d[N].son_id[2] = (*M2).length;
		p2.x = p1.x + e[2][0]*space;
		p2.y = p1.y + e[2][1]*space;
		p2.z = p1.z + e[2][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] = (*M2).length + 1;
		latt.neighbour[1] = -1;
		latt.neighbour[2] = -1;
		latt.neighbour[3] = (*M2).length - 2;
		latt.neighbour[4] = (*M2).length + 4;
		latt.neighbour[5] = -1;
		latt.neighbour[6] = -1;
		latt.neighbour[7] = -1;
		latt.neighbour[8] = (*M2).length - 1;
		latt.neighbour[9] = -1;
		latt.neighbour[10] = (*M2).length + 5;
		latt.neighbour[11] = -1;
		latt.neighbour[12] = -1;
		latt.neighbour[13] = -1;
		latt.neighbour[14] = -1;
		latt.neighbour[15] = -1;
		latt.neighbour[16] = -1;
		latt.neighbour[17] = (*M2).length + 2;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;

		//插入第3个子格点******************************************************
		(*M1).lattice3d[N].son_id[3] = (*M2).length;
		p2.x = p1.x + e[3][0]*space;
		p2.y = p1.y + e[3][1]*space;
		p2.z = p1.z + e[3][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] = -1;
		latt.neighbour[1] = (*M2).length - 1;
		latt.neighbour[2] = -1;
		latt.neighbour[3] = (*M2).length - 2;
		latt.neighbour[4] = (*M2).length + 4;
		latt.neighbour[5] = -1;
		latt.neighbour[6] = -1;
		latt.neighbour[7] = (*M2).length - 3;
		latt.neighbour[8] = -1;
		latt.neighbour[9] = -1;
		latt.neighbour[10] = -1;
		latt.neighbour[11] = -1;
		latt.neighbour[12] = -1;
		latt.neighbour[13] = (*M2).length + 3;
		latt.neighbour[14] = -1;
		latt.neighbour[15] = -1;
		latt.neighbour[16] = -1;
		latt.neighbour[17] = (*M2).length + 2;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;

		//插入第4个子格点******************************************************
		(*M1).lattice3d[N].son_id[4] = (*M2).length;
		p2.x = p1.x + e[4][0]*space;
		p2.y = p1.y + e[4][1]*space;
		p2.z = p1.z + e[4][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] = (*M2).length + 1;
		latt.neighbour[1] = -1;
		latt.neighbour[2] = (*M2).length + 2;
		latt.neighbour[3] = -1;
		latt.neighbour[4] = -1;
		latt.neighbour[5] = (*M2).length - 4;
		latt.neighbour[6] = (*M2).length + 3;
		latt.neighbour[7] = -1;
		latt.neighbour[8] = -1;
		latt.neighbour[9] = -1;
		latt.neighbour[10] = -1;
		latt.neighbour[11] = -1;
		latt.neighbour[12] = (*M2).length - 3;
		latt.neighbour[13] = -1;
		latt.neighbour[14] = -1;
		latt.neighbour[15] = -1;
		latt.neighbour[16] = (*M2).length - 2;
		latt.neighbour[17] = -1;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;

		//插入第5个子格点******************************************************
		(*M1).lattice3d[N].son_id[5] = (*M2).length;
		p2.x = p1.x + e[5][0]*space;
		p2.y = p1.y + e[5][1]*space;
		p2.z = p1.z + e[5][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] =  -1;
		latt.neighbour[1] = (*M2).length - 1;
		latt.neighbour[2] = (*M2).length + 2;
		latt.neighbour[3] = -1;
		latt.neighbour[4] = -1;
		latt.neighbour[5] = (*M2).length - 4;
		latt.neighbour[6] = -1;
		latt.neighbour[7] = -1;
		latt.neighbour[8] = -1;
		latt.neighbour[9] = (*M2).length + 1;
		latt.neighbour[10] = -1;
		latt.neighbour[11] = (*M2).length - 5;
		latt.neighbour[12] = -1;
		latt.neighbour[13] = -1;
		latt.neighbour[14] = -1;
		latt.neighbour[15] = -1;
		latt.neighbour[16] = (*M2).length - 2;
		latt.neighbour[17] = -1;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;

		//插入第6个子格点******************************************************
		(*M1).lattice3d[N].son_id[6] = (*M2).length;
		p2.x = p1.x + e[6][0]*space;
		p2.y = p1.y + e[6][1]*space;
		p2.z = p1.z + e[6][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] = (*M2).length + 1;
		latt.neighbour[1] = -1;
		latt.neighbour[2] = -1;
		latt.neighbour[3] = (*M2).length - 2;
		latt.neighbour[4] = -1;
		latt.neighbour[5] = (*M2).length - 4;
		latt.neighbour[6] = -1;
		latt.neighbour[7] = -1;
		latt.neighbour[8] = (*M2).length - 1;
		latt.neighbour[9] = -1;
		latt.neighbour[10] = -1;
		latt.neighbour[11] = -1;
		latt.neighbour[12] = (*M2).length - 3;
		latt.neighbour[13] = -1;
		latt.neighbour[14] = -1;
		latt.neighbour[15] = (*M2).length - 6;
		latt.neighbour[16] = -1;
		latt.neighbour[17] = -1;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;

		//插入第7个子格点******************************************************
		(*M1).lattice3d[N].son_id[7] = (*M2).length;
		p2.x = p1.x + e[7][0]*space;
		p2.y = p1.y + e[7][1]*space;
		p2.z = p1.z + e[7][2]*space;

		latt.id = (*M2).length;
		latt.coordinate = p2;
		latt.neighbour[0] = -1;
		latt.neighbour[1] = (*M2).length - 1;
		latt.neighbour[2] = -1;
		latt.neighbour[3] = (*M2).length - 2;
		latt.neighbour[4] = -1;
		latt.neighbour[5] = (*M2).length - 4;
		latt.neighbour[6] = -1;
		latt.neighbour[7] = (*M2).length - 3;
		latt.neighbour[8] = -1;
		latt.neighbour[9] = -1;
		latt.neighbour[10] = -1;
		latt.neighbour[11] = (*M2).length - 5;
		latt.neighbour[12] = -1;
		latt.neighbour[13] = -1;
		latt.neighbour[14] = -1;
		latt.neighbour[15] = (*M2).length - 6;
		latt.neighbour[16] = -1;
		latt.neighbour[17] = -1;

		(*M2).lattice3d[(*M2).length] = latt;
		(*M2).length = (*M2).length + 1;
	}
}

void SearchNeighbourInformation( Mesh* M1,  Mesh* M2 )
{
	double eps = 1.e-6;					//误差范围
	int e[18][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},
					{1,1,0},{-1,-1,0},{1,-1,0},{-1,1,0},{1,0,1},{-1,0,-1},
					{1,0,-1},{-1,0,1},{0,1,1},{0,-1,-1},{0,1,-1},{0,-1,1}};
	int inv[18]={1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16};		//18个方向的反方向
	int i,j,k;
	int meshnum = (*M2).length;

	//第一次搜索邻居信息
	for( i=0; i<meshnum; i++ )
	{
		int father_id = (*M2).lattice3d[i].father_id;
		// 0 1         4 5
		// 2 3 (下层)  6 7 (上层)
		int son_id = i % 8;
		
		//第1-6个方向找邻居
		for( k=0; k<6; k++ )
		{
			if( (*M2).lattice3d[i].neighbour[k] == -1 )
			{
				int father_neigh_id = (*M1).lattice3d[father_id].neighbour[k];
				if( father_neigh_id == -1 || (*M1).lattice3d[father_neigh_id].yesorno == 0 )	//父格点无邻居或者未加密
				{
					continue;
				}
				else
				{
					int father_neigh_son_id = (*M1).lattice3d[father_neigh_id].son_id[son_id];
					father_neigh_son_id = (*M2).lattice3d[father_neigh_son_id].neighbour[inv[k]];
					(*M2).lattice3d[i].neighbour[k] = father_neigh_son_id;
				}
			}
		}
		
		//第7-18个方向找邻居
		for( k=6; k<18; k++ )
		{
			if( (*M2).lattice3d[i].neighbour[k] == -1 )
			{
				int father_neigh_id = (*M1).lattice3d[father_id].neighbour[k];
				if( father_neigh_id == -1 || (*M1).lattice3d[father_neigh_id].yesorno == 0 )	//父格点无邻居或者未加密
				{
					continue;
				}
				else
				{
					int father_neigh_son_id = (*M1).lattice3d[father_neigh_id].son_id[son_id];
					father_neigh_son_id = (*M2).lattice3d[father_neigh_son_id].neighbour[inv[k]];
					if( father_neigh_son_id != -1 )
					{
						Point3d coord = (*M2).lattice3d[father_neigh_son_id].coordinate;
						Point3d p = (*M2).lattice3d[i].coordinate;
						double space = (*M2).space;
						if( fabs(p.x-coord.x)<=space+eps && fabs(p.y-coord.y)<=space+eps && fabs(p.z-coord.z)<=space+eps )
						{
							(*M2).lattice3d[i].neighbour[k] = father_neigh_son_id;
						}						
					}
				}
			}
		}		
	}
	
	//第二次搜索邻居信息
	for( i=0; i<meshnum; i++ )
	{
		for( k=6; k<18; k++ )
		{
			if( (*M2).lattice3d[i].neighbour[k] == -1 )
			{
				int directx = -1;
				int directy = -1;
				int directz = -1;

				//根据k的方向判断搜索方向
				if (e[k][0]>0)
					directx = 0;
				else if (e[k][0]<0)
					directx = 1;
				if (e[k][1]>0)
					directy = 2;
				else if (e[k][1]<0)
					directy = 3;
				if (e[k][2]>0)
					directz = 4;
				else if (e[k][2]<0)
					directz = 5;
				
				if (directx==-1)
				{
					if ( (*M2).lattice3d[i].neighbour[directy] != -1 )
					{
						int id = (*M2).lattice3d[i].neighbour[directy];
						id = (*M2).lattice3d[id].neighbour[directz];
						(*M2).lattice3d[i].neighbour[k] = id;
					}
					else if ((*M2).lattice3d[i].neighbour[directz] != -1 )
					{
						
						int id = (*M2).lattice3d[i].neighbour[directz];
						id = (*M2).lattice3d[id].neighbour[directy];
						(*M2).lattice3d[i].neighbour[k] = id;
					}
					else
						continue;
				}
				else if (directy==-1)
				{
					if ( (*M2).lattice3d[i].neighbour[directx] != -1 )
					{						
						int id = (*M2).lattice3d[i].neighbour[directx];
						id = (*M2).lattice3d[id].neighbour[directz];
						(*M2).lattice3d[i].neighbour[k] = id;
					}
					else if ( (*M2).lattice3d[i].neighbour[directz] != -1 )
					{
						int id = (*M2).lattice3d[i].neighbour[directz];
						id = (*M2).lattice3d[id].neighbour[directx];
						(*M2).lattice3d[i].neighbour[k] = id;
					}
					else
						continue;
				}
				else if (directz==-1)
				{
					if ( (*M2).lattice3d[i].neighbour[directx] != -1 )
					{						
						int id = (*M2).lattice3d[i].neighbour[directx];
						id = (*M2).lattice3d[id].neighbour[directy];
						(*M2).lattice3d[i].neighbour[k] = id;
					}
					else if ( (*M2).lattice3d[i].neighbour[directy] != -1 )
					{
						int id = (*M2).lattice3d[i].neighbour[directy];
						id = (*M2).lattice3d[id].neighbour[directx];
						(*M2).lattice3d[i].neighbour[k] = id;
					}
					else
						continue;
				}
			}			
		}		
	}	
}

void WriteMultiMeshLattice( Mesh* M[10], int N, double space, char name[30] )
{
	Point3d Direction[8] =  {{ 1, 1, 1}, {-1, 1, 1}, {-1, -1, 1}, {1, -1, 1},{1, 1,-1}, {-1, 1, -1}, {-1, -1, -1}, {1, -1, -1}};
	int i,j,k;
	int number = 0;
	FILE *fp;
	Point3d p, centerp;
	
	for( j=0; j<N; j++ )
	{
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( (*(M[j])).lattice3d[i].style != 's' && (*(M[j])).lattice3d[i].yesorno == 0 )
			{
				number++;
			}
		}
	}
	

	fp = fopen(name,"w");
	if ( fp == NULL )
	{
		printf("Open Out File is error!!!\n");
		abort();
	}

	fprintf( fp,"title=\"Mesh Show\"\n" );
	fprintf( fp,"VARIABLES=\"x\", \"y\", \"z\"\n" );
	fprintf( fp,"ZONE T =\"fuse\"\n" );
	fprintf( fp,"Nodes = %d, Elements = %d\n", number*8, number );
	fprintf( fp,"ZONETYPE = FEBRICK, DATAPACKING = POINT\n" );

	for( j=0; j<N; j++ )
	{
		space = space/2.0;
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( (*(M[j])).lattice3d[i].style != 's' && (*(M[j])).lattice3d[i].yesorno == 0 )
			{
				centerp = (*(M[j])).lattice3d[i].coordinate;
				for ( k=0; k<8; k++)
				{
					p.x = centerp.x + space * Direction[k].x;
					p.y = centerp.y + space * Direction[k].y;
					p.z = centerp.z + space * Direction[k].z;
					fprintf(fp,"%f %f %f\n",p.x, p.y, p.z);
				}
			}
		}
	}	

	for( i=0; i<number; i++)
    {
		for ( k=1; k<=8; k++)
        {
			fprintf(fp,"%d ",8*i+k);
		}
		fprintf(fp,"\n");
	}

	fclose(fp);
}

//*********该函数只是把计算区域在不同的加密区分别进行任务划分********************//
void SetMpiMesh( Mesh* M[], double init_space, int myid, int numprocs , int level)
{
	// int countLatticeNodeX = (int)((max1.x - min1.x + space)/space + 0.5f);		//x方向总的格子数
	
	// int regionXDiv = countLatticeNodeX / numprocs;
	// int regionXMod = countLatticeNodeX % numprocs;

	// int regionXBeg = myid * regionXDiv + minInt(myid, regionXMod);
	// int regionXEnd = regionXBeg + regionXDiv - 1;

	// if(regionXMod > myid) regionXEnd = regionXEnd + 1;
	// (*M3).min.x = min1.x + regionXBeg * space - space;
	// (*M3).min.y = min1.y;
	// (*M3).min.z = min1.z;
	// (*M3).max.x = min1.x + regionXEnd * space + space + space + space;
	// (*M3).max.y = max1.y;
	// (*M3).max.z = max1.z;
	
	// printf("myid = %d, x: %f --- %f\n", myid, (*M3).min.x, (*M3).max.x );
	int latt_num;				//该层网格非加密区格点数
	double space;
	int i = 0;
	for(;i<level-1;i++)
	{
/////////是不是去掉循环，在主函数里面循环。（需要调用不同层的space）
		space = pow(0.5,i) * init_space;
		int latt_num_i_x,latt_num_i_y,latt_num_i_z;				//第i层各方向格点数
		int latt_num_i2_x,latt_num_i2_y,latt_num_i2_z;			//第i+1层各方向格点数

		latt_num_i_x  = (int)(((*M[i]).max.x - (*M[i]).min.x + space) / space + 0.5f);		//第i层各方向格点数		
		latt_num_i_y  = (int)(((*M[i]).max.y - (*M[i]).min.y + space) / space + 0.5f);		//1维划分，只是用于计算格子数
		latt_num_i_z  = (int)(((*M[i]).max.z - (*M[i]).min.z + space) / space + 0.5f);
		latt_num_i2_x = (int)(((*M[i+1]).max.x - (*M[i+1]).min.x + space) / space + 0.5f);
		latt_num_i2_y = (int)(((*M[i+1]).max.y - (*M[i+1]).min.y + space) / space + 0.5f);
		latt_num_i2_z = (int)(((*M[i+1]).max.z - (*M[i+1]).min.z + space) / space + 0.5f);

		latt_num = latt_num_i_x * latt_num_i_y * latt_num_i_z - latt_num_i2_x * latt_num_i2_y * latt_num_i2_z;

		//利用非加密区(的x)与加密区(的x)每层格点的倍数关系，求得新的x方向格点数。如果非加密区格点数是加密区的两倍，则两层加密区算一个格点
		int latt_Refinelayer_num,latt_Refinelayer_num2;		//加密区外部与内部每层含有的格点数(每层即每个x值)
		latt_Refinelayer_num = latt_num_i_y * latt_num_i_z;
		latt_Refinelayer_num2 = latt_num_i_y * latt_num_i_z - latt_num_i2_y * latt_num_i2_z;

		printf("%d  %d \n",latt_Refinelayer_num,latt_Refinelayer_num2);
		//计算新的格点数
	//*****************交互边界点算作加密区的**************** 暂时这样处理
		int temp_mul = (int)(latt_Refinelayer_num / latt_Refinelayer_num2 + 0.5f);

		int temp_latt_num_i_x = latt_num_i_x - latt_num_i2_x + (int)(latt_num_i2_x / temp_mul);

		//新格点生成后，进程任务的划分
		int regionXDiv = temp_latt_num_i_x / numprocs;
		int regionXMod = temp_latt_num_i_x % numprocs;
		int regionXBeg = myid * regionXDiv + minInt(myid, regionXMod);
		int regionXEnd = regionXBeg + regionXDiv - 1;
		if(regionXMod > myid) regionXEnd = regionXEnd + 1;
		// 以上进程任务划分结束
	
		//需要按照旧的格点还原回去
		int latt_num_i_x1 = (int)(((*M[i+1]).min.x - (*M[i]).min.x + space) / space + 0.5f);		//非加密区第一部分x方向格点数
		int latt_num_i_x2 = (int)(((*M[i+1]).max.x - (*M[i]).min.x + space) / space + 0.5f);
		//更新格点后，加密部分的划分

		int regionXDiv2 = latt_num_i2_x / ((int)(latt_num_i2_x / temp_mul));			//确定新的格点与旧的格点的关系，eg：新格点1代表旧格点1、2、3
		int regionXMod2 = latt_num_i2_x % ((int)(latt_num_i2_x / temp_mul));

// 进程开始或者结束在 交界面点是否需要特殊处理
		//该进程跨越非加密区第一部分+加密区
		if(regionXEnd > latt_num_i_x1-1 && regionXEnd < latt_num_i_x2 && regionXBeg < latt_num_i_x1-1)
		{
			int rank = regionXEnd - latt_num_i_x1;							//求进程终点
			int regionXBeg2 = rank * regionXDiv2 + minInt(rank, regionXMod2);
			int regionXEnd2 = regionXBeg2 + regionXDiv2 - 1;
			if(regionXMod2 > myid) regionXEnd2 = regionXEnd2 + 1;
			regionXEnd =  regionXEnd2 + latt_num_i_x1 - 1;
		}

		if(regionXBeg >= latt_num_i_x1-1 && regionXEnd < latt_num_i_x2)		//进程起点终点均在加密区
		{
			int rank = regionXBeg - latt_num_i_x1;							//针对进程起点
			int regionXBeg2 = rank * regionXDiv2 + minInt(rank, regionXMod2);
			int rank2 = regionXEnd - latt_num_i_x1;							//针对进程终点
			int regionXBeg3 = rank2 * regionXDiv2 + minInt(rank2, regionXMod2);
			int regionXEnd3 = regionXBeg3 + regionXDiv2 - 1;
			if(regionXMod2 > myid) regionXEnd3 = regionXEnd3 + 1;
			regionXBeg = regionXBeg2 + latt_num_i_x1 - 1;
			regionXEnd = regionXEnd3 + latt_num_i_x1 - 1;			
		}
		if(regionXBeg >= latt_num_i_x1-1 && regionXBeg < latt_num_i_x2 && regionXEnd >= latt_num_i_x2)	//进程起点在加密区，终点在非加密区
		{
			int rank = regionXBeg - latt_num_i_x1;							//针对进程起点
			int regionXBeg2 = rank * regionXDiv2 + minInt(rank, regionXMod2);
			regionXBeg = regionXBeg2 + latt_num_i_x1 - 1;
			regionXEnd = regionXEnd + latt_num_i2_x - (int)(latt_num_i2_x / temp_mul);
		}

		if(regionXBeg >= latt_num_i_x2 && regionXEnd >= latt_num_i_x2)		//进程起点终点均在第二(位置靠后)非加密区
		{
			regionXBeg = regionXBeg + latt_num_i2_x - (int)(latt_num_i2_x / temp_mul);
			regionXEnd = regionXEnd + latt_num_i2_x - (int)(latt_num_i2_x / temp_mul);
		}
		if(regionXBeg < latt_num_i_x1-1 && regionXEnd >= latt_num_i_x2)		//进程起点终点在两个不同加密区
		{
			regionXEnd = regionXEnd + latt_num_i2_x - (int)(latt_num_i2_x / temp_mul);
		}

		(*M[i]).min.x = (*M[i]).min.x + regionXBeg * space - space;
		(*M[i]).min.y = (*M[i]).min.y;
		(*M[i]).min.z = (*M[i]).min.z;
		(*M[i]).max.x = (*M[i]).min.x + regionXEnd * space + space + space + space;
		(*M[i]).max.y = (*M[i]).max.y;
		(*M[i]).max.z = (*M[i]).max.z;

		printf("myid = %d, x: %f --- %f\n", myid, (*M[i]).min.x, (*M[i]).max.x );
	}

	//处理最后一层格点
	if(i == level - 1)
	{
		space = pow(0.5,i) * init_space;
		int latt_num_i_x  = (int)(((*M[i]).max.x - (*M[i]).min.x + space) / space + 0.5f);		//x方向总的格子数
	
		int regionXDiv = latt_num_i_x / numprocs;
		int regionXMod = latt_num_i_x % numprocs;

		int regionXBeg = myid * regionXDiv + minInt(myid, regionXMod);
		int regionXEnd = regionXBeg + regionXDiv - 1;
		if(regionXMod > myid) regionXEnd = regionXEnd + 1;

		(*M[i]).min.x = (*M[i]).min.x + regionXBeg * space - space;
		(*M[i]).min.y = (*M[i]).min.y;
		(*M[i]).min.z = (*M[i]).min.z;
		(*M[i]).max.x = (*M[i]).min.x + regionXEnd * space + space + space + space;
		(*M[i]).max.y = (*M[i]).max.y;
		(*M[i]).max.z = (*M[i]).max.z;

		printf("myid = %d, x: %f --- %f\n", myid, (*M[i]).min.x, (*M[i]).max.x );
	}
	
}

// void SetMpiMesh( Mesh* M3, Point3d min1, Point3d max1, double space, int myid, int numprocs )
// {
// 	int countLatticeNodeX = (int)((max1.x - min1.x + space)/space + 0.5f);		//x方向总的格子数
	
// 	int regionXDiv = countLatticeNodeX / numprocs;
// 	int regionXMod = countLatticeNodeX % numprocs;

// 	int regionXBeg = myid * regionXDiv + minInt(myid, regionXMod);
// 	int regionXEnd = regionXBeg + regionXDiv - 1;

// 	if(regionXMod > myid) regionXEnd = regionXEnd + 1;

// 	(*M3).min.x = min1.x + regionXBeg * space - space;
// 	(*M3).min.y = min1.y;
// 	(*M3).min.z = min1.z;
// 	(*M3).max.x = min1.x + regionXEnd * space + space + space + space;
// 	(*M3).max.y = max1.y;
// 	(*M3).max.z = max1.z;

// 	printf("myid = %d, x: %f --- %f\n", myid, (*M3).min.x, (*M3).max.x );
// }

int minInt(int a, int b)
{
    if(a < b)
		return a;
	else
		return b;
}

void JudgeMeshStyle( Mesh* M )
{
	int i,j,id;
	char sty;
	int level = (*M).level;
	int num = (*M).length;
	Point3d p;

	for( i=0; i<num; i++ )
	{
		sty = (*M).lattice3d[i].style;
		
		if( level == 0 )
		{
			p = (*M).lattice3d[i].coordinate;
			//if( (p.x-10.0)*(p.x-10.0) + (p.y-10.0)*(p.y-10.0) <= 4 )
			if( (p.x-6.0)*(p.x-6.0) + (p.y-6.0)*(p.y-6.0) + (p.z-6.0)*(p.z-6.0) < 1 )
			{
				(*M).lattice3d[i].style = 's';
			}
		}
		else
		{
			if( sty == 'b' || sty == 's' )
			{
				p = (*M).lattice3d[i].coordinate;
				//if( (p.x-10.0)*(p.x-10.0) + (p.y-10.0)*(p.y-10.0) <= 4 )
				if( (p.x-7.0)*(p.x-7.0) + (p.y-6.0)*(p.y-6.0) + (p.z-6.0)*(p.z-6.0) < 1 )
				{
					(*M).lattice3d[i].style = 's';
				}
				else
				{
					(*M).lattice3d[i].style = 'f';
				}
			}
		}
	}

	for( i=0; i<num; i++ )
	{
		sty = (*M).lattice3d[i].style;
		if( sty == 's' )
		{
			for( j=0; j<18; j++ )
			{
				id = (*M).lattice3d[i].neighbour[j];
				if( (*M).lattice3d[id].style == 'f' )
				{
					(*M).lattice3d[id].style = 'b';
				}
			}
		}
	}
}

void InitialFlowField( Mesh* M[10], int N, double Rho,Point3d U, double P, double L, double Umax, double Re )
{
	// f 流体
	// b 边界
	// d 粗到细，最外粗	down 最贴近粗
	// e 粗到细，次外粗
	// u 细到粗，最外细 up   最贴近粗
	// v 细到粗，次外细
	// s 固体
	// (*(M[n]))
	
	int i,j,k,n;
	int num;
	int yesorno;
	char sty,sty1;
	
	double space = (*(M[0])).space;	
	double tau = 0.5 + 3.0*(L/space)*Umax/Re;	//第0重的松弛因子
	tau = 0.52;
	
	for( n=0; n<N; n++ )		//从第0重，遍历初始化没一重
	{
		num = (*(M[n])).length;
		for( i=0; i<num; i++ )		//找到 f b d 类型
		{
			yesorno = (*(M[n])).lattice3d[i].yesorno;	//0未加密，1加密
			sty = (*(M[n])).lattice3d[i].style;
			sty1 = (*(M[n])).lattice3d[i].movestyle;
			
			if( sty == 'f' && yesorno == 0 && sty1 != 'u' && sty1 != 'v' )		//是流场点，且未加密 是否加入movestyle == 'o' ?存疑
			{
				(*(M[n])).lattice3d[i].movestyle = 'f';
			}
			else if( sty != 'f' && sty != 's' && yesorno == 0  )
			{
				(*(M[n])).lattice3d[i].movestyle = 'b';
			}
			else if( yesorno == 1 )
			{
				for( k=0; k<18; k++ )
				{
					int neigh_id = (*(M[n])).lattice3d[i].neighbour[k];
					if( neigh_id != -1 )
					{
						if( (*(M[n])).lattice3d[neigh_id].yesorno == 0 && (*(M[n])).lattice3d[neigh_id].style == 'f' )
						{
							(*(M[n])).lattice3d[i].movestyle = 'd';
							break;
						}
					}
				}
			}
		}
		
		for( i=0; i<num; i++ )		//找到 e u v 类型
		{
			if( (*(M[n])).lattice3d[i].movestyle == 'd' )
			{
				for( k=0; k<18; k++ )			//找到 e 类型
				{
					int neigh_id = (*(M[n])).lattice3d[i].neighbour[k];
					yesorno = (*(M[n])).lattice3d[neigh_id].yesorno;	//0未加密，1加密
					sty = (*(M[n])).lattice3d[neigh_id].movestyle;
					if( yesorno == 1 && sty != 'd' &&  sty != 'e' )
					{
						(*(M[n])).lattice3d[neigh_id].movestyle = 'e';
					}
				}
				
				if( n < N-1 )					//找到 u v 类型
				{
					for( k=0; k<8; k++ )
					{
						int sonid = (*(M[n])).lattice3d[i].son_id[k];
						int flag = 1;
						
						for( j=0; j<18; j++)
						{
							int neigh_id = (*(M[n+1])).lattice3d[sonid].neighbour[j];
							if( neigh_id == -1 )
							{
								flag = 0;
							}
						}
						
						if( flag == 0 )
						{
							(*(M[n+1])).lattice3d[sonid].movestyle = 'u';
						}
						else
						{
							(*(M[n+1])).lattice3d[sonid].movestyle = 'v';
						}
					}
				}					
			}
		}
		
		double tau_f = 0.5 + pow(2.0,n)*(tau-0.5);		//第n重的松弛因子
		(*(M[n])).tau = tau_f;
		
		for( i=0; i<num; i++ )		//流场信息初始化
		{
			(*(M[n])).lattice3d[i].rho = Rho;
			(*(M[n])).lattice3d[i].u = U;
			(*(M[n])).lattice3d[i].p = P;
			(*(M[n])).lattice3d[i].tau = tau_f;
			
			if( (*(M[n])).lattice3d[i].style == 's' )
			{
				(*(M[n])).lattice3d[i].u.x = 0.0;
				(*(M[n])).lattice3d[i].u.y = 0.0;
				(*(M[n])).lattice3d[i].u.z = 0.0;
			}
			
			for( k=0; k<19; k++ )
			{
				(*(M[n])).lattice3d[i].f[k] = 0.0;
				(*(M[n])).lattice3d[i].fcol[k] = 0.0;
				(*(M[n])).lattice3d[i].feq[k] = 0.0;
			}
			
			ComputeLatticeFeq( &((*(M[n])).lattice3d[i]) );
			
			for( k=0; k<19; k++ )
			{
				(*(M[n])).lattice3d[i].f[k] = (*(M[n])).lattice3d[i].feq[k];
				(*(M[n])).lattice3d[i].fcol[k] = (*(M[n])).lattice3d[i].feq[k];
			}
			
		}		
	}	
}

void ComputeLatticeFeq( Lattice3d* latt )
{
	Point3d u = (*latt).u;
	double rho = (*latt).rho;
	
	double w0 = rho/3.0;
	double w1 = rho/18.0;
	double w2 = rho/36.0;

	double uu = 1 - 1.5*(u.x*u.x+u.y*u.y+u.z*u.z);
	
	(*latt).feq[0] = w0*( uu );
	(*latt).feq[1] = w1*( uu + 3.0*(u.x) + 4.5*(u.x)*(u.x) );
	(*latt).feq[2] = w1*( uu - 3.0*(u.x) + 4.5*(u.x)*(u.x) );
	(*latt).feq[3] = w1*( uu + 3.0*(u.y) + 4.5*(u.y)*(u.y) );
	(*latt).feq[4] = w1*( uu - 3.0*(u.y) + 4.5*(u.y)*(u.y) );
	(*latt).feq[5] = w1*( uu + 3.0*(u.z) + 4.5*(u.z)*(u.z) );
	(*latt).feq[6] = w1*( uu - 3.0*(u.z) + 4.5*(u.z)*(u.z) );
	(*latt).feq[7] = w2*( uu + 3.0*(u.x+u.y) + 4.5*(u.x+u.y)*(u.x+u.y) );
	(*latt).feq[8] = w2*( uu - 3.0*(u.x+u.y) + 4.5*(u.x+u.y)*(u.x+u.y) );
	(*latt).feq[9] = w2*( uu + 3.0*(u.x-u.y) + 4.5*(u.x-u.y)*(u.x-u.y) );
	(*latt).feq[10]= w2*( uu - 3.0*(u.x-u.y) + 4.5*(u.x-u.y)*(u.x-u.y) );
	(*latt).feq[11]= w2*( uu + 3.0*(u.x+u.z) + 4.5*(u.x+u.z)*(u.x+u.z) );
	(*latt).feq[12]= w2*( uu - 3.0*(u.x+u.z) + 4.5*(u.x+u.z)*(u.x+u.z) );
	(*latt).feq[13]= w2*( uu + 3.0*(u.x-u.z) + 4.5*(u.x-u.z)*(u.x-u.z) );
	(*latt).feq[14]= w2*( uu - 3.0*(u.x-u.z) + 4.5*(u.x-u.z)*(u.x-u.z) );
	(*latt).feq[15]= w2*( uu + 3.0*(u.y+u.z) + 4.5*(u.y+u.z)*(u.y+u.z) );
	(*latt).feq[16]= w2*( uu - 3.0*(u.y+u.z) + 4.5*(u.y+u.z)*(u.y+u.z) );
	(*latt).feq[17]= w2*( uu + 3.0*(u.y-u.z) + 4.5*(u.y-u.z)*(u.y-u.z) );
	(*latt).feq[18]= w2*( uu - 3.0*(u.y-u.z) + 4.5*(u.y-u.z)*(u.y-u.z) );
}

void WriteMultiMeshLatticeMpiStyle( Mesh* M[10], int N, double space, char name[30], char ch )
{
	Point3d Direction[8] =  {{ 1, 1, 1}, {-1, 1, 1}, {-1, -1, 1}, {1, -1, 1},{1, 1,-1}, {-1, 1, -1}, {-1, -1, -1}, {1, -1, -1}};
	int i,j,k;
	int number = 0;
	FILE *fp;
	Point3d p, centerp;
	
	for( j=0; j<N; j++ )
	{
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( (*(M[j])).lattice3d[i].style != 's' && (*(M[j])).lattice3d[i].yesorno == 0 && (*(M[j])).lattice3d[i].mpistyle == ch )
			{
				number++;
			}
		}
	}
	

	fp = fopen(name,"w");
	if ( fp == NULL )
	{
		printf("Open Out File is error!!!\n");
		abort();
	}

	fprintf( fp,"title=\"Mesh Show\"\n" );
	fprintf( fp,"VARIABLES=\"x\", \"y\", \"z\"\n" );
	fprintf( fp,"ZONE T =\"fuse\"\n" );
	fprintf( fp,"Nodes = %d, Elements = %d\n", number*8, number );
	fprintf( fp,"ZONETYPE = FEBRICK, DATAPACKING = POINT\n" );

	for( j=0; j<N; j++ )
	{
		space = space/2.0;
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( (*(M[j])).lattice3d[i].style != 's' && (*(M[j])).lattice3d[i].yesorno == 0 && (*(M[j])).lattice3d[i].mpistyle == ch )
			{
				centerp = (*(M[j])).lattice3d[i].coordinate;
				for ( k=0; k<8; k++)
				{
					p.x = centerp.x + space * Direction[k].x;
					p.y = centerp.y + space * Direction[k].y;
					p.z = centerp.z + space * Direction[k].z;
					fprintf(fp,"%f %f %f\n",p.x, p.y, p.z);
				}
			}
		}
	}	

	for( i=0; i<number; i++)
    {
		for ( k=1; k<=8; k++)
        {
			fprintf(fp,"%d ",8*i+k);
		}
		fprintf(fp,"\n");
	}

	fclose(fp);
}

void WriteMpiStylePoint( Mesh* M, double space, int myid, char ch )
{
	int level = (*M).level;
	int num = (*M).length;
	char na[60];
	int i;
	
	sprintf( na,"MpiStylePoint_myid_%d_level_%d_%c.dat", myid, level, ch );
	
	FILE *fp = fopen(na,"w");
	if ( fp == NULL )
	{
		printf("Open Out File is error!!!\n");
		abort();
	}
	
	for( i=0; i<num; i++ )
	{
		char sty = (*M).lattice3d[i].mpistyle;
		if( sty == ch )
		{
			Point3d p =  (*M).lattice3d[i].coordinate;
			fprintf(fp,"%f %f %f\n",p.x, p.y, p.z);
		}
	}
	
	fclose(fp);
}

 void WriteMultiMeshLatticeFlowPointD3Q19( Mesh* M[10], int N, double space, int n, int myid )
{
	Point3d Direction[8] =  {{ 1, 1, 1}, {-1, 1, 1}, {-1, -1, 1}, {1, -1, 1},{1, 1,-1}, {-1, 1, -1}, {-1, -1, -1}, {1, -1, -1}};
	int i,j,k;
	int number = 0;
	FILE *fp;
	Point3d p, centerp, u;
	double rho;

	for( j=0; j<N; j++ )
	{
		for( i=0; i<(*(M[j])).length; i++ )
		{
			char mpisty = (*(M[j])).lattice3d[i].mpistyle;
			char sty = (*(M[j])).lattice3d[i].style;
			int yesorno = (*(M[j])).lattice3d[i].yesorno;
			if( sty != 's' && yesorno == 0 && mpisty != 'n' && mpisty != 'r' && mpisty != 'z' && mpisty != 'j' )
			{
				number++;
			}
		}
	}

	char name[30];
	sprintf( name,"OutPut_%d_%d.dat", n, myid );

	fp = fopen(name,"w");
	if ( fp == NULL )
	{
		printf("Open Out File is error!!!\n");
		abort();
	}

	fprintf( fp,"title=\"Out Put\"\n" );
	fprintf( fp,"VARIABLES=\"x\", \"y\", \"z\", \"ux\", \"uy\", \"uz\", \"p\"\n" );
	fprintf( fp,"ZONE T =\"fuse\"\n" );
	fprintf( fp,"Nodes = %d, Elements = %d\n", number*8, number );
	fprintf( fp,"ZONETYPE = FEBRICK, DATAPACKING = POINT\n" );

	for( j=0; j<N; j++ )
	{
		space = space/2.0;
		for( i=0; i<(*(M[j])).length; i++ )
		{
			char mpisty = (*(M[j])).lattice3d[i].mpistyle;
			char sty = (*(M[j])).lattice3d[i].style;
			int yesorno = (*(M[j])).lattice3d[i].yesorno;
			if( sty != 's' && yesorno == 0 && mpisty != 'n' && mpisty != 'r' && mpisty != 'z' && mpisty != 'j' )
			{
				centerp = (*(M[j])).lattice3d[i].coordinate;
				u = (*(M[j])).lattice3d[i].u;
				rho = (*(M[j])).lattice3d[i].rho;
				for ( k=0; k<8; k++)
				{
					p.x = centerp.x + space * Direction[k].x;
					p.y = centerp.y + space * Direction[k].y;
					p.z = centerp.z + space * Direction[k].z;
					fprintf(fp,"%f %f %f %f %f %f \n",p.x, p.y, p.z, u.x, u.y, u.z);
				}
			}
		}
	}

	for( i=0; i<number; i++)
    {
		for ( k=1; k<=8; k++)
        {
			fprintf(fp,"%d ",8*i+k);
		}
		fprintf(fp,"\n");
	}

	fclose(fp);
}

void DoubleMeshCollisionStreamLBGKD3Q19( Mesh* M1, Mesh* M2, int myid, int numprocs )
{
		
		
		MPI_Barrier(MPI_COMM_WORLD);
		//第一层网格进行碰撞
		ComputeMultipleMeshCollisionLBGKD3Q19( M1, 0 );
		
		MPI_Barrier(MPI_COMM_WORLD);
		//第一层网格进行通信
		MultiMeshDataTransfer( M1, myid, numprocs );
		
		MPI_Barrier(MPI_COMM_WORLD);
		//第一层网格进行迁移
		ComputeMultipleMeshMoveLBGKD3Q19( M1, 0 );
		MPI_Barrier(MPI_COMM_WORLD);
		

						
						MPI_Barrier(MPI_COMM_WORLD);
						//第二层网格进行第一次碰撞
						ComputeMultipleMeshCollisionLBGKD3Q19( M2, 1 );
						
						MPI_Barrier(MPI_COMM_WORLD);
						//第二层网格进行通信
						MultiMeshDataTransfer( M2, myid, numprocs );
						
						MPI_Barrier(MPI_COMM_WORLD);						
						//第二层网格进行第一次迁移
						ComputeMultipleMeshMoveLBGKD3Q19( M2, 1 );
						MPI_Barrier(MPI_COMM_WORLD);
						

				//第一层网格向第二层网格传送,计算T+1/2时刻的值
				PassDownDataHalfLBGKD3Q19( M1, M2, 0 );

						
						MPI_Barrier(MPI_COMM_WORLD);
						//第二层网格进行第二次碰撞
						ComputeMultipleMeshCollisionLBGKD3Q19( M2, 1 );
						
						MPI_Barrier(MPI_COMM_WORLD);
						//第二层网格进行通信
						MultiMeshDataTransfer( M2, myid, numprocs );
						
						MPI_Barrier(MPI_COMM_WORLD);						
						//第二层网格进行第二次迁移
						ComputeMultipleMeshMoveLBGKD3Q19( M2, 1 );
						MPI_Barrier(MPI_COMM_WORLD);
						

				//第二层网格向第一层网格传送T+1时刻的值
				PassUpDataLBGKD3Q19( M1, M2, 0 );
				MPI_Barrier(MPI_COMM_WORLD);

				//第一层网格向第二层网格传送,计算T+1时刻的值
				PassDownDataAllLBGKD3Q19( M1, M2, 0 );
}

void ComputeMultipleMeshCollisionLBGKD3Q19( Mesh* M, int n )
{
	if( (*M).level != n )
	{
		printf( "Collish level error in line 1668\n" );
		abort();
	}

	// f 流体
	// b 边界
	// d 粗到细，最外粗	down 最贴近粗
	// e 粗到细，次外粗
	// u 细到粗，最外细 up   最贴近粗
	// v 细到粗，次外细
	// s 固体

	int i,j,k;

	int num = (*M).length;
	for( i=0; i<num; i++ )
	{
		char movesty = (*M).lattice3d[i].movestyle;
		char mpisty = (*M).lattice3d[i].mpistyle;
		//if( movesty != 's' && mpisty != 'j' && mpisty != 'r' && mpisty != 'n' )
		if( movesty != 's' && mpisty != 'j' && mpisty != 'r' )
		//if( movesty != 's' )
		{
			ComputeLatticeFeq( &((*M).lattice3d[i]) );
			for( k=0; k<19; k++ )
			{
				double f = (*M).lattice3d[i].f[k];
				double feq = (*M).lattice3d[i].feq[k];
				double tau = (*M).lattice3d[i].tau;
				double fcol = f + ( feq - f )/tau;
				(*M).lattice3d[i].fcol[k] = fcol;
			}
		}
	}
}

void ComputeMultipleMeshMoveLBGKD3Q19( Mesh* M, int n )
{
	if( (*M).level != n )
	{
		printf( "Meshmove level error in line 1165\n" );
		abort();
	}

	int inv[19] = {0, 2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17};
	int ex[19]={0, 1,-1, 0, 0, 0, 0, 1,-1, 1,-1, 1,-1, 1,-1, 0, 0, 0, 0};
	int ey[19]={0, 0, 0, 1,-1, 0, 0, 1,-1,-1, 1, 0, 0, 0, 0, 1,-1, 1,-1};
	int ez[19]={0, 0, 0, 0, 0, 1,-1, 0, 0, 0, 0, 1,-1,-1, 1, 1,-1,-1, 1};

	// f 流体
	// b 边界
	// d 粗到细，最外粗	down 最贴近粗
	// e 粗到细，次外粗
	// u 细到粗，最外细 up   最贴近粗
	// v 细到粗，次外细
	// s 固体

	int i,j,k;
	int num = (*M).length;

	for( i=0; i<num; i++ )
	{
		char sty = (*M).lattice3d[i].movestyle;
		char mpisty = (*M).lattice3d[i].mpistyle;
		if( sty == 'v' && mpisty != 'j' && mpisty != 'r' && mpisty != 'n' )
		//if( sty == 'v' && mpisty != 'j' && mpisty != 'r' )
		//if( sty == 'v' )
		{
			double rho = 0.0;
			Point3d u = {0.0, 0.0, 0.0};

			int neigh_id = i;
			double fcol = (*M).lattice3d[neigh_id].fcol[0];
			(*M).lattice3d[i].f[0] = fcol;

			rho = fcol;			//宏观量计算
			u.x = fcol*ex[0];
			u.y = fcol*ey[0];
			u.z = fcol*ez[0];

			for( k=1; k<19; k++ )
			{
				neigh_id = (*M).lattice3d[i].neighbour[inv[k]-1];
				fcol = (*M).lattice3d[neigh_id].fcol[k];
				(*M).lattice3d[i].f[k] = fcol;

				rho += fcol;			//宏观量计算
				u.x += fcol*ex[k];
				u.y += fcol*ey[k];
				u.z += fcol*ez[k];
			}
			//宏观量计算
			u.x /= rho;
			u.y /= rho;
			u.z /= rho;

			(*M).lattice3d[i].rho = rho;
			(*M).lattice3d[i].u = u;

			ComputeLatticeFeq( &((*M).lattice3d[i]) );
		}
	}
	
	for( i=0; i<num; i++ )
	{
		char sty = (*M).lattice3d[i].movestyle;
		char mpisty = (*M).lattice3d[i].mpistyle;
		if( sty == 'd' && mpisty != 'j' && mpisty != 'r' && mpisty != 'n' )
		//if( sty == 'd' && mpisty != 'j' && mpisty != 'r' )
		//if( sty == 'd' )
		{
			double rho = 0.0;
			Point3d u = {0.0, 0.0, 0.0};

			int neigh_id = i;
			double fcol = (*M).lattice3d[neigh_id].fcol[0];
			(*M).lattice3d[i].f[0] = fcol;

			rho = fcol;			//宏观量计算
			u.x = fcol*ex[0];
			u.y = fcol*ey[0];
			u.z = fcol*ez[0];

			for( k=1; k<19; k++ )
			{
				neigh_id = (*M).lattice3d[i].neighbour[inv[k]-1];
				fcol = (*M).lattice3d[neigh_id].fcol[k];
				(*M).lattice3d[i].f[k] = fcol;

				rho += fcol;			//宏观量计算
				u.x += fcol*ex[k];
				u.y += fcol*ey[k];
				u.z += fcol*ez[k];
			}
			//宏观量计算
			u.x /= rho;
			u.y /= rho;
			u.z /= rho;

			(*M).lattice3d[i].rho = rho;
			(*M).lattice3d[i].u = u;

			ComputeLatticeFeq( &((*M).lattice3d[i]) );
		}
	}
	
	for( i=0; i<num; i++ )
	{
		char sty = (*M).lattice3d[i].movestyle;
		char mpisty = (*M).lattice3d[i].mpistyle;
		if( sty == 'f' && mpisty != 'j' && mpisty != 'r' && mpisty != 'n' )
		//if( sty == 'f' && mpisty != 'j' && mpisty != 'r' )
		//if( sty == 'f' )
		{
			double rho = 0.0;
			Point3d u = {0.0, 0.0, 0.0};

			int neigh_id = i;
			double fcol = (*M).lattice3d[neigh_id].fcol[0];
			(*M).lattice3d[i].f[0] = fcol;

			rho = fcol;			//宏观量计算
			u.x = fcol*ex[0];
			u.y = fcol*ey[0];
			u.z = fcol*ez[0];

			for( k=1; k<19; k++ )
			{
				neigh_id = (*M).lattice3d[i].neighbour[inv[k]-1];
				fcol = (*M).lattice3d[neigh_id].fcol[k];
				(*M).lattice3d[i].f[k] = fcol;

				rho += fcol;			//宏观量计算
				u.x += fcol*ex[k];
				u.y += fcol*ey[k];
				u.z += fcol*ez[k];
			}
			//宏观量计算
			u.x /= rho;
			u.y /= rho;
			u.z /= rho;

			(*M).lattice3d[i].rho = rho;
			(*M).lattice3d[i].u = u;

			ComputeLatticeFeq( &((*M).lattice3d[i]) );
		}
	}
	
	for( i=0; i<num; i++ )
	{
		char sty = (*M).lattice3d[i].movestyle;
		char mpisty = (*M).lattice3d[i].mpistyle;
		if( sty == 'b' && mpisty != 'j' && mpisty != 'r' && mpisty != 'n' )
		//if( sty == 'b' && mpisty != 'j' && mpisty != 'r' )
		//if( sty == 'b' )
		{
			char osty = (*M).lattice3d[i].style;

			if( osty == 'b' )	//物面边界
			{
				double rho = 0.0;			//密度初值
				Point3d u = {0.0, 0.0, 0.0};//速度初值

				int neigh_id = i;
				double fcol = (*M).lattice3d[neigh_id].fcol[0];
				(*M).lattice3d[i].f[0] = fcol;

				rho = fcol;			//宏观量计算
				u.x = fcol*ex[0];
				u.y = fcol*ey[0];
				u.z = fcol*ez[0];

				for( k=1; k<19; k++ )
				{
					neigh_id = (*M).lattice3d[i].neighbour[inv[k]-1];
					char neigh_sty = (*M).lattice3d[neigh_id].style;

					if( neigh_sty == 's' )		//反弹格式
					{
						neigh_id = (*M).lattice3d[i].neighbour[k-1];
						neigh_sty = (*M).lattice3d[neigh_id].style;
						if( neigh_sty == 'f' )
						{
							fcol = (*M).lattice3d[neigh_id].fcol[inv[k]];
							//fcol = (*M).lattice3d[neigh_id].fcol[k];
							(*M).lattice3d[i].f[k] = fcol;
						}
						else
						{
							fcol = (*M).lattice3d[i].fcol[k];
							(*M).lattice3d[i].f[k] = fcol;
						}
					}
					else
					{
						fcol = (*M).lattice3d[neigh_id].fcol[k];
						(*M).lattice3d[i].f[k] = fcol;
					}
					rho += fcol;			//宏观量计算
					u.x += fcol*ex[k];
					u.y += fcol*ey[k];
					u.z += fcol*ez[k];
				}

				u.x /= rho;
				u.y /= rho;
				u.z /= rho;

				(*M).lattice3d[i].rho = rho;
				(*M).lattice3d[i].u = u;
			}
			else				//计算区域包围盒边界
			{
				int neigh_id;
				double rho;
				Point3d uu;
				double fcol, feq0, feq1;

				switch( osty )
				{
				case 'e':	//left 入口
					neigh_id = (*M).lattice3d[i].neighbour[0];
					rho = (*M).lattice3d[neigh_id].rho;
					(*M).lattice3d[i].rho = rho;

					ComputeLatticeFeq( &((*M).lattice3d[i]) );
					for( k=0; k<19; k++ )
					{
						feq0 = (*M).lattice3d[i].feq[k];
						feq1 = (*M).lattice3d[neigh_id].feq[k];
						fcol = (*M).lattice3d[neigh_id].f[k];
						fcol = feq0 + (fcol - feq1);
						(*M).lattice3d[i].f[k] = fcol;
					}
					break;
				case 'i':	//right 出口
					neigh_id = (*M).lattice3d[i].neighbour[1];
					rho = (*M).lattice3d[neigh_id].rho;
					(*M).lattice3d[i].rho = rho;
					uu = (*M).lattice3d[neigh_id].u;
					(*M).lattice3d[i].u = uu;

					ComputeLatticeFeq( &((*M).lattice3d[i]) );
					for( k=0; k<19; k++ )
					{
						feq0 = (*M).lattice3d[i].feq[k];
						feq1 = (*M).lattice3d[neigh_id].feq[k];
						fcol = (*M).lattice3d[neigh_id].f[k];
						fcol = feq0 + (fcol - feq1);
						(*M).lattice3d[i].f[k] = fcol;
					}
					break;
				case 'p':	//up
					neigh_id = (*M).lattice3d[i].neighbour[5];
					rho = (*M).lattice3d[neigh_id].rho;
					(*M).lattice3d[i].rho = rho;

					ComputeLatticeFeq( &((*M).lattice3d[i]) );
					for( k=0; k<19; k++ )
					{
						feq0 = (*M).lattice3d[i].feq[k];
						feq1 = (*M).lattice3d[neigh_id].feq[k];
						fcol = (*M).lattice3d[neigh_id].f[k];
						fcol = feq0 + (fcol - feq1);
						(*M).lattice3d[i].f[k] = fcol;
					}
					break;
				case 'o':	//down
					neigh_id = (*M).lattice3d[i].neighbour[4];
					rho = (*M).lattice3d[neigh_id].rho;
					(*M).lattice3d[i].rho = rho;

					ComputeLatticeFeq( &((*M).lattice3d[i]) );
					for( k=0; k<19; k++ )
					{
						feq0 = (*M).lattice3d[i].feq[k];
						feq1 = (*M).lattice3d[neigh_id].feq[k];
						fcol = (*M).lattice3d[neigh_id].f[k];
						fcol = feq0 + (fcol - feq1);
						(*M).lattice3d[i].f[k] = fcol;
					}
					break;
				case 'r':	//front
					neigh_id = (*M).lattice3d[i].neighbour[3];
					rho = (*M).lattice3d[neigh_id].rho;
					(*M).lattice3d[i].rho = rho;

					ComputeLatticeFeq( &((*M).lattice3d[i]) );
					for( k=0; k<19; k++ )
					{
						feq0 = (*M).lattice3d[i].feq[k];
						feq1 = (*M).lattice3d[neigh_id].feq[k];
						fcol = (*M).lattice3d[neigh_id].f[k];
						fcol = feq0 + (fcol - feq1);
						(*M).lattice3d[i].f[k] = fcol;
					}
					break;
				case 'a':	//back
					neigh_id = (*M).lattice3d[i].neighbour[2];
					rho = (*M).lattice3d[neigh_id].rho;
					(*M).lattice3d[i].rho = rho;

					ComputeLatticeFeq( &((*M).lattice3d[i]) );
					for( k=0; k<19; k++ )
					{
						feq0 = (*M).lattice3d[i].feq[k];
						feq1 = (*M).lattice3d[neigh_id].feq[k];
						fcol = (*M).lattice3d[neigh_id].f[k];
						fcol = feq0 + (fcol - feq1);
						(*M).lattice3d[i].f[k] = fcol;
					}
					break;
				default:
					break;
				}
			}
		}
	}
}

void PassDownDataHalfLBGKD3Q19( Mesh* M1, Mesh* M2, int n )
{
	if( (*M1).level != n )
	{
		printf( "PassDown DataHalf level error in line 1392\n" );
		abort();
	}

	// f 流体
	// b 边界
	// d 粗到细，最外粗	down 最贴近粗
	// e 粗到细，次外粗
	// u 细到粗，最外细 up   最贴近粗
	// v 细到粗，次外细
	// s 固体

	int i,j,k;
	int num = (*M1).length;

	for( i=0; i<num; i++ )
	{
		char sty = (*M1).lattice3d[i].movestyle;
		char mpisty = (*M1).lattice3d[i].mpistyle;
		//if( sty == 'd' && mpisty != 'r' && mpisty != 'j')
		//if( sty == 'd' && mpisty != 'r' && mpisty != 'j' && mpisty != 'n' )
		if( sty == 'd' )
		{
			double rho = (*M1).lattice3d[i].rho;
			double p = (*M1).lattice3d[i].p;
			Point3d u = (*M1).lattice3d[i].u;

			for( j=0; j<8; j++ )	//宏观量传递
			{
				int son_id = (*M1).lattice3d[i].son_id[j];
				double son_rho = (*M2).lattice3d[son_id].rho;
				double son_p = (*M2).lattice3d[son_id].p;
				Point3d son_u = (*M2).lattice3d[son_id].u;

				son_rho = ( rho + son_rho )/2.0;
				son_p = ( p + son_p )/2.0;
				son_u.x = ( u.x + son_u.x )/2.0;
				son_u.y = ( u.y + son_u.y )/2.0;
				son_u.z = ( u.z + son_u.z )/2.0;

				(*M2).lattice3d[son_id].rho = son_rho;
				(*M2).lattice3d[son_id].p = son_p;
				(*M2).lattice3d[son_id].u = son_u;
			}
			for( k=0; k<19; k++ )
			{
				double f_c = (*M1).lattice3d[i].f[k];
				double f_eq = (*M1).lattice3d[i].feq[k];
				double tau_c = (*M1).lattice3d[i].tau;
				int son0 = (*M1).lattice3d[i].son_id[0];
				double tau_f = (*M2).lattice3d[son0].tau;

				double f_f = f_eq + (tau_f-1.0)/2.0/(tau_c-1.0)*(f_c-f_eq);
				for( j=0; j<8; j++ )
				{
					int son_id = (*M1).lattice3d[i].son_id[j];
					double f_f1 = (*M2).lattice3d[son_id].f[k];
					f_f1 = ( f_f + f_f1 )/2.0;
					(*M2).lattice3d[son_id].f[k] = f_f1;
				}
			}
		}
	}
}

void PassUpDataLBGKD3Q19( Mesh* M1, Mesh* M2, int n )
{
	if( (*M1).level != n )
	{
		printf( "PassUP Data level error in line 1517\n" );
		abort();
	}

	// f 流体
	// b 边界
	// d 粗到细，最外粗	down 最贴近粗
	// e 粗到细，次外粗
	// u 细到粗，最外细 up   最贴近粗
	// v 细到粗，次外细
	// s 固体

	int i,j,k;
	int num = (*M1).length;

	for( i=0; i<num; i++ )
	{
		char sty = (*M1).lattice3d[i].movestyle;
		char mpisty = (*M1).lattice3d[i].mpistyle;
		//if( sty == 'e' && mpisty != 'r' && mpisty != 'j' )
		if( sty == 'e' )
		//if( sty == 'e' && mpisty != 'r' && mpisty != 'j' && mpisty != 'n' )
		{
			double rho = 0.0;
			Point3d u = {0.0, 0.0, 0.0};
			double p = 0.0;

			for( j=0; j<8; j++ )	//宏观量传递
			{
				int son_id = (*M1).lattice3d[i].son_id[j];
				double son_rho = (*M2).lattice3d[son_id].rho;
				double son_p = (*M2).lattice3d[son_id].p;
				Point3d son_u = (*M2).lattice3d[son_id].u;
				rho = rho + son_rho;
				p = p + son_p;
				u.x = u.x + son_u.x;
				u.y = u.y + son_u.y;
				u.z = u.z + son_u.z;
			}
			rho = rho/8.0;
			u.x = u.x/8.0;
			u.y = u.y/8.0;
			u.z = u.z/8.0;
			p = p/8.0;

			(*M1).lattice3d[i].rho = rho;
			(*M1).lattice3d[i].u = u;
			(*M1).lattice3d[i].p = p;

			ComputeLatticeFeq( &((*M1).lattice3d[i]) );

			for( k=0; k<19; k++ )		//微观量传递
			{
				double f_c = 0.0;
				for( j=0; j<8; j++ )
				{
					int son_id = (*M1).lattice3d[i].son_id[j];
					f_c = f_c + (*M2).lattice3d[son_id].f[k];
				}
				f_c = f_c/8.0;

				double tau_c = (*M1).lattice3d[i].tau;
				int son_idd = (*M1).lattice3d[i].son_id[0];
				double tau_f = (*M2).lattice3d[son_idd].tau;
				double f_eq = (*M1).lattice3d[i].feq[k];

				f_c = f_eq + (f_c - f_eq)*2.0*tau_c/tau_f;
				(*M1).lattice3d[i].f[k] = f_c;
			}
		}
	}
}

void PassDownDataAllLBGKD3Q19( Mesh* M1, Mesh* M2, int n )
{
	if( (*M1).level != n )
	{
		printf( "PassDown DataAll level error in line 1459\n" );
		abort();
	}

	// f 流体
	// b 边界
	// d 粗到细，最外粗	down 最贴近粗
	// e 粗到细，次外粗
	// u 细到粗，最外细 up   最贴近粗
	// v 细到粗，次外细
	// s 固体

	int i,j,k;
	int num = (*M1).length;

	for( i=0; i<num; i++ )
	{
		char sty = (*M1).lattice3d[i].movestyle;
		char mpisty = (*M1).lattice3d[i].mpistyle;
		//if( sty == 'd' && mpisty != 'r' && mpisty != 'j')
		if( sty == 'd' )
		//if( sty == 'd' && mpisty != 'r' && mpisty != 'j' && mpisty != 'n' )
		{
			double rho = (*M1).lattice3d[i].rho;
			double p = (*M1).lattice3d[i].p;
			Point3d u = (*M1).lattice3d[i].u;

			for( j=0; j<8; j++ )	//宏观量传递
			{
				int son_id = (*M1).lattice3d[i].son_id[j];

				(*M2).lattice3d[son_id].rho = rho;
				(*M2).lattice3d[son_id].p = p;
				(*M2).lattice3d[son_id].u = u;
				ComputeLatticeFeq( &((*M2).lattice3d[son_id]) );

			}
			for( k=0; k<19; k++ )
			{
				double f_c = (*M1).lattice3d[i].f[k];
				double tau_c = (*M1).lattice3d[i].tau;

				for( j=0; j<8; j++ )
				{
					int son_id = (*M1).lattice3d[i].son_id[j];
					double f_eq = (*M2).lattice3d[son_id].feq[k];
					double tau_f = (*M2).lattice3d[son_id].tau;

					double f_f = f_eq + (f_c - f_eq)*tau_f/2.0/tau_c;
					(*M2).lattice3d[son_id].f[k] = f_f;
				}
			}
		}
	}
}

void MultiMeshDataTransfer( Mesh* M, int myid, int numprocs )
{
	MPI_Status status;
	int leftsend = (*M).leftsend;						//左侧发送缓冲区格子数
	int leftrecv = (*M).leftrecv;						//左侧接收缓冲区格子数
	int rightsend = (*M).rightsend;						//右侧发送缓冲区格子数
	int rightrecv = (*M).rightrecv;						//右侧接收缓冲区格子数
	double *temp_leftsend;
	double *temp_leftrecv;
	double *temp_rightsend;
	double *temp_rightrecv;
	
	int danum = 5;
	
	if( leftsend != 0 )
	{
		temp_leftsend = (double*)malloc(danum * leftsend * sizeof(double));	
	}
	if( leftrecv != 0 )
	{
		temp_leftrecv = (double*)malloc(danum * leftrecv * sizeof(double));	
	}
	if( rightsend != 0 )
	{
		temp_rightsend = (double*)malloc(danum * rightsend * sizeof(double));	
	}
	if( rightrecv != 0 )
	{
		temp_rightrecv = (double*)malloc(danum * rightrecv * sizeof(double));	
	}
	// if( temp_leftsend == NULL || temp_leftrecv == NULL || temp_rightsend == NULL || temp_rightrecv == NULL  )
	// {
		// printf("malloc send&recv temp error in line 2284\n");
		// abort();
	// }
	
	int num = (*M).length;
	int i,count;
	
	if( myid % 2 == 0 )		//偶数进程先发送后接收
	{
		if( myid != numprocs - 1 )		//发送右端数据
		{
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 'f' )
				{
					temp_rightsend[count * danum + 0] = (*M).lattice3d[i].fcol[1];
					temp_rightsend[count * danum + 1] = (*M).lattice3d[i].fcol[7];
					temp_rightsend[count * danum + 2] = (*M).lattice3d[i].fcol[9];
					temp_rightsend[count * danum + 3] = (*M).lattice3d[i].fcol[11];
					temp_rightsend[count * danum + 4] = (*M).lattice3d[i].fcol[13];
					
					// temp_rightsend[count * danum + 5] = (*M).lattice3d[i].fcol[2];
					// temp_rightsend[count * danum + 6] = (*M).lattice3d[i].fcol[3];
					// temp_rightsend[count * danum + 7] = (*M).lattice3d[i].fcol[4];
					// temp_rightsend[count * danum + 8] = (*M).lattice3d[i].fcol[5];
					// temp_rightsend[count * danum + 9] = (*M).lattice3d[i].fcol[6];
					// temp_rightsend[count * danum + 10] = (*M).lattice3d[i].fcol[8];
					// temp_rightsend[count * danum + 11] = (*M).lattice3d[i].fcol[10];
					// temp_rightsend[count * danum + 12] = (*M).lattice3d[i].fcol[12];
					// temp_rightsend[count * danum + 13] = (*M).lattice3d[i].fcol[14];
					// temp_rightsend[count * danum + 14] = (*M).lattice3d[i].fcol[15];
					// temp_rightsend[count * danum + 15] = (*M).lattice3d[i].fcol[16];
					// temp_rightsend[count * danum + 16] = (*M).lattice3d[i].fcol[17];
					// temp_rightsend[count * danum + 17] = (*M).lattice3d[i].fcol[18];
					count++;
				}
			}
			MPI_Send(temp_rightsend, danum * rightsend, MPI_DOUBLE, myid + 1, 123, MPI_COMM_WORLD);
		}
		if( myid != 0 )					//发送左端数据
		{
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 's' )
				{
					temp_leftsend[count * danum + 0] = (*M).lattice3d[i].fcol[2];
					temp_leftsend[count * danum + 1] = (*M).lattice3d[i].fcol[8];
					temp_leftsend[count * danum + 2] = (*M).lattice3d[i].fcol[10];
					temp_leftsend[count * danum + 3] = (*M).lattice3d[i].fcol[12];
					temp_leftsend[count * danum + 4] = (*M).lattice3d[i].fcol[14];
					
					// temp_leftsend[count * danum + 5] = (*M).lattice3d[i].fcol[1];
					// temp_leftsend[count * danum + 6] = (*M).lattice3d[i].fcol[3];
					// temp_leftsend[count * danum + 7] = (*M).lattice3d[i].fcol[4];
					// temp_leftsend[count * danum + 8] = (*M).lattice3d[i].fcol[5];
					// temp_leftsend[count * danum + 9] = (*M).lattice3d[i].fcol[6];
					// temp_leftsend[count * danum + 10] = (*M).lattice3d[i].fcol[7];
					// temp_leftsend[count * danum + 11] = (*M).lattice3d[i].fcol[9];
					// temp_leftsend[count * danum + 12] = (*M).lattice3d[i].fcol[11];
					// temp_leftsend[count * danum + 13] = (*M).lattice3d[i].fcol[13];
					// temp_leftsend[count * danum + 14] = (*M).lattice3d[i].fcol[15];
					// temp_leftsend[count * danum + 15] = (*M).lattice3d[i].fcol[16];
					// temp_leftsend[count * danum + 15] = (*M).lattice3d[i].fcol[17];
					// temp_leftsend[count * danum + 17] = (*M).lattice3d[i].fcol[18];
					count++;
				}
			}
			MPI_Send(temp_leftsend, danum * leftsend, MPI_DOUBLE, myid - 1, 123, MPI_COMM_WORLD);
		}
		
		if( myid != 0 )					//接收左端数据
		{
			MPI_Recv(temp_leftrecv, danum * leftrecv, MPI_DOUBLE, myid - 1, 123, MPI_COMM_WORLD, &status);
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 'r' )
				{
					(*M).lattice3d[i].fcol[1]  = temp_leftrecv[count * danum + 0];
					(*M).lattice3d[i].fcol[7]  = temp_leftrecv[count * danum + 1];
					(*M).lattice3d[i].fcol[9]  = temp_leftrecv[count * danum + 2];
					(*M).lattice3d[i].fcol[11] = temp_leftrecv[count * danum + 3];
					(*M).lattice3d[i].fcol[13] = temp_leftrecv[count * danum + 4];
					
					// (*M).lattice3d[i].fcol[2]  = temp_leftrecv[count * danum + 5];
					// (*M).lattice3d[i].fcol[3]  = temp_leftrecv[count * danum + 6];
					// (*M).lattice3d[i].fcol[4]  = temp_leftrecv[count * danum + 7];
					// (*M).lattice3d[i].fcol[5] = temp_leftrecv[count * danum + 8];
					// (*M).lattice3d[i].fcol[6] = temp_leftrecv[count * danum + 9];
					// (*M).lattice3d[i].fcol[8]  = temp_leftrecv[count * danum + 10];
					// (*M).lattice3d[i].fcol[10]  = temp_leftrecv[count * danum + 11];
					// (*M).lattice3d[i].fcol[12]  = temp_leftrecv[count * danum + 12];
					// (*M).lattice3d[i].fcol[14] = temp_leftrecv[count * danum + 13];
					// (*M).lattice3d[i].fcol[15] = temp_leftrecv[count * danum + 14];
					// (*M).lattice3d[i].fcol[16]  = temp_leftrecv[count * danum + 15];
					// (*M).lattice3d[i].fcol[17]  = temp_leftrecv[count * danum + 16];
					// (*M).lattice3d[i].fcol[18]  = temp_leftrecv[count * danum + 17];
					count++;
				}
			}
		}
		if( myid != numprocs - 1 )		//接收右端数据
		{
			MPI_Recv(temp_rightrecv, danum * rightrecv, MPI_DOUBLE, myid + 1, 123, MPI_COMM_WORLD, &status);
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 'j' )
				{
					(*M).lattice3d[i].fcol[2]  = temp_rightrecv[count * danum + 0];
					(*M).lattice3d[i].fcol[8]  = temp_rightrecv[count * danum + 1];
					(*M).lattice3d[i].fcol[10] = temp_rightrecv[count * danum + 2];
					(*M).lattice3d[i].fcol[12] = temp_rightrecv[count * danum + 3];
					(*M).lattice3d[i].fcol[14] = temp_rightrecv[count * danum + 4];
					
					// (*M).lattice3d[i].fcol[1]  = temp_rightrecv[count * danum + 5];
					// (*M).lattice3d[i].fcol[3]  = temp_rightrecv[count * danum + 6];
					// (*M).lattice3d[i].fcol[4] = temp_rightrecv[count * danum + 7];
					// (*M).lattice3d[i].fcol[5] = temp_rightrecv[count * danum + 8];
					// (*M).lattice3d[i].fcol[6] = temp_rightrecv[count * danum + 9];
					// (*M).lattice3d[i].fcol[7]  = temp_rightrecv[count * danum + 10];
					// (*M).lattice3d[i].fcol[9]  = temp_rightrecv[count * danum + 11];
					// (*M).lattice3d[i].fcol[11] = temp_rightrecv[count * danum + 12];
					// (*M).lattice3d[i].fcol[13] = temp_rightrecv[count * danum + 13];
					// (*M).lattice3d[i].fcol[15] = temp_rightrecv[count * danum + 14];
					// (*M).lattice3d[i].fcol[16]  = temp_rightrecv[count * danum + 15];
					// (*M).lattice3d[i].fcol[17]  = temp_rightrecv[count * danum + 16];
					// (*M).lattice3d[i].fcol[18] = temp_rightrecv[count * danum + 17];
					
					count++;
				}
			}
		}
	}
	if( myid % 2 == 1 )		//奇数进程先接收后发送
	{
		if( myid != 0 )					//接收左端数据
		{
			MPI_Recv(temp_leftrecv, danum * leftrecv, MPI_DOUBLE, myid - 1, 123, MPI_COMM_WORLD, &status);
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 'r' )
				{					
					(*M).lattice3d[i].fcol[1]  = temp_leftrecv[count * danum + 0];
					(*M).lattice3d[i].fcol[7]  = temp_leftrecv[count * danum + 1];
					(*M).lattice3d[i].fcol[9]  = temp_leftrecv[count * danum + 2];
					(*M).lattice3d[i].fcol[11] = temp_leftrecv[count * danum + 3];
					(*M).lattice3d[i].fcol[13] = temp_leftrecv[count * danum + 4];
					
					// (*M).lattice3d[i].fcol[2]  = temp_leftrecv[count * danum + 5];
					// (*M).lattice3d[i].fcol[3]  = temp_leftrecv[count * danum + 6];
					// (*M).lattice3d[i].fcol[4]  = temp_leftrecv[count * danum + 7];
					// (*M).lattice3d[i].fcol[5] = temp_leftrecv[count * danum + 8];
					// (*M).lattice3d[i].fcol[6] = temp_leftrecv[count * danum + 9];
					// (*M).lattice3d[i].fcol[8]  = temp_leftrecv[count * danum + 10];
					// (*M).lattice3d[i].fcol[10]  = temp_leftrecv[count * danum + 11];
					// (*M).lattice3d[i].fcol[12]  = temp_leftrecv[count * danum + 12];
					// (*M).lattice3d[i].fcol[14] = temp_leftrecv[count * danum + 13];
					// (*M).lattice3d[i].fcol[15] = temp_leftrecv[count * danum + 14];
					// (*M).lattice3d[i].fcol[16]  = temp_leftrecv[count * danum + 15];
					// (*M).lattice3d[i].fcol[17]  = temp_leftrecv[count * danum + 16];
					// (*M).lattice3d[i].fcol[18]  = temp_leftrecv[count * danum + 17];
					
					
					count++;
				}
			}
		}
		if( myid != numprocs - 1 )		//接收右端数据
		{
			MPI_Recv(temp_rightrecv, danum * rightrecv, MPI_DOUBLE, myid + 1, 123, MPI_COMM_WORLD, &status);
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 'j' )
				{					
					(*M).lattice3d[i].fcol[2]  = temp_rightrecv[count * danum + 0];
					(*M).lattice3d[i].fcol[8]  = temp_rightrecv[count * danum + 1];
					(*M).lattice3d[i].fcol[10] = temp_rightrecv[count * danum + 2];
					(*M).lattice3d[i].fcol[12] = temp_rightrecv[count * danum + 3];
					(*M).lattice3d[i].fcol[14] = temp_rightrecv[count * danum + 4];
					
					// (*M).lattice3d[i].fcol[1]  = temp_rightrecv[count * danum + 5];
					// (*M).lattice3d[i].fcol[3]  = temp_rightrecv[count * danum + 6];
					// (*M).lattice3d[i].fcol[4] = temp_rightrecv[count * danum + 7];
					// (*M).lattice3d[i].fcol[5] = temp_rightrecv[count * danum + 8];
					// (*M).lattice3d[i].fcol[6] = temp_rightrecv[count * danum + 9];
					// (*M).lattice3d[i].fcol[7]  = temp_rightrecv[count * danum + 10];
					// (*M).lattice3d[i].fcol[9]  = temp_rightrecv[count * danum + 11];
					// (*M).lattice3d[i].fcol[11] = temp_rightrecv[count * danum + 12];
					// (*M).lattice3d[i].fcol[13] = temp_rightrecv[count * danum + 13];
					// (*M).lattice3d[i].fcol[15] = temp_rightrecv[count * danum + 14];
					// (*M).lattice3d[i].fcol[16]  = temp_rightrecv[count * danum + 15];
					// (*M).lattice3d[i].fcol[17]  = temp_rightrecv[count * danum + 16];
					// (*M).lattice3d[i].fcol[18] = temp_rightrecv[count * danum + 17];
					count++;
				}
			}
		}
		
		if( myid != numprocs - 1 )		//发送右端数据
		{
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 'f' )
				{					
					temp_rightsend[count * danum + 0] = (*M).lattice3d[i].fcol[1];
					temp_rightsend[count * danum + 1] = (*M).lattice3d[i].fcol[7];
					temp_rightsend[count * danum + 2] = (*M).lattice3d[i].fcol[9];
					temp_rightsend[count * danum + 3] = (*M).lattice3d[i].fcol[11];
					temp_rightsend[count * danum + 4] = (*M).lattice3d[i].fcol[13];
					
					// temp_rightsend[count * danum + 5] = (*M).lattice3d[i].fcol[2];
					// temp_rightsend[count * danum + 6] = (*M).lattice3d[i].fcol[3];
					// temp_rightsend[count * danum + 7] = (*M).lattice3d[i].fcol[4];
					// temp_rightsend[count * danum + 8] = (*M).lattice3d[i].fcol[5];
					// temp_rightsend[count * danum + 9] = (*M).lattice3d[i].fcol[6];
					// temp_rightsend[count * danum + 10] = (*M).lattice3d[i].fcol[8];
					// temp_rightsend[count * danum + 11] = (*M).lattice3d[i].fcol[10];
					// temp_rightsend[count * danum + 12] = (*M).lattice3d[i].fcol[12];
					// temp_rightsend[count * danum + 13] = (*M).lattice3d[i].fcol[14];
					// temp_rightsend[count * danum + 14] = (*M).lattice3d[i].fcol[15];
					// temp_rightsend[count * danum + 15] = (*M).lattice3d[i].fcol[16];
					// temp_rightsend[count * danum + 16] = (*M).lattice3d[i].fcol[17];
					// temp_rightsend[count * danum + 17] = (*M).lattice3d[i].fcol[18];
					count++;
				}
			}
			MPI_Send(temp_rightsend, danum * rightsend, MPI_DOUBLE, myid + 1, 123, MPI_COMM_WORLD);
		}
		if( myid != 0 )					//发送左端数据
		{
			count = 0;
			for( i=0; i<num; i++ )
			{
				char mpisty = (*M).lattice3d[i].mpistyle;
				if( mpisty == 's' )
				{					
					temp_leftsend[count * danum + 0] = (*M).lattice3d[i].fcol[2];
					temp_leftsend[count * danum + 1] = (*M).lattice3d[i].fcol[8];
					temp_leftsend[count * danum + 2] = (*M).lattice3d[i].fcol[10];
					temp_leftsend[count * danum + 3] = (*M).lattice3d[i].fcol[12];
					temp_leftsend[count * danum + 4] = (*M).lattice3d[i].fcol[14];
					
					// temp_leftsend[count * danum + 5] = (*M).lattice3d[i].fcol[1];
					// temp_leftsend[count * danum + 6] = (*M).lattice3d[i].fcol[3];
					// temp_leftsend[count * danum + 7] = (*M).lattice3d[i].fcol[4];
					// temp_leftsend[count * danum + 8] = (*M).lattice3d[i].fcol[5];
					// temp_leftsend[count * danum + 9] = (*M).lattice3d[i].fcol[6];
					// temp_leftsend[count * danum + 10] = (*M).lattice3d[i].fcol[7];
					// temp_leftsend[count * danum + 11] = (*M).lattice3d[i].fcol[9];
					// temp_leftsend[count * danum + 12] = (*M).lattice3d[i].fcol[11];
					// temp_leftsend[count * danum + 13] = (*M).lattice3d[i].fcol[13];
					// temp_leftsend[count * danum + 14] = (*M).lattice3d[i].fcol[15];
					// temp_leftsend[count * danum + 15] = (*M).lattice3d[i].fcol[16];
					// temp_leftsend[count * danum + 15] = (*M).lattice3d[i].fcol[17];
					// temp_leftsend[count * danum + 17] = (*M).lattice3d[i].fcol[18];
					count++;
				}
			}
			MPI_Send(temp_leftsend, danum * leftsend, MPI_DOUBLE, myid - 1, 123, MPI_COMM_WORLD);
		}
	}

	if(temp_leftsend != 0) {free(temp_leftsend);temp_leftsend = NULL;};
	if(temp_leftrecv != 0) {free(temp_leftrecv);temp_leftrecv = NULL;};
	if(temp_rightsend != 0) {free(temp_rightsend);temp_rightsend = NULL;};
	if(temp_rightrecv != 0)	{free(temp_rightrecv);temp_rightrecv = NULL;};	
}

void InitialMpiStyle( Mesh* M[10], int N, int myid, int numprocs )
{
	// r 左 接收缓冲区									
	// m 左 发送与接收中间层
	// s 左 发送缓冲区
	// j 右 接收缓冲区
	// z 右 发送与接收中间层
	// f 右 发送缓冲区
	// o 其他
	// n 左侧多余点，不需计算
	int leftsend;						//左侧发送缓冲区格子数
	int leftrecv;						//左侧接收缓冲区格子数
	int rightsend;						//右侧发送缓冲区格子数
	int rightrecv;						//右侧接收缓冲区格子数
	
	int i,j,k;
	double eps = 1.e-10;	
	int num;
	double space = (*(M[0])).space;
	Point3d max = (*(M[0])).max;
	Point3d min = (*(M[0])).min;
	
	for( i=0; i<N; i++ )		//找到右侧
	{
		rightrecv = 0;
		rightsend = 0;
		num = (*(M[i])).length;
		for( j=0; j<num; j++ )
		{
			
			Point3d p = (*(M[i])).lattice3d[j].coordinate;
			double cha = space*(1.0/(pow(2.0,i+1)));
			double maxx = max.x - 0.5*space;
			double minx = max.x - 1.5*space;
			//if( fabs(maxx-cha-p.x) <= eps )
			if( p.x >minx && p.x<maxx )
			{
				(*(M[i])).lattice3d[j].mpistyle = 'j';
				rightrecv++;
			}
			maxx = max.x - 2.5*space;
			minx = max.x - 3.5*space;
			//if( fabs(maxx+cha-p.x) <= eps )
			if( p.x >minx && p.x<maxx )
			{
				(*(M[i])).lattice3d[j].mpistyle = 'f';
				rightsend++;
			}
		}
		(*(M[i])).rightrecv = rightrecv;
		(*(M[i])).rightsend = rightsend;
	}
	
	for( i=0; i<N; i++ )		//找到左侧
	{
		leftsend = 0;
		leftrecv = 0;
		num = (*(M[i])).length;
		for( j=0; j<num; j++ )
		{			
			Point3d p = (*(M[i])).lattice3d[j].coordinate;
			double cha = space*(1.0/(pow(2.0,i+1)));
			double maxx = min.x + 2.5*space;
			double minx = min.x + 1.5*space;
			//if( fabs(maxx-cha-p.x) <= eps )
			if( p.x >minx && p.x<maxx )
			{
				(*(M[i])).lattice3d[j].mpistyle = 's';
				leftsend++;
			}
			maxx = min.x + 0.5*space;
			minx = min.x - 0.5*space;
			//if( fabs(maxx+cha-p.x) <= eps )
			if( p.x >minx && p.x<maxx )
			{
				(*(M[i])).lattice3d[j].mpistyle = 'r';
				leftrecv++;
			}
		}
		(*(M[i])).leftsend = leftsend;
		(*(M[i])).leftrecv = leftrecv;
	}
	
	// for( i=0; i<N; i++ )		//找到左侧接收层左侧不需要计算的区域
	// {
		// num = (*(M[i])).length;
		// for( j=0; j<num; j++ )
		// {
		
			
			
				// Point3d p = (*(M[i])).lattice3d[j].coordinate;
				// double cha = min.x + 2.5*space;
				// if( p.x < cha )
				// {
					// if( (*(M[i])).lattice3d[j].mpistyle == 'o' )
					// {
						// (*(M[i])).lattice3d[j].mpistyle = 'n';
					// }
				// }
			
		// }
	// }
}
	
void WriteMultiMeshLatticeOneLayerXYZ( Mesh* M[10], int N, double space, char name[50], double xyz, int flag )
{
	int i,j,k;
	int number = 0;
	FILE *fp;
	Point3d p, centerp,u;
	double plotxyz, rho;
	Point3d Direction[4];

	for( j=0; j<N; j++ )
	{
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( flag==1 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.x;
			}
			if( flag==2 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.y;
			}
			if( flag==3 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.z;
			}
			char mpisty = (*(M[j])).lattice3d[i].mpistyle;
			if( (*(M[j])).lattice3d[i].style != 's' && (*(M[j])).lattice3d[i].yesorno == 0 && fabs( plotxyz+((*(M[j])).level==0?0:1)*(*(M[j])).space/2.0 - xyz)<1e-15 && mpisty != 'n' && mpisty != 'r' && mpisty != 'z' && mpisty != 'j')
			{
				number++;
			}
		}
	}


	fp = fopen(name,"w");
	if ( fp == NULL )
	{
		printf("Open Out File is error!!!\n");
		abort();
	}

	fprintf( fp,"title=\"Mesh Show\"\n" );
	if( flag==1 )
	{
		fprintf( fp,"VARIABLES=\"y\", \"z\", \"ux\", \"uy\", \"uz\", \"p\"\n" );
	}
	if( flag==2 )
	{
		fprintf( fp,"VARIABLES=\"x\", \"z\", \"ux\", \"uy\", \"uz\", \"p\"\n" );
	}
	if( flag==3 )
	{
		fprintf( fp,"VARIABLES=\"x\", \"y\", \"ux\", \"uy\", \"uz\", \"p\"\n" );
	}
	fprintf( fp,"ZONE N =%d,E=%d,F= FEPOINT, ET = QUADRILATERAL\n", number*4, number);

	for( j=0; j<N; j++ )
	{
		space = space/2.0;
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( flag==1 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.x;
				//Point3d Directiontemp[4] =  {{0,1,1},{0,1,-1},{0,-1,-1},{0,-1,1}};
				Direction[0].x = 0;
				Direction[0].y = 1;
				Direction[0].z = 1;
				Direction[1].x = 0;
				Direction[1].y = 1;
				Direction[1].z = -1;
				Direction[2].x = 0;
				Direction[2].y = -1;
				Direction[2].z = -1;
				Direction[3].x = 0;
				Direction[3].y = -1;
				Direction[3].z = 1;
			}
			if( flag==2 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.y;
				//Point3d Directiontemp[4] =  {{1,0,1},{1,0,-1},{-1,0,-1},{-1,0,1}};
				Direction[0].x = 1;
				Direction[0].y = 0;
				Direction[0].z = 1;
				Direction[1].x = 1;
				Direction[1].y = 0;
				Direction[1].z = -1;
				Direction[2].x = -1;
				Direction[2].y = 0;
				Direction[2].z = -1;
				Direction[3].x = -1;
				Direction[3].y = 0;
				Direction[3].z = 1;
			}
			if( flag==3 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.z;
				//Point3d Directiontemp[4] =  {{1,1,0},{1,-1,0},{-1,-1,0},{-1,1,0}};
				Direction[0].x = 1;
				Direction[0].y = 1;
				Direction[0].z = 0;
				Direction[1].x = 1;
				Direction[1].y = -1;
				Direction[1].z = 0;
				Direction[2].x = -1;
				Direction[2].y = -1;
				Direction[2].z = 0;
				Direction[3].x = -1;
				Direction[3].y = 1;
				Direction[3].z = 0;
			}
			char mpisty = (*(M[j])).lattice3d[i].mpistyle;
			if( (*(M[j])).lattice3d[i].style != 's' && (*(M[j])).lattice3d[i].yesorno == 0 && fabs( plotxyz+((*(M[j])).level==0?0:1)*(*(M[j])).space/2.0 - xyz)<1e-15 && mpisty != 'n' && mpisty != 'r' && mpisty != 'z' && mpisty != 'j')
			{
				centerp = (*(M[j])).lattice3d[i].coordinate;
				u = (*(M[j])).lattice3d[i].u;
				rho = (*(M[j])).lattice3d[i].rho;
				for ( k=0; k<4; k++)
				{
					p.x = centerp.x + space * Direction[k].x;
					p.y = centerp.y + space * Direction[k].y;
					p.z = centerp.z + space * Direction[k].z;
					if( flag==1 )
					{
						fprintf(fp,"%f %f %f %f %f %f\n",p.y, p.z, u.x, u.y, u.z, rho/3.0);
					}
					if( flag==2 )
					{
						fprintf(fp,"%f %f %f %f %f %f\n",p.x, p.z, u.x, u.y, u.z, rho/3.0);
					}
					if( flag==3 )
					{
						fprintf(fp,"%f %f %f %f %f %f\n",p.x, p.y, u.x, u.y, u.z, rho/3.0);
					}
				}
			}
		}
	}

	for( i=0; i<number; i++)
    {
		for ( k=1; k<=4; k++)
        {
			fprintf(fp,"%d ",4*i+k);
		}
		fprintf(fp,"\n");
	}

	fclose(fp);
}

void WriteMultiMeshLatticeBforCP( Mesh* M[10], int N, double space, char name[50], double xyz, int flag )
{
	int i,j,k;
	int number = 0;
	FILE *fp;
	Point3d p, centerp,u;
	double plotxyz, rho;

	for( j=0; j<N; j++ )
	{
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( flag==1 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.x;
			}
			if( flag==2 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.y;
			}
			if( flag==3 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.z;
			}
			char mpisty = (*(M[j])).lattice3d[i].mpistyle;
			if( (*(M[j])).lattice3d[i].style == 'b' && (*(M[j])).lattice3d[i].yesorno == 0 && fabs( plotxyz+((*(M[j])).level==0?0:1)*(*(M[j])).space/2.0 - xyz)<1e-15 && mpisty != 'n' && mpisty != 'r' && mpisty != 'z' && mpisty != 'j')
			{
				number++;
			}
		}
	}


	fp = fopen(name,"w");
	if ( fp == NULL )
	{
		printf("Open Out File is error!!!\n");
		abort();
	}
	
	fprintf( fp,"%d\n", number );
	
	for( j=0; j<N; j++ )
	{
		space = space/2.0;
		for( i=0; i<(*(M[j])).length; i++ )
		{
			if( flag==1 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.x;
			}
			if( flag==2 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.y;
			}
			if( flag==3 )
			{
				plotxyz = (*(M[j])).lattice3d[i].coordinate.z;
			}
			char mpisty = (*(M[j])).lattice3d[i].mpistyle;
			if( (*(M[j])).lattice3d[i].style == 'b' && (*(M[j])).lattice3d[i].yesorno == 0 && fabs( plotxyz+((*(M[j])).level==0?0:1)*(*(M[j])).space/2.0 - xyz)<1e-15 && mpisty != 'n' && mpisty != 'r' && mpisty != 'z' && mpisty != 'j')
			{
				centerp = (*(M[j])).lattice3d[i].coordinate;
				rho = (*(M[j])).lattice3d[i].rho;
			
				if( flag==1 )
				{
					fprintf(fp,"%f %f %f\n",centerp.y, centerp.z, rho/3.0);
				}
				if( flag==2 )
				{
					fprintf(fp,"%f %f %f\n",centerp.x, centerp.z, rho/3.0);
				}
				if( flag==3 )
				{
					fprintf(fp,"%f %f %f\n",centerp.x, centerp.y, rho/3.0);
				}				
			}
		}
	}

	fclose(fp);
}

void SetInterLevel( Mesh* M1, Mesh* M2, int layer )
{
	int i,j,k;
	int num;
	double space = (*M1).space;
	(*M2).level = (*M1).level + 1;
	(*M2).space = space/2.0;
	(*M2).length = 0;
	
	if( layer == 1 )
	{
		SetInterOneLevel( M1, M2 );
	}
	else
	{
		SetInterOneLevel( M1, M2 );
		
		for( i=0; i<layer-2; i++ )
		{
			num = (*M1).length;
			int flag[num];
			for( j=0; j<num; j++ )
			{
				if( (*M1).lattice3d[j].yesorno == 1 )
				{
					flag[j] = 1;	//0未加密，1加密
				}
				else
				{
					flag[j] = 0;
				}
			}
			
			for( j=0; j<num; j++ )
			{
				if( flag[j] == 1 )
				{
					for( k=0; k<18; k++ )
					{
						int neigh_id = (*M1).lattice3d[j].neighbour[k];
						if( neigh_id != -1 )
						{
							int yesorno = (*M1).lattice3d[neigh_id].yesorno;
							char sty = (*M1).lattice3d[neigh_id].style;
							if( yesorno == 0 && sty != 's' )
							{
								SetSecondlevelMesh( M1, M2, neigh_id );
							}
						}
					}
				}
			}
		}
	}	
	
	SearchNeighbourInformation( M1, M2 );
}

void SetInterOneLevel( Mesh* M1, Mesh* M2 )
{
	int i,k;
	int num = (*M1).length;
	double space = (*M1).space;
	
	for( i=0; i<num; i++ )
	{
		char sty = (*M1).lattice3d[i].style;
		if( sty == 'b' )
		{
			SetSecondlevelMesh( M1, M2, i );
			
			for( k=0; k<18; k++ )
			{
				int neigh_id = (*M1).lattice3d[i].neighbour[k];
				int yesorno = (*M1).lattice3d[neigh_id].yesorno;
				if( neigh_id != -1 && yesorno == 0 )	//0未加密，1加密
				{
					SetSecondlevelMesh( M1, M2, neigh_id );
				}
			}
		}
	}	
}

void MultipleMeshCollisionStreamLBGKD3Q19( Mesh* M[10], int N, int myid, int numprocs )
{
	int i,j;
	int level = N-1;
	if( N == 1 )
	{
		printf("Single Mesh is not my work! That Function is Unfinished!\n");
		abort();
	}
	else
	{
		for ( i=1; i<=(int)pow(2.0,level); i++)
		{
			
			MPI_Barrier(MPI_COMM_WORLD);
			ComputeMultipleMeshCollisionLBGKD3Q19( M[level], level );	// 碰撞过程
			MPI_Barrier(MPI_COMM_WORLD);
			MultiMeshDataTransfer( M[level], myid, numprocs );			// 进程数据传输
			MPI_Barrier(MPI_COMM_WORLD);
			ComputeMultipleMeshMoveLBGKD3Q19( M[level], level );		// 宏观量和feq的计算。
			MPI_Barrier(MPI_COMM_WORLD);

			if (i%2 == 0)
			{
				int layer = DivideTwo(i);	//能被多少2整除
				for ( j=1; j<=layer; j++ )
				{

					MPI_Barrier(MPI_COMM_WORLD);
					ComputeMultipleMeshCollisionLBGKD3Q19( M[level-j], level-j );
					MPI_Barrier(MPI_COMM_WORLD);
					MultiMeshDataTransfer( M[level-j], myid, numprocs );
					MPI_Barrier(MPI_COMM_WORLD);
					ComputeMultipleMeshMoveLBGKD3Q19( M[level-j], level-j );
					MPI_Barrier(MPI_COMM_WORLD);
				}
				for ( j=1; j<=layer; j++ )
				{
					MPI_Barrier(MPI_COMM_WORLD);
					PassUpDataLBGKD3Q19( M[level-j], M[level-j+1], level-j );
					MPI_Barrier(MPI_COMM_WORLD);
					PassDownDataAllLBGKD3Q19( M[level-j], M[level-j+1], level-j );
					MPI_Barrier(MPI_COMM_WORLD);
				}
			}
		}
	}
}

int DivideTwo(int Number)
{
	int sum = 0;
	while (Number%2 == 0)
	{
		Number = Number/2;
		sum++;
	}
	return sum;
}


















































































































