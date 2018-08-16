//***********注意**************//
// 解决上一版本无法跑无攻角情况，
// 解决无攻角会多一点情况

#include "Surface.h"
#include <algorithm>
#include <math.h>

using namespace std;

bool JudgePointProjectionOutOfTri(Point p1,Triangle tri);
double S_of_tri(double a1,double a2,double a3,double b1,double b2,double b3);
//判断格点投影是否在三角形投影内部（这里先向x方向投影）
bool JudgePointProjectionOutOfTri_Y(Point p1,Triangle tri);
//X方向投影，判断点在三角形投影内部
bool JudgePointProjectionOutOfTri_X(Point p1,Triangle tri);
//Z方向投影，判断点在三角形投影内部
bool JudgePointProjectionOutOfTri_Z(Point p1,Triangle tri);
//判断格点在三角形内部或者外（三角形内部指：比三角形更靠近几何体内部）
bool JugdePointInTheTri(Point p1,Point tri_p,Point normal);
//根据物面三角形找出对应距离最近的格点,内部数据为格点坐标（x,y,z顺序)
void FindBoundaryPoint(double space,vector<string> PATH,vector<vector<double> > &result,Surface surf,Point global_min);
//求点与三角形各点距离平方之和
double PointTriDistance(Point p1,Triangle tri);
double PointTriDistance2(Point p1,Triangle tri);
//空间点进行顺序排序
bool comp(const vector<double> &p,const vector<double> &q);
//判断两点是否相同
bool pointequal(const vector<double> &p,const vector<double> &q);
//返回两点构成的包围盒的最小点,0表示最小点，1表示最大点
Point box_point_min(Point a,Point b,bool c);
//判断点是否在三角形内
bool IsPointOutTri(Point p,Triangle tri);
//利用所有边界点，判断点是否是几何体内部点，X作为展向
//判断依据：如果点p在以x为展向处于偶数点之间，则判断为内部点(理想偶数点，因为存在两个尖凑成的差偶数点)
//返回2：外部点，返回1：内部点，返回0：无法判断
int JudgePointInTheSur_X(double y,double z,double x1,double x2,vector<Point> result);
int JudgePointInTheSur_Z(double x,double y,double z1,double z2,vector<Point> result);

//从result结果到坐标对结果过度
void FromResultToCouple(vector<vector<double> > result,vector<vector<double> > &result_couple);
//从Couple结果到2坐标对结果过度,couple2坐标点格式，可以tec查看
//1 对于一条线超过6个点的点，取头和尾
void FromCoupleToCouple2(vector<vector<double> > &result_couple,vector<vector<double> > &result_couple2,double space);
//result_couple2输出文件
void Result_couple2OutputTofile(vector<vector<double> > result_couple2,int N[3]);
void Result_couple2OutputTofile2(vector<vector<double> > result_couple2);
void Result_coupleOutputTofile(vector<vector<double> > result_couple);
//Result结构输出文件
void ResultOutputTofile(vector<vector<double> > result);

//寻找xy平面的点
void Find_Output_XYplane_Point(vector<vector<double> > &result_couple2,vector<vector<double> > &XYplane,int N[3]);

//************************************主函数开始**************************************//
int main(int argc,char **argv)
{
	int N[3] = { 3000,1000,60};

	double space = 0.002f;
	vector<vector<double> > result;			//距离最小点的x,y,z方向坐标,以及对应三角形法向量x,y,z方向的正负
	vector<vector<double> > result_couple;	//存储坐标对，x,y,z0,f0,z1,f1,z2,f2.f为法向量
	vector<vector<double> > result_couple2;	//存储坐标对，x1,y1,z1,x2,y2,z2...
	vector<vector<double> > XYplane;		//XOY平面的点坐标
	Surface surf;
	Point global_min,global_max;

	//读入网格文件名称
	//string Path = "sphere.stl";	
	//string Path = "30p30n.stl";	
	//string Path = "c919.stl";
	//string Path = "30p30nAllOne.stl";
	//string Path = "mesh_nobound.stl";
	//string Path = "mesh.stl";
	string Path = "plane2.stl";
	vector<string> PATH;	      
	PATH.push_back(Path);

	surf.ReadStlFile(PATH,1,2);	
	

	//求物面最小点及最大点,最小点作为原点
	global_min = surf.GetSurfaceGeometryMinPoint(0);		//初始化物面包围盒最小点
	global_max = surf.GetSurfaceGeometryMinPoint(0);		//初始化物面包围盒最大点
	for(int i=1;i<surf.GetSurfaceGeometryNum();i++)
	{
		global_min = box_point_min(global_min,surf.GetSurfaceGeometryMinPoint(i),1);
		global_max = box_point_min(global_max,surf.GetSurfaceGeometryMinPoint(i),0);
	}

	global_min.x = int(global_min.x / space - 1) * space;		//更新原点坐标
	global_min.y = int(global_min.y / space - 1) * space;
	global_min.z = int(global_min.z / space - 1) * space;
	cout<<"dot.x,dot.y,dot.z is:"<<global_min.x<<" "<<global_min.y<<" "<<global_min.z<<endl;
	
	//result结果，x,y,z顺序存储**
	FindBoundaryPoint(space,PATH,result,surf,global_min);

	FromResultToCouple(result,result_couple);
	
	
	cout<<"calc the upper and lower boundary point couple.begin...."<<endl;
	FromCoupleToCouple2(result_couple,result_couple2,space);

//	cout<<"calc the XYplane_point and output to file..."<<endl;
	Find_Output_XYplane_Point(result_couple2,XYplane,N);

//	Result_coupleOutputTofile(result_couple);
//	Result_couple2OutputTofile2(result_couple2);			//一个x,z对应一个y
	Result_couple2OutputTofile(result_couple2,N);	//输出result_cople2结果，一个x,z对应一对y，没有表头
//	ResultOutputTofile(result);	
	
	return 0;
	
}
//************************************主函数结束**************************************//

//space:格子长度
void FindBoundaryPoint(double space,vector<string> PATH,vector<vector<double> > &result,Surface surf,Point global_min)
{
	int pnum = PATH.size();
	Triangle tri;
	Point min_tribox,max_tribox;
	double dir_symbol_x,dir_symbol_y,dir_symbol_z;		//存储格点对应三角形的法向量的正负
	vector<double> result_element;						//result中的一个元素
	
	for(int j=0;j<pnum;j++)
	{
		int tri_num = surf.GetSurfaceGeometryTriangleNum(j);
		cout<<"tri_num:\t"<<tri_num<<endl;
		for(int i=0;i<tri_num;i++)
		{
			tri = surf.GetSurfaceGeometryTriangle(j,i);		

			//三角形三个顶点及其法向量
			Point p1 = tri.GetTriangletri(0);
			Point p2 = tri.GetTriangletri(1);
			Point p3 = tri.GetTriangletri(2);
			Point normal = tri.GetTriangleNormal();

			if(normal.x > 1.e-10)			//若法向量x坐标大于0，则dir_symbol_x = 1;小于0：等于-1；等于0：等于0；
				dir_symbol_x = 1;
			else if(normal.x < -1.e-10)
				dir_symbol_x = -1;
			else
				dir_symbol_x = 0;

			if(normal.y > 1.e-10)			//若法向量x坐标大于0，则dir_symbol_x = 1;小于0：等于-1；等于0：等于0；
				dir_symbol_y = 1;
			else if(normal.y < -1.e-10)
				dir_symbol_y = -1;
			else
				dir_symbol_y = 0;

			if(normal.z > 1.e-10)			//若法向量x坐标大于0，则dir_symbol_x = 1;小于0：等于-1；等于0：等于0；
				dir_symbol_z = 1;
			else if(normal.z < -1.e-10)
				dir_symbol_z = -1;
			else
				dir_symbol_z = 0;


			//三角形包围盒由min_tribox和max_tribox两点确定
			//使用0.7是为了减少包围盒大小，防止上下边界越界
			min_tribox = box_point_min(p1,p2,1);
			min_tribox = box_point_min(min_tribox,p3,1);
			min_tribox.x -= space;
			min_tribox.y -= space;
			min_tribox.z -= space;
			
			max_tribox = box_point_min(p1,p2,0);
			max_tribox = box_point_min(max_tribox,p3,0);
			max_tribox.x += space;
			max_tribox.y += space;
			max_tribox.z += space;

			double dist_min;			//最小距离（距离是指格点latt与三角形tri各点距离平方之和）
			double dist_temp;
			Point latt;					//网格点
			double temp_y;

			//求出包围盒中所有格点与该三角形各点的距离平方最小的格点
			//**************根据投影面选择循环顺序*****************//
			for(int k=0;int(min_tribox.x /space ) *space + k*space<=max_tribox.x;k++)
				for(int t=0;int(min_tribox.z /space) *space + t*space<=max_tribox.z;t++)
					{
						dist_min = 50000.0;
						for(int s=0;int(min_tribox.y /space) *space + s*space<=max_tribox.y;s++)	
						{
							latt.x = int(min_tribox.x /space) *space + k*space;
							latt.y = int(min_tribox.y /space) *space + s*space;
							latt.z = int(min_tribox.z /space) *space + t*space;
						
							// 1 格点在三角形（几何体）内部，继续下个格点计算
							// 2 格点投影不在三角形内部，继续下个格点计算
							//if(JugdePointInTheTri(latt,p1,normal) || IsPointOutTri(latt,tri))
							// if(JugdePointInTheTri(latt,p1,normal) || JudgePointProjectionOutOfTri_Y(latt,tri))
							// 	continue;

							// dist_temp = PointTriDistance(latt,tri);				//格点latt与三角形tri各点距离平方之和
							// if(dist_min > dist_temp)
							// {
							// 	dist_min = dist_temp;
							// 	temp_y = latt.y;
							// }

						//******************method1.5****************************
							if(JugdePointInTheTri(latt,p1,normal))
								continue;
							
							if(dir_symbol_y != 0)
							{
								if(JudgePointProjectionOutOfTri_Y(latt,tri))
									continue;
							}
							else if(dir_symbol_x != 0 && dir_symbol_z != 0)
							{
								if(JudgePointProjectionOutOfTri(latt,tri) || PointTriDistance2(latt,tri) > space)
									continue;
							}
							else
							{
								if(dir_symbol_z == 0)
									if(JudgePointProjectionOutOfTri_X(latt,tri))
										continue;
								if(dir_symbol_x == 0)
									if(JudgePointProjectionOutOfTri_Z(latt,tri))
										continue;
							}
							
							dist_temp = PointTriDistance2(latt,tri);
							if(dist_min > dist_temp)
							{
								dist_min = dist_temp;
							 	temp_y = latt.y;
							}
						}


							
						//*********************method2***************************
						// 	if(JugdePointInTheTri(latt,p1,normal))
						// 		continue;

						// 	//利用垂直距离找取所有边界点
						// 	//首先处理三角形法向量y轴坐标为0的情况
						// 	if(dir_symbol_y == 0)
						// 	{
						// 		if(dir_symbol_x != 0 && dir_symbol_z == 0 && (!JudgePointProjectionOutOfTri_X(latt,tri)) && dir_symbol_x * (latt.x - p1.x) < space)
						// 		{
						// 			latt.x = (latt.x - global_min.x) / space;	//转换坐标部分
						// 			latt.z = (latt.z - global_min.z) / space;
						// 			latt.y = (latt.y - global_min.y) / space;

						// 			result_element.push_back(latt.x);
						// 			result_element.push_back(dir_symbol_x);
						// 			result_element.push_back(latt.y);
						// 			result_element.push_back(dir_symbol_y);
						// 			result_element.push_back(latt.z);
						// 			result_element.push_back(dir_symbol_z);	

						// 			result.push_back(result_element);
						// 			result_element.clear();			
						// 		}
						// 		else if(dir_symbol_x == 0 && dir_symbol_z != 0 && (!JudgePointProjectionOutOfTri_Z(latt,tri)) && dir_symbol_z * (latt.z - p1.z) < space)
						// 		{
						// 			latt.x = (latt.x - global_min.x) / space;	//转换坐标部分
						// 			latt.z = (latt.z - global_min.z) / space;
						// 			latt.y = (latt.y - global_min.y) / space;

						// 			result_element.push_back(latt.x);
						// 			result_element.push_back(dir_symbol_x);
						// 			result_element.push_back(latt.y);
						// 			result_element.push_back(dir_symbol_y);
						// 			result_element.push_back(latt.z);
						// 			result_element.push_back(dir_symbol_z);	

						// 			result.push_back(result_element);
						// 			result_element.clear();
						// 		}
						// 		else if(dir_symbol_x != 0 && dir_symbol_z != 0)		//可能多点了，少了判定投影部分
						// 		{
						// 			double dis_p_tri;		//格点到其对应三角形的距离
						// 			double dot = (latt.x - p1.x)*normal.x + (latt.y - p1.y)*normal.y + (latt.z - p1.z)*normal.z;
						// 			dis_p_tri = dot / (sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z));

						// 			if(fabs(dis_p_tri) < 1.4142136*space)			//距离斜面小于根号2倍的space
						// 			{
						// 				latt.x = (latt.x - global_min.x) / space;	//转换坐标部分
						// 				latt.z = (latt.z - global_min.z) / space;
						// 				latt.y = (latt.y - global_min.y) / space;

						// 				result_element.push_back(latt.x);
						// 				result_element.push_back(dir_symbol_x);
						// 				result_element.push_back(latt.y);
						// 				result_element.push_back(dir_symbol_y);
						// 				result_element.push_back(latt.z);
						// 				result_element.push_back(dir_symbol_z);	

						// 				result.push_back(result_element);
						// 				result_element.clear();
						// 			}
						// 		}
						// 		continue;
						// 	}
						// 	//网格点投影不在三角形投影内
						// 	if(JudgePointProjectionOutOfTri_Y(latt,tri))
						// 		continue;

						// 	if(dir_symbol_y > 0 &&  dist_min > latt.y)			//有错误。。。
						// 		dist_min = latt.y;
						// 	else if(dir_symbol_y < 0 && dist_min < latt.y)
						// 		dist_min = latt.y;
						// }
						
						if(fabs(dist_min) < 40000.0)
						{
							latt.x = (latt.x - global_min.x) / space;	//转换坐标部分
							latt.z = (latt.z - global_min.z) / space;
							//latt.y = (dist_min - global_min.y) / space;
							latt.y = (temp_y - global_min.y) / space;	//垂直距离不用该句*********************

							result_element.push_back(latt.x);
							result_element.push_back(dir_symbol_x);
							result_element.push_back(latt.y);
							result_element.push_back(dir_symbol_y);
							result_element.push_back(latt.z);
							result_element.push_back(dir_symbol_z);	

							result.push_back(result_element);
							result_element.clear();				
						}
					}
		}
	}
	
	sort(result.begin(),result.end(),comp);		
	result.erase(unique(result.begin(), result.end(),pointequal), result.end());
}


//返回两点构成的包围盒的最小点,c=1表示最小点，c=0表示最大点
Point box_point_min(Point a,Point b,bool c)
{
	Point point;
	if(c)				//包围盒最小点
	{
		point.x = (a.x < b.x?a.x:b.x);
		point.y = (a.y < b.y?a.y:b.y);
		point.z = (a.z < b.z?a.z:b.z);
	}
	else if(!c)			//包围盒最大点
	{
		point.x = (a.x > b.x?a.x:b.x);
		point.y = (a.y > b.y?a.y:b.y);
		point.z = (a.z > b.z?a.z:b.z);
	}
	return point;
}

//求点与三角形各点距离平方之和
double PointTriDistance(Point p1,Triangle tri)
{
	Point a = tri.GetTriangletri(0);
	Point b = tri.GetTriangletri(1);
	Point c = tri.GetTriangletri(2);
	double dist1 = (p1.x-a.x)*(p1.x-a.x)+(p1.y-a.y)*(p1.y-a.y)+(p1.z-a.z)*(p1.z-a.z);
	double dist2 = (p1.x-b.x)*(p1.x-b.x)+(p1.y-b.y)*(p1.y-b.y)+(p1.z-b.z)*(p1.z-b.z);
	double dist3 = (p1.x-c.x)*(p1.x-c.x)+(p1.y-c.y)*(p1.y-c.y)+(p1.z-c.z)*(p1.z-c.z);
	return (sqrt(dist1)+sqrt(dist2)+sqrt(dist3));
}
double PointTriDistance2(Point p1,Triangle tri)
{
	Point a = tri.GetTriangletri(0);
	Point normal = tri.GetTriangleNormal();

	Point vec;
	vec.x = p1.x - a.x;
	vec.y = p1.y - a.y;
	vec.z = p1.z - a.z;

	double dot = vec.x * normal.x + vec.y * normal.y + vec.z * normal.z;
	double distance = dot / (sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z));
	return distance;
}

//判断格点投影是否在三角形投影内部（这里先用x方向投影)
//判断逻辑：格点在三角形内部，格点分别与所有三角形顶点能 构成的3个三角形面积等于三角形面积
bool JudgePointProjectionOutOfTri_Y(Point p1,Triangle tri)
{
	double s_p1ab,s_p1ac,s_p1bc,s_tri;			//s_p1ab表示三角形p1ab的面积
	Point a = tri.GetTriangletri(0);
	Point b = tri.GetTriangletri(1);
	Point c = tri.GetTriangletri(2);

	double vec_p1a_x = a.x - p1.x;				//表示向量p1a的y坐标
	double vec_p1a_z = a.z - p1.z;
	double vec_p1b_x = b.x - p1.x;
	double vec_p1b_z = b.z - p1.z;
	double vec_p1c_x = c.x - p1.x;
	double vec_p1c_z = c.z - p1.z;

	double vec_ab_x = b.x - a.x;
	double vec_ab_z = b.z - a.z;
	double vec_ac_x = c.x - a.x;
	double vec_ac_z = c.z - a.z;

	s_p1ab = fabs(vec_p1a_x * vec_p1b_z - vec_p1b_x * vec_p1a_z);
	s_p1ac = fabs(vec_p1a_x * vec_p1c_z - vec_p1c_x * vec_p1a_z);
	s_p1bc = fabs(vec_p1b_x * vec_p1c_z - vec_p1c_x * vec_p1b_z);
	s_tri = fabs(vec_ab_x * vec_ac_z - vec_ac_x * vec_ab_z);

	return (fabs(s_p1bc + s_p1ac + s_p1ab - s_tri) > 1.e-10);
}

//X方向投影，判断点在三角形投影内部
bool JudgePointProjectionOutOfTri_X(Point p1,Triangle tri)
{
	double s_p1ab,s_p1ac,s_p1bc,s_tri;			//s_p1ab表示三角形p1ab的面积
	Point a = tri.GetTriangletri(0);
	Point b = tri.GetTriangletri(1);
	Point c = tri.GetTriangletri(2);

	double vec_p1a_y = a.y - p1.y;				//表示向量p1a的y坐标
	double vec_p1a_z = a.z - p1.z;
	double vec_p1b_y = b.y - p1.y;
	double vec_p1b_z = b.z - p1.z;
	double vec_p1c_y = c.y - p1.y;
	double vec_p1c_z = c.z - p1.z;

	double vec_ab_y = b.y - a.y;
	double vec_ab_z = b.z - a.z;
	double vec_ac_y = c.y - a.y;
	double vec_ac_z = c.z - a.z;

	s_p1ab = fabs(vec_p1a_y * vec_p1b_z - vec_p1b_y * vec_p1a_z);
	s_p1ac = fabs(vec_p1a_y * vec_p1c_z - vec_p1c_y * vec_p1a_z);
	s_p1bc = fabs(vec_p1b_y * vec_p1c_z - vec_p1c_y * vec_p1b_z);
	s_tri = fabs(vec_ab_y * vec_ac_z - vec_ac_y * vec_ab_z);

	return (fabs(s_p1bc + s_p1ac + s_p1ab - s_tri) > 1.e-10);
}

//Z方向投影，判断点在三角形投影内部
bool JudgePointProjectionOutOfTri_Z(Point p1,Triangle tri)
{
	double s_p1ab,s_p1ac,s_p1bc,s_tri;			//s_p1ab表示三角形p1ab的面积
	Point a = tri.GetTriangletri(0);
	Point b = tri.GetTriangletri(1);
	Point c = tri.GetTriangletri(2);

	double vec_p1a_x = a.x - p1.x;				//表示向量p1a的y坐标
	double vec_p1a_y = a.y - p1.y;
	double vec_p1b_x = b.x - p1.x;
	double vec_p1b_y = b.y - p1.y;
	double vec_p1c_x = c.x - p1.x;
	double vec_p1c_y = c.y - p1.y;

	double vec_ab_x = b.x - a.x;
	double vec_ab_y = b.y - a.y;
	double vec_ac_x = c.x - a.x;
	double vec_ac_y = c.y - a.y;

	s_p1ab = fabs(vec_p1a_x * vec_p1b_y - vec_p1b_x * vec_p1a_y);
	s_p1ac = fabs(vec_p1a_x * vec_p1c_y - vec_p1c_x * vec_p1a_y);
	s_p1bc = fabs(vec_p1b_x * vec_p1c_y - vec_p1c_x * vec_p1b_y);
	s_tri = fabs(vec_ab_x * vec_ac_y - vec_ac_x * vec_ab_y);

	return (fabs(s_p1bc + s_p1ac + s_p1ab - s_tri) > 1.e-10);
}


bool JudgePointProjectionOutOfTri(Point p1,Triangle tri)
{
	double s_p2ab,s_p2ac,s_p2bc,s_tri;
	Point p2;										//p2为p1在三角形tri平面的投影
	Point a = tri.GetTriangletri(0);				//abc为三角形三个顶点
	Point b = tri.GetTriangletri(1);
	Point c = tri.GetTriangletri(2);							
	Point normal = tri.GetTriangleNormal();

	double len_normal = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);

	double dis_p_tri = PointTriDistance2(p1,tri);	//p1到三角形tri所在平面的垂直距离

	p2.x = p1.x - normal.x / len_normal * dis_p_tri;
	p2.y = p1.y - normal.y / len_normal * dis_p_tri;
	p2.z = p1.z - normal.z / len_normal * dis_p_tri;

	double vec_p2a_x = a.x - p2.x;				//由p2和三角形两个顶点组成的三角形边。表示向量p2a的x坐标
	double vec_p2a_y = a.y - p2.y;
	double vec_p2a_z = a.z - p2.z;
	double vec_p2b_x = b.x - p2.x;
	double vec_p2b_y = b.y - p2.y;
	double vec_p2b_z = b.z - p2.z;
	double vec_p2c_x = c.x - p2.x;
	double vec_p2c_y = c.y - p2.y;
	double vec_p2c_z = c.z - p2.z;

	double vec_ab_x = b.x - a.x;				//三角形边ab,ac
	double vec_ab_y = b.y - a.y;
	double vec_ab_z = b.z - a.z;
	double vec_ac_x = c.x - a.x;
	double vec_ac_y = c.y - a.y;
	double vec_ac_z = c.z - a.z;

	
	s_p2ab = S_of_tri(vec_p2a_x,vec_p2a_y,vec_p2a_z,vec_p2b_x,vec_p2b_y,vec_p2b_z);
	s_p2ac = S_of_tri(vec_p2a_x,vec_p2a_y,vec_p2a_z,vec_p2c_x,vec_p2c_y,vec_p2c_z);
	s_p2bc = S_of_tri(vec_p2b_x,vec_p2b_y,vec_p2b_z,vec_p2c_x,vec_p2c_y,vec_p2c_z);
	s_tri  = S_of_tri(vec_ab_x,vec_ab_y,vec_ab_z,vec_ac_x,vec_ac_y,vec_ac_z);

	return (fabs(s_p2bc + s_p2ac + s_p2ab - s_tri) > 1.e-10);
}

//由两条边a,b的三个坐标求三角形面积
double S_of_tri(double a1,double a2,double a3,double b1,double b2,double b3)
{
	double cross_ab_i = a2*b3 - a3*b2;
	double cross_ab_j =  - (a1*b3 - a3*b1);
	double cross_ab_k = a1*b2 - a2*b1;
	return sqrt(cross_ab_i * cross_ab_i + cross_ab_j * cross_ab_j + cross_ab_k * cross_ab_k);
}

//判断格点在三角形内部或者外（三角形内部指：比三角形更靠近几何体内部）
bool JugdePointInTheTri(Point p1,Point tri_p,Point normal)
{
	Point vec;				//三角形一顶点指向格点的向量
	vec.x = p1.x - tri_p.x;
	vec.y = p1.y - tri_p.y;
	vec.z = p1.z - tri_p.z;

	if(vec.x*normal.x + vec.y*normal.y + vec.z*normal.z >= 0)		//两向量点乘大于0，两向量同向，格点在三角形外部
		return false;
	else if(vec.x*normal.x + vec.y*normal.y + vec.z*normal.z < 0)
		return true;
/////////////////格点在三角形上怎么办？？？？？？？？？？？？？？？？？？？？？？？//暂时当作内部点处理
}

//空间点进行顺序排序,以Z方向作为向
//影响数据从result转换到couple
bool comp(const vector<double> &p,const vector<double> &q)
{
	if(p[0] < q[0])
		return true;
	else if(p[0] == q[0] && p[4] < q[4])
		return true;
	else if(p[0] == q[0] && p[4] == q[4] && p[2] < q[2])
		return true;
	else
		return false;
}

//判断两点是否相同
//1 针对两线的交点
bool pointequal(const vector<double> &p,const vector<double> &q)
{
	return ( (fabs(p[0]-q[0]) < 1.e-6) && (fabs(p[2]-q[2]) < 1.e-6) && (fabs(p[4]-q[4]) < 1.e-6) && (fabs(p[3]-q[3]) < 1.e-6));
}


//点p是否和a一边
bool IsPointOutTri(Point p,Triangle tri)
{
	Point a = tri.GetTriangletri(0);
	Point b = tri.GetTriangletri(1);
	Point c = tri.GetTriangletri(2);


	//点p是否和a一边
	double vec_bp_x = p.x - b.x;
	double vec_bp_z = p.z - b.z;
	double vec_bc_x = c.x - b.x;
	double vec_bc_z = c.z - b.z;
	double vec_ba_x = a.x - b.x;
	double vec_ba_z = a.z - b.z;

	double f1 = vec_bc_x * vec_ba_z - vec_bc_z * vec_ba_x;
	double f2 = vec_bc_x * vec_bp_z - vec_bc_z * vec_bp_x;

	//点p是否和b一边
	double vec_cp_x = p.x - c.x;
	double vec_cp_z = p.z - c.z;
	double vec_cb_x = b.x - c.x;
	double vec_cb_z = b.z - c.z;
	double vec_ca_x = a.x - c.x;
	double vec_ca_z = a.z - c.z;

	double f3 = vec_ca_x * vec_cb_z - vec_ca_z * vec_cb_x;
	double f4 = vec_ca_x * vec_cp_z - vec_ca_z * vec_cp_x;

	//点p是否和c一边
	double vec_ap_x = p.x - a.x;
	double vec_ap_z = p.z - a.z;
	double vec_ab_x = b.x - a.x;
	double vec_ab_z = b.z - a.z;
	double vec_ac_x = c.x - a.x;
	double vec_ac_z = c.z - a.z;

	double f6 = vec_ab_x * vec_ac_z - vec_ab_z * vec_ac_x;
	double f5 = vec_ab_x * vec_ap_z - vec_ab_z * vec_ap_x;

	return ((f1*f2 < 0) || (f3*f4 < 0) || (f5*f6 < 0));
}

//y方向投影，couple存储顺序X,Z,Y
void FromResultToCouple(vector<vector<double> > result,vector<vector<double> > &result_couple)
{
	int flag = 1;				
	vector<double> point_temp;			//xz坐标构成的点对
	
	for(int i=0;i<result.size()-1;i++)
	{
		if(flag)				//flag=1,说明x,z坐标第一次出现，作为坐标对存入result_couple
		{
			point_temp.push_back(result[i][0]);			//从y方向，不存储法向量x,z方向的正负值了
			point_temp.push_back(result[i][4]);
			flag = 0;
		}
		
//////////////////////////////////////////////////////////////////////////
	//！！！！！！判断相等时候，假定点排列依据是先比较X，然后Z,最后Y！！！！！！！！！！ //
		if(fabs(result[i][0] - result[i+1][0]) < 1.e-10 && fabs(result[i][4] - result[i+1][4]) < 1.e-10)
		{
			if(fabs(result[i][2] - result[i+1][2]) < 1.e-10 && (result[i][3] - result[i+1][3]) < 1.e-10)
			{
				cout<<"These point is repeated"<<"\t"<<endl;
				cout<<result[i][0]<<" "<<result[i][2]<<" "<<result[i][4]<<endl;
			}
			else
			{
				point_temp.push_back(result[i][2]);
				point_temp.push_back(result[i][3]);			//这里是y方向，所以用result[i][3]，即存储法向量y方向的值
			}
		}
		else
		{
			point_temp.push_back(result[i][2]);
			point_temp.push_back(result[i][3]);
			result_couple.push_back(point_temp);
			point_temp.clear();
			flag = 1;
		}
	}
	//处理容器最后一个点
	if(flag == 0)
	{
		point_temp.push_back(result[result.size()-1][2]);
		point_temp.push_back(result[result.size()-1][3]);
		result_couple.push_back(point_temp);
		point_temp.clear();
	}
	else
	{
		point_temp.push_back(result[result.size()-1][0]);
		point_temp.push_back(result[result.size()-1][4]);
		point_temp.push_back(result[result.size()-1][2]);
		point_temp.push_back(result[result.size()-1][3]);
		result_couple.push_back(point_temp);
		point_temp.clear();	
	}
	
}

//生成四对
void FromCoupleToCouple2(vector<vector<double> > &result_couple,vector<vector<double> > &result_couple2,double space)
{	
	vector<double> point_temp;
	for(vector<vector<double> > ::iterator it = result_couple.begin();it != result_couple.end();it++)
	{
		int len = (*it).size();		//len表示去掉向量方向数据的长度
		if(len < 4 || len % 2 == 1)
			cout<<"loss data of result point"<<endl;
		else if(len == 4)
		{
			point_temp.push_back((*it)[0]);
			point_temp.push_back((*it)[1]);
			point_temp.push_back((*it)[2]);
			point_temp.push_back((*it)[2]);
			result_couple2.push_back(point_temp);
			point_temp.clear();
		}
		else
		{
			for(int i = 2;i < len - 1; i += 2)				//从第一个y坐标开始计算
			{	
				if(i == (len - 2))							//只剩一个点，无法配对
				{
					point_temp.push_back((*it)[0]);			//x坐标
					point_temp.push_back((*it)[1]);			//z坐标
					point_temp.push_back((*it)[i]);
					point_temp.push_back((*it)[i]);
					result_couple2.push_back(point_temp);
					point_temp.clear();
					continue;
				}

				if((*it)[i+1] < 0.5 && (*it)[i+3] > 0.5 || (*it)[i+1] < -0.5 && (*it)[i+3] > -0.5)		
				{
					point_temp.push_back((*it)[0]);			//x坐标
					point_temp.push_back((*it)[1]);			//z坐标
					point_temp.push_back((*it)[i]);

					int k = i;
					//考虑到几何体内部也有面网格
					while(k+5 < len && (*it)[k+5] > - 0.5)
						k += 2;

					i = k;
					point_temp.push_back((*it)[i+2]);
					result_couple2.push_back(point_temp);
					point_temp.clear();
					i = i+2;
				}
				else
				{
					cout<<"he\t"<<endl;
					int j = i;
					point_temp.push_back((*it)[0]);			//x坐标
					point_temp.push_back((*it)[1]);			//z坐标
					point_temp.push_back((*it)[i]);
					while((*it)[j+2] - (*it)[j] < 3*space && (j+2) < len-1)
						j += 2;
					point_temp.push_back((*it)[j]);
					result_couple2.push_back(point_temp);
					point_temp.clear();
					if(j > i)
					{
						i = j - 2;
					}					
				}
			}			
		}

	}
}

void Result_couple2OutputTofile(vector<vector<double> > result_couple2,int N[3])
{

	 cout<<"output to the file x,y with boundary couple..."<<endl;
	 ostringstream name;
	 name << "final_point_couple"<<".dat";
	 ofstream out(name.str().c_str());
	 out<<N[0]<<endl<<N[1]<<endl<<N[2]<<endl;
	 out<<result_couple2.size()<<endl;

	 for(vector<vector<double> >::iterator it = result_couple2.begin();it!=result_couple2.end();it++)
		 out<<(*it)[0]<<"\t"<<(*it)[1]<<"\t"<<(*it)[2]<<"\t"<<(*it)[3]<<endl;
	
	 cout<<"result_couple.size is:\t"<<result_couple2.size()<<endl;
}

void Result_couple2OutputTofile2(vector<vector<double> > result_couple2)
{

	 cout<<"output to the file..."<<endl;
	 ostringstream name;
	 name << "final_point_couple22"<<".dat";
	 ofstream out(name.str().c_str());
	 out<<"Title = \"LBM Cylinder Flow\""<<endl;
	 out<<"VARIABLES = \"X\",\"Y\",\"Z\""<<endl;
	 out<<"Zone I = "<<2*result_couple2.size()<<",F = POINT"<<endl;

	 for(vector<vector<double> >::iterator it = result_couple2.begin();it!=result_couple2.end();it++)
	 {
		 out<<(*it)[0]<<"\t"<<(*it)[1]<<"\t"<<(*it)[2]<<endl;
		 out<<(*it)[0]<<"\t"<<(*it)[1]<<"\t"<<(*it)[3]<<endl;
	 }
	 cout<<"result_couple2.size is:\t"<<result_couple2.size()<<endl;
}

//输出result_couple
void Result_coupleOutputTofile(vector<vector<double> > result_couple)
{
	cout<<"result_couple output to the file..."<<endl;
	ostringstream name;
	name << "result_couple_point"<<".dat";
	ofstream out(name.str().c_str());

//	for(vector<Point>::iterator it = result.begin();it!=result.end();it++)
//		out<<.x<<"\t"<<(*it).z<<"\t"<<(*it).y<<endl;
	for(int i=0;i<result_couple.size();i++)
	{
		out<<result_couple[i][0]<<"\t"<<result_couple[i][1]<<"\t";
		for(int j=2;j<result_couple[i].size();j++)
			out<<result_couple[i][j]<<"\t";
		out<<endl;
	}
	
	cout<<"result_couple.size is:\t"<<result_couple.size()<<endl;
}	


//将result结果输出文件
void ResultOutputTofile(vector<vector<double> > result)
{
	cout<<"result output to the file..."<<endl;
	ostringstream name;
	name << "final_point"<<".dat";
	ofstream out(name.str().c_str());
	out<<"Title = \"LBM Cylinder Flow\""<<endl;
	out<<"VARIABLES = \"X\",\"Y\",\"Z\""<<endl;
	out<<"Zone I = "<<result.size()<<",F = POINT"<<endl;

//	for(vector<Point>::iterator it = result.begin();it!=result.end();it++)
//		out<<.x<<"\t"<<(*it).z<<"\t"<<(*it).y<<endl;
	for(int i=0;i<result.size();i++)
		out<<result[i][0]<<"\t"<<result[i][4]<<"\t"<<result[i][2]<<endl;
	
	cout<<"result.size is:\t"<<result.size()<<endl;
}


//找出xy平面的点，或者所有内部点
void Find_Output_XYplane_Point(vector<vector<double> > &result_couple2,vector<vector<double> > &XYplane,int N[3])
{
	////调整输出格式
	// int count = 0;
	// double z_temp = result_couple2[0][1];
	// for(vector<vector<double> > ::iterator it = result_couple2.begin();it!=result_couple2.end();it++)
	// {
	// 	if((*it)[1] == z_temp)
	// 		for(double i = (*it)[2];i <= (*it)[3];i++)
	// 			count++;
	// }

	cout<<"result output to the file xyplane.point..."<<endl;
	ostringstream name;
	name << "xyplane_point"<<".dat";
	ofstream out(name.str().c_str());
//	out<<N[0]<<endl;
//	out<<N[1]<<endl;
//	out<<N[2]<<endl;
//	out<<count<<endl;

	vector<double> xyplane_temp;
//	double z_temp = result_couple2[int(result_couple2.size() / 2)][1];				//取坐标对中间的z坐标作为输出平面的z
//	double z_temp = result_couple2[0][1];
	for(vector<vector<double> > ::iterator it = result_couple2.begin();it!=result_couple2.end();it++)
	{
//		if((*it)[1] == z_temp)
			for(double i = (*it)[2];i <= (*it)[3];i++)
			{
				out<<(*it)[0]<<"\t"<<i<<"\t"<<(*it)[1]<<endl;				//坐标输出顺序为x,z,y				
			}

	}
}


//利用所有边界点，判断点是否是几何体内部点，X作为展向
//判断依据：如果点p在以x为展向处于偶数点之间，则判断为内部点(理想偶数点，因为存在两个尖凑成的差偶数点)
//返回0：无法判断。  返回1：内部点。  返回2：外部点
int JudgePointInTheSur_X(double y,double z,double x1,double x2,vector<Point> result)
{
	vector<double> dir_x;
	Point p_temp = {x1+1,y,z};

	int flag_inter = 0;
	int flag_outer = 0;

	for(p_temp.x;p_temp.x< x2;p_temp.x++)
	{
		for(vector<Point> ::iterator it = result.begin();it!=result.end();it++)
		{
			if((*it).y == p_temp.y && (*it).z == p_temp.z)
				dir_x.push_back((*it).x);
		}
	
		//连续坐标中间不可能存在边界点，所以此循环只返回2个值
		//返回2：外部点，flag_outer++.返回1：内部点
		if(dir_x.size() % 2 == 0)
			for(vector<double> ::iterator it = dir_x.begin();it!=dir_x.end();it += 2)
			{
				if(p_temp.x > *it && p_temp.x < *(it+1))
					{
						flag_inter++;
						break;
					}
				else if(p_temp.x < *it && p_temp.x > *(it+1))
					{
						flag_outer++;
						break;
					}
			}

		dir_x.clear();		
	}

	if(flag_inter > flag_outer && flag_inter > 0)
		return 1;
	else if(flag_outer > flag_inter && flag_outer > 0)
		return 2;
	else 
		return 0;
}

int JudgePointInTheSur_Z(double x,double y,double z1,double z2,vector<Point> result)
{
	vector<double> dir_z;
	Point p_temp = {x,y,z1+1};
	
	int flag_inter = 0;
	int flag_outer = 0;

	for(p_temp.z;p_temp.z<z2;p_temp.z++)
	{
		for(vector<Point> ::iterator it = result.begin();it!=result.end();it++)
		{
			if((*it).x == p_temp.x && (*it).y == p_temp.y)
				dir_z.push_back((*it).z);
		}
	
		//连续坐标中间不可能存在边界点，所以此循环只返回2个值
		//返回2：外部点，flag_outer++.返回1：内部点
		if(dir_z.size() % 2 == 0)
			for(vector<double> ::iterator it = dir_z.begin();it!=dir_z.end();it += 2)
			{
				if(p_temp.z > *it && p_temp.z < *(it+1))
					{
						flag_inter++;
						break;
					}
				else if(p_temp.z < *it && p_temp.z > *(it+1))
					{
						flag_outer++;
						break;
					}
			}

		dir_z.clear();		
	}

	if(flag_inter > flag_outer && flag_inter > 0)
		return 1;
	else if(flag_outer > flag_inter && flag_outer > 0)
		return 2;
	else 
		return 0;
}