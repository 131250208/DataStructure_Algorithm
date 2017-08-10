#include <stdio.h>;
#include <algorithm>;
using namespace std;

int tree[28];
int findroot(int x) {
	if (tree[x] == -1)
		return x;
	else {
		int tmp = findroot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}

struct Edge {
	int a, b;
	int cost;
	bool operator < (const Edge & A) const {
		return cost< A.cost;
	}
}edge[76];

//int main() {
//	int n;
//	while (scanf("%d", & n) != EOF && n != 0) {
//		char head;
//		char tail;
//		int cost;
//		int m;
//		int size = 0;
//		int n_ = n - 1;
//		while (n_--) {
//			scanf(" %c %d", & head, & m);  //注意字符输入问题，回车键也会被当成一个字符，所以%c前要加一个空格
//			while (m--) {
//				scanf(" %c %d", & tail, & cost);
//				edge[size].a = (int)(head - 'A');
//				edge[size].b = (int)(tail - 'A');
//				edge[size].cost = cost;
//				size++;
//			}
//		}
//		sort(edge, edge + size);
//		for (int i = 0; i< n; i++) {
//			tree[i] = -1;
//		}
//		int ans = 0;
//		for (int i = 0; i< size; i++) {
//			int a = findroot(edge[i].a);
//			int b = findroot(edge[i].b);
//			if (a != b) {
//				tree[a] = b;
//				ans += edge[i].cost;
//			}
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}

/*百炼2016研究生复试上机题 链接见收藏
输入
第一行只包含一个表示星星个数的数n，n不大于26，并且这n个星星是由大写字母表里的前n个字母表示。
接下来的n-1行是由字母表的前n-1个字母开头。最后一个星星表示的字母不用输入。对于每一行，以每
个星星表示的字母开头，然后后面跟着一个数字，表示有多少条边可以从这个星星到后面字母表中的星
星。如果k是大于0，表示该行后面会表示k条边的k个数据。每条边的数据是由表示连接到另一端星星的
字母和该边的权值组成。权值是正整数的并且小于100。该行的所有数据字段分隔单一空白。该星星网
络将始终连接所有的星星。该星星网络将永远不会超过75条边。没有任何一个星星会有超过15条的边连
接到其他星星（之前或之后的字母）。在下面的示例输入，数据是与上面的图相一致的。

输出
输出是一个整数，表示最小的权值和

正确输出：216

测试数据
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35


*/
//练习Prim
#include<iostream>
#include<stdio.h>
#include<algorithm>
#define INF 1<<30;
using namespace std;

static int matrix[30][30];
static char v[30];
static int lowcost[30];
static 	int n;
void upd_lowc(int ind_c) {
	for (int i = 0; i < n; ++i) {
		if (v[i]=='0'&&matrix[ind_c][i] < lowcost[i]) {
			lowcost[i] = matrix[ind_c][i];
		}
	}
}

int getMin_edge() {
	int ind=-1, min_edge=INF;
	for (int i = 0; i < n; ++i) {
		if (v[i] == '0'&&lowcost[i] < min_edge) {
			ind = i;
			min_edge = lowcost[i];
		}
	}
	return ind;
}
//int main() {
//	for (int i = 0; i < 30; ++i)
//		for (int j = 0; j < 30; ++j)
//			matrix[i][j] = INF;
//	scanf("%d", &n);
//	for (int i = 0; i < n-1; ++i) {
//		getchar();//吐掉一个回车
//		char v1; int num_e;
//		scanf("%c %d", &v1, &num_e);
//		for (int j = 0; j < num_e; ++j) {
//			char v2; int val_e;
//			scanf(" %c %d", &v2, &val_e);
//			matrix[v1 - 'A'][v2 - 'A'] = val_e;
//			matrix[v2 - 'A'][v1 - 'A'] = val_e;
//		}
//	}
//
//	//输入完毕，开始筛选点
//	memset(v, '0', sizeof(v));
//	memcpy(lowcost, matrix[0], sizeof(matrix[0]));
//	v[0] = '@';
//
//	int sum = 0;
//	int count = n;
//	while (--count)
//	{
//		int ind_min = getMin_edge();
//		sum += lowcost[ind_min];
//		v[ind_min] = '@';//先入选，后更新
//		upd_lowc(ind_min);
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

/*解法一：prim算法（最简，只能算最小权值，无法输出边）
错误次数：2
原因：
1、临接矩阵int数组初始化不能用memset
2、输入数据到临接矩阵时，漏掉了反向边，如点1到节点2可达，2到1应该也可达
*/
//#include<iostream>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define infinite 200
//static int n;
//static int matrix[26][26];
//static int v[26];
//static int lowcost[26];
//int getindex(char c) {
//	return c - 'A';
//}
//void upd_lowc(int index_r) {
//	for (int i = 0; i < n; ++i) {
//		if (v[i] != 1) {
//			lowcost[i] = min(lowcost[i], matrix[index_r][i]);
//		}
//	}
//}
//int getindex_min(int lowcost[]) {
//	int index=-1;
//	int min= infinite;
//	for (int i = 0; i < n; ++i) {
//		if (lowcost[i] < min&&v[i]!=1) {
//			min = lowcost[i];
//			index = i;
//		}
//	}
//	return index;
//}
//int main() {
//
//	cin >> n;
//
//	//memset(matrix, infinite, sizeof(int)*26*26);//*初值为各边不可达，200,memset只适合用来初始化char数组，或者初始化int数组为0
//	for (int i = 0; i < 26; ++i)
//		for (int j = 0; j < 26; ++j)
//			matrix[i][j] = infinite;
//	char c_r;
//	int index_r,num_edges;
//	for (int i = 0; i < n - 1; ++i) {
//		cin >> c_r;
//		index_r = getindex(c_r);
//		cin >> num_edges;
//		int index_c,value; char c_c;
//		for (int j = 0; j < num_edges; ++j) {
//			cin >> c_c; cin >> value;
//			index_c = getindex(c_c);
//			matrix[index_r][index_c]=value;
//			matrix[index_c][index_r] = value;//*反向边也标记上权值
//		}
//	}
//
//	/*prime算法核心代码,以上是读取数据进临接矩阵*/
//	memset(v, 0, sizeof(v));
//	v[0] = 1;//从第一个点开始
//
//	int focus = 0;
//	memcpy(lowcost, matrix[0], sizeof(matrix[0]));
//
//	//循环挑选合适的顶点并累加权值
//	int count = n,sum=0;
//	while (--count!=0)
//	{
//		int index = getindex_min(lowcost);
//		v[index] = 1;//标记新入选的边
//		sum += lowcost[index];//累加权值
//		upd_lowc(index);
//	}
//
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}


/*解法二：prim算法（用结构体，方便地输出边）
错误次数：1
原因：部分结构体的节点标记没有与matrix的坐标对应---142，145
收获：
1、结构体写了初始值，在以结构体声明数组时，会按带初始值的结构体自动初始化数组，无需手动操作
注意：返回结构体一定要申请空间---119
*/

//#include<iostream>
//using namespace std;
//#define infinite 200
//typedef struct {
//	int i=-1, j=-1, value= infinite;
//}Edge;
//
//
//static int n;
//static Edge matrix[26][26];
//static int v[26];
//static Edge lowcost[26];
//
//Edge*  getInstance_edge(int i,int j,int v) {
//	Edge* edge = (Edge*)malloc(sizeof(Edge));
//	edge->i = i;
//	edge->j = j;
//	edge->value = v;
//	return edge;
//}
//void upd_lowcost(int r) {
//	for (int i = 0; i < n; ++i) {
//		if (v[i] != 1) {//未入选的才需要更新
//			lowcost[i] = (matrix[r][i].value < lowcost[i].value) ? matrix[r][i] : lowcost[i];
//		}
//	}
//}
//Edge getMin(Edge lowc[]) {
//	Edge edge=*getInstance_edge(-1,-1, infinite);//*
//	for (int i = 0; i < n; ++i) {
//		if (v[i] != 1) {//从未入选的边中找最短
//			edge = (lowc[i].value < edge.value) ? lowc[i] : edge;
//		}
//	}
//	return edge;
//}
//int getInd(char c) {
//	return c - 'A';
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n - 1; ++i) {
//		char c; int num_e;
//		cin >> c, cin >> num_e;
//		int ind1 = getInd(c);
//		while (num_e--)
//		{
//			char c; int v;
//			cin >> c; cin >> v;
//			int ind2 = getInd(c);
//			Edge edge1 = *getInstance_edge(ind1, ind2, v);
//			Edge edge2 = *getInstance_edge(ind2, ind1, v);//*原代码无此行
//
//			matrix[ind1][ind2] = edge1;
//			matrix[ind2][ind1] = edge2;//*原代码matrix[ind2][ind1] = edge1，临接矩阵不同方向的标记都用了同一方向的边
//		}
//	}
//
//	//循环执行挑选最短边步骤
//	memset(v, 0, sizeof(v));
//	v[0] = 1;
//
//	//以第一个点初始化lowcost
//	upd_lowcost(0);
//
//	int value=0,count = n;
//	while (--count)//循环选出每个点并输出边
//	{
//		Edge e_min = getMin(lowcost);
//		v[e_min.j] = 1;//边的列坐标代表边的出度点标号
//		value += e_min.value;
//		cout << "(" << e_min.i << "," << e_min.j << "),";
//
//		upd_lowcost(e_min.j);//以新入选的点更新lowcost各未入选点到当前树的最短距离
//	}
//	
//	cout << value << endl;
//	system("pause");
//	return 0;
//}

/*解法三：克鲁斯卡尔算法（用边的结构体，但不需要临接矩阵）
错误次数：1
原因：循环n-1次时，用的是while(--n)，这样n最终会变成0，导致错误，所有这种循环不熟悉就不要轻易用，
应该另外声明一个变量i赋值n，再用while(--i),或者直接用for循环
*/

//#include<iostream>
//using namespace std;
//#define infinite 200
//typedef struct {
//	int i=-1, j=-1, value= infinite,tag=0;//tag标记该边是否入选
//}Edge;
//Edge*  getInstance_edge(int i,int j,int v) {
//	Edge* edge = (Edge*)malloc(sizeof(Edge));
//	edge->i = i;
//	edge->j = j;
//	edge->value = v;
//	return edge;
//}
//
//static Edge edges[450];//无向边组，该算法不同方向无需存储两次
//static int set[26];//父节点索引存储结构，用于并查集判断是否构成回路，即两点同祖父（同集合）不能再合并（连一条边）
//static int n;
//
//int getInd(char c) {
//	return c - 'A';
//}
//int cmp_edge(const void* e1, const void* e2) {
//	Edge* edge1 = (Edge*)e1;
//	Edge* edge2 = (Edge*)e2;
//	return (edge1->value < edge2->value) ? -1 : 1;
//}
////查找祖父结点带压缩
//int getAnces(int node) {
//	if (set[node] == node)return node;
//	set[node] = getAnces(set[node]);//将父亲设置成父亲的祖先，即压缩
//	return set[node];
//}
////合并两个结点
//void combine_nodes(int a,int b) {//b所在集合并入a所在集合，即b的祖先认a的祖先为父
//	int ancestor_a=getAnces(a);
//	int ancestor_b=getAnces(b);
//	set[ancestor_b] = ancestor_a;
//}
////判断是否构成回路
//bool isCandidator(Edge e) {
//	if (getAnces(e.i) == getAnces(e.j))return false;//有相同祖先，合并就构成回路
//	return true;
//}
//int main() {
//	cin >> n;
//
//	int count_e=0;
//	for (int i = 0; i < n - 1;++i)//n-1次循环，因为题设最后一个点无输入
//	{
//		char c; int num_e;
//		cin >> c; cin >> num_e;
//		int ind1 = getInd(c);
//		while (num_e--)
//		{
//			char c; int v;
//			cin >> c;  cin >> v;
//			int ind2 = getInd(c);
//			Edge edge = *getInstance_edge(ind1, ind2, v);
//			edges[count_e++] = edge;
//		}
//	}
//	//边输入完毕
//	//边从小到大排序
//	qsort(edges, count_e, sizeof(edges[0]), cmp_edge);
//
//	
//	//初始化用到的并查集
//	for (int i = 0; i < n; ++i)set[i] = i;//各点初始化指向自己，自己是自己的父，各自为一个集合
//	//从小到大遍历边，若不构成回路，则入选
//	for (int i = 0; i < count_e; ++i) {
//		if (isCandidator(edges[i])) {
//			edges[i].tag = 1;//标记为入选
//			combine_nodes(edges[i].i, edges[i].j);//合并（连接）该边的两点
//		}
//	}
//	//输出入选边及价值
//	int value = 0;
//	for (int i = 0; i < count_e; ++i) {
//		if (edges[i].tag == 1) {
//			value += edges[i].value;
//			cout << "(" << edges[i].i << "," << edges[i].j << "),";
//		}
//	}
//	cout << value << endl;
//	system("pause");
//	return 0;
//
//}