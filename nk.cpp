11
给定两个数a和b，如何不用比较运算符，返回较大的数。

12
给定一个数n，表示n层汉诺塔问题，请打印最优步数的所有过
程
进阶：给定一个汉诺塔的状况用数组arr表示（arr中只有1，2，
3三种数字），请返回这是汉诺塔最优步数的第几步？
举例：
arr = {3,2,1}
arr长度为3，表示这是一个3层汉诺塔问题；
arr[0] == 3表示上面的汉诺塔在右边；
arr[1] == 2表示中间的汉诺塔在中间；
arr[2] == 1表示底下的汉诺塔在左间；
这种状况是3层汉诺塔最优步数的第2步，所以返回2。

13
给定一棵二叉树的头节点head，和一个整数sum，二叉树每个节点上都
有数字，我们规定路径必须是从上往下的，求二叉树上累加和为sum的
最长路径长度。

14
给定一棵搜索二叉树的头节点head，树上没有重复的值。
这棵树有可能：因为某些节点错误的交换了位置，而不再是搜
索二叉树了。
要求：
1，如果树没问题，还是搜索二叉树，不调整。
2，如果只用交换两个节点，就能让树重新变成搜索二叉树，请
调整正确。
3，如果只交换两个节点，无法让树重新变成搜索二叉树，不调
整。
4，调整不能使用交换两个节点值的方式。

15
给定一棵二叉树的头节点head，判断这棵树是不是平衡二叉树

16
给定一棵二叉树的头节点head，请返回最大搜索二叉子树的大小。

17
二叉树的拓扑结构概念：任何经过left和right指针，连成一片的节点，都叫一
个拓扑结构。
给定一棵二叉树的头节点head，请返回满足二叉搜索树条件的最大拓扑结构
的大小。
注意：请注意区分拓扑结构和子树的区别。

18
二叉树节点间距离的概念：二叉树一个节点到另一个节点间最短线路上的节点
数量，叫做两个节点间的距离。
给定一棵二叉树的头节点head，请返回这棵二叉树上的最大距离。

19
给定一个字符串str，str表示一个公式，公式里可能有整数、加减乘除符号和
左右括号，返回公式的计算结果。
【举例】
str="48*((70-65)-43)+8*1"，返回-1816。
str="3+1*4"，返回7。
str="3+(1*4)"，返回7。
【说明】
1．可以认为给定的字符串一定是正确的公式，即不需要对str做公式有效性检
查。
2．如果是负数，就需要用括号括起来，比如"4*(-3)"。但如果负数作为公式的
开头或括号部分的开头，则可以没有括号，比如"-3*4"和"(-3*4)"都是合法的。
3．不用考虑计算过程中会发生溢出的情况。




21
设计可以变更的缓存结构
【题目】
设计一种缓存结构，该结构在构造时确定大小，假设大小为K，并有两个功能：
set(key,value)：将记录(key,value)插入该结构。
get(key)：返回key对应的value值。
【要求】
1．set和get方法的时间复杂度为O(1)。
2．某个key的set或get操作一旦发生，认为这个key的记录成了最经常使用的。
3．当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
【举例】
假设缓存结构的实例是cache，大小为3，并依次发生如下行为：
1．cache.set("A",1)。最经常使用的记录为("A",1)。
2．cache.set("B",2)。最经常使用的记录为("B",2)，("A",1)变为最不经常的。
3．cache.set("C",3)。最经常使用的记录为("C",2)，("A",1)还是最不经常的。
4．cache.get("A")。最经常使用的记录为("A",1)，("B",2)变为最不经常的。
5．cache.set("D",4)。大小超过了3，所以移除此时最不经常使用的记录("B",2)，加入记录
("D",4)，并且为最经常使用的记录，然后("C",2)变为最不经常使用的记录。

22
给定一个N行3列二维数组，每一行表示有一座大楼，一共有N座大楼。
所有大楼的底部都坐落在X轴上，每一行的三个值(a,b,c)代表每座大楼的从(a,0)点开始，到
(b,0)点结束，高度为c。
输入的数据可以保证a<b,且a，b，c均为正数。大楼之间可以有重合。
请输出整体的轮廓线。
例子：给定一个二维数组
[
  [1, 3, 3],
  [2, 4, 4],
  [5, 6, 1]
]
输出为轮廓线
[
  [1, 2, 3],
  [2, 4, 4],
  [5, 6, 1]
]

23
找到被指的新类型字符
【题目】
新类型字符的定义如下：
1．新类型字符是长度为1或者2的字符串。
2．表现形式可以仅是小写字母，例如，"e"；也可以是大写字母+小写
字母，例如，"Ab"；还可以是大写字母+大写字母，例如，"DC"。
现在给定一个字符串str，str一定是若干新类型字符正确组合的结果。
比如"eaCCBi"，由新类型字符"e"、"a"、"CC"和"Bi"拼成。再给定一
个整数k，代表str中的位置。请返回被k位置指中的新类型字符。
【举例】
str="aaABCDEcBCg"。
1．k=7时，返回"Ec"。
2．k=4时，返回"CD"。
3．k=10时，返回"g"。

24
字典树（前缀树）的实现
【题目】
字典树又称为前缀树或Trie树，是处理字符串常见的数据结构。
假设组成所有单词的字符仅是“a”~“z”，请实现字典树结构，
并包含以下四个主要功能。
void insert(String word)：添加word，可重复添加。
void delete(String word)：删除word，如果word添
加过多次，仅删除一个。
boolean search(String word)：查询word是否在字典
树中。
int prefixNumber(String pre)：返回以字符串pre为
前缀的单词数量。

25
给定一个整数数组arr，请返回子数组的最大异或值
要求：时间复杂度O(N)

26 & 27
数字的英文表达和中文表达
【题目】
给定一个32位整数num，写两个函数分别返回num的英文与中文表达字符串。
【举例】
num=319
英文表达字符串为：Three Hundred Nineteen
中文表达字符串为：三百一十九
num=1014
英文表达字符串为：One Thousand, Fourteen  
中文表达字符串为：一千零十四
num=-2147483648
英文表达字符串为：Negative, Two Billion, One Hundred Forty Seven Million, Four 
Hundred Eighty Three Thousand, Six Hundred Forty Eight 
中文表达字符串为：负二十一亿四千七百四十八万三千六百四十八
num=0
英文表达字符串为：Zero
中文表达字符串为：零



31
介绍一种时间复杂度O(N)，额外空间复杂度O(1)的二叉树的遍
历方式，N为二叉树的节点个数

32
Morris遍历
利用Morris遍历实现二叉树的先序，中序，后续遍历，时间复
杂度O(N)，额外空间复杂度O(1)。

33
在二叉树上，何为一个节点的后继节点？
何为搜索二叉树？
如何实现搜索二叉树的查找？插入？删除？

34
扩展：
1，如何实现在搜索二叉树上查找<=给定值aim最近的值
2，如何实现在搜索二叉树上查找>=给定值aim最近的值

35
何为具有平衡性的树？
介绍调整树的左旋操
介绍调整树的右旋操作

36
介绍AVL树
1，当插入或者删除一个节点时，可能会让整棵AVL不平衡。此时，只需要把
最小不平衡子树调整即可恢复整体的平衡性。
2，介绍树的LL，RR，LR，RL调整
3，介绍插入节点时的调整细节
4，介绍删除节点时的调整细节

37
何为红黑树？（了解的内容，但是附带了实现）

38
何为SB树？
每棵子树的大小，不小于其兄弟的子树大小(既每棵叔叔树的大小，不小于侄
子树的大小)陈启峰发明于2006年底完成的论文《Size  Balanced Tree》，
并在2007年的全国青少年信息学奥林匹克竞赛冬令营中发表。

39
何为跳表？




41
给定一个N行3列二维数组，每一行表示有一座大楼，一共有N座
大楼。 所有大楼的底部都坐落在X轴上，每一行的三个值
(a,b,c)代表每座大楼的从(a,0)点开始，到 (b,0)点结束，高
度为c。 输入的数据可以保证a<b,且a，b，c均为正数。大楼之
间可以有重合。 请输出整体的轮廓线。
例子：给定一个二维数组 [  [1, 3, 3],  [2, 4, 4],  [5, 6,
1] ]
输出为轮廓线 [  [1, 2, 3],  [2, 4, 4],  [5, 6, 1] ]

42
设计可以变更的缓存结构（LRU）
【题目】
设计一种缓存结构，该结构在构造时确定大小，假设大小为K，并有两个功能：
set(key,value)：将记录(key,value)插入该结构。
get(key)：返回key对应的value值。
【要求】
1．set和get方法的时间复杂度为O(1)。
2．某个key的set或get操作一旦发生，认为这个key的记录成了最经常使用的。
3．当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
【举例】
假设缓存结构的实例是cache，大小为3，并依次发生如下行为：
1．cache.set("A",1)。最经常使用的记录为("A",1)。
2．cache.set("B",2)。最经常使用的记录为("B",2)，("A",1)变为最不经常的。
3．cache.set("C",3)。最经常使用的记录为("C",2)，("A",1)还是最不经常的。
4．cache.get("A")。最经常使用的记录为("A",1)，("B",2)变为最不经常的。
5．cache.set("D",4)。大小超过了3，所以移除此时最不经常使用的记录("B",2)，
加入记录 ("D",4)，并且为最经常使用的记录，然后("C",2)变为最不经常使用的
记录

43
上一题实现了LRU缓存算法，LFU也是一个著名的缓存算法
自行了解之后实现LFU中的set 和 get
要求：两个方法的时间复杂度都为O(1)

44
给定一棵二叉树的头节点head，请返回最大搜索二叉子树的大小。

45
给定一个数组arr，和一个整数num，求在arr中，累加和等于num的最长
子数组的长度
例子：
arr = {7,3,2,1,1,7,7,7}   num = 7
其中有很多的子数组累加和等于7，但是最长的子数组是{3,2,1,1}，所
以返回其长度4

46
定义数组的异或和的概念：
数组中所有的数异或起来，得到的结果叫做数组的异或和，
比如数组{3,2,1}的异或和是，3^2^1 = 0
给定一个数组arr，你可以任意把arr分成很多不相容的子数组，你的目的是：
分出来的子数组中，异或和为0的子数组最多。
请返回：分出来的子数组中，异或和为0的子数组最多是多少？

47
给定一个字符串str，str表示一个公式，公式里可能有整数、加减乘除符号和
左右括号，返回公式的计算结果。
【举例】
str="48*((70-65)-43)+8*1"，返回-1816。
str="3+1*4"，返回7。 str="3+(1*4)"，返回7。
【说明】
1．可以认为给定的字符串一定是正确的公式，即不需要对str做公式有效性检
查。
2．如果是负数，就需要用括号括起来，比如"4*(-3)"。但如果负数作为公式的
开头或括号部分的开头，则可以没有括号，比如"-3*4"和"(-3*4)"都是合法的。
3．不用考虑计算过程中会发生溢出的情况




51
判断一棵二叉树是否是搜索二叉树
判断一棵二叉树是否是完全二叉树

52
判断一棵树是否是平衡二叉树

53
二叉树中，一个节点可以往上走和往下走，那么从节点A总能走到节点B。
节点A走到节点B的距离为：A走到B最短路径上的节点个数。
求一棵二叉树上的最远距离

54
一个公司的上下节关系是一棵多叉树，这个公司要举办晚会，你作为组织者已经摸清了大家的心理：一个员工的直
接上级如果到场，这个员工肯定不会来。每个员工都有一个活跃度的值，决定谁来你会给这个员工发邀请函，怎么
让舞会的气氛最活跃？返回最大的活跃值。
举例：
给定一个矩阵来表述这种关系
matrix = 
{
1,6
1,5
1,4
}
这个矩阵的含义是：
matrix[0] = {1 , 6}，表示0这个员工的直接上级为1,0这个员工自己的活跃度为6
matrix[1] = {1 , 5}，表示1这个员工的直接上级为1（他自己是这个公司的最大boss）,1这个员工自己的活跃度
为5
matrix[2] = {1 , 4}，表示2这个员工的直接上级为1,2这个员工自己的活跃度为4
为了让晚会活跃度最大，应该让1不来，0和2来。最后返回活跃度为10

55
给定一个数组，求子数组的最大异或和。
一个数组的异或和为，数组中所有的数异或起来的结果。

56
求一棵完全二叉树的节点个数，要求时间复杂度低于O(N)




61
换钱的方法数
【题目】
给定数组arr，arr中所有的值都为正数且不重复。每个值代表
一种面值的货币，每种面值的货币可以使用任意张，再给定一
个整数aim代表要找的钱数，求换钱有多少种方法。
【举例】
arr=[5,10,25,1]，aim=0。
组成0元的方法有1种，就是所有面值的货币都不用。所以返回1。
arr=[5,10,25,1]，aim=15。
组成15元的方法有6种，分别为3张5元、1张10元+1张5元、1张
10元+5张1元、10张1元+1张5元、2张5元+5张1元和15张1元。所
以返回6。
arr=[3,5]，aim=2。
任何方法都无法组成2元。所以返回0。

62
排成一条线的纸牌博弈问题
【题目】
给定一个整型数组arr，代表数值不同的纸牌排成一条线。玩家A和玩家B依次拿走
每张纸牌，规定玩家A先拿，玩家B后拿，但是每个玩家每次只能拿走最左或最右
的纸牌，玩家A和玩家B都绝顶聪明。请返回最后获胜者的分数。
【举例】
arr=[1,2,100,4]。
开始时玩家A只能拿走1或4。如果玩家A拿走1，则排列变为[2,100,4]，接下来玩
家B可以拿走2或4，然后继续轮到玩家A。如果开始时玩家A拿走4，则排列变为
[1,2,100]，接下来玩家B可以拿走1或100，然后继续轮到玩家A。玩家A作为绝顶
聪明的人不会先拿4，因为拿4之后，玩家B将拿走100。所以玩家A会先拿1，让排
列变为[2,100,4]，接下来玩家B不管怎么选，100都会被玩家A拿走。玩家A会获胜，
分数为101。所以返回101。
arr=[1,100,2]。
开始时玩家A不管拿1还是2，玩家B作为绝顶聪明的人，都会把100拿走。玩家B会
获胜，分数为100。所以返回100。

63
字符串匹配问题
【题目】
给定字符串str，其中绝对不含有字符'.'和'*'。再给定字符串exp，
其中可以含有'.'或'*'，'*'字符不能是exp的首字符，并且任意两个
'*'字符不相邻。exp中的'.'代表任何一个字符，exp中的'*'表示'*'
的前一个字符可以有0个或者多个。请写一个函数，判断str是否能被
exp匹配。
【举例】
str="abc"，exp="abc"，返回true。
str="abc"，exp="a.c"，exp中单个'.'可以代表任意字符，所以返回
true。
str="abcd"，exp=".*"。exp中'*'的前一个字符是'.'，所以可表示任
意数量的'.'字符，当exp是"...."时与"abcd"匹配，返回true。
str=""，exp="..*"。exp中'*'的前一个字符是'.'，可表示任意数量
的'.'字符，但是".*"之前还有一个'.'字符，该字符不受'*'的影响，
所以str起码有一个字符才能被exp匹配。所以返回false。

64
给定一个数组arr，全是正数；一个整数aim，求累加和等
于aim的，最长子数组，要求额外空间复杂度O(1)，时间
复杂度O(N)

65
给定一个数组arr，值可正，可负，可0；一个整数aim，求累加
和小于等于aim的，最长子数组，要求时间复杂度O(N)

66
环形单链表的约瑟夫问题
【题目】
据说著名犹太历史学家Josephus有过以下故事：在罗马人占领乔塔帕特后，
39个犹太人与Josephus及他的朋友躲到一个洞中，39个犹太人决定宁愿死也
不要被敌人抓到，于是决定了一个自杀方式，41个人排成一个圆圈，由第1个
人开始报数，报数到3的人就自杀，然后再由下一个人重新报1，报数到3的人
再自杀，这样依次下去，直到剩下最后一个人时，那个人可以自由选择自己的
命运。这就是著名的约瑟夫问题。现在请用单向环形链表描述该结构并呈现整
个自杀过程。
输入：一个环形单向链表的头节点head和报数的值m。
返回：最后生存下来的节点，且这个节点自己组成环形单向链表，其他节点都
删掉。
进阶：
如果链表节点数为N，想在时间复杂度为O(N)时完成原问题的要求，该怎么实
现？




71
矩阵的最小路径和
【题目】
给定一个矩阵m，从左上角开始每次只能向右或者向下走，最后
到达右下角的位置，路径上所有的数字累加起来就是路径和，
返回所有的路径中最小的路径和。
【举例】
如果给定的m如下：
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
路径1，3，1，0，6，1，0是所有路径中路径和最小的，所以返
回12。
【要求】
额外空间复杂度O( min {m , n})

72
最长递增子序列
【题目】
给定数组arr，返回arr的最长递增子序列。
【举例】
arr=[2,1,5,3,6,4,8,9,7]，返回的最长递增子序列为
[1,3,4,8,9]。
【要求】
如果arr长度为N，请实现时间复杂度为O(NlogN)的方法。

73
最长公共子序列问题
【题目】
给定两个字符串str1和str2，返回两个字符串的最长公共子序列。
【举例】
str1="1A2C3D4B56"，str2="B1D23CA45B6A"。
"123456"或者"12C4B6"都是最长公共子序列，返回哪一个都行

74
最长公共子串问题
【题目】
给定两个字符串str1和str2，返回两个字符串的最长公共子串。
【举例】
str1="1AB2345CD"，str2="12345EF"，返回"2345"。
【要求】
如果str1长度为M，str2长度为N，实现时间复杂度为O(MN)，额
外空间复杂度为O(1)的方法。

75
最小编辑代价
【题目】
给定两个字符串str1和str2，再给定三个整数ic、dc和rc，分别代表插
入、删除和替换一个字符的代价，返回将str1编辑成str2的最小代价。
【举例】
str1="abc"，str2="adc"，ic=5，dc=3，rc=2。
从"abc"编辑成"adc"，把'b'替换成'd'是代价最小的，所以返回2。
str1="abc"，str2="adc"，ic=5，dc=3，rc=100。
从"abc"编辑成"adc"，先删除'b'，然后插入'd'是代价最小的，所以返
回8。
str1="abc"，str2="abc"，ic=5，dc=3，rc=2。
不用编辑了，本来就是一样的字符串，所以返回0。

76
回文最小分割数
【题目】
给定两个字符串str，请把str切割，保证每一部分都是回文串，求最小的分割
数。
【举例】
str="AA12321BB"，切成"AA","12321","BB"，每一部分都是回文串，分出3个
部分，所以返回3

77
字符串的交错组成
【题目】
给定三个字符串str1、str2和aim，如果aim包含且仅包含来自str1和str2的所有
字符，而且在aim中属于str1的字符之间保持原来在str1中的顺序，属于str2的
字符之间保持原来在str2中的顺序，那么称aim是str1和str2的交错组成。实现
一个函数，判断aim是否是str1和str2交错组成。
【举例】
str1="AB"，str2="12"。那么"AB12"、"A1B2"、"A12B"、"1A2B"和"1AB2"等都
是str1和str2的交错组成。

78
括号问题
【题目】
给定一个字符串str，判断是不是整体有效的括号字符串。
【举例】
str="()"，返回true；str="(()())"，返回true；str="(())"，返回true。
str="())"。返回false；str="()("，返回false；str="()a()"，返回false。
【补充题目】
给定一个括号字符串str，返回最长的有效括号子串。
【举例】
str="(()())"，返回6；str="())"，返回2；str="()(()()("，返回4。




81
两个有序数组间相加和的TOP K问题
【题目】
给定两个有序数组arr1和arr2，再给定一个整数k，返回来自
arr1和arr2的两个数相加和最大的前k个，两个数必须分别来自
两个数组。
【举例】
arr1=[1,2,3,4,5]，arr2=[3,5,7,9,11]，k=4。
返回数组[16,15,14,14]。
【要求】
时间复杂度达到O(klogk)。

82
子数组的最大累加和问题
【题目】
给定一个数组arr，返回子数组的最大累加和。
例如，arr=[1,-2,3,5,-2,6,-1]，所有的子数组中，[3,5,-2,6]
可以累加出最大的和12，所以返回12。
【要求】
如果arr长度为N，要求时间复杂度为O(N)，额外空间复杂度为
O(1)。

83
边界都是1的最大正方形大小
【题目】
给定一个NN的矩阵matrix，在这个矩阵中，只有0和1两种值，返回边
框全是1的最大正方形的边长长度。
例如：
0 1 1 1 1
0 1 0 0 1
0 1 0 0 1
0 1 1 1 1
0 1 0 1 1
其中，边框全是1的最大正方形的大小为4*4，所以返回4。

84
斐波那契系列问题的递归和动态规划
【题目】
给定整数N，返回斐波那契数列的第N项。
【补充题目1】
给定整数N，代表台阶数，一次可以跨2个或者1个台阶，返回有多少种走法。
【举例】
N=3，可以三次都跨1个台阶；也可以先跨2个台阶，再跨1个台阶；还可以先跨1个台阶，再跨2
个台阶。所以有三种走法，返回3。
【补充题目2】
假设农场中成熟的母牛每年只会生1头小母牛，并且永远不会死。第一年农场有1只成熟的母牛，
从第二年开始，母牛开始生小母牛。每只小母牛3年之后成熟又可以生小母牛。给定整数N，求
出N年后牛的数量。
【举例】
N=6，第1年1头成熟母牛记为a；第2年a生了新的小母牛，记为b，总牛数为2；第3年a生了新的
小母牛，记为c，总牛数为3；第4年a生了新的小母牛，记为d，总牛数为4。第5年b成熟了，a
和b分别生了新的小母牛，总牛数为6；第6年c也成熟了，a、b和c分别生了新的小母牛，总牛
数为9，返回9。
【要求】
对以上所有的问题，请实现时间复杂度O(logN)的解法。

85
找到字符串的最长无重复字符子串
【题目】
给定一个字符串str，返回str的最长无重复字符子串的长度。
【举例】
str="abcd"，返回4
str="aabcb"，最长无重复字符子串为"abc"，返回3。
【要求】
如果str的长度为N，请实现时间复杂度为O(N)的方法。

86
认识完美洗牌问题




///////////////////////////////////////////////////////////////////////////
11
package advanced_class_01;

public class Code_01_GetMax {

	public static int flip(int n) {
		return n ^ 1;
	}

	public static int sign(int n) {
		return flip((n >> 31) & 1);
	}

	public static int getMax1(int a, int b) {
		int c = a - b;
		int scA = sign(c);
		int scB = flip(scA);
		return a * scA + b * scB;
	}

	public static int getMax2(int a, int b) {
		int c = a - b;
		int sa = sign(a);
		int sb = sign(b);
		int sc = sign(c);
		int difSab = sa ^ sb;
		int sameSab = flip(difSab);
		int returnA = difSab * sa + sameSab * sc;
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}

	public static void main(String[] args) {
		int a = -16;
		int b = 1;
		System.out.println(getMax1(a, b));
		System.out.println(getMax2(a, b));
		a = 2147483647;
		b = -2147480000;
		System.out.println(getMax1(a, b)); // wrong answer because of overflow
		System.out.println(getMax2(a, b));

	}

}

12
package advanced_class_01;

public class Code_02_HanoiProblem {

	public static void hanoi(int n) {
		if (n > 0) {
			func(n, "left", "mid", "right");
		}
	}

	public static void func(int n, String from, String mid, String to) {
		if (n == 1) {
			System.out.println("move from " + from + " to " + to);
		} else {
			func(n - 1, from, to, mid);
			func(1, from, mid, to);
			func(n - 1, mid, from, to);
		}
	}

	public static int step1(int[] arr) {
		if (arr == null || arr.length == 0) {
			return -1;
		}
		return process(arr, arr.length - 1, 1, 2, 3);
	}

	public static int process(int[] arr, int i, int from, int mid, int to) {
		if (i == -1) {
			return 0;
		}
		if (arr[i] != from && arr[i] != to) {
			return -1;
		}
		if (arr[i] == from) {
			return process(arr, i - 1, from, to, mid);
		} else {
			int rest = process(arr, i - 1, mid, from, to);
			if (rest == -1) {
				return -1;
			}
			return (1 << i) + rest;
		}
	}

	public static int step2(int[] arr) {
		if (arr == null || arr.length == 0) {
			return -1;
		}
		int from = 1;
		int mid = 2;
		int to = 3;
		int i = arr.length - 1;
		int res = 0;
		int tmp = 0;
		while (i >= 0) {
			if (arr[i] != from && arr[i] != to) {
				return -1;
			}
			if (arr[i] == to) {
				res += 1 << i;
				tmp = from;
				from = mid;
			} else {
				tmp = to;
				to = mid;
			}
			mid = tmp;
			i--;
		}
		return res;
	}

	public static void main(String[] args) {
		int n = 4;
		hanoi(n);

		int[] arr = { 3, 3, 2, 1 };
		System.out.println(step1(arr));
		System.out.println(step2(arr));

	}
}

13
package advanced_class_01;

import java.util.HashMap;

public class Code_03_LongestPathSum {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static int getMaxLength(Node head, int sum) {
		HashMap<Integer, Integer> sumMap = new HashMap<Integer, Integer>();
		sumMap.put(0, 0); // important
		return preOrder(head, sum, 0, 1, 0, sumMap);
	}

	public static int preOrder(Node head, int sum, int preSum, int level,
			int maxLen, HashMap<Integer, Integer> sumMap) {
		if (head == null) {
			return maxLen;
		}
		int curSum = preSum + head.value;
		if (!sumMap.containsKey(curSum)) {
			sumMap.put(curSum, level);
		}
		if (sumMap.containsKey(curSum - sum)) {
			maxLen = Math.max(level - sumMap.get(curSum - sum), maxLen);
		}
		maxLen = preOrder(head.left, sum, curSum, level + 1, maxLen, sumMap);
		maxLen = preOrder(head.right, sum, curSum, level + 1, maxLen, sumMap);
		if (level == sumMap.get(curSum)) {
			sumMap.remove(curSum);
		}
		return maxLen;
	}

	// for test -- print tree
	public static void printTree(Node head) {
		System.out.println("Binary Tree:");
		printInOrder(head, 0, "H", 17);
		System.out.println();
	}

	public static void printInOrder(Node head, int height, String to, int len) {
		if (head == null) {
			return;
		}
		printInOrder(head.right, height + 1, "v", len);
		String val = to + head.value + to;
		int lenM = val.length();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = getSpace(lenL) + val + getSpace(lenR);
		System.out.println(getSpace(height * len) + val);
		printInOrder(head.left, height + 1, "^", len);
	}

	public static String getSpace(int num) {
		String space = " ";
		StringBuffer buf = new StringBuffer("");
		for (int i = 0; i < num; i++) {
			buf.append(space);
		}
		return buf.toString();
	}

	public static void main(String[] args) {
		Node head = new Node(-3);
		head.left = new Node(3);
		head.right = new Node(-9);
		head.left.left = new Node(1);
		head.left.right = new Node(0);
		head.left.right.left = new Node(1);
		head.left.right.right = new Node(6);
		head.right.left = new Node(2);
		head.right.right = new Node(1);
		printTree(head);
		System.out.println(getMaxLength(head, 6));
		System.out.println(getMaxLength(head, -9));

	}

}


15 
package advanced_class_01;

public class Code_05_IsBalancedTree {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static boolean isBalance(Node head) {
		boolean[] res = new boolean[1];
		res[0] = true;
		getHeight(head, 1, res);
		return res[0];
	}

	public static int getHeight(Node head, int level, boolean[] res) {
		if (head == null) {
			return level;
		}
		int lH = getHeight(head.left, level + 1, res);
		if (!res[0]) {
			return level;
		}
		int rH = getHeight(head.right, level + 1, res);
		if (!res[0]) {
			return level;
		}
		if (Math.abs(lH - rH) > 1) {
			res[0] = false;
		}
		return Math.max(lH, rH);
	}

	public static void main(String[] args) {
		Node head = new Node(1);
		head.left = new Node(2);
		head.right = new Node(3);
		head.left.left = new Node(4);
		head.left.right = new Node(5);
		head.right.left = new Node(6);
		head.right.right = new Node(7);

		System.out.println(isBalance(head));

	}

}


16
package advanced_class_01;

public class Code_06_T1ContainsT2Topology {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static boolean contains(Node t1, Node t2) {
		if (t2 == null) {
			return true;
		}
		if (t1 == null) {
			return false;
		}
		return check(t1, t2) || contains(t1.left, t2) || contains(t1.right, t2);
	}

	public static boolean check(Node h, Node t2) {
		if (t2 == null) {
			return true;
		}
		if (h == null || h.value != t2.value) {
			return false;
		}
		return check(h.left, t2.left) && check(h.right, t2.right);
	}

	public static void main(String[] args) {
		Node t1 = new Node(1);
		t1.left = new Node(2);
		t1.right = new Node(3);
		t1.left.left = new Node(4);
		t1.left.right = new Node(5);
		t1.right.left = new Node(6);
		t1.right.right = new Node(7);
		t1.left.left.left = new Node(8);
		t1.left.left.right = new Node(9);
		t1.left.right.left = new Node(10);

		Node t2 = new Node(2);
		t2.left = new Node(4);
		t2.left.left = new Node(8);
		t2.right = new Node(5);

		System.out.println(contains(t1, t2));

	}

}


17
package advanced_class_01;

import java.util.LinkedList;

public class Code_07_ExpressionCompute {

	public static int getValue(String str) {
		return value(str.toCharArray(), 0)[0];
	}

	public static int[] value(char[] str, int i) {
		LinkedList<String> que = new LinkedList<String>();
		int pre = 0;
		int[] bra = null;
		while (i < str.length && str[i] != ')') {
			if (str[i] >= '0' && str[i] <= '9') {
				pre = pre * 10 + str[i++] - '0';
			} else if (str[i] != '(') {
				addNum(que, pre);
				que.addLast(String.valueOf(str[i++]));
				pre = 0;
			} else {
				bra = value(str, i + 1);
				pre = bra[0];
				i = bra[1] + 1;
			}
		}
		addNum(que, pre);
		return new int[] { getNum(que), i };
	}

	public static void addNum(LinkedList<String> que, int num) {
		if (!que.isEmpty()) {
			int cur = 0;
			String top = que.pollLast();
			if (top.equals("+") || top.equals("-")) {
				que.addLast(top);
			} else {
				cur = Integer.valueOf(que.pollLast());
				num = top.equals("*") ? (cur * num) : (cur / num);
			}
		}
		que.addLast(String.valueOf(num));
	}

	public static int getNum(LinkedList<String> que) {
		int res = 0;
		boolean add = true;
		String cur = null;
		int num = 0;
		while (!que.isEmpty()) {
			cur = que.pollFirst();
			if (cur.equals("+")) {
				add = true;
			} else if (cur.equals("-")) {
				add = false;
			} else {
				num = Integer.valueOf(cur);
				res += add ? num : (-num);
			}
		}
		return res;
	}

	public static void main(String[] args) {
		String exp = "48*((70-65)-43)+8*1";
		System.out.println(getValue(exp));

		exp = "4*(6+78)+53-9/2+45*8";
		System.out.println(getValue(exp));

		exp = "10-5*3";
		System.out.println(getValue(exp));

		exp = "-3*4";
		System.out.println(getValue(exp));

		exp = "3+1*4";
		System.out.println(getValue(exp));

	}

}


18 
package advanced_class_01;

public class Code_08_MaxDistanceInTree {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static int maxDistance(Node head) {
		int[] record = new int[1];
		return posOrder(head, record);
	}

	public static int posOrder(Node head, int[] record) {
		if (head == null) {
			record[0] = 0;
			return 0;
		}
		int lMax = posOrder(head.left, record);
		int maxfromLeft = record[0];
		int rMax = posOrder(head.right, record);
		int maxFromRight = record[0];
		int curNodeMax = maxfromLeft + maxFromRight + 1;
		record[0] = Math.max(maxfromLeft, maxFromRight) + 1;
		return Math.max(Math.max(lMax, rMax), curNodeMax);
	}

	public static void main(String[] args) {
		Node head1 = new Node(1);
		head1.left = new Node(2);
		head1.right = new Node(3);
		head1.left.left = new Node(4);
		head1.left.right = new Node(5);
		head1.right.left = new Node(6);
		head1.right.right = new Node(7);
		head1.left.left.left = new Node(8);
		head1.right.left.right = new Node(9);
		System.out.println(maxDistance(head1));

		Node head2 = new Node(1);
		head2.left = new Node(2);
		head2.right = new Node(3);
		head2.right.left = new Node(4);
		head2.right.right = new Node(5);
		head2.right.left.left = new Node(6);
		head2.right.right.right = new Node(7);
		head2.right.left.left.left = new Node(8);
		head2.right.right.right.right = new Node(9);
		System.out.println(maxDistance(head2));

	}

}




21 
package advanced_class_02;

import java.util.HashMap;

public class Code_01_LeastRecentlyUsedCache {

	public static class Node<V> {
		public V value;
		public Node<V> last;
		public Node<V> next;

		public Node(V value) {
			this.value = value;
		}
	}

	public static class NodeDoubleLinkedList<V> {
		private Node<V> head;
		private Node<V> tail;

		public NodeDoubleLinkedList() {
			this.head = null;
			this.tail = null;
		}

		public void addNode(Node<V> newNode) {
			if (newNode == null) {
				return;
			}
			if (this.head == null) {
				this.head = newNode;
				this.tail = newNode;
			} else {
				this.tail.next = newNode;
				newNode.last = this.tail;
				this.tail = newNode;
			}
		}

		public void moveNodeToTail(Node<V> node) {
			if (this.tail == node) {
				return;
			}
			if (this.head == node) {
				this.head = node.next;
				this.head.last = null;
			} else {
				node.last.next = node.next;
				node.next.last = node.last;
			}
			node.last = this.tail;
			node.next = null;
			this.tail.next = node;
			this.tail = node;
		}

		public Node<V> removeHead() {
			if (this.head == null) {
				return null;
			}
			Node<V> res = this.head;
			if (this.head == this.tail) {
				this.head = null;
				this.tail = null;
			} else {
				this.head = res.next;
				res.next = null;
				this.head.last = null;
			}
			return res;
		}

	}

	public static class MyCache<K, V> {
		private HashMap<K, Node<V>> keyNodeMap;
		private HashMap<Node<V>, K> nodeKeyMap;
		private NodeDoubleLinkedList<V> nodeList;
		private int capacity;

		public MyCache(int capacity) {
			if (capacity < 1) {
				throw new RuntimeException("should be more than 0.");
			}
			this.keyNodeMap = new HashMap<K, Node<V>>();
			this.nodeKeyMap = new HashMap<Node<V>, K>();
			this.nodeList = new NodeDoubleLinkedList<V>();
			this.capacity = capacity;
		}

		public V get(K key) {
			if (this.keyNodeMap.containsKey(key)) {
				Node<V> res = this.keyNodeMap.get(key);
				this.nodeList.moveNodeToTail(res);
				return res.value;
			}
			return null;
		}

		public void set(K key, V value) {
			if (this.keyNodeMap.containsKey(key)) {
				Node<V> node = this.keyNodeMap.get(key);
				node.value = value;
				this.nodeList.moveNodeToTail(node);
			} else {
				Node<V> newNode = new Node<V>(value);
				this.keyNodeMap.put(key, newNode);
				this.nodeKeyMap.put(newNode, key);
				this.nodeList.addNode(newNode);
				if (this.keyNodeMap.size() == this.capacity + 1) {
					this.removeMostUnusedCache();
				}
			}
		}

		private void removeMostUnusedCache() {
			Node<V> removeNode = this.nodeList.removeHead();
			K removeKey = this.nodeKeyMap.get(removeNode);
			this.nodeKeyMap.remove(removeNode);
			this.keyNodeMap.remove(removeKey);
		}

	}

	public static void main(String[] args) {
		MyCache<String, Integer> testCache = new MyCache<String, Integer>(3);
		testCache.set("A", 1);
		testCache.set("B", 2);
		testCache.set("C", 3);
		System.out.println(testCache.get("B"));
		System.out.println(testCache.get("A"));
		testCache.set("D", 4);
		System.out.println(testCache.get("D"));
		System.out.println(testCache.get("C"));

	}

}


22
package advanced_class_02;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map.Entry;
import java.util.TreeMap;

// http://lintcode.com/zh-cn/problem/building-outline/
public class Code_02_Building_Outline {
	public static class Node {
		public boolean be;
		public int p;
		public int h;

		public Node(boolean bORe, int position, int height) {
			be = bORe;
			p = position;
			h = height;
		}
	}

	public static class NodeComparator implements Comparator<Node> {
		@Override
		public int compare(Node o1, Node o2) {
			if (o1.p != o2.p) {
				return o1.p - o2.p;
			}
			if (o1.be != o2.be) {
				return o1.be ? -1 : 1;
			}
			return 0;
		}
	}

	public static List<List<Integer>> buildingOutline(int[][] buildings) {
		Node[] nodes = new Node[buildings.length * 2];
		for (int i = 0; i < buildings.length; i++) {
			nodes[i * 2] = new Node(true, buildings[i][0], buildings[i][2]);
			nodes[i * 2 + 1] = new Node(false, buildings[i][1], buildings[i][2]);
		}
		Arrays.sort(nodes, new NodeComparator());
		TreeMap<Integer, Integer> htMap = new TreeMap<>();
		TreeMap<Integer, Integer> pmMap = new TreeMap<>();
		for (int i = 0; i < nodes.length; i++) {
			if (nodes[i].be) {
				if (!htMap.containsKey(nodes[i].h)) {
					htMap.put(nodes[i].h, 1);
				} else {
					htMap.put(nodes[i].h, htMap.get(nodes[i].h) + 1);
				}
			} else {
				if (htMap.containsKey(nodes[i].h)) {
					if (htMap.get(nodes[i].h) == 1) {
						htMap.remove(nodes[i].h);
					} else {
						htMap.put(nodes[i].h, htMap.get(nodes[i].h) - 1);
					}
				}
			}
			if (htMap.isEmpty()) {
				pmMap.put(nodes[i].p, 0);
			} else {
				pmMap.put(nodes[i].p, htMap.lastKey());
			}
		}
		List<List<Integer>> res = new ArrayList<>();
		int start = 0;
		int height = 0;
		for (Entry<Integer, Integer> entry : pmMap.entrySet()) {
			int curPosition = entry.getKey();
			int curMaxHeight = entry.getValue();
			if (height != curMaxHeight) {
				if (height != 0) {
					List<Integer> newRecord = new ArrayList<Integer>();
					newRecord.add(start);
					newRecord.add(curPosition);
					newRecord.add(height);
					res.add(newRecord);
				}
				start = curPosition;
				height = curMaxHeight;
			}
		}
		return res;
	}

}


23
package advanced_class_02;

public class Code_03_FindNewTypeChar {

	public static String pointNewchar(String s, int k) {
		if (s == null || s.equals("") || k < 0 || k >= s.length()) {
			return "";
		}
		char[] chas = s.toCharArray();
		int uNum = 0;
		for (int i = k - 1; i >= 0; i--) {
			if (!isUpper(chas[i])) {
				break;
			}
			uNum++;
		}
		if ((uNum & 1) == 1) {
			return s.substring(k - 1, k + 1);
		}
		if (isUpper(chas[k])) {
			return s.substring(k, k + 2);
		}
		return String.valueOf(chas[k]);
	}

	public static boolean isUpper(char ch) {
		return !(ch < 'A' || ch > 'Z');
	}

	public static void main(String[] args) {
		String str = "aaABCDEcBCg";
		System.out.println(pointNewchar(str, 7));
		System.out.println(pointNewchar(str, 4));
		System.out.println(pointNewchar(str, 10));

	}

}


24
package advanced_class_02;

public class Code_04_TrieTree {

	public static class TrieNode {
		public int path;
		public int end;
		public TrieNode[] map;

		public TrieNode() {
			path = 0;
			end = 0;
			map = new TrieNode[26];
		}
	}

	public static class Trie {
		private TrieNode root;

		public Trie() {
			root = new TrieNode();
		}

		public void insert(String word) {
			if (word == null) {
				return;
			}
			char[] chs = word.toCharArray();
			TrieNode node = root;
			int index = 0;
			for (int i = 0; i < chs.length; i++) {
				index = chs[i] - 'a';
				if (node.map[index] == null) {
					node.map[index] = new TrieNode();
				}
				node = node.map[index];
				node.path++;
			}
			node.end++;
		}

		public void delete(String word) {
			if (search(word)) {
				char[] chs = word.toCharArray();
				TrieNode node = root;
				int index = 0;
				for (int i = 0; i < chs.length; i++) {
					index = chs[i] - 'a';
					if (node.map[index].path-- == 1) {
						node.map[index] = null;
						return;
					}
					node = node.map[index];
				}
				node.end--;
			}
		}

		public boolean search(String word) {
			if (word == null) {
				return false;
			}
			char[] chs = word.toCharArray();
			TrieNode node = root;
			int index = 0;
			for (int i = 0; i < chs.length; i++) {
				index = chs[i] - 'a';
				if (node.map[index] == null) {
					return false;
				}
				node = node.map[index];
			}
			return node.end != 0;
		}

		public int prefixNumber(String pre) {
			if (pre == null) {
				return 0;
			}
			char[] chs = pre.toCharArray();
			TrieNode node = root;
			int index = 0;
			for (int i = 0; i < chs.length; i++) {
				index = chs[i] - 'a';
				if (node.map[index] == null) {
					return 0;
				}
				node = node.map[index];
			}
			return node.path;
		}
	}

	public static void main(String[] args) {
		Trie trie = new Trie();
		System.out.println(trie.search("zuo"));
		trie.insert("zuo");
		System.out.println(trie.search("zuo"));
		trie.delete("zuo");
		System.out.println(trie.search("zuo"));
		trie.insert("zuo");
		trie.insert("zuo");
		trie.delete("zuo");
		System.out.println(trie.search("zuo"));
		trie.delete("zuo");
		System.out.println(trie.search("zuo"));
		trie.insert("zuoa");
		trie.insert("zuoac");
		trie.insert("zuoab");
		trie.insert("zuoad");
		trie.delete("zuoa");
		System.out.println(trie.search("zuoa"));
		System.out.println(trie.prefixNumber("zuo"));

	}

}


25
package advanced_class_02;

public class Code_05_EnglishExpression {

	public static String num1To19(int num) {
		if (num < 1 || num > 19) {
			return "";
		}
		String[] names = { "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
				"Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
				"Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Sixteen ",
				"Eighteen ", "Nineteen " };
		return names[num - 1];
	}

	public static String num1To99(int num) {
		if (num < 1 || num > 99) {
			return "";
		}
		if (num < 20) {
			return num1To19(num);
		}
		int high = num / 10;
		String[] tyNames = { "Twenty ", "Thirty ", "Forty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety " };
		return tyNames[high - 2] + num1To19(num % 10);
	}

	public static String num1To999(int num) {
		if (num < 1 || num > 999) {
			return "";
		}
		if (num < 100) {
			return num1To99(num);
		}
		int high = num / 100;
		return num1To19(high) + "Hundred " + num1To99(num % 100);
	}

	public static String getNumEngExp(int num) {
		if (num == 0) {
			return "Zero";
		}
		String res = "";
		if (num < 0) {
			res = "Negative, ";
		}
		if (num == Integer.MIN_VALUE) {
			res += "Two Billion, ";
			num %= -2000000000;
		}
		num = Math.abs(num);
		int high = 1000000000;
		int highIndex = 0;
		String[] names = { "Billion", "Million", "Thousand", "" };
		while (num != 0) {
			int cur = num / high;
			num %= high;
			if (cur != 0) {
				res += num1To999(cur);
				res += names[highIndex] + (num == 0 ? " " : ", ");
			}
			high /= 1000;
			highIndex++;
		}
		return res;
	}

	public static int generateRandomNum() {
		boolean isNeg = Math.random() > 0.5 ? false : true;
		int value = (int) (Math.random() * Integer.MIN_VALUE);
		return isNeg ? value : -value;
	}

	public static void main(String[] args) {
		System.out.println(getNumEngExp(0));
		System.out.println(getNumEngExp(Integer.MAX_VALUE));
		System.out.println(getNumEngExp(Integer.MIN_VALUE));
		int num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumEngExp(num));

	}

}


26
package advanced_class_02;

public class Code_06_ChineseExpression {

	public static String num1To9(int num) {
		if (num < 1 || num > 9) {
			return "";
		}
		String[] names = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
		return names[num - 1];
	}

	public static String num1To99(int num, boolean hasBai) {
		if (num < 1 || num > 99) {
			return "";
		}
		if (num < 10) {
			return num1To9(num);
		}
		int shi = num / 10;
		if (shi == 1 && (!hasBai)) {
			return "十" + num1To9(num % 10);
		} else {
			return num1To9(shi) + "十" + num1To9(num % 10);
		}
	}

	public static String num1To999(int num) {
		if (num < 1 || num > 999) {
			return "";
		}
		if (num < 100) {
			return num1To99(num, false);
		}
		String res = num1To9(num / 100) + "百";
		int rest = num % 100;
		if (rest == 0) {
			return res;
		} else if (rest >= 10) {
			res += num1To99(rest, true);
		} else {
			res += "零" + num1To9(rest);
		}
		return res;
	}

	public static String num1To9999(int num) {
		if (num < 1 || num > 9999) {
			return "";
		}
		if (num < 1000) {
			return num1To999(num);
		}
		String res = num1To9(num / 1000) + "千";
		int rest = num % 1000;
		if (rest == 0) {
			return res;
		} else if (rest >= 100) {
			res += num1To999(rest);
		} else {
			res += "零" + num1To99(rest, false);
		}
		return res;
	}

	public static String num1To99999999(int num) {
		if (num < 1 || num > 99999999) {
			return "";
		}
		int wan = num / 10000;
		int rest = num % 10000;
		if (wan == 0) {
			return num1To9999(rest);
		}
		String res = num1To9999(wan) + "万";
		if (rest == 0) {
			return res;
		} else {
			if (rest < 1000) {
				return res + "零" + num1To999(rest);
			} else {
				return res + num1To9999(rest);
			}
		}
	}

	public static String getNumChiExp(int num) {
		if (num == 0) {
			return "零";
		}
		String res = num < 0 ? "负" : "";
		int yi = Math.abs(num / 100000000);
		int rest = Math.abs((num % 100000000));
		if (yi == 0) {
			return res + num1To99999999(rest);
		}
		res += num1To9999(yi) + "亿";
		if (rest == 0) {
			return res;
		} else {
			if (rest < 10000000) {
				return res + "零" + num1To99999999(rest);
			} else {
				return res + num1To99999999(rest);
			}
		}
	}

	// for test
	public static int generateRandomNum() {
		boolean isNeg = Math.random() > 0.5 ? false : true;
		int value = (int) (Math.random() * Integer.MIN_VALUE);
		return isNeg ? value : -value;
	}

	public static void main(String[] args) {
		System.out.println(0);
		System.out.println(getNumChiExp(0));

		System.out.println(Integer.MAX_VALUE);
		System.out.println(getNumChiExp(Integer.MAX_VALUE));

		System.out.println(Integer.MIN_VALUE);
		System.out.println(getNumChiExp(Integer.MIN_VALUE));

		int num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		System.out.println(getNumChiExp(10));
		System.out.println(getNumChiExp(110));
		System.out.println(getNumChiExp(1010));
		System.out.println(getNumChiExp(10010));
		System.out.println(getNumChiExp(1900000000));
		System.out.println(getNumChiExp(1000000010));
		System.out.println(getNumChiExp(1010100010));

	}
}


27
package advanced_class_02;

public class Code_07_ThrowChessPiecesProblem {

	public static int solution1(int nLevel, int kChess) {
		if (nLevel < 1 || kChess < 1) {
			return 0;
		}
		return Process1(nLevel, kChess);
	}

	public static int Process1(int nLevel, int kChess) {
		if (nLevel == 0) {
			return 0;
		}
		if (kChess == 1) {
			return nLevel;
		}
		int min = Integer.MAX_VALUE;
		for (int i = 1; i != nLevel + 1; i++) {
			if (i == nLevel) {

			}
			min = Math.min(
					min,
					Math.max(Process1(i - 1, kChess - 1),
							Process1(nLevel - i, kChess)));
		}
		return min + 1;
	}

	public static int solution2(int nLevel, int kChess) {
		if (nLevel < 1 || kChess < 1) {
			return 0;
		}
		if (kChess == 1) {
			return nLevel;
		}
		int[][] dp = new int[nLevel + 1][kChess + 1];
		for (int i = 1; i != dp.length; i++) {
			dp[i][1] = i;
		}
		for (int i = 1; i != dp.length; i++) {
			for (int j = 2; j != dp[0].length; j++) {
				int min = Integer.MAX_VALUE;
				for (int k = 1; k != i + 1; k++) {
					min = Math.min(min,
							Math.max(dp[k - 1][j - 1], dp[i - k][j]));
				}
				dp[i][j] = min + 1;
			}
		}
		return dp[nLevel][kChess];
	}

	public static int solution3(int nLevel, int kChess) {
		if (nLevel < 1 || kChess < 1) {
			return 0;
		}
		if (kChess == 1) {
			return nLevel;
		}
		int[] preArr = new int[nLevel + 1];
		int[] curArr = new int[nLevel + 1];
		for (int i = 1; i != curArr.length; i++) {
			curArr[i] = i;
		}
		for (int i = 1; i != kChess; i++) {
			int[] tmp = preArr;
			preArr = curArr;
			curArr = tmp;
			for (int j = 1; j != curArr.length; j++) {
				int min = Integer.MAX_VALUE;
				for (int k = 1; k != j + 1; k++) {
					min = Math.min(min, Math.max(preArr[k - 1], curArr[j - k]));
				}
				curArr[j] = min + 1;
			}
		}
		return curArr[curArr.length - 1];
	}

	public static int solution4(int nLevel, int kChess) {
		if (nLevel < 1 || kChess < 1) {
			return 0;
		}
		if (kChess == 1) {
			return nLevel;
		}
		int[][] dp = new int[nLevel + 1][kChess + 1];
		for (int i = 1; i != dp.length; i++) {
			dp[i][1] = i;
		}
		int[] cands = new int[kChess + 1];
		for (int i = 1; i != dp[0].length; i++) {
			dp[1][i] = 1;
			cands[i] = 1;
		}
		for (int i = 2; i < nLevel + 1; i++) {
			for (int j = kChess; j > 1; j--) {
				int min = Integer.MAX_VALUE;
				int minEnum = cands[j];
				int maxEnum = j == kChess ? i / 2 + 1 : cands[j + 1];
				for (int k = minEnum; k < maxEnum + 1; k++) {
					int cur = Math.max(dp[k - 1][j - 1], dp[i - k][j]);
					if (cur <= min) {
						min = cur;
						cands[j] = k;
					}
				}
				dp[i][j] = min + 1;
			}
		}
		return dp[nLevel][kChess];
	}

	public static int solution5(int nLevel, int kChess) {
		if (nLevel < 1 || kChess < 1) {
			return 0;
		}
		int bsTimes = log2N(nLevel) + 1;
		if (kChess >= bsTimes) {
			return bsTimes;
		}
		int[] dp = new int[kChess];
		int res = 0;
		while (true) {
			res++;
			int previous = 0;
			for (int i = 0; i < dp.length; i++) {
				int tmp = dp[i];
				dp[i] = dp[i] + previous + 1;
				previous = tmp;
				if (dp[i] >= nLevel) {
					return res;
				}
			}
		}
	}

	public static int log2N(int n) {
		int res = -1;
		while (n != 0) {
			res++;
			n >>>= 1;
		}
		return res;
	}

	public static void main(String[] args) {
		System.out.println(solution1(21, 2));
		System.out.println(solution2(21, 2));
		System.out.println(solution3(21, 2));
		System.out.println(solution4(21, 2));
		System.out.println(solution5(21, 2));

		System.out.println("==============");

		System.out.println(solution2(105, 2));
		System.out.println(solution3(105, 2));
		System.out.println(solution4(105, 2));
		System.out.println(solution5(105, 2));

		System.out.println("==============");

		System.out.println(solution2(3000, 10));
		System.out.println(solution3(3000, 10));
		System.out.println(solution4(3000, 10));
		System.out.println(solution5(3000, 10));

		System.out.println("==============");

		System.out.println(solution2(6884, 5));
		System.out.println(solution3(6884, 5));
		System.out.println(solution4(6884, 5));
		System.out.println(solution5(6884, 5));

		System.out.println("==============");

		System.out.println(solution2(6885, 5));
		System.out.println(solution3(6885, 5));
		System.out.println(solution4(6885, 5));
		System.out.println(solution5(6885, 5));

		System.out.println("==============");

		int nLevel = 100000000;
		int kChess = 10;
		long start = System.currentTimeMillis();
		System.out.println(solution5(nLevel, kChess));
		long end = System.currentTimeMillis();
		System.out.println("cost time: " + (end - start) + " ms");

	}

}




31
AbstractBinarySearchTree
AbstractSelfBalancingBinarySearchTree
AVLTree
Code_01_MorrisTraversal
Code_02_SkipList
RedBlackTree

package advanced_class_03;

/**
 * Not implemented by zuochengyun
 * 
 * Abstract binary search tree implementation. Its basically fully implemented
 * binary search tree, just template method is provided for creating Node (other
 * trees can have slightly different nodes with more info). This way some code
 * from standart binary search tree can be reused for other kinds of binary
 * trees.
 * 
 * @author Ignas Lelys
 * @created Jun 29, 2011
 * 
 */
public class AbstractBinarySearchTree {

	/** Root node where whole tree starts. */
	public Node root;

	/** Tree size. */
	protected int size;

	/**
	 * Because this is abstract class and various trees have different
	 * additional information on different nodes subclasses uses this abstract
	 * method to create nodes (maybe of class {@link Node} or maybe some
	 * different node sub class).
	 * 
	 * @param value
	 *            Value that node will have.
	 * @param parent
	 *            Node's parent.
	 * @param left
	 *            Node's left child.
	 * @param right
	 *            Node's right child.
	 * @return Created node instance.
	 */
	protected Node createNode(int value, Node parent, Node left, Node right) {
		return new Node(value, parent, left, right);
	}

	/**
	 * Finds a node with concrete value. If it is not found then null is
	 * returned.
	 * 
	 * @param element
	 *            Element value.
	 * @return Node with value provided, or null if not found.
	 */
	public Node search(int element) {
		Node node = root;
		while (node != null && node.value != null && node.value != element) {
			if (element < node.value) {
				node = node.left;
			} else {
				node = node.right;
			}
		}
		return node;
	}

	/**
	 * Insert new element to tree.
	 * 
	 * @param element
	 *            Element to insert.
	 */
	public Node insert(int element) {
		if (root == null) {
			root = createNode(element, null, null, null);
			size++;
			return root;
		}

		Node insertParentNode = null;
		Node searchTempNode = root;
		while (searchTempNode != null && searchTempNode.value != null) {
			insertParentNode = searchTempNode;
			if (element < searchTempNode.value) {
				searchTempNode = searchTempNode.left;
			} else {
				searchTempNode = searchTempNode.right;
			}
		}

		Node newNode = createNode(element, insertParentNode, null, null);
		if (insertParentNode.value > newNode.value) {
			insertParentNode.left = newNode;
		} else {
			insertParentNode.right = newNode;
		}

		size++;
		return newNode;
	}

	/**
	 * Removes element if node with such value exists.
	 * 
	 * @param element
	 *            Element value to remove.
	 * 
	 * @return New node that is in place of deleted node. Or null if element for
	 *         delete was not found.
	 */
	public Node delete(int element) {
		Node deleteNode = search(element);
		if (deleteNode != null) {
			return delete(deleteNode);
		} else {
			return null;
		}
	}

	/**
	 * Delete logic when node is already found.
	 * 
	 * @param deleteNode
	 *            Node that needs to be deleted.
	 * 
	 * @return New node that is in place of deleted node. Or null if element for
	 *         delete was not found.
	 */
	protected Node delete(Node deleteNode) {
		if (deleteNode != null) {
			Node nodeToReturn = null;
			if (deleteNode != null) {
				if (deleteNode.left == null) {
					nodeToReturn = transplant(deleteNode, deleteNode.right);
				} else if (deleteNode.right == null) {
					nodeToReturn = transplant(deleteNode, deleteNode.left);
				} else {
					Node successorNode = getMinimum(deleteNode.right);
					if (successorNode.parent != deleteNode) {
						transplant(successorNode, successorNode.right);
						successorNode.right = deleteNode.right;
						successorNode.right.parent = successorNode;
					}
					transplant(deleteNode, successorNode);
					successorNode.left = deleteNode.left;
					successorNode.left.parent = successorNode;
					nodeToReturn = successorNode;
				}
				size--;
			}
			return nodeToReturn;
		}
		return null;
	}

	/**
	 * Put one node from tree (newNode) to the place of another (nodeToReplace).
	 * 
	 * @param nodeToReplace
	 *            Node which is replaced by newNode and removed from tree.
	 * @param newNode
	 *            New node.
	 * 
	 * @return New replaced node.
	 */
	private Node transplant(Node nodeToReplace, Node newNode) {
		if (nodeToReplace.parent == null) {
			this.root = newNode;
		} else if (nodeToReplace == nodeToReplace.parent.left) {
			nodeToReplace.parent.left = newNode;
		} else {
			nodeToReplace.parent.right = newNode;
		}
		if (newNode != null) {
			newNode.parent = nodeToReplace.parent;
		}
		return newNode;
	}

	/**
	 * @param element
	 * @return true if tree contains element.
	 */
	public boolean contains(int element) {
		return search(element) != null;
	}

	/**
	 * @return Minimum element in tree.
	 */
	public int getMinimum() {
		return getMinimum(root).value;
	}

	/**
	 * @return Maximum element in tree.
	 */
	public int getMaximum() {
		return getMaximum(root).value;
	}

	/**
	 * Get next element element who is bigger than provided element.
	 * 
	 * @param element
	 *            Element for whom descendand element is searched
	 * @return Successor value.
	 */
	// TODO Predecessor
	public int getSuccessor(int element) {
		return getSuccessor(search(element)).value;
	}

	/**
	 * @return Number of elements in the tree.
	 */
	public int getSize() {
		return size;
	}

	/**
	 * Tree traversal with printing element values. In order method.
	 */
	public void printTreeInOrder() {
		printTreeInOrder(root);
	}

	/**
	 * Tree traversal with printing element values. Pre order method.
	 */
	public void printTreePreOrder() {
		printTreePreOrder(root);
	}

	/**
	 * Tree traversal with printing element values. Post order method.
	 */
	public void printTreePostOrder() {
		printTreePostOrder(root);
	}

	/*-------------------PRIVATE HELPER METHODS-------------------*/

	private void printTreeInOrder(Node entry) {
		if (entry != null) {
			printTreeInOrder(entry.left);
			if (entry.value != null) {
				System.out.println(entry.value);
			}
			printTreeInOrder(entry.right);
		}
	}

	private void printTreePreOrder(Node entry) {
		if (entry != null) {
			if (entry.value != null) {
				System.out.println(entry.value);
			}
			printTreeInOrder(entry.left);
			printTreeInOrder(entry.right);
		}
	}

	private void printTreePostOrder(Node entry) {
		if (entry != null) {
			printTreeInOrder(entry.left);
			printTreeInOrder(entry.right);
			if (entry.value != null) {
				System.out.println(entry.value);
			}
		}
	}

	protected Node getMinimum(Node node) {
		while (node.left != null) {
			node = node.left;
		}
		return node;
	}

	protected Node getMaximum(Node node) {
		while (node.right != null) {
			node = node.right;
		}
		return node;
	}

	protected Node getSuccessor(Node node) {
		// if there is right branch, then successor is leftmost node of that
		// subtree
		if (node.right != null) {
			return getMinimum(node.right);
		} else { // otherwise it is a lowest ancestor whose left child is also
			// ancestor of node
			Node currentNode = node;
			Node parentNode = node.parent;
			while (parentNode != null && currentNode == parentNode.right) {
				// go up until we find parent that currentNode is not in right
				// subtree.
				currentNode = parentNode;
				parentNode = parentNode.parent;
			}
			return parentNode;
		}
	}

	// -------------------------------- TREE PRINTING
	// ------------------------------------

	public void printTree() {
		printSubtree(root);
	}

	public void printSubtree(Node node) {
		if (node.right != null) {
			printTree(node.right, true, "");
		}
		printNodeValue(node);
		if (node.left != null) {
			printTree(node.left, false, "");
		}
	}

	private void printNodeValue(Node node) {
		if (node.value == null) {
			System.out.print("<null>");
		} else {
			System.out.print(node.value.toString());
		}
		System.out.println();
	}

	private void printTree(Node node, boolean isRight, String indent) {
		if (node.right != null) {
			printTree(node.right, true, indent + (isRight ? "        " : " |      "));
		}
		System.out.print(indent);
		if (isRight) {
			System.out.print(" /");
		} else {
			System.out.print(" \\");
		}
		System.out.print("----- ");
		printNodeValue(node);
		if (node.left != null) {
			printTree(node.left, false, indent + (isRight ? " |      " : "        "));
		}
	}

	public static class Node {
		public Node(Integer value, Node parent, Node left, Node right) {
			super();
			this.value = value;
			this.parent = parent;
			this.left = left;
			this.right = right;
		}

		public Integer value;
		public Node parent;
		public Node left;
		public Node right;

		public boolean isLeaf() {
			return left == null && right == null;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((value == null) ? 0 : value.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Node other = (Node) obj;
			if (value == null) {
				if (other.value != null)
					return false;
			} else if (!value.equals(other.value))
				return false;
			return true;
		}

	}
}


package advanced_class_03;

/**
 * Not implemented by zuochengyun
 * 
 * Abstract class for self balancing binary search trees. Contains some methods
 * that is used for self balancing trees.
 * 
 * @author Ignas Lelys
 * @created Jul 24, 2011
 * 
 */
public abstract class AbstractSelfBalancingBinarySearchTree extends AbstractBinarySearchTree {

    /**
     * Rotate to the left.
     * 
     * @param node Node on which to rotate.
     * @return Node that is in place of provided node after rotation.
     */
    protected Node rotateLeft(Node node) {
        Node temp = node.right;
        temp.parent = node.parent;

        node.right = temp.left;
        if (node.right != null) {
            node.right.parent = node;
        }

        temp.left = node;
        node.parent = temp;

        // temp took over node's place so now its parent should point to temp
        if (temp.parent != null) {
            if (node == temp.parent.left) {
                temp.parent.left = temp;
            } else {
                temp.parent.right = temp;
            }
        } else {
            root = temp;
        }
        
        return temp;
    }

    /**
     * Rotate to the right.
     * 
     * @param node Node on which to rotate.
     * @return Node that is in place of provided node after rotation.
     */
    protected Node rotateRight(Node node) {
        Node temp = node.left;
        temp.parent = node.parent;

        node.left = temp.right;
        if (node.left != null) {
            node.left.parent = node;
        }

        temp.right = node;
        node.parent = temp;

        // temp took over node's place so now its parent should point to temp
        if (temp.parent != null) {
            if (node == temp.parent.left) {
                temp.parent.left = temp;
            } else {
                temp.parent.right = temp;
            }
        } else {
            root = temp;
        }
        
        return temp;
    }

}


package advanced_class_03;

/**
 * Not implemented by zuochengyun
 * 
 * AVL tree implementation.
 * 
 * In computer science, an AVL tree is a self-balancing binary search tree, and
 * it was the first such data structure to be invented.[1] In an AVL tree, the
 * heights of the two child subtrees of any node differ by at most one. Lookup,
 * insertion, and deletion all take O(log n) time in both the average and worst
 * cases, where n is the number of nodes in the tree prior to the operation.
 * Insertions and deletions may require the tree to be rebalanced by one or more
 * tree rotations.
 * 
 * @author Ignas Lelys
 * @created Jun 28, 2011
 * 
 */
public class AVLTree extends AbstractSelfBalancingBinarySearchTree {

    /**
     * @see trees.AbstractBinarySearchTree#insert(int)
     * 
     *      AVL tree insert method also balances tree if needed. Additional
     *      height parameter on node is used to track if one subtree is higher
     *      than other by more than one, if so AVL tree rotations is performed
     *      to regain balance of the tree.
     */
    @Override
    public Node insert(int element) {
        Node newNode = super.insert(element);
        rebalance((AVLNode)newNode);
        return newNode;
    }

    /**
     * @see trees.AbstractBinarySearchTree#delete(int)
     */
    @Override
    public Node delete(int element) {
        Node deleteNode = super.search(element);
        if (deleteNode != null) {
            Node successorNode = super.delete(deleteNode);
            if (successorNode != null) {
                // if replaced from getMinimum(deleteNode.right) then come back there and update heights
                AVLNode minimum = successorNode.right != null ? (AVLNode)getMinimum(successorNode.right) : (AVLNode)successorNode;
                recomputeHeight(minimum);
                rebalance((AVLNode)minimum);
            } else {
                recomputeHeight((AVLNode)deleteNode.parent);
                rebalance((AVLNode)deleteNode.parent);
            }
            return successorNode;
        }
        return null;
    }
    
    /**
     * @see trees.AbstractBinarySearchTree#createNode(int, trees.AbstractBinarySearchTree.Node, trees.AbstractBinarySearchTree.Node, trees.AbstractBinarySearchTree.Node)
     */
    @Override
    protected Node createNode(int value, Node parent, Node left, Node right) {
        return new AVLNode(value, parent, left, right);
    }

    /**
     * Go up from inserted node, and update height and balance informations if needed.
     * If some node balance reaches 2 or -2 that means that subtree must be rebalanced.
     * 
     * @param node Inserted Node.
     */
    private void rebalance(AVLNode node) {
        while (node != null) {
            
            Node parent = node.parent;
            
            int leftHeight = (node.left == null) ? -1 : ((AVLNode) node.left).height;
            int rightHeight = (node.right == null) ? -1 : ((AVLNode) node.right).height;
            int nodeBalance = rightHeight - leftHeight;
            // rebalance (-2 means left subtree outgrow, 2 means right subtree)
            if (nodeBalance == 2) {
                if (node.right.right != null) {
                    node = (AVLNode)avlRotateLeft(node);
                    break;
                } else {
                    node = (AVLNode)doubleRotateRightLeft(node);
                    break;
                }
            } else if (nodeBalance == -2) {
                if (node.left.left != null) {
                    node = (AVLNode)avlRotateRight(node);
                    break;
                } else {
                    node = (AVLNode)doubleRotateLeftRight(node);
                    break;
                }
            } else {
                updateHeight(node);
            }
            
            node = (AVLNode)parent;
        }
    }

    /**
     * Rotates to left side.
     */
    private Node avlRotateLeft(Node node) {
        Node temp = super.rotateLeft(node);
        
        updateHeight((AVLNode)temp.left);
        updateHeight((AVLNode)temp);
        return temp;
    }

    /**
     * Rotates to right side.
     */
    private Node avlRotateRight(Node node) {
        Node temp = super.rotateRight(node);

        updateHeight((AVLNode)temp.right);
        updateHeight((AVLNode)temp);
        return temp;
    }

    /**
     * Take right child and rotate it to the right side first and then rotate
     * node to the left side.
     */
    protected Node doubleRotateRightLeft(Node node) {
        node.right = avlRotateRight(node.right);
        return avlRotateLeft(node);
    }

    /**
     * Take right child and rotate it to the right side first and then rotate
     * node to the left side.
     */
    protected Node doubleRotateLeftRight(Node node) {
        node.left = avlRotateLeft(node.left);
        return avlRotateRight(node);
    }
    
    /**
     * Recomputes height information from the node and up for all of parents. It needs to be done after delete.
     */
    private void recomputeHeight(AVLNode node) {
       while (node != null) {
          node.height = maxHeight((AVLNode)node.left, (AVLNode)node.right) + 1;
          node = (AVLNode)node.parent;
       }
    }
    
    /**
     * Returns higher height of 2 nodes. 
     */
    private int maxHeight(AVLNode node1, AVLNode node2) {
        if (node1 != null && node2 != null) {
            return node1.height > node2.height ? node1.height : node2.height;
        } else if (node1 == null) {
            return node2 != null ? node2.height : -1;
        } else if (node2 == null) {
            return node1 != null ? node1.height : -1;
        }
        return -1;
    }

    /**
     * Updates height and balance of the node.
     * 
     * @param node Node for which height and balance must be updated.
     */
    private static final void updateHeight(AVLNode node) {
        int leftHeight = (node.left == null) ? -1 : ((AVLNode) node.left).height;
        int rightHeight = (node.right == null) ? -1 : ((AVLNode) node.right).height;
        node.height = 1 + Math.max(leftHeight, rightHeight);
    }

    /**
     * Node of AVL tree has height and balance additional properties. If balance
     * equals 2 (or -2) that node needs to be re balanced. (Height is height of
     * the subtree starting with this node, and balance is difference between
     * left and right nodes heights).
     * 
     * @author Ignas Lelys
     * @created Jun 30, 2011
     * 
     */
    protected static class AVLNode extends Node {
        public int height;

        public AVLNode(int value, Node parent, Node left, Node right) {
            super(value, parent, left, right);
        }
    }

}


package advanced_class_03;

public class Code_01_MorrisTraversal {

	
	
	public static void process(Node head) {
		if(head == null) {
			return;
		}
		
		// 1
		//System.out.println(head.value);
		
		
		process(head.left);
		
		// 2
		//System.out.println(head.value);
		
		
		process(head.right);
		
		// 3
		//System.out.println(head.value);
	}
	
	
	public static class Node {
		public int value;
		Node left;
		Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static void morrisIn(Node head) {
		if (head == null) {
			return;
		}
		Node cur1 = head;
		Node cur2 = null;
		while (cur1 != null) {
			cur2 = cur1.left;
			if (cur2 != null) {
				while (cur2.right != null && cur2.right != cur1) {
					cur2 = cur2.right;
				}
				if (cur2.right == null) {
					cur2.right = cur1;
					cur1 = cur1.left;
					continue;
				} else {
					cur2.right = null;
				}
			}
			System.out.print(cur1.value + " ");
			cur1 = cur1.right;
		}
		System.out.println();
	}

	public static void morrisPre(Node head) {
		if (head == null) {
			return;
		}
		Node cur1 = head;
		Node cur2 = null;
		while (cur1 != null) {
			cur2 = cur1.left;
			if (cur2 != null) {
				while (cur2.right != null && cur2.right != cur1) {
					cur2 = cur2.right;
				}
				if (cur2.right == null) {
					cur2.right = cur1;
					System.out.print(cur1.value + " ");
					cur1 = cur1.left;
					continue;
				} else {
					cur2.right = null;
				}
			} else {
				System.out.print(cur1.value + " ");
			}
			cur1 = cur1.right;
		}
		System.out.println();
	}

	public static void morrisPos(Node head) {
		if (head == null) {
			return;
		}
		Node cur1 = head;
		Node cur2 = null;
		while (cur1 != null) {
			cur2 = cur1.left;
			if (cur2 != null) {
				while (cur2.right != null && cur2.right != cur1) {
					cur2 = cur2.right;
				}
				if (cur2.right == null) {
					cur2.right = cur1;
					cur1 = cur1.left;
					continue;
				} else {
					cur2.right = null;
					printEdge(cur1.left);
				}
			}
			cur1 = cur1.right;
		}
		printEdge(head);
		System.out.println();
	}

	public static void printEdge(Node head) {
		Node tail = reverseEdge(head);
		Node cur = tail;
		while (cur != null) {
			System.out.print(cur.value + " ");
			cur = cur.right;
		}
		reverseEdge(tail);
	}

	public static Node reverseEdge(Node from) {
		Node pre = null;
		Node next = null;
		while (from != null) {
			next = from.right;
			from.right = pre;
			pre = from;
			from = next;
		}
		return pre;
	}

	// for test -- print tree
	public static void printTree(Node head) {
		System.out.println("Binary Tree:");
		printInOrder(head, 0, "H", 17);
		System.out.println();
	}

	public static void printInOrder(Node head, int height, String to, int len) {
		if (head == null) {
			return;
		}
		printInOrder(head.right, height + 1, "v", len);
		String val = to + head.value + to;
		int lenM = val.length();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = getSpace(lenL) + val + getSpace(lenR);
		System.out.println(getSpace(height * len) + val);
		printInOrder(head.left, height + 1, "^", len);
	}

	public static String getSpace(int num) {
		String space = " ";
		StringBuffer buf = new StringBuffer("");
		for (int i = 0; i < num; i++) {
			buf.append(space);
		}
		return buf.toString();
	}

	public static void main(String[] args) {
		Node head = new Node(4);
		head.left = new Node(2);
		head.right = new Node(6);
		head.left.left = new Node(1);
		head.left.right = new Node(3);
		head.right.left = new Node(5);
		head.right.right = new Node(7);
		printTree(head);
		morrisIn(head);
		morrisPre(head);
		morrisPos(head);
		printTree(head);

	}

}


package advanced_class_03;

import java.util.ArrayList;
import java.util.Iterator;

public class Code_02_SkipList {

	public static class SkipListNode {
		public Integer value;
		public ArrayList<SkipListNode> nextNodes;

		public SkipListNode(Integer value) {
			this.value = value;
			nextNodes = new ArrayList<SkipListNode>();
		}
	}

	public static class SkipListIterator implements Iterator<Integer> {
		SkipList list;
		SkipListNode current;

		public SkipListIterator(SkipList list) {
			this.list = list;
			this.current = list.getHead();
		}

		public boolean hasNext() {
			return current.nextNodes.get(0) != null;
		}

		public Integer next() {
			current = current.nextNodes.get(0);
			return current.value;
		}
	}

	public static class SkipList {
		private SkipListNode head;
		private int maxLevel;
		private int size;
		private static final double PROBABILITY = 0.5;

		public SkipList() {
			size = 0;
			maxLevel = 0;
			head = new SkipListNode(null);
			head.nextNodes.add(null);
		}

		public SkipListNode getHead() {
			return head;
		}

		public void add(Integer newValue) {
			if (!contains(newValue)) {
				size++;
				int level = 0;
				while (Math.random() < PROBABILITY) {
					level++;
				}
				while (level > maxLevel) {
					head.nextNodes.add(null);
					maxLevel++;
				}
				SkipListNode newNode = new SkipListNode(newValue);
				SkipListNode current = head;
				do {
					current = findNext(newValue, current, level);
					newNode.nextNodes.add(0, current.nextNodes.get(level));
					current.nextNodes.set(level, newNode);
				} while (level-- > 0);
			}
		}

		public void delete(Integer deleteValue) {
			if (contains(deleteValue)) {
				SkipListNode deleteNode = find(deleteValue);
				size--;
				int level = maxLevel;
				SkipListNode current = head;
				do {
					current = findNext(deleteNode.value, current, level);
					if (deleteNode.nextNodes.size() > level) {
						current.nextNodes.set(level, deleteNode.nextNodes.get(level));
					}
				} while (level-- > 0);
			}
		}

		// Returns the skiplist node with greatest value <= e
		private SkipListNode find(Integer e) {
			return find(e, head, maxLevel);
		}

		// Returns the skiplist node with greatest value <= e
		// Starts at node start and level
		private SkipListNode find(Integer e, SkipListNode current, int level) {
			do {
				current = findNext(e, current, level);
			} while (level-- > 0);
			return current;
		}

		// Returns the node at a given level with highest value less than e
		private SkipListNode findNext(Integer e, SkipListNode current, int level) {
			SkipListNode next = current.nextNodes.get(level);
			while (next != null) {
				Integer value = next.value;
				if (lessThan(e, value)) { // e < value
					break;
				}
				current = next;
				next = current.nextNodes.get(level);
			}
			return current;
		}

		public int size() {
			return size;
		}

		public boolean contains(Integer value) {
			SkipListNode node = find(value);
			return node != null && node.value != null && equalTo(node.value, value);
		}

		public Iterator<Integer> iterator() {
			return new SkipListIterator(this);
		}

		/******************************************************************************
		 * Utility Functions *
		 ******************************************************************************/

		private boolean lessThan(Integer a, Integer b) {
			return a.compareTo(b) < 0;
		}

		private boolean equalTo(Integer a, Integer b) {
			return a.compareTo(b) == 0;
		}

	}

	public static void main(String[] args) {

	}

}


package advanced_class_03;

/**
 * Not implemented by zuochengyun
 * 
 * Red-Black tree implementation. From Introduction to Algorithms 3rd edition.
 * 
 * @author Ignas Lelys
 * @created May 6, 2011
 * 
 */
public class RedBlackTree extends AbstractSelfBalancingBinarySearchTree {

    protected enum ColorEnum {
        RED,
        BLACK
    };

    protected static final RedBlackNode nilNode = new RedBlackNode(null, null, null, null, ColorEnum.BLACK);

    /**
     * @see trees.AbstractBinarySearchTree#insert(int)
     */
    @Override
    public Node insert(int element) {
        Node newNode = super.insert(element);
        newNode.left = nilNode;
        newNode.right = nilNode;
        root.parent = nilNode;
        insertRBFixup((RedBlackNode) newNode);
        return newNode;
    }
    
    /**
     * Slightly modified delete routine for red-black tree.
     * 
     * {@inheritDoc}
     */
    @Override
    protected Node delete(Node deleteNode) {
        Node replaceNode = null; // track node that replaces removedOrMovedNode
        if (deleteNode != null && deleteNode != nilNode) {
            Node removedOrMovedNode = deleteNode; // same as deleteNode if it has only one child, and otherwise it replaces deleteNode
            ColorEnum removedOrMovedNodeColor = ((RedBlackNode)removedOrMovedNode).color;
        
            if (deleteNode.left == nilNode) {
                replaceNode = deleteNode.right;
                rbTreeTransplant(deleteNode, deleteNode.right);
            } else if (deleteNode.right == nilNode) {
                replaceNode = deleteNode.left;
                rbTreeTransplant(deleteNode, deleteNode.left);
            } else {
                removedOrMovedNode = getMinimum(deleteNode.right);
                removedOrMovedNodeColor = ((RedBlackNode)removedOrMovedNode).color;
                replaceNode = removedOrMovedNode.right;
                if (removedOrMovedNode.parent == deleteNode) {
                    replaceNode.parent = removedOrMovedNode;
                } else {
                    rbTreeTransplant(removedOrMovedNode, removedOrMovedNode.right);
                    removedOrMovedNode.right = deleteNode.right;
                    removedOrMovedNode.right.parent = removedOrMovedNode;
                }
                rbTreeTransplant(deleteNode, removedOrMovedNode);
                removedOrMovedNode.left = deleteNode.left;
                removedOrMovedNode.left.parent = removedOrMovedNode;
                ((RedBlackNode)removedOrMovedNode).color = ((RedBlackNode)deleteNode).color;
            }
            
            size--;
            if (removedOrMovedNodeColor == ColorEnum.BLACK) {
                deleteRBFixup((RedBlackNode)replaceNode);
            }
        }
        
        return replaceNode;
    }
    
    /**
     * @see trees.AbstractBinarySearchTree#createNode(int, trees.AbstractBinarySearchTree.Node, trees.AbstractBinarySearchTree.Node, trees.AbstractBinarySearchTree.Node)
     */
    @Override
    protected Node createNode(int value, Node parent, Node left, Node right) {
        return new RedBlackNode(value, parent, left, right, ColorEnum.RED);
    }
    
    /**
     * {@inheritDoc}
     */
    @Override
    protected Node getMinimum(Node node) {
        while (node.left != nilNode) {
            node = node.left;
        }
        return node;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected Node getMaximum(Node node) {
        while (node.right != nilNode) {
            node = node.right;
        }
        return node;
    }
    
    /**
     * {@inheritDoc}
     */
    @Override
    protected Node rotateLeft(Node node) {
        Node temp = node.right;
        temp.parent = node.parent;
        
        node.right = temp.left;
        if (node.right != nilNode) {
            node.right.parent = node;
        }

        temp.left = node;
        node.parent = temp;

        // temp took over node's place so now its parent should point to temp
        if (temp.parent != nilNode) {
            if (node == temp.parent.left) {
                temp.parent.left = temp;
            } else {
                temp.parent.right = temp;
            }
        } else {
            root = temp;
        }
        
        return temp;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected Node rotateRight(Node node) {
        Node temp = node.left;
        temp.parent = node.parent;

        node.left = temp.right;
        if (node.left != nilNode) {
            node.left.parent = node;
        }

        temp.right = node;
        node.parent = temp;

        // temp took over node's place so now its parent should point to temp
        if (temp.parent != nilNode) {
            if (node == temp.parent.left) {
                temp.parent.left = temp;
            } else {
                temp.parent.right = temp;
            }
        } else {
            root = temp;
        }
        
        return temp;
    }

    
    /**
     * Similar to original transplant() method in BST but uses nilNode instead of null.
     */
    private Node rbTreeTransplant(Node nodeToReplace, Node newNode) {
        if (nodeToReplace.parent == nilNode) {
            this.root = newNode;
        } else if (nodeToReplace == nodeToReplace.parent.left) {
            nodeToReplace.parent.left = newNode;
        } else {
            nodeToReplace.parent.right = newNode;
        }
        newNode.parent = nodeToReplace.parent;
        return newNode;
    }
    
    /**
     * Restores Red-Black tree properties after delete if needed.
     */
    private void deleteRBFixup(RedBlackNode x) {
        while (x != root && isBlack(x)) {
            
            if (x == x.parent.left) {
                RedBlackNode w = (RedBlackNode)x.parent.right;
                if (isRed(w)) { // case 1 - sibling is red
                    w.color = ColorEnum.BLACK;
                    ((RedBlackNode)x.parent).color = ColorEnum.RED;
                    rotateLeft(x.parent);
                    w = (RedBlackNode)x.parent.right; // converted to case 2, 3 or 4
                }
                // case 2 sibling is black and both of its children are black
                if (isBlack(w.left) && isBlack(w.right)) {
                    w.color = ColorEnum.RED;
                    x = (RedBlackNode)x.parent;
                } else if (w != nilNode) {
                    if (isBlack(w.right)) { // case 3 sibling is black and its left child is red and right child is black
                        ((RedBlackNode)w.left).color = ColorEnum.BLACK;
                        w.color = ColorEnum.RED;
                        rotateRight(w);
                        w = (RedBlackNode)x.parent.right;
                    }
                    w.color = ((RedBlackNode)x.parent).color; // case 4 sibling is black and right child is red
                    ((RedBlackNode)x.parent).color = ColorEnum.BLACK;
                    ((RedBlackNode)w.right).color = ColorEnum.BLACK;
                    rotateLeft(x.parent);
                    x = (RedBlackNode)root;
                } else {
                    x.color = ColorEnum.BLACK;
                    x = (RedBlackNode)x.parent;
                }
            } else {
                RedBlackNode w = (RedBlackNode)x.parent.left;
                if (isRed(w)) { // case 1 - sibling is red
                    w.color = ColorEnum.BLACK;
                    ((RedBlackNode)x.parent).color = ColorEnum.RED;
                    rotateRight(x.parent);
                    w = (RedBlackNode)x.parent.left; // converted to case 2, 3 or 4
                }
                // case 2 sibling is black and both of its children are black
                if (isBlack(w.left) && isBlack(w.right)) {
                    w.color = ColorEnum.RED;
                    x = (RedBlackNode)x.parent;
                } else if (w != nilNode) {
                    if (isBlack(w.left)) { // case 3 sibling is black and its right child is red and left child is black
                        ((RedBlackNode)w.right).color = ColorEnum.BLACK;
                        w.color = ColorEnum.RED;
                        rotateLeft(w);
                        w = (RedBlackNode)x.parent.left;
                    }
                    w.color = ((RedBlackNode)x.parent).color; // case 4 sibling is black and left child is red
                    ((RedBlackNode)x.parent).color = ColorEnum.BLACK;
                    ((RedBlackNode)w.left).color = ColorEnum.BLACK;
                    rotateRight(x.parent);
                    x = (RedBlackNode)root;
                } else {
                    x.color = ColorEnum.BLACK;
                    x = (RedBlackNode)x.parent;
                }
            }
            
        }
    }
    
    private boolean isBlack(Node node) {
        return node != null ? ((RedBlackNode)node).color == ColorEnum.BLACK : false;
    }
    
    private boolean isRed(Node node) {
        return node != null ? ((RedBlackNode)node).color == ColorEnum.RED : false;
    }

    /**
     * Restores Red-Black tree properties after insert if needed. Insert can
     * break only 2 properties: root is red or if node is red then children must
     * be black.
     */
    private void insertRBFixup(RedBlackNode currentNode) {
        // current node is always RED, so if its parent is red it breaks
        // Red-Black property, otherwise no fixup needed and loop can terminate
        while (currentNode.parent != root && ((RedBlackNode) currentNode.parent).color == ColorEnum.RED) {
            RedBlackNode parent = (RedBlackNode) currentNode.parent;
            RedBlackNode grandParent = (RedBlackNode) parent.parent;
            if (parent == grandParent.left) {
                RedBlackNode uncle = (RedBlackNode) grandParent.right;
                // case1 - uncle and parent are both red
                // re color both of them to black
                if (((RedBlackNode) uncle).color == ColorEnum.RED) {
                    parent.color = ColorEnum.BLACK;
                    uncle.color = ColorEnum.BLACK;
                    grandParent.color = ColorEnum.RED;
                    // grandparent was recolored to red, so in next iteration we
                    // check if it does not break Red-Black property
                    currentNode = grandParent;
                } 
                // case 2/3 uncle is black - then we perform rotations
                else {
                    if (currentNode == parent.right) { // case 2, first rotate left
                        currentNode = parent;
                        rotateLeft(currentNode);
                    }
                    // do not use parent
                    parent.color = ColorEnum.BLACK; // case 3
                    grandParent.color = ColorEnum.RED;
                    rotateRight(grandParent);
                }
            } else if (parent == grandParent.right) {
                RedBlackNode uncle = (RedBlackNode) grandParent.left;
                // case1 - uncle and parent are both red
                // re color both of them to black
                if (((RedBlackNode) uncle).color == ColorEnum.RED) {
                    parent.color = ColorEnum.BLACK;
                    uncle.color = ColorEnum.BLACK;
                    grandParent.color = ColorEnum.RED;
                    // grandparent was recolored to red, so in next iteration we
                    // check if it does not break Red-Black property
                    currentNode = grandParent;
                }
                // case 2/3 uncle is black - then we perform rotations
                else {
                    if (currentNode == parent.left) { // case 2, first rotate right
                        currentNode = parent;
                        rotateRight(currentNode);
                    }
                    // do not use parent
                    parent.color = ColorEnum.BLACK; // case 3
                    grandParent.color = ColorEnum.RED;
                    rotateLeft(grandParent);
                }
            }

        }
        // ensure root is black in case it was colored red in fixup
        ((RedBlackNode) root).color = ColorEnum.BLACK;
    }

    protected static class RedBlackNode extends Node {
        public ColorEnum color;

        public RedBlackNode(Integer value, Node parent, Node left, Node right, ColorEnum color) {
            super(value, parent, left, right);
            this.color = color;
        }
    }

}




41
package advanced_class_04;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map.Entry;
import java.util.TreeMap;

public class Code_01_Building_Outline {

	public static class Node {
		public boolean isUp;
		public int posi;
		public int h;

		public Node(boolean bORe, int position, int height) {
			isUp = bORe;
			posi = position;
			h = height;
		}
	}

	public static class NodeComparator implements Comparator<Node> {
		@Override
		public int compare(Node o1, Node o2) {
			if (o1.posi != o2.posi) {				
				return o1.posi - o2.posi;
			}
			if (o1.isUp != o2.isUp) {
				return o1.isUp ? -1 : 1;
			}
			return 0;
		}
	}

	public static List<List<Integer>> buildingOutline(int[][] buildings) {
		Node[] nodes = new Node[buildings.length * 2];
		for (int i = 0; i < buildings.length; i++) {
			nodes[i * 2] = new Node(true, buildings[i][0], buildings[i][2]);
			nodes[i * 2 + 1] = new Node(false, buildings[i][1], buildings[i][2]);
		}
		Arrays.sort(nodes, new NodeComparator());
		TreeMap<Integer, Integer> htMap = new TreeMap<>();
		TreeMap<Integer, Integer> pmMap = new TreeMap<>();
		for (int i = 0; i < nodes.length; i++) {
			if (nodes[i].isUp) {
				if (!htMap.containsKey(nodes[i].h)) {
					htMap.put(nodes[i].h, 1);
				} else {
					htMap.put(nodes[i].h, htMap.get(nodes[i].h) + 1);
				}
			} else {
				if (htMap.containsKey(nodes[i].h)) {
					if (htMap.get(nodes[i].h) == 1) {
						htMap.remove(nodes[i].h);
					} else {
						htMap.put(nodes[i].h, htMap.get(nodes[i].h) - 1);
					}
				}
			}
			if (htMap.isEmpty()) {
				pmMap.put(nodes[i].posi, 0);
			} else {
				pmMap.put(nodes[i].posi, htMap.lastKey());
			}
		}
		List<List<Integer>> res = new ArrayList<>();
		int start = 0;
		int height = 0;
		for (Entry<Integer, Integer> entry : pmMap.entrySet()) {
			int curPosition = entry.getKey();
			int curMaxHeight = entry.getValue();
			if (height != curMaxHeight) {
				if (height != 0) {
					List<Integer> newRecord = new ArrayList<Integer>();
					newRecord.add(start);
					newRecord.add(curPosition);
					newRecord.add(height);
					res.add(newRecord);
				}
				start = curPosition;
				height = curMaxHeight;
			}
		}
		return res;
	}

}

42
package advanced_class_04;

import java.util.HashMap;

public class Code_02_LRU {

	public static class Node<V> {
		public V value;
		public Node<V> last;
		public Node<V> next;

		public Node(V value) {
			this.value = value;
		}
	}

	public static class NodeDoubleLinkedList<V> {
		private Node<V> head;
		private Node<V> tail;

		public NodeDoubleLinkedList() {
			this.head = null;
			this.tail = null;
		}

		public void addNode(Node<V> newNode) {
			if (newNode == null) {
				return;
			}
			if (this.head == null) {
				this.head = newNode;
				this.tail = newNode;
			} else {
				this.tail.next = newNode;
				newNode.last = this.tail;
				this.tail = newNode;
			}
		}

		public void moveNodeToTail(Node<V> node) {
			if (this.tail == node) {
				return;
			}
			if (this.head == node) {
				this.head = node.next;
				this.head.last = null;
			} else {
				node.last.next = node.next;
				node.next.last = node.last;
			}
			node.last = this.tail;
			node.next = null;
			this.tail.next = node;
			this.tail = node;
		}

		public Node<V> removeHead() {
			if (this.head == null) {
				return null;
			}
			Node<V> res = this.head;
			if (this.head == this.tail) {
				this.head = null;
				this.tail = null;
			} else {
				this.head = res.next;
				res.next = null;
				this.head.last = null;
			}
			return res;
		}

	}

	public static class MyCache<K, V> {
		private HashMap<K, Node<V>> keyNodeMap;
		private HashMap<Node<V>, K> nodeKeyMap;
		private NodeDoubleLinkedList<V> nodeList;
		private int capacity;

		public MyCache(int capacity) {
			if (capacity < 1) {
				throw new RuntimeException("should be more than 0.");
			}
			this.keyNodeMap = new HashMap<K, Node<V>>();
			this.nodeKeyMap = new HashMap<Node<V>, K>();
			this.nodeList = new NodeDoubleLinkedList<V>();
			this.capacity = capacity;
		}

		public V get(K key) {
			if (this.keyNodeMap.containsKey(key)) {
				Node<V> res = this.keyNodeMap.get(key);
				this.nodeList.moveNodeToTail(res);
				return res.value;
			}
			return null;
		}

		public void set(K key, V value) {
			if (this.keyNodeMap.containsKey(key)) {
				Node<V> node = this.keyNodeMap.get(key);
				node.value = value;
				this.nodeList.moveNodeToTail(node);
			} else {
				Node<V> newNode = new Node<V>(value);
				this.keyNodeMap.put(key, newNode);
				this.nodeKeyMap.put(newNode, key);
				this.nodeList.addNode(newNode);
				if (this.keyNodeMap.size() == this.capacity + 1) {
					this.removeMostUnusedCache();
				}
			}
		}

		private void removeMostUnusedCache() {
			Node<V> removeNode = this.nodeList.removeHead();
			K removeKey = this.nodeKeyMap.get(removeNode);
			this.nodeKeyMap.remove(removeNode);
			this.keyNodeMap.remove(removeKey);
		}

	}

	public static void main(String[] args) {
		MyCache<String, Integer> testCache = new MyCache<String, Integer>(3);
		testCache.set("A", 1);
		testCache.set("B", 2);
		testCache.set("C", 3);
		System.out.println(testCache.get("B"));
		System.out.println(testCache.get("A"));
		testCache.set("D", 4);
		System.out.println(testCache.get("D"));
		System.out.println(testCache.get("C"));

	}

}


43
package advanced_class_04;

import java.util.HashMap;

public class Code_03_LFU {

	public static class Node {
		public Integer key;
		public Integer value;
		public Integer times;
		public Node up;
		public Node down;

		public Node(int key, int value, int times) {
			this.key = key;
			this.value = value;
			this.times = times;
		}
	}

	public static class LFUCache {

		public static class NodeList {
			public Node head;
			public Node tail;
			public NodeList last;
			public NodeList next;

			public NodeList(Node node) {
				head = node;
				tail = node;
			}

			public void addNodeFromHead(Node newHead) {
				newHead.down = head;
				head.up = newHead;
				head = newHead;
			}

			public boolean isEmpty() {
				return head == null;
			}

			public void deleteNode(Node node) {
				if (head == tail) {
					head = null;
					tail = null;
				} else {
					if (node == head) {
						head = node.down;
						head.up = null;
					} else if (node == tail) {
						tail = node.up;
						tail.down = null;
					} else {
						node.up.down = node.down;
						node.down.up = node.up;
					}
				}
				node.up = null;
				node.down = null;
			}
		}

		private int capacity;
		private int size;
		private HashMap<Integer, Node> records;
		private HashMap<Node, NodeList> heads;
		private NodeList headList;

		public LFUCache(int capacity) {
			this.capacity = capacity;
			this.size = 0;
			this.records = new HashMap<>();
			this.heads = new HashMap<>();
			headList = null;
		}

		public void set(int key, int value) {
			if (records.containsKey(key)) {
				Node node = records.get(key);
				node.value = value;
				node.times++;
				NodeList curNodeList = heads.get(node);
				move(node, curNodeList);
			} else {
				if (size == capacity) {
					Node node = headList.tail;
					headList.deleteNode(node);
					modifyHeadList(headList);
					records.remove(node.key);
					heads.remove(node);
					size--;
				}
				Node node = new Node(key, value, 1);
				if (headList == null) {
					headList = new NodeList(node);
				} else {
					if (headList.head.times.equals(node.times)) {
						headList.addNodeFromHead(node);
					} else {
						NodeList newList = new NodeList(node);
						newList.next = headList;
						headList.last = newList;
						headList = newList;
					}
				}
				records.put(key, node);
				heads.put(node, headList);
				size++;
			}
		}

		private void move(Node node, NodeList oldNodeList) {
			oldNodeList.deleteNode(node);
			NodeList preList = modifyHeadList(oldNodeList) ? oldNodeList.last
					: oldNodeList;
			NodeList nextList = oldNodeList.next;
			if (nextList == null) {
				NodeList newList = new NodeList(node);
				if (preList != null) {
					preList.next = newList;
				}
				newList.last = preList;
				if (headList == null) {
					headList = newList;
				}
				heads.put(node, newList);
			} else {
				if (nextList.head.times.equals(node.times)) {
					nextList.addNodeFromHead(node);
					heads.put(node, nextList);
				} else {
					NodeList newList = new NodeList(node);
					if (preList != null) {
						preList.next = newList;
					}
					newList.last = preList;
					newList.next = nextList;
					nextList.last = newList;
					if (headList == nextList) {
						headList = newList;
					}
					heads.put(node, newList);
				}
			}
		}

		// return whether delete this head
		private boolean modifyHeadList(NodeList nodeList) {
			if (nodeList.isEmpty()) {
				if (headList == nodeList) {
					headList = nodeList.next;
					if (headList != null) {
						headList.last = null;
					}
				} else {
					nodeList.last.next = nodeList.next;
					if (nodeList.next != null) {
						nodeList.next.last = nodeList.last;
					}
				}
				return true;
			}
			return false;
		}

		public int get(int key) {
			if (!records.containsKey(key)) {
				return -1;
			}
			Node node = records.get(key);
			node.times++;
			NodeList curNodeList = heads.get(node);
			move(node, curNodeList);
			return node.value;
		}

	}
}

44
package advanced_class_04;

public class Code_04_BiggestSubBSTInTree {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static Node biggestSubBST(Node head) {
		int[] record = new int[3]; // 0->size, 1->min, 2->max
		return posOrder(head, record);
	}
	
	public static class ReturnType{
		public int size;
		public Node head;
		public int min;
		public int max;
		
		public ReturnType(int a, Node b,int c,int d) {
			this.size =a;
			this.head = b;
			this.min = c;
			this.max = d;
		}
	}
	
	public static ReturnType process(Node head) {
		if(head == null) {
			return new ReturnType(0,null,Integer.MAX_VALUE, Integer.MIN_VALUE);
		}
		Node left = head.left;
		ReturnType leftSubTressInfo = process(left);
		Node right = head.right;
		ReturnType rightSubTressInfo = process(right);
		
		int includeItSelf = 0;
		if(leftSubTressInfo.head == left 
				&&rightSubTressInfo.head == right
				&& head.value > leftSubTressInfo.max
				&& head.value < rightSubTressInfo.min
				) {
			includeItSelf = leftSubTressInfo.size + 1 + rightSubTressInfo.size;
		}
		int p1 = leftSubTressInfo.size;
		int p2 = rightSubTressInfo.size;
		int maxSize = Math.max(Math.max(p1, p2), includeItSelf);
		
		Node maxHead = p1 > p2 ? leftSubTressInfo.head : rightSubTressInfo.head;
		if(maxSize == includeItSelf) {
			maxHead = head;
		}
		
		return new ReturnType(maxSize,
				maxHead, 
				Math.min(Math.min(leftSubTressInfo.min,rightSubTressInfo.min),head.value),
				Math.max(Math.max(leftSubTressInfo.max,rightSubTressInfo.max),head.value));	
	}
	
	
	

	public static Node posOrder(Node head, int[] record) {
		if (head == null) {
			record[0] = 0;
			record[1] = Integer.MAX_VALUE;
			record[2] = Integer.MIN_VALUE;
			return null;
		}
		int value = head.value;
		Node left = head.left;
		Node right = head.right;
		Node lBST = posOrder(left, record);
		int lSize = record[0];
		int lMin = record[1];
		int lMax = record[2];
		Node rBST = posOrder(right, record);
		int rSize = record[0];
		int rMin = record[1];
		int rMax = record[2];
		record[1] = Math.min(rMin, Math.min(lMin, value)); // lmin, value, rmin -> min 
		record[2] =  Math.max(lMax, Math.max(rMax, value)); // lmax, value, rmax -> max
		if (left == lBST && right == rBST && lMax < value && value < rMin) {
			record[0] = lSize + rSize + 1;
			return head;
		}
		record[0] = Math.max(lSize, rSize);
		return lSize > rSize ? lBST : rBST;
	}

	// for test -- print tree
	public static void printTree(Node head) {
		System.out.println("Binary Tree:");
		printInOrder(head, 0, "H", 17);
		System.out.println();
	}

	public static void printInOrder(Node head, int height, String to, int len) {
		if (head == null) {
			return;
		}
		printInOrder(head.right, height + 1, "v", len);
		String val = to + head.value + to;
		int lenM = val.length();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = getSpace(lenL) + val + getSpace(lenR);
		System.out.println(getSpace(height * len) + val);
		printInOrder(head.left, height + 1, "^", len);
	}

	public static String getSpace(int num) {
		String space = " ";
		StringBuffer buf = new StringBuffer("");
		for (int i = 0; i < num; i++) {
			buf.append(space);
		}
		return buf.toString();
	}

	public static void main(String[] args) {

		Node head = new Node(6);
		head.left = new Node(1);
		head.left.left = new Node(0);
		head.left.right = new Node(3);
		head.right = new Node(12);
		head.right.left = new Node(10);
		head.right.left.left = new Node(4);
		head.right.left.left.left = new Node(2);
		head.right.left.left.right = new Node(5);
		head.right.left.right = new Node(14);
		head.right.left.right.left = new Node(11);
		head.right.left.right.right = new Node(15);
		head.right.right = new Node(13);
		head.right.right.left = new Node(20);
		head.right.right.right = new Node(16);

		printTree(head);
		Node bst = biggestSubBST(head);
		printTree(bst);

	}

}


45
package advanced_class_04;

import java.util.HashMap;

public class Code_05_LongestSumSubArrayLength {

	public static int maxLength(int[] arr, int k) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		map.put(0, -1); // important
		int len = 0;
		int sum = 0;
		for (int i = 0; i < arr.length; i++) {
			sum += arr[i];
			if (map.containsKey(sum - k)) {
				len = Math.max(i - map.get(sum - k), len);
			}
			if (!map.containsKey(sum)) {
				map.put(sum, i);
			}
		}
		return len;
	}

	public static int[] generateArray(int size) {
		int[] result = new int[size];
		for (int i = 0; i != size; i++) {
			result[i] = (int) (Math.random() * 11) - 5;
		}
		return result;
	}

	public static void printArray(int[] arr) {
		for (int i = 0; i != arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		int[] arr = generateArray(20);
		printArray(arr);
		System.out.println(maxLength(arr, 10));

	}

}


46
package advanced_class_04;

import java.util.HashMap;

public class Code_06_Most_EOR {

	public static int mostEOR(int[] arr) {
		int ans = 0;
		int xor = 0;
		int[] mosts = new int[arr.length];
		HashMap<Integer, Integer> map = new HashMap<>();
		map.put(0, -1);
		for (int i = 0; i < arr.length; i++) {
			xor ^= arr[i];
			if (map.containsKey(xor)) {
				int pre = map.get(xor);
				mosts[i] = pre == -1 ? 1 : (mosts[pre] + 1);
			}
			if (i > 0) {
				mosts[i] = Math.max(mosts[i - 1], mosts[i]);
			}
			map.put(xor, i);
			ans = Math.max(ans, mosts[i]);
		}
		return ans;
	}

	// for test
	public static int comparator(int[] arr) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int[] eors = new int[arr.length];
		int eor = 0;
		for (int i = 0; i < arr.length; i++) {
			eor ^= arr[i];
			eors[i] = eor;
		}
		int[] mosts = new int[arr.length];
		mosts[0] = arr[0] == 0 ? 1 : 0;
		for (int i = 1; i < arr.length; i++) {
			mosts[i] = eors[i] == 0 ? 1 : 0;
			for (int j = 0; j < i; j++) {
				if ((eors[i] ^ eors[j]) == 0) {
					mosts[i] = Math.max(mosts[i], mosts[j] + 1);
				}
			}
			mosts[i] = Math.max(mosts[i], mosts[i - 1]);
		}
		return mosts[mosts.length - 1];
	}

	// for test
	public static int[] generateRandomArray(int maxSize, int maxValue) {
		int[] arr = new int[(int) ((maxSize + 1) * Math.random())];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = (int) ((maxValue + 1) * Math.random());
		}
		return arr;
	}

	// for test
	public static void printArray(int[] arr) {
		if (arr == null) {
			return;
		}
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	// for test
	public static void main(String[] args) {
		int testTime = 500000;
		int maxSize = 300;
		int maxValue = 100;
		boolean succeed = true;
		for (int i = 0; i < testTime; i++) {
			int[] arr = generateRandomArray(maxSize, maxValue);
			int res = mostEOR(arr);
			int comp = comparator(arr);
			if (res != comp) {
				succeed = false;
				printArray(arr);
				System.out.println(res);
				System.out.println(comp);
				break;
			}
		}
		System.out.println(succeed ? "Nice!" : "Fucking fucked!");
	}

}


47
package advanced_class_04;

import java.util.LinkedList;

public class Code_07_ExpressionCompute {

	public static int getValue(String str) {
		return value(str.toCharArray(), 0)[0];
	}

	public static int[] value(char[] str, int i) {
		LinkedList<String> que = new LinkedList<String>();
		int pre = 0;
		int[] bra = null;
		while (i < str.length && str[i] != ')') {
			if (str[i] >= '0' && str[i] <= '9') {
				pre = pre * 10 + str[i++] - '0';
			} else if (str[i] != '(') {
				addNum(que, pre);
				que.addLast(String.valueOf(str[i++]));
				pre = 0;
			} else {
				bra = value(str, i + 1);
				pre = bra[0];
				i = bra[1] + 1;
			}
		}
		addNum(que, pre);
		return new int[] { getNum(que), i };
	}

	public static void addNum(LinkedList<String> que, int num) {
		if (!que.isEmpty()) {
			int cur = 0;
			String top = que.pollLast();
			if (top.equals("+") || top.equals("-")) {
				que.addLast(top);
			} else {
				cur = Integer.valueOf(que.pollLast());
				num = top.equals("*") ? (cur * num) : (cur / num);
			}
		}
		que.addLast(String.valueOf(num));
	}

	public static int getNum(LinkedList<String> que) {
		int res = 0;
		boolean add = true;
		String cur = null;
		int num = 0;
		while (!que.isEmpty()) {
			cur = que.pollFirst();
			if (cur.equals("+")) {
				add = true;
			} else if (cur.equals("-")) {
				add = false;
			} else {
				num = Integer.valueOf(cur);
				res += add ? num : (-num);
			}
		}
		return res;
	}

	public static void main(String[] args) {
		String exp = "48*((70-65)-43)+8*1";
		System.out.println(getValue(exp));

		exp = "4*(6+78)+53-9/2+45*8";
		System.out.println(getValue(exp));

		exp = "10-5*3";
		System.out.println(getValue(exp));

		exp = "-3*4";
		System.out.println(getValue(exp));

		exp = "3+1*4";
		System.out.println(getValue(exp));

	}

}




51
package advanced_class_05;

import java.util.LinkedList;
import java.util.Queue;

public class Code_01_IsBSTAndCBT {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static boolean isBST(Node head) {
		if (head == null) {
			return true;
		}
		boolean res = true;
		Node pre = null;
		Node cur1 = head;
		Node cur2 = null;
		while (cur1 != null) {
			cur2 = cur1.left;
			if (cur2 != null) {
				while (cur2.right != null && cur2.right != cur1) {
					cur2 = cur2.right;
				}
				if (cur2.right == null) {
					cur2.right = cur1;
					cur1 = cur1.left;
					continue;
				} else {
					cur2.right = null;
				}
			}
			if (pre != null && pre.value > cur1.value) {
				res = false;
			}
			pre = cur1;
			cur1 = cur1.right;
		}
		return res;
	}

	public static boolean isCBT(Node head) {
		if (head == null) {
			return true;
		}
		Queue<Node> queue = new LinkedList<Node>();
		boolean leaf = false;
		Node l = null;
		Node r = null;
		queue.offer(head);
		while (!queue.isEmpty()) {
			head = queue.poll();
			l = head.left;
			r = head.right;
			if ((leaf && (l != null || r != null)) || (l == null && r != null)) {
				return false;
			}
			if (l != null) {
				queue.offer(l);
			}
			if (r != null) {
				queue.offer(r);
			} else {
				leaf = true;
			}
		}
		return true;
	}

	// for test -- print tree
	public static void printTree(Node head) {
		System.out.println("Binary Tree:");
		printInOrder(head, 0, "H", 17);
		System.out.println();
	}

	public static void printInOrder(Node head, int height, String to, int len) {
		if (head == null) {
			return;
		}
		printInOrder(head.right, height + 1, "v", len);
		String val = to + head.value + to;
		int lenM = val.length();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = getSpace(lenL) + val + getSpace(lenR);
		System.out.println(getSpace(height * len) + val);
		printInOrder(head.left, height + 1, "^", len);
	}

	public static String getSpace(int num) {
		String space = " ";
		StringBuffer buf = new StringBuffer("");
		for (int i = 0; i < num; i++) {
			buf.append(space);
		}
		return buf.toString();
	}

	public static void main(String[] args) {
		Node head = new Node(4);
		head.left = new Node(2);
		head.right = new Node(6);
		head.left.left = new Node(1);
		head.left.right = new Node(3);
		head.right.left = new Node(5);

		printTree(head);
		System.out.println(isBST(head));
		System.out.println(isCBT(head));

	}
}


52
package advanced_class_05;

public class Code_02_IsBalancedTree {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static boolean isBalance(Node head) {
		boolean[] res = new boolean[1];
		res[0] = true;
		getHeight(head, 1, res);
		return res[0];
	}
	
	public static class ReturnType {
		public int level;
		public boolean isB;
		
		public ReturnType(int l, boolean is) {
			level = l;
			isB = is;
		}
	}
	
	// process(head, 1)
	
	public static ReturnType process(Node head, int level) {
		if (head == null) {
			return new ReturnType(level, true);
		}
		ReturnType leftSubTreeInfo = process(head.left, level + 1);
		if(!leftSubTreeInfo.isB) {
			return new ReturnType(level, false);
		}
		ReturnType rightSubTreeInfo = process(head.right, level + 1);
		if(!rightSubTreeInfo.isB) {
			return new ReturnType(level, false);
		}
		if (Math.abs(rightSubTreeInfo.level - leftSubTreeInfo.level) > 1) {
			return new ReturnType(level, false);
		}
		return new ReturnType(Math.max(leftSubTreeInfo.level, rightSubTreeInfo.level), true);
	}

	public static int getHeight(Node head, int level, boolean[] res) {
		if (head == null) {
			return level;
		}
		int lH = getHeight(head.left, level + 1, res);
		if (!res[0]) {
			return level;
		}
		int rH = getHeight(head.right, level + 1, res);
		if (!res[0]) {
			return level;
		}
		if (Math.abs(lH - rH) > 1) {
			res[0] = false;
		}
		return Math.max(lH, rH);
	}

	public static void main(String[] args) {
		Node head = new Node(1);
		head.left = new Node(2);
		head.right = new Node(3);
		head.left.left = new Node(4);
		head.left.right = new Node(5);
		head.right.left = new Node(6);
		head.right.right = new Node(7);

		System.out.println(isBalance(head));

	}

}


53
package advanced_class_05;

public class Code_03_MaxDistanceInTree {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static int maxDistance(Node head) {
		int[] record = new int[1];
		return posOrder(head, record);
	}
	
	public static class ReturnType{
		public int maxDistance;
		public int h;
		
		public ReturnType(int m, int h) {
			this.maxDistance = m;;
			this.h = h;
		}
	}
	
	public static ReturnType process(Node head) {
		if(head == null) {
			return new ReturnType(0,0);
		}
		ReturnType leftReturnType = process(head.left);
		ReturnType rightReturnType = process(head.right);
		int includeHeadDistance = leftReturnType.h + 1 + rightReturnType.h;
		int p1 = leftReturnType.maxDistance;
		int p2 = rightReturnType.maxDistance;
		int resultDistance = Math.max(Math.max(p1, p2), includeHeadDistance);
		int hitself  = Math.max(leftReturnType.h, leftReturnType.h) + 1;
		return new ReturnType(resultDistance, hitself);
	}

	public static int posOrder(Node head, int[] record) {
		if (head == null) {
			record[0] = 0;
			return 0;
		}
		int lMax = posOrder(head.left, record);
		int maxfromLeft = record[0];
		int rMax = posOrder(head.right, record);
		int maxFromRight = record[0];
		int curNodeMax = maxfromLeft + maxFromRight + 1;
		record[0] = Math.max(maxfromLeft, maxFromRight) + 1;
		return Math.max(Math.max(lMax, rMax), curNodeMax);
	}

	public static void main(String[] args) {
		Node head1 = new Node(1);
		head1.left = new Node(2);
		head1.right = new Node(3);
		head1.left.left = new Node(4);
		head1.left.right = new Node(5);
		head1.right.left = new Node(6);
		head1.right.right = new Node(7);
		head1.left.left.left = new Node(8);
		head1.right.left.right = new Node(9);
		System.out.println(maxDistance(head1));

		Node head2 = new Node(1);
		head2.left = new Node(2);
		head2.right = new Node(3);
		head2.right.left = new Node(4);
		head2.right.right = new Node(5);
		head2.right.left.left = new Node(6);
		head2.right.right.right = new Node(7);
		head2.right.left.left.left = new Node(8);
		head2.right.right.right.right = new Node(9);
		System.out.println(maxDistance(head2));

	}

}


54
package advanced_class_05;

public class Code_04_MaxHappy {

	public static int maxHappy(int[][] matrix) {
		int[][] dp = new int[matrix.length][2];
		boolean[] visited = new boolean[matrix.length];
		int root = 0;
		for (int i = 0; i < matrix.length; i++) {
			if (i == matrix[i][0]) {
				root = i;
			}
		}
		process(matrix, dp, visited, root);
		return Math.max(dp[root][0], dp[root][1]);
	}

	public static void process(int[][] matrix, int[][] dp, boolean[] visited, int root) {
		visited[root] = true;
		dp[root][1] = matrix[root][1];
		for (int i = 0; i < matrix.length; i++) {
			if (matrix[i][0] == root && !visited[i]) {
				process(matrix, dp, visited, i);
				dp[root][1] += dp[i][0];
				dp[root][0] += Math.max(dp[i][1], dp[i][0]);
			}
		}
	}

	public static void main(String[] args) {
		int[][] matrix = { { 1, 8 }, { 1, 9 }, { 1, 10 } };
		System.out.println(maxHappy(matrix));
	}
}


55
package advanced_class_05;

public class Code_05_Max_EOR {

	public static class Node {
		public Node[] nexts = new Node[2];
	}

	public static class NumTrie {
		public Node head = new Node();

		public void add(int num) {
			Node cur = head;
			for (int move = 31; move >= 0; move--) {
				int path = ((num >> move) & 1);
				cur.nexts[path] = cur.nexts[path] == null ? new Node() : cur.nexts[path];
				cur = cur.nexts[path];
			}
		}

		public int maxXor(int num) {
			Node cur = head;
			int res = 0;
			for (int move = 31; move >= 0; move--) {
				int path = (num >> move) & 1;
				int best = move == 31 ? path : (path ^ 1);
				best = cur.nexts[best] != null ? best : (best ^ 1);
				res |= (path ^ best) << move;
				cur = cur.nexts[best];
			}
			return res;
		}

	}

	public static int maxXorSubarray(int[] arr) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int max = Integer.MIN_VALUE;
		int eor = 0;
		NumTrie numTrie = new NumTrie();
		numTrie.add(0);
		for (int i = 0; i < arr.length; i++) {
			eor ^= arr[i];
			max = Math.max(max, numTrie.maxXor(eor));
			numTrie.add(eor);
		}
		return max;
	}

	// for test
	public static int comparator(int[] arr) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < arr.length; i++) {
			int eor = 0;
			for (int j = i; j < arr.length; j++) {
				eor ^= arr[j];
				max = Math.max(max, eor);
			}
		}
		return max;
	}

	// for test
	public static int[] generateRandomArray(int maxSize, int maxValue) {
		int[] arr = new int[(int) ((maxSize + 1) * Math.random())];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = (int) ((maxValue + 1) * Math.random()) - (int) (maxValue * Math.random());
		}
		return arr;
	}

	// for test
	public static void printArray(int[] arr) {
		if (arr == null) {
			return;
		}
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	// for test
	public static void main(String[] args) {
		int testTime = 500000;
		int maxSize = 30;
		int maxValue = 50;
		boolean succeed = true;
		for (int i = 0; i < testTime; i++) {
			int[] arr = generateRandomArray(maxSize, maxValue);
			int res = maxXorSubarray(arr);
			int comp = comparator(arr);
			if (res != comp) {
				succeed = false;
				printArray(arr);
				System.out.println(res);
				System.out.println(comp);
				break;
			}
		}
		System.out.println(succeed ? "Nice!" : "Fucking fucked!");
	}
}


56
package advanced_class_05;

public class Code_06_CompleteTreeNodeNumber {

	public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
	}

	public static int nodeNum(Node head) {
		if (head == null) {
			return 0;
		}
		return bs(head, 1, mostLeftLevel(head, 1));
	}

	public static int bs(Node node, int l, int h) {
		if (l == h) {
			return 1;
		}
		if (mostLeftLevel(node.right, l + 1) == h) {
			return (1 << (h - l)) + bs(node.right, l + 1, h);
		} else {
			return (1 << (h - l - 1)) + bs(node.left, l + 1, h);
		}
	}

	public static int mostLeftLevel(Node node, int level) {
		while (node != null) {
			level++;
			node = node.left;
		}
		return level - 1;
	}

	public static void main(String[] args) {
		Node head = new Node(1);
		head.left = new Node(2);
		head.right = new Node(3);
		head.left.left = new Node(4);
		head.left.right = new Node(5);
		head.right.left = new Node(6);
		System.out.println(nodeNum(head));

	}

}




61
package advanced_class_06;

public class Code_01_CoinsWay {

	public static int coins1(int[] arr, int aim) {
		if (arr == null || arr.length == 0 || aim < 0) {
			return 0;
		}
		return process1(arr, 0, aim);
	}

	public static int process1(int[] arr, int index, int aim) {
		int res = 0;
		if (index == arr.length) {
			res = aim == 0 ? 1 : 0;
		} else {
			for (int i = 0; arr[index] * i <= aim; i++) {
				res += process1(arr, index + 1, aim - arr[index] * i);
			}
		}
		return res;
	}

	public static int coinsOther(int[] arr, int aim) {
		if (arr == null || arr.length == 0 || aim < 0) {
			return 0;
		}
		return processOther(arr, arr.length - 1, aim);
	}

	public static int processOther(int[] arr, int index, int aim) {
		int res = 0;
		if (index == -1) {
			res = aim == 0 ? 1 : 0;
		} else {
			for (int i = 0; arr[index] * i <= aim; i++) {
				res += processOther(arr, index - 1, aim - arr[index] * i);
			}
		}
		return res;
	}

	public static int coins2(int[] arr, int aim) {
		if (arr == null || arr.length == 0 || aim < 0) {
			return 0;
		}
		int[][] map = new int[arr.length + 1][aim + 1];
		return process2(arr, 0, aim, map);
	}

	public static int process2(int[] arr, int index, int aim, int[][] map) {
		int res = 0;
		if (index == arr.length) {
			res = aim == 0 ? 1 : 0;
		} else {
			int mapValue = 0;
			for (int i = 0; arr[index] * i <= aim; i++) {
				mapValue = map[index + 1][aim - arr[index] * i];
				if (mapValue != 0) {
					res += mapValue == -1 ? 0 : mapValue;
				} else {
					res += process2(arr, index + 1, aim - arr[index] * i, map);
				}
			}
		}
		map[index][aim] = res == 0 ? -1 : res;
		return res;
	}

	public static int coins3(int[] arr, int aim) {
		if (arr == null || arr.length == 0 || aim < 0) {
			return 0;
		}
		int[][] dp = new int[arr.length][aim + 1];
		for (int i = 0; i < arr.length; i++) {
			dp[i][0] = 1;
		}
		for (int j = 1; arr[0] * j <= aim; j++) {
			dp[0][arr[0] * j] = 1;
		}
		int num = 0;
		for (int i = 1; i < arr.length; i++) {
			for (int j = 1; j <= aim; j++) {
				num = 0;
				for (int k = 0; j - arr[i] * k >= 0; k++) {
					num += dp[i - 1][j - arr[i] * k];
				}
				dp[i][j] = num;
			}
		}
		return dp[arr.length - 1][aim];
	}

	public static int coins4(int[] arr, int aim) {
		if (arr == null || arr.length == 0 || aim < 0) {
			return 0;
		}
		int[][] dp = new int[arr.length][aim + 1];
		for (int i = 0; i < arr.length; i++) {
			dp[i][0] = 1;
		}
		for (int j = 1; arr[0] * j <= aim; j++) {
			dp[0][arr[0] * j] = 1;
		}
		for (int i = 1; i < arr.length; i++) {
			for (int j = 1; j <= aim; j++) {
				dp[i][j] = dp[i - 1][j];
				dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0;
			}
		}
		return dp[arr.length - 1][aim];
	}

	public static int coins5(int[] arr, int aim) {
		if (arr == null || arr.length == 0 || aim < 0) {
			return 0;
		}
		int[] dp = new int[aim + 1];
		for (int j = 0; arr[0] * j <= aim; j++) {
			dp[arr[0] * j] = 1;
		}
		for (int i = 1; i < arr.length; i++) {
			for (int j = 1; j <= aim; j++) {
				dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0;
			}
		}
		return dp[aim];
	}

	public static void main(String[] args) {
		int[] coins = { 10, 5, 1, 25 };
		int aim = 2000;

		long start = 0;
		long end = 0;
		start = System.currentTimeMillis();
		System.out.println(coins1(coins, aim));
		end = System.currentTimeMillis();
		System.out.println("cost time : " + (end - start) + "(ms)");

		start = System.currentTimeMillis();
		System.out.println(coinsOther(coins, aim));
		end = System.currentTimeMillis();
		System.out.println("cost time : " + (end - start) + "(ms)");

		aim = 20000;

		start = System.currentTimeMillis();
		System.out.println(coins2(coins, aim));
		end = System.currentTimeMillis();
		System.out.println("cost time : " + (end - start) + "(ms)");

		start = System.currentTimeMillis();
		System.out.println(coins3(coins, aim));
		end = System.currentTimeMillis();
		System.out.println("cost time : " + (end - start) + "(ms)");

		start = System.currentTimeMillis();
		System.out.println(coins4(coins, aim));
		end = System.currentTimeMillis();
		System.out.println("cost time : " + (end - start) + "(ms)");

		start = System.currentTimeMillis();
		System.out.println(coins5(coins, aim));
		end = System.currentTimeMillis();
		System.out.println("cost time : " + (end - start) + "(ms)");

	}

}


62
package advanced_class_06;

public class Code_02_CardsInLine {

	public static int win1(int[] arr) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		return Math.max(f(arr, 0, arr.length - 1), s(arr, 0, arr.length - 1));
	}

	public static int f(int[] arr, int i, int j) {
		if (i == j) {
			return arr[i];
		}
		return Math.max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
	}

	public static int s(int[] arr, int i, int j) {
		if (i == j) {
			return 0;
		}
		return Math.min(f(arr, i + 1, j), f(arr, i, j - 1));
	}

	public static int win2(int[] arr) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int[][] f = new int[arr.length][arr.length];
		int[][] s = new int[arr.length][arr.length];
		for (int j = 0; j < arr.length; j++) {
			f[j][j] = arr[j];
			for (int i = j - 1; i >= 0; i--) {
				f[i][j] = Math.max(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]);
				s[i][j] = Math.min(f[i + 1][j], f[i][j - 1]);
			}
		}
		return Math.max(f[0][arr.length - 1], s[0][arr.length - 1]);
	}

	public static void main(String[] args) {
		int[] arr = { 1, 9, 1 };
		System.out.println(win1(arr));
		System.out.println(win2(arr));

	}

}


63
package advanced_class_06;

public class Code_03_RegularExpressionMatch {

	public static boolean isValid(char[] s, char[] e) {
		for (int i = 0; i < s.length; i++) {
			if (s[i] == '*' || s[i] == '.') {
				return false;
			}
		}
		for (int i = 0; i < e.length; i++) {
			if (e[i] == '*' && (i == 0 || e[i - 1] == '*')) {
				return false;
			}
		}
		return true;
	}

	public static boolean isMatch(String str, String exp) {
		if (str == null || exp == null) {
			return false;
		}
		char[] s = str.toCharArray();
		char[] e = exp.toCharArray();
		return isValid(s, e) ? process(s, e, 0, 0) : false;
	}

	public static boolean process(char[] s, char[] e, int si, int ei) {
		if (ei == e.length) {
			return si == s.length;
		}
		if (ei + 1 == e.length || e[ei + 1] != '*') {
			return si != s.length && (e[ei] == s[si] || e[ei] == '.')
					&& process(s, e, si + 1, ei + 1);
		}
		while (si != s.length && (e[ei] == s[si] || e[ei] == '.')) {
			if (process(s, e, si, ei + 2)) {
				return true;
			}
			si++;
		}
		return process(s, e, si, ei + 2);
	}

	public static boolean isMatchDP(String str, String exp) {
		if (str == null || exp == null) {
			return false;
		}
		char[] s = str.toCharArray();
		char[] e = exp.toCharArray();
		if (!isValid(s, e)) {
			return false;
		}
		boolean[][] dp = initDPMap(s, e);
		for (int i = s.length - 1; i > -1; i--) {
			for (int j = e.length - 2; j > -1; j--) {
				if (e[j + 1] != '*') {
					dp[i][j] = (s[i] == e[j] || e[j] == '.')
							&& dp[i + 1][j + 1];
				} else {
					int si = i;
					while (si != s.length && (s[si] == e[j] || e[j] == '.')) {
						if (dp[si][j + 2]) {
							dp[i][j] = true;
							break;
						}
						si++;
					}
					if (dp[i][j] != true) {
						dp[i][j] = dp[si][j + 2];
					}
				}
			}
		}
		return dp[0][0];
	}

	public static boolean[][] initDPMap(char[] s, char[] e) {
		int slen = s.length;
		int elen = e.length;
		boolean[][] dp = new boolean[slen + 1][elen + 1];
		dp[slen][elen] = true;
		for (int j = elen - 2; j > -1; j = j - 2) {
			if (e[j] != '*' && e[j + 1] == '*') {
				dp[slen][j] = true;
			} else {
				break;
			}
		}
		if (slen > 0 && elen > 0) {
			if ((e[elen - 1] == '.' || s[slen - 1] == e[elen - 1])) {
				dp[slen - 1][elen - 1] = true;
			}
		}
		return dp;
	}

	public static void main(String[] args) {
		String str = "abcccdefg";
		String exp = "ab.*d.*e.*";
		System.out.println(isMatch(str, exp));
		System.out.println(isMatchDP(str, exp));

	}

}


64
package advanced_class_06;

public class Code_04_LongestSumSubArrayLengthInPositiveArray {

	public static int getMaxLength(int[] arr, int k) {
		if (arr == null || arr.length == 0 || k <= 0) {
			return 0;
		}
		int L = 0;
		int R = 0;
		int sum = arr[0];
		int len = 0;
		while (R < arr.length) {
			if (sum == k) {
				len = Math.max(len, R - L + 1);
				sum -= arr[L++];
			} else if (sum < k) {
				R++;
				if (R == arr.length) {
					break;
				}
				sum += arr[R];
			} else {
				sum -= arr[L++];
			}
		}
		return len;
	}

	public static int[] generatePositiveArray(int size) {
		int[] result = new int[size];
		for (int i = 0; i != size; i++) {
			result[i] = (int) (Math.random() * 10) + 1;
		}
		return result;
	}

	public static void printArray(int[] arr) {
		for (int i = 0; i != arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		int len = 20;
		int k = 15;
		int[] arr = generatePositiveArray(len);
		printArray(arr);
		System.out.println(getMaxLength(arr, k));

	}

}


65
package advanced_class_06;

import java.util.HashMap;

public class Code_05_LongestSubarrayLessSumAwesomeSolution {

	public static int maxLengthAwesome(int[] arr, int k) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int[] sums = new int[arr.length];
		HashMap<Integer, Integer> ends = new HashMap<Integer, Integer>();
		sums[arr.length - 1] = arr[arr.length - 1];
		ends.put(arr.length - 1, arr.length - 1);
		for (int i = arr.length - 2; i >= 0; i--) {
			if (sums[i + 1] < 0) {
				sums[i] = arr[i] + sums[i + 1];
				ends.put(i, ends.get(i + 1));
			} else {
				sums[i] = arr[i];
				ends.put(i, i);
			}
		}
		int end = 0;
		int sum = 0;
		int res = 0;
		for (int i = 0; i < arr.length; i++) {
			while (end < arr.length && sum + sums[end] <= k) {
				sum += sums[end];
				end = ends.get(end) + 1;
			}
			sum -= end > i ? arr[i] : 0;
			res = Math.max(res, end - i);
			end = Math.max(end, i + 1);
		}
		return res;
	}

	public static int maxLength(int[] arr, int k) {
		int[] h = new int[arr.length + 1];
		int sum = 0;
		h[0] = sum;
		for (int i = 0; i != arr.length; i++) {
			sum += arr[i];
			h[i + 1] = Math.max(sum, h[i]);
		}
		sum = 0;
		int res = 0;
		int pre = 0;
		int len = 0;
		for (int i = 0; i != arr.length; i++) {
			sum += arr[i];
			pre = getLessIndex(h, sum - k);
			len = pre == -1 ? 0 : i - pre + 1;
			res = Math.max(res, len);
		}
		return res;
	}

	public static int getLessIndex(int[] arr, int num) {
		int low = 0;
		int high = arr.length - 1;
		int mid = 0;
		int res = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (arr[mid] >= num) {
				res = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return res;
	}

	// for test
	public static int[] generateRandomArray(int len, int maxValue) {
		int[] res = new int[len];
		for (int i = 0; i != res.length; i++) {
			res[i] = (int) (Math.random() * maxValue) - (maxValue / 3);
		}
		return res;
	}

	public static void main(String[] args) {
		for (int i = 0; i < 1000000; i++) {
			int[] arr = generateRandomArray(10, 20);
			int k = (int) (Math.random() * 20) - 5;
			if (maxLengthAwesome(arr, k) != maxLength(arr, k)) {
				System.out.println("oops!");
			}
		}

	}

}


66
package advanced_class_06;

public class Code_06_JosephusProblem {

	public static class Node {
		public int value;
		public Node next;

		public Node(int data) {
			this.value = data;
		}
	}

	public static Node josephusKill1(Node head, int m) {
		if (head == null || head.next == head || m < 1) {
			return head;
		}
		Node last = head;
		while (last.next != head) {
			last = last.next;
		}
		int count = 0;
		while (head != last) {
			if (++count == m) {
				last.next = head.next;
				count = 0;
			} else {
				last = last.next;
			}
			head = last.next;
		}
		return head;
	}

	public static Node josephusKill2(Node head, int m) {
		if (head == null || head.next == head || m < 1) {
			return head;
		}
		Node cur = head.next;
		int tmp = 1; // tmp -> list size
		while (cur != head) {
			tmp++;
			cur = cur.next;
		}
		tmp = getLive(tmp, m); // tmp -> service node position
		while (--tmp != 0) {
			head = head.next;
		}
		head.next = head;
		return head;
	}

	public static int getLive(int i, int m) {
		if (i == 1) {
			return 1;
		}
		return (getLive(i - 1, m) + m - 1) % i + 1;
	}

	public static void printCircularList(Node head) {
		if (head == null) {
			return;
		}
		System.out.print("Circular List: " + head.value + " ");
		Node cur = head.next;
		while (cur != head) {
			System.out.print(cur.value + " ");
			cur = cur.next;
		}
		System.out.println("-> " + head.value);
	}

	public static void main(String[] args) {
		Node head1 = new Node(1);
		head1.next = new Node(2);
		head1.next.next = new Node(3);
		head1.next.next.next = new Node(4);
		head1.next.next.next.next = new Node(5);
		head1.next.next.next.next.next = head1;
		printCircularList(head1);
		head1 = josephusKill1(head1, 3);
		printCircularList(head1);

		Node head2 = new Node(1);
		head2.next = new Node(2);
		head2.next.next = new Node(3);
		head2.next.next.next = new Node(4);
		head2.next.next.next.next = new Node(5);
		head2.next.next.next.next.next = head2;
		printCircularList(head2);
		head2 = josephusKill2(head2, 3);
		printCircularList(head2);

	}

}




71
package advanced_class_07;

public class Code_01_MinPathSum {

	public static int minPathSum1(int[][] m) {
		if (m == null || m.length == 0 || m[0] == null || m[0].length == 0) {
			return 0;
		}
		int row = m.length;
		int col = m[0].length;
		int[][] dp = new int[row][col];
		dp[0][0] = m[0][0];
		for (int i = 1; i < row; i++) {
			dp[i][0] = dp[i - 1][0] + m[i][0];
		}
		for (int j = 1; j < col; j++) {
			dp[0][j] = dp[0][j - 1] + m[0][j];
		}
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + m[i][j];
			}
		}
		return dp[row - 1][col - 1];
	}

	public static int minPathSum2(int[][] m) {
		if (m == null || m.length == 0 || m[0] == null || m[0].length == 0) {
			return 0;
		}
		int more = Math.max(m.length, m[0].length); // �����������ϴ���Ǹ�Ϊmore
		int less = Math.min(m.length, m[0].length); // ������������С���Ǹ�Ϊless
		boolean rowmore = more == m.length; // �����ǲ��Ǵ��ڵ�������
		int[] arr = new int[less]; // ��������ĳ��Ƚ�Ϊ�����������е���Сֵ
		arr[0] = m[0][0];
		for (int i = 1; i < less; i++) {
			arr[i] = arr[i - 1] + (rowmore ? m[0][i] : m[i][0]);
		}
		for (int i = 1; i < more; i++) {
			arr[0] = arr[0] + (rowmore ? m[i][0] : m[0][i]);
			for (int j = 1; j < less; j++) {
				arr[j] = Math.min(arr[j - 1], arr[j])
						+ (rowmore ? m[i][j] : m[j][i]);
			}
		}
		return arr[less - 1];
	}

	// for test
	public static int[][] generateRandomMatrix(int rowSize, int colSize) {
		if (rowSize < 0 || colSize < 0) {
			return null;
		}
		int[][] result = new int[rowSize][colSize];
		for (int i = 0; i != result.length; i++) {
			for (int j = 0; j != result[0].length; j++) {
				result[i][j] = (int) (Math.random() * 10);
			}
		}
		return result;
	}

	// for test
	public static void printMatrix(int[][] matrix) {
		for (int i = 0; i != matrix.length; i++) {
			for (int j = 0; j != matrix[0].length; j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		// int[][] m = generateRandomMatrix(3, 4);
		int[][] m = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 },
				{ 8, 8, 4, 0 } };
		printMatrix(m);
		System.out.println(minPathSum1(m));
		System.out.println(minPathSum2(m));

	}
}


72
package advanced_class_07;

public class Code_02_LIS {

	public static int[] lis1(int[] arr) {
		if (arr == null || arr.length == 0) {
			return null;
		}
		int[] dp = getdp1(arr);
		return generateLIS(arr, dp);
	}

	public static int[] getdp1(int[] arr) {
		int[] dp = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j]) {
					dp[i] = Math.max(dp[i], dp[j] + 1);
				}
			}
		}
		return dp;
	}

	public static int[] generateLIS(int[] arr, int[] dp) {
		int len = 0;
		int index = 0;
		for (int i = 0; i < dp.length; i++) {
			if (dp[i] > len) {
				len = dp[i];
				index = i;
			}
		}
		int[] lis = new int[len];
		lis[--len] = arr[index];
		for (int i = index; i >= 0; i--) {
			if (arr[i] < arr[index] && dp[i] == dp[index] - 1) {
				lis[--len] = arr[i];
				index = i;
			}
		}
		return lis;
	}

	public static int[] lis2(int[] arr) {
		if (arr == null || arr.length == 0) {
			return null;
		}
		int[] dp = getdp2(arr);
		return generateLIS(arr, dp);
	}

	public static int[] getdp2(int[] arr) {
		int[] dp = new int[arr.length];
		int[] ends = new int[arr.length];
		ends[0] = arr[0];
		dp[0] = 1;
		int right = 0;
		int l = 0;
		int r = 0;
		int m = 0;
		for (int i = 1; i < arr.length; i++) {
			l = 0;
			r = right;
			while (l <= r) {
				m = (l + r) / 2;
				if (arr[i] > ends[m]) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			}
			right = Math.max(right, l);
			ends[l] = arr[i];
			dp[i] = l + 1;
		}
		return dp;
	}

	// for test
	public static void printArray(int[] arr) {
		for (int i = 0; i != arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		int[] arr = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
		printArray(arr);
		printArray(lis1(arr));
		printArray(lis2(arr));

	}
}


73
package advanced_class_07;

public class Code_03_LCSubsequence {

	public static String lcse(String str1, String str2) {
		if (str1 == null || str2 == null || str1.equals("") || str2.equals("")) {
			return "";
		}
		char[] chs1 = str1.toCharArray();
		char[] chs2 = str2.toCharArray();
		int[][] dp = getdp(chs1, chs2);
		int m = chs1.length - 1;
		int n = chs2.length - 1;
		char[] res = new char[dp[m][n]];
		int index = res.length - 1;
		while (index >= 0) {
			if (n > 0 && dp[m][n] == dp[m][n - 1]) {
				n--;
			} else if (m > 0 && dp[m][n] == dp[m - 1][n]) {
				m--;
			} else {
				res[index--] = chs1[m];
				m--;
				n--;
			}
		}
		return String.valueOf(res);
	}

	public static int[][] getdp(char[] str1, char[] str2) {
		int[][] dp = new int[str1.length][str2.length];
		dp[0][0] = str1[0] == str2[0] ? 1 : 0;
		for (int i = 1; i < str1.length; i++) {
			dp[i][0] = Math.max(dp[i - 1][0], str1[i] == str2[0] ? 1 : 0);
		}
		for (int j = 1; j < str2.length; j++) {
			dp[0][j] = Math.max(dp[0][j - 1], str1[0] == str2[j] ? 1 : 0);
		}
		for (int i = 1; i < str1.length; i++) {
			for (int j = 1; j < str2.length; j++) {
				dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				if (str1[i] == str2[j]) {
					dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		return dp;
	}

	public static void main(String[] args) {
		String str1 = "A1BC2D3EFGH45I6JK7LMN";
		String str2 = "12OPQ3RST4U5V6W7XYZ";
		System.out.println(lcse(str1, str2));

	}
}


74
package advanced_class_07;

public class Code_04_LCSubstring {

	public static String lcst1(String str1, String str2) {
		if (str1 == null || str2 == null || str1.equals("") || str2.equals("")) {
			return "";
		}
		char[] chs1 = str1.toCharArray();
		char[] chs2 = str2.toCharArray();
		int[][] dp = getdp(chs1, chs2);
		int end = 0;
		int max = 0;
		for (int i = 0; i < chs1.length; i++) {
			for (int j = 0; j < chs2.length; j++) {
				if (dp[i][j] > max) {
					end = i;
					max = dp[i][j];
				}
			}
		}
		return str1.substring(end - max + 1, end + 1);
	}

	public static int[][] getdp(char[] str1, char[] str2) {
		int[][] dp = new int[str1.length][str2.length];
		for (int i = 0; i < str1.length; i++) {
			if (str1[i] == str2[0]) {
				dp[i][0] = 1;
			}
		}
		for (int j = 1; j < str2.length; j++) {
			if (str1[0] == str2[j]) {
				dp[0][j] = 1;
			}
		}
		for (int i = 1; i < str1.length; i++) {
			for (int j = 1; j < str2.length; j++) {
				if (str1[i] == str2[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		return dp;
	}

	public static String lcst2(String str1, String str2) {
		if (str1 == null || str2 == null || str1.equals("") || str2.equals("")) {
			return "";
		}
		char[] chs1 = str1.toCharArray();
		char[] chs2 = str2.toCharArray();
		int row = 0;
		int col = chs2.length - 1;
		int max = 0;
		int end = 0;
		while (row < chs1.length) {
			int i = row;
			int j = col;
			int len = 0;
			while (i < chs1.length && j < chs2.length) {
				if (chs1[i] != chs2[j]) {
					len = 0;
				} else {
					len++;
				}
				if (len > max) {
					end = i;
					max = len;
				}
				i++;
				j++;
			}
			if (col > 0) {
				col--;
			} else {
				row++;
			}
		}
		return str1.substring(end - max + 1, end + 1);
	}

	public static void main(String[] args) {
		String str1 = "ABC1234567DEFG";
		String str2 = "HIJKL1234567MNOP";
		System.out.println(lcst1(str1, str2));
		System.out.println(lcst2(str1, str2));

	}

}


75
package advanced_class_07;

public class Code_05_EditCost {

	public static int minCost1(String str1, String str2, int ic, int dc, int rc) {
		if (str1 == null || str2 == null) {
			return 0;
		}
		char[] chs1 = str1.toCharArray();
		char[] chs2 = str2.toCharArray();
		int row = chs1.length + 1;
		int col = chs2.length + 1;
		int[][] dp = new int[row][col];
		for (int i = 1; i < row; i++) {
			dp[i][0] = dc * i;
		}
		for (int j = 1; j < col; j++) {
			dp[0][j] = ic * j;
		}
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				if (chs1[i - 1] == chs2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = dp[i - 1][j - 1] + rc;
				}
				dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + ic);
				dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + dc);
			}
		}
		return dp[row - 1][col - 1];
	}

	public static int minCost2(String str1, String str2, int ic, int dc, int rc) {
		if (str1 == null || str2 == null) {
			return 0;
		}
		char[] chs1 = str1.toCharArray();
		char[] chs2 = str2.toCharArray();
		char[] longs = chs1.length >= chs2.length ? chs1 : chs2;
		char[] shorts = chs1.length < chs2.length ? chs1 : chs2;
		if (chs1.length < chs2.length) { // str2�ϳ��ͽ���ic��dc��ֵ
			int tmp = ic;
			ic = dc;
			dc = tmp;
		}
		int[] dp = new int[shorts.length + 1];
		for (int i = 1; i <= shorts.length; i++) {
			dp[i] = ic * i;
		}
		for (int i = 1; i <= longs.length; i++) {
			int pre = dp[0]; // pre��ʾ���Ͻǵ�ֵ
			dp[0] = dc * i;
			for (int j = 1; j <= shorts.length; j++) {
				int tmp = dp[j]; // dp[j]û����ǰ�ȱ�������
				if (longs[i - 1] == shorts[j - 1]) {
					dp[j] = pre;
				} else {
					dp[j] = pre + rc;
				}
				dp[j] = Math.min(dp[j], dp[j - 1] + ic);
				dp[j] = Math.min(dp[j], tmp + dc);
				pre = tmp; // pre���dp[j]û����ǰ��ֵ
			}
		}
		return dp[shorts.length];
	}

	public static void main(String[] args) {
		String str1 = "ab12cd3";
		String str2 = "abcdf";
		System.out.println(minCost1(str1, str2, 5, 3, 2));
		System.out.println(minCost2(str1, str2, 5, 3, 2));

		str1 = "abcdf";
		str2 = "ab12cd3";
		System.out.println(minCost1(str1, str2, 3, 2, 4));
		System.out.println(minCost2(str1, str2, 3, 2, 4));

		str1 = "";
		str2 = "ab12cd3";
		System.out.println(minCost1(str1, str2, 1, 7, 5));
		System.out.println(minCost2(str1, str2, 1, 7, 5));

		str1 = "abcdf";
		str2 = "";
		System.out.println(minCost1(str1, str2, 2, 9, 8));
		System.out.println(minCost2(str1, str2, 2, 9, 8));

	}

}


76
package advanced_class_07;

public class Code_06_PalindromeMinCut {

	public static int minCut(String str) {
		if (str == null || str.equals("")) {
			return 0;
		}
		char[] chas = str.toCharArray();
		int len = chas.length;
		int[] dp = new int[len + 1];
		dp[len] = -1;
		boolean[][] p = new boolean[len][len];
		for (int i = len - 1; i >= 0; i--) {
			dp[i] = Integer.MAX_VALUE;
			for (int j = i; j < len; j++) {
				if (chas[i] == chas[j] && (j - i < 2 || p[i + 1][j - 1])) {
					p[i][j] = true;
					dp[i] = Math.min(dp[i], dp[j + 1] + 1);
				}
			}
		}
		return dp[0];
	}

	// for test
	public static String getRandomStringOnlyAToD(int len) {
		int range = 'D' - 'A' + 1;
		char[] charArr = new char[(int) (Math.random() * (len + 1))];
		for (int i = 0; i != charArr.length; i++) {
			charArr[i] = (char) ((int) (Math.random() * range) + 'A');
		}
		return String.valueOf(charArr);
	}

	public static void main(String[] args) {
		int maxLen = 10;
		int testTimes = 5;
		String str = null;
		for (int i = 0; i != testTimes; i++) {
			str = getRandomStringOnlyAToD(maxLen);
			System.out.print("\"" + str + "\"" + " : ");
			System.out.println(minCut(str));
		}

	}
}


77
package advanced_class_07;

public class Code_07_StringCross {

	public static boolean isCross1(String str1, String str2, String aim) {
		if (str1 == null || str2 == null || aim == null) {
			return false;
		}
		char[] ch1 = str1.toCharArray();
		char[] ch2 = str2.toCharArray();
		char[] chaim = aim.toCharArray();
		if (chaim.length != ch1.length + ch2.length) {
			return false;
		}
		boolean[][] dp = new boolean[ch1.length + 1][ch2.length + 1];
		dp[0][0] = true;
		for (int i = 1; i <= ch1.length; i++) {
			if (ch1[i - 1] != chaim[i - 1]) {
				break;
			}
			dp[i][0] = true;
		}
		for (int j = 1; j <= ch2.length; j++) {
			if (ch2[j - 1] != chaim[j - 1]) {
				break;
			}
			dp[0][j] = true;
		}
		for (int i = 1; i <= ch1.length; i++) {
			for (int j = 1; j <= ch2.length; j++) {
				if ((ch1[i - 1] == chaim[i + j - 1] && dp[i - 1][j])
						|| (ch2[j - 1] == chaim[i + j - 1] && dp[i][j - 1])) {
					dp[i][j] = true;
				}
			}
		}
		return dp[ch1.length][ch2.length];
	}

	public static boolean isCross2(String str1, String str2, String aim) {
		if (str1 == null || str2 == null || aim == null) {
			return false;
		}
		char[] ch1 = str1.toCharArray();
		char[] ch2 = str2.toCharArray();
		char[] chaim = aim.toCharArray();
		if (chaim.length != ch1.length + ch2.length) {
			return false;
		}
		char[] longs = ch1.length >= ch2.length ? ch1 : ch2;
		char[] shorts = ch1.length < ch2.length ? ch1 : ch2;
		boolean[] dp = new boolean[shorts.length + 1];
		dp[0] = true;
		for (int i = 1; i <= shorts.length; i++) {
			if (shorts[i - 1] != chaim[i - 1]) {
				break;
			}
			dp[i] = true;
		}
		for (int i = 1; i <= longs.length; i++) {
			dp[0] = dp[0] && longs[i - 1] == chaim[i - 1];
			for (int j = 1; j <= shorts.length; j++) {
				if ((longs[i - 1] == chaim[i + j - 1] && dp[j])
						|| (shorts[j - 1] == chaim[i + j - 1] && dp[j - 1])) {
					dp[j] = true;
				} else {
					dp[j] = false;
				}
			}
		}
		return dp[shorts.length];
	}

	public static void main(String[] args) {
		String str1 = "1234";
		String str2 = "abcd";
		String aim = "1a23bcd4";
		System.out.println(isCross1(str1, str2, aim));
		System.out.println(isCross2(str1, str2, aim));

	}

}


78
package advanced_class_07;

public class Code_08_ParenthesesProblem {

	public static boolean isValid(String str) {
		if (str == null || str.equals("")) {
			return false;
		}
		char[] chas = str.toCharArray();
		int status = 0;
		for (int i = 0; i < chas.length; i++) {
			if (chas[i] != ')' && chas[i] != '(') {
				return false;
			}
			if (chas[i] == ')' && --status < 0) {
				return false;
			}
			if (chas[i] == '(') {
				status++;
			}
		}
		return status == 0;
	}

	public static int maxLength(String str) {
		if (str == null || str.equals("")) {
			return 0;
		}
		char[] chas = str.toCharArray();
		int[] dp = new int[chas.length];
		int pre = 0;
		int res = 0;
		for (int i = 1; i < chas.length; i++) {
			if (chas[i] == ')') {
				pre = i - dp[i - 1] - 1;
				if (pre >= 0 && chas[pre] == '(') {
					dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
				}
			}
			res = Math.max(res, dp[i]);
		}
		return res;
	}

	public static void main(String[] args) {
		String str1 = "((())())";
		System.out.println(isValid(str1));
		System.out.println(maxLength(str1));

		String str2 = "(())(()(()))";
		System.out.println(isValid(str2));
		System.out.println(maxLength(str2));

		String str3 = "()(()()(";
		System.out.println(isValid(str3));
		System.out.println(maxLength(str3));

	}
}





81
package advanced_class_08;

import java.util.Arrays;
import java.util.HashSet;

public class Code_01_TopKSumCrossTwoArrays {

	public static class HeapNode {
		public int row;
		public int col;
		public int value;

		public HeapNode(int row, int col, int value) {
			this.row = row;
			this.col = col;
			this.value = value;
		}
	}

	public static int[] topKSum(int[] a1, int[] a2, int topK) {
		if (a1 == null || a2 == null || topK < 1) {
			return null;
		}
		topK = Math.min(topK, a1.length * a2.length);
		HeapNode[] heap = new HeapNode[topK + 1];
		int heapSize = 0;
		int headR = a1.length - 1;
		int headC = a2.length - 1;
		int uR = -1;
		int uC = -1;
		int lR = -1;
		int lC = -1;
		heapInsert(heap, heapSize++, headR, headC, a1[headR] + a2[headC]);
		HashSet<String> positionSet = new HashSet<String>();
		int[] res = new int[topK];
		int resIndex = 0;
		while (resIndex != topK) {
			HeapNode head = popHead(heap, heapSize--);
			res[resIndex++] = head.value;
			headR = head.row;
			headC = head.col;
			uR = headR - 1;
			uC = headC;
			if (headR != 0 && !isContains(uR, uC, positionSet)) {
				heapInsert(heap, heapSize++, uR, uC, a1[uR] + a2[uC]);
				addPositionToSet(uR, uC, positionSet);
			}
			lR = headR;
			lC = headC - 1;
			if (headC != 0 && !isContains(lR, lC, positionSet)) {
				heapInsert(heap, heapSize++, lR, lC, a1[lR] + a2[lC]);
				addPositionToSet(lR, lC, positionSet);
			}
		}
		return res;
	}

	public static HeapNode popHead(HeapNode[] heap, int heapSize) {
		HeapNode res = heap[0];
		swap(heap, 0, heapSize - 1);
		heap[--heapSize] = null;
		heapify(heap, 0, heapSize);
		return res;
	}

	public static void heapify(HeapNode[] heap, int index, int heapSize) {
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int largest = index;
		while (left < heapSize) {
			if (heap[left].value > heap[index].value) {
				largest = left;
			}
			if (right < heapSize && heap[right].value > heap[largest].value) {
				largest = right;
			}
			if (largest != index) {
				swap(heap, largest, index);
			} else {
				break;
			}
			index = largest;
			left = index * 2 + 1;
			right = index * 2 + 2;
		}
	}

	public static void heapInsert(HeapNode[] heap, int index, int row, int col,
			int value) {
		heap[index] = new HeapNode(row, col, value);
		int parent = (index - 1) / 2;
		while (index != 0) {
			if (heap[index].value > heap[parent].value) {
				swap(heap, parent, index);
				index = parent;
				parent = (index - 1) / 2;
			} else {
				break;
			}
		}
	}

	public static void swap(HeapNode[] heap, int index1, int index2) {
		HeapNode tmp = heap[index1];
		heap[index1] = heap[index2];
		heap[index2] = tmp;
	}

	public static boolean isContains(int row, int col, HashSet<String> set) {
		return set.contains(String.valueOf(row + "_" + col));
	}

	public static void addPositionToSet(int row, int col, HashSet<String> set) {
		set.add(String.valueOf(row + "_" + col));
	}

	// For test, this method is inefficient but absolutely right
	public static int[] topKSumTest(int[] arr1, int[] arr2, int topK) {
		int[] all = new int[arr1.length * arr2.length];
		int index = 0;
		for (int i = 0; i != arr1.length; i++) {
			for (int j = 0; j != arr2.length; j++) {
				all[index++] = arr1[i] + arr2[j];
			}
		}
		Arrays.sort(all);
		int[] res = new int[Math.min(topK, all.length)];
		index = all.length - 1;
		for (int i = 0; i != res.length; i++) {
			res[i] = all[index--];
		}
		return res;
	}

	public static int[] generateRandomSortArray(int len) {
		int[] res = new int[len];
		for (int i = 0; i != res.length; i++) {
			res[i] = (int) (Math.random() * 50000) + 1;
		}
		Arrays.sort(res);
		return res;
	}

	public static void printArray(int[] arr) {
		for (int i = 0; i != arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static boolean isEqual(int[] arr1, int[] arr2) {
		if (arr1 == null || arr2 == null || arr1.length != arr2.length) {
			return false;
		}
		for (int i = 0; i != arr1.length; i++) {
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		int a1Len = 5000;
		int a2Len = 4000;
		int k = 2000;
		int[] arr1 = generateRandomSortArray(a1Len);
		int[] arr2 = generateRandomSortArray(a2Len);
		long start = System.currentTimeMillis();
		int[] res = topKSum(arr1, arr2, k);
		long end = System.currentTimeMillis();
		System.out.println(end - start + " ms");

		start = System.currentTimeMillis();
		int[] absolutelyRight = topKSumTest(arr1, arr2, k);
		end = System.currentTimeMillis();
		System.out.println(end - start + " ms");

		System.out.println(isEqual(res, absolutelyRight));

	}

}


82
package advanced_class_08;

public class Code_02_MaxSubMatrixSum {

	public static int maxSum(int[][] m) {
		if (m == null || m.length == 0 || m[0].length == 0) {
			return 0;
		}
		int max = Integer.MIN_VALUE;
		int cur = 0;
		int[] s = null;
		for (int i = 0; i != m.length; i++) {
			s = new int[m[0].length];
			for (int j = i; j != m.length; j++) {
				cur = 0;
				for (int k = 0; k != s.length; k++) {
					s[k] += m[j][k];
					cur += s[k];
					max = Math.max(max, cur);
					cur = cur < 0 ? 0 : cur;
				}
			}
		}
		return max;
	}

	public static void main(String[] args) {
		int[][] matrix = { { -90, 48, 78 }, { 64, -40, 64 }, { -81, -7, 66 } };
		System.out.println(maxSum(matrix));

	}
}


83
package advanced_class_08;

public class Code_03_MaxOneBorderSize {

	public static void setBorderMap(int[][] m, int[][] right, int[][] down) {
		int r = m.length;
		int c = m[0].length;
		if (m[r - 1][c - 1] == 1) {
			right[r - 1][c - 1] = 1;
			down[r - 1][c - 1] = 1;
		}
		for (int i = r - 2; i != -1; i--) {
			if (m[i][c - 1] == 1) {
				right[i][c - 1] = 1;
				down[i][c - 1] = down[i + 1][c - 1] + 1;
			}
		}
		for (int i = c - 2; i != -1; i--) {
			if (m[r - 1][i] == 1) {
				right[r - 1][i] = right[r - 1][i + 1] + 1;
				down[r - 1][i] = 1;
			}
		}
		for (int i = r - 2; i != -1; i--) {
			for (int j = c - 2; j != -1; j--) {
				if (m[i][j] == 1) {
					right[i][j] = right[i][j + 1] + 1;
					down[i][j] = down[i + 1][j] + 1;
				}
			}
		}
	}

	public static int getMaxSize(int[][] m) {
		int[][] right = new int[m.length][m[0].length];
		int[][] down = new int[m.length][m[0].length];
		setBorderMap(m, right, down);
		for (int size = Math.min(m.length, m[0].length); size != 0; size--) {
			if (hasSizeOfBorder(size, right, down)) {
				return size;
			}
		}
		return 0;
	}

	public static boolean hasSizeOfBorder(int size, int[][] right, int[][] down) {
		for (int i = 0; i != right.length - size + 1; i++) {
			for (int j = 0; j != right[0].length - size + 1; j++) {
				if (right[i][j] >= size && down[i][j] >= size
						&& right[i + size - 1][j] >= size
						&& down[i][j + size - 1] >= size) {
					return true;
				}
			}
		}
		return false;
	}

	public static int[][] generateRandom01Matrix(int rowSize, int colSize) {
		int[][] res = new int[rowSize][colSize];
		for (int i = 0; i != rowSize; i++) {
			for (int j = 0; j != colSize; j++) {
				res[i][j] = (int) (Math.random() * 2);
			}
		}
		return res;
	}

	public static void printMatrix(int[][] matrix) {
		for (int i = 0; i != matrix.length; i++) {
			for (int j = 0; j != matrix[0].length; j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		int[][] matrix = generateRandom01Matrix(7, 8);
		printMatrix(matrix);
		System.out.println(getMaxSize(matrix));
	}
}


84
package advanced_class_08;

public class Code_04_FibonacciProblem {

	public static int f1(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		return f1(n - 1) + f1(n - 2);
	}

	public static int f2(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		int res = 1;
		int pre = 1;
		int tmp = 0;
		for (int i = 3; i <= n; i++) {
			tmp = res;
			res = res + pre;
			pre = tmp;
		}
		return res;
	}

	public static int f3(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		int[][] base = { { 1, 1 }, { 1, 0 } };
		int[][] res = matrixPower(base, n - 2);
		return res[0][0] + res[1][0];
	}

	public static int[][] matrixPower(int[][] m, int p) {
		int[][] res = new int[m.length][m[0].length];
		for (int i = 0; i < res.length; i++) {
			res[i][i] = 1;
		}
		int[][] tmp = m;
		for (; p != 0; p >>= 1) {
			if ((p & 1) != 0) {
				res = muliMatrix(res, tmp);
			}
			tmp = muliMatrix(tmp, tmp);
		}
		return res;
	}

	public static int[][] muliMatrix(int[][] m1, int[][] m2) {
		int[][] res = new int[m1.length][m2[0].length];
		for (int i = 0; i < m1.length; i++) {
			for (int j = 0; j < m2[0].length; j++) {
				for (int k = 0; k < m2.length; k++) {
					res[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
		return res;
	}

	public static int s1(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2) {
			return n;
		}
		return s1(n - 1) + s1(n - 2);
	}

	public static int s2(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2) {
			return n;
		}
		int res = 2;
		int pre = 1;
		int tmp = 0;
		for (int i = 3; i <= n; i++) {
			tmp = res;
			res = res + pre;
			pre = tmp;
		}
		return res;
	}

	public static int s3(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2) {
			return n;
		}
		int[][] base = { { 1, 1 }, { 1, 0 } };
		int[][] res = matrixPower(base, n - 2);
		return 2 * res[0][0] + res[1][0];
	}

	public static int c1(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2 || n == 3) {
			return n;
		}
		return c1(n - 1) + c1(n - 3);
	}

	public static int c2(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2 || n == 3) {
			return n;
		}
		int res = 3;
		int pre = 2;
		int prepre = 1;
		int tmp1 = 0;
		int tmp2 = 0;
		for (int i = 4; i <= n; i++) {
			tmp1 = res;
			tmp2 = pre;
			res = res + prepre;
			pre = tmp1;
			prepre = tmp2;
		}
		return res;
	}

	public static int c3(int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1 || n == 2 || n == 3) {
			return n;
		}
		int[][] base = { { 1, 1, 0 }, { 0, 0, 1 }, { 1, 0, 0 } };
		int[][] res = matrixPower(base, n - 3);
		return 3 * res[0][0] + 2 * res[1][0] + res[2][0];
	}

	public static void main(String[] args) {
		int n = 20;
		System.out.println(f1(n));
		System.out.println(f2(n));
		System.out.println(f3(n));
		System.out.println("===");

		System.out.println(s1(n));
		System.out.println(s2(n));
		System.out.println(s3(n));
		System.out.println("===");

		System.out.println(c1(n));
		System.out.println(c2(n));
		System.out.println(c3(n));
		System.out.println("===");

	}

}


85
package advanced_class_08;

public class Code_05_LongestNoRepeatSubstring {

	public static int maxUnique(String str) {
		if (str == null || str.equals("")) {
			return 0;
		}
		char[] chas = str.toCharArray();
		int[] map = new int[256];
		for (int i = 0; i < 256; i++) {
			map[i] = -1;
		}
		int len = 0;
		int pre = -1;
		int cur = 0;
		for (int i = 0; i != chas.length; i++) {
			pre = Math.max(pre, map[chas[i]]);
			cur = i - pre;
			len = Math.max(len, cur);
			map[chas[i]] = i;
		}
		return len;
	}

	// for test
	public static String getRandomString(int len) {
		char[] str = new char[len];
		int base = 'a';
		int range = 'z' - 'a' + 1;
		for (int i = 0; i != len; i++) {
			str[i] = (char) ((int) (Math.random() * range) + base);
		}
		return String.valueOf(str);
	}

	// for test
	public static String maxUniqueString(String str) {
		if (str == null || str.equals("")) {
			return str;
		}
		char[] chas = str.toCharArray();
		int[] map = new int[256];
		for (int i = 0; i < 256; i++) {
			map[i] = -1;
		}
		int len = -1;
		int pre = -1;
		int cur = 0;
		int end = -1;
		for (int i = 0; i != chas.length; i++) {
			pre = Math.max(pre, map[chas[i]]);
			cur = i - pre;
			if (cur > len) {
				len = cur;
				end = i;
			}
			map[chas[i]] = i;
		}
		return str.substring(end - len + 1, end + 1);
	}

	public static void main(String[] args) {
		String str = getRandomString(20);
		System.out.println(str);
		System.out.println(maxUnique(str));
		System.out.println(maxUniqueString(str));
	}
}


86
package advanced_class_08;

import java.util.Arrays;

public class Code_06_ShuffleProblem {

	// https://arxiv.org/pdf/0805.1598.pdf
	public static void shuffle(int[] arr) {
		if (arr != null && arr.length != 0 && (arr.length & 1) == 0) {
			shuffle(arr, 0, arr.length - 1);
		}
	}

	public static void shuffle(int[] arr, int l, int r) {
		while (r - l + 1 > 0) {
			int lenAndOne = r - l + 2;
			int bloom = 3;
			int k = 1;
			while (bloom <= lenAndOne / 3) {
				bloom *= 3;
				k++;
			}
			int m = (bloom - 1) / 2;
			int mid = (l + r) / 2;
			rotate(arr, l + m, mid, mid + m);
			cycles(arr, l - 1, bloom, k);
			l = l + bloom - 1;
		}
	}

	public static void cycles(int[] arr, int base, int bloom, int k) {
		for (int i = 0, trigger = 1; i < k; i++, trigger *= 3) {
			int next = (2 * trigger) % bloom;
			int cur = next;
			int record = arr[next + base];
			int tmp = 0;
			arr[next + base] = arr[trigger + base];
			while (cur != trigger) {
				next = (2 * cur) % bloom;
				tmp = arr[next + base];
				arr[next + base] = record;
				cur = next;
				record = tmp;
			}
		}
	}

	public static void rotate(int[] arr, int l, int m, int r) {
		reverse(arr, l, m);
		reverse(arr, m + 1, r);
		reverse(arr, l, r);
	}

	public static void reverse(int[] arr, int l, int r) {
		while (l < r) {
			int tmp = arr[l];
			arr[l++] = arr[r];
			arr[r--] = tmp;
		}
	}

	// for test
	public static void printArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	// for test
	public static int[] generateArray() {
		int len = (int) (Math.random() * 10) * 2;
		int[] arr = new int[len];
		for (int i = 0; i < len; i++) {
			arr[i] = (int) (Math.random() * 100);
		}
		return arr;
	}

	// for test
	public static void shuffleTest(int[] arr) {
		int[] tarr = new int[arr.length];
		int bloom = arr.length + 1;
		for (int i = 1; i <= arr.length; i++) {
			tarr[((2 * i) % bloom) - 1] = arr[i - 1];
		}
		for (int i = 0; i < arr.length; i++) {
			arr[i] = tarr[i];
		}
	}

	public static boolean equalArrays(int[] arr1, int[] arr2) {
		if (arr1 == null || arr2 == null || arr1.length != arr2.length) {
			return false;
		}
		for (int i = 0; i < arr1.length; i++) {
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		for (int i = 0; i < 5000000; i++) {
			int[] arr = generateArray();
			int[] arr1 = Arrays.copyOfRange(arr, 0, arr.length);
			int[] arr2 = Arrays.copyOfRange(arr, 0, arr.length);
			shuffle(arr1);
			shuffleTest(arr2);
			if (!equalArrays(arr1, arr2)) {
				System.out.println("ooops!");
				printArray(arr);
				printArray(arr1);
				printArray(arr2);
				break;
			}
		}

	}

}



