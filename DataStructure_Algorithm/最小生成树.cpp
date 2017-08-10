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
//			scanf(" %c %d", & head, & m);  //ע���ַ��������⣬�س���Ҳ�ᱻ����һ���ַ�������%cǰҪ��һ���ո�
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

/*����2016�о��������ϻ��� ���Ӽ��ղ�
����
��һ��ֻ����һ����ʾ���Ǹ�������n��n������26��������n���������ɴ�д��ĸ�����ǰn����ĸ��ʾ��
��������n-1��������ĸ���ǰn-1����ĸ��ͷ�����һ�����Ǳ�ʾ����ĸ�������롣����ÿһ�У���ÿ
�����Ǳ�ʾ����ĸ��ͷ��Ȼ��������һ�����֣���ʾ�ж������߿��Դ�������ǵ�������ĸ���е���
�ǡ����k�Ǵ���0����ʾ���к�����ʾk���ߵ�k�����ݡ�ÿ���ߵ��������ɱ�ʾ���ӵ���һ�����ǵ�
��ĸ�͸ñߵ�Ȩֵ��ɡ�Ȩֵ���������Ĳ���С��100�����е����������ֶηָ���һ�հס���������
�罫ʼ���������е����ǡ����������罫��Զ���ᳬ��75���ߡ�û���κ�һ�����ǻ��г���15���ı���
�ӵ��������ǣ�֮ǰ��֮�����ĸ�����������ʾ�����룬�������������ͼ��һ�µġ�

���
�����һ����������ʾ��С��Ȩֵ��

��ȷ�����216

��������
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
//��ϰPrim
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
//		getchar();//�µ�һ���س�
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
//	//������ϣ���ʼɸѡ��
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
//		v[ind_min] = '@';//����ѡ�������
//		upd_lowc(ind_min);
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

/*�ⷨһ��prim�㷨�����ֻ������СȨֵ���޷�����ߣ�
���������2
ԭ��
1���ٽӾ���int�����ʼ��������memset
2���������ݵ��ٽӾ���ʱ��©���˷���ߣ����1���ڵ�2�ɴ2��1Ӧ��Ҳ�ɴ�
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
//	//memset(matrix, infinite, sizeof(int)*26*26);//*��ֵΪ���߲��ɴ200,memsetֻ�ʺ�������ʼ��char���飬���߳�ʼ��int����Ϊ0
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
//			matrix[index_c][index_r] = value;//*�����Ҳ�����Ȩֵ
//		}
//	}
//
//	/*prime�㷨���Ĵ���,�����Ƕ�ȡ���ݽ��ٽӾ���*/
//	memset(v, 0, sizeof(v));
//	v[0] = 1;//�ӵ�һ���㿪ʼ
//
//	int focus = 0;
//	memcpy(lowcost, matrix[0], sizeof(matrix[0]));
//
//	//ѭ����ѡ���ʵĶ��㲢�ۼ�Ȩֵ
//	int count = n,sum=0;
//	while (--count!=0)
//	{
//		int index = getindex_min(lowcost);
//		v[index] = 1;//�������ѡ�ı�
//		sum += lowcost[index];//�ۼ�Ȩֵ
//		upd_lowc(index);
//	}
//
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}


/*�ⷨ����prim�㷨���ýṹ�壬���������ߣ�
���������1
ԭ�򣺲��ֽṹ��Ľڵ���û����matrix�������Ӧ---142��145
�ջ�
1���ṹ��д�˳�ʼֵ�����Խṹ����������ʱ���ᰴ����ʼֵ�Ľṹ���Զ���ʼ�����飬�����ֶ�����
ע�⣺���ؽṹ��һ��Ҫ����ռ�---119
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
//		if (v[i] != 1) {//δ��ѡ�Ĳ���Ҫ����
//			lowcost[i] = (matrix[r][i].value < lowcost[i].value) ? matrix[r][i] : lowcost[i];
//		}
//	}
//}
//Edge getMin(Edge lowc[]) {
//	Edge edge=*getInstance_edge(-1,-1, infinite);//*
//	for (int i = 0; i < n; ++i) {
//		if (v[i] != 1) {//��δ��ѡ�ı��������
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
//			Edge edge2 = *getInstance_edge(ind2, ind1, v);//*ԭ�����޴���
//
//			matrix[ind1][ind2] = edge1;
//			matrix[ind2][ind1] = edge2;//*ԭ����matrix[ind2][ind1] = edge1���ٽӾ���ͬ����ı�Ƕ�����ͬһ����ı�
//		}
//	}
//
//	//ѭ��ִ����ѡ��̱߲���
//	memset(v, 0, sizeof(v));
//	v[0] = 1;
//
//	//�Ե�һ�����ʼ��lowcost
//	upd_lowcost(0);
//
//	int value=0,count = n;
//	while (--count)//ѭ��ѡ��ÿ���㲢�����
//	{
//		Edge e_min = getMin(lowcost);
//		v[e_min.j] = 1;//�ߵ����������ߵĳ��ȵ���
//		value += e_min.value;
//		cout << "(" << e_min.i << "," << e_min.j << "),";
//
//		upd_lowcost(e_min.j);//������ѡ�ĵ����lowcost��δ��ѡ�㵽��ǰ������̾���
//	}
//	
//	cout << value << endl;
//	system("pause");
//	return 0;
//}

/*�ⷨ������³˹�����㷨���ñߵĽṹ�壬������Ҫ�ٽӾ���
���������1
ԭ��ѭ��n-1��ʱ���õ���while(--n)������n���ջ���0�����´�����������ѭ������Ϥ�Ͳ�Ҫ�����ã�
Ӧ����������һ������i��ֵn������while(--i),����ֱ����forѭ��
*/

//#include<iostream>
//using namespace std;
//#define infinite 200
//typedef struct {
//	int i=-1, j=-1, value= infinite,tag=0;//tag��Ǹñ��Ƿ���ѡ
//}Edge;
//Edge*  getInstance_edge(int i,int j,int v) {
//	Edge* edge = (Edge*)malloc(sizeof(Edge));
//	edge->i = i;
//	edge->j = j;
//	edge->value = v;
//	return edge;
//}
//
//static Edge edges[450];//������飬���㷨��ͬ��������洢����
//static int set[26];//���ڵ������洢�ṹ�����ڲ��鼯�ж��Ƿ񹹳ɻ�·��������ͬ�游��ͬ���ϣ������ٺϲ�����һ���ߣ�
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
////�����游����ѹ��
//int getAnces(int node) {
//	if (set[node] == node)return node;
//	set[node] = getAnces(set[node]);//���������óɸ��׵����ȣ���ѹ��
//	return set[node];
//}
////�ϲ��������
//void combine_nodes(int a,int b) {//b���ڼ��ϲ���a���ڼ��ϣ���b��������a������Ϊ��
//	int ancestor_a=getAnces(a);
//	int ancestor_b=getAnces(b);
//	set[ancestor_b] = ancestor_a;
//}
////�ж��Ƿ񹹳ɻ�·
//bool isCandidator(Edge e) {
//	if (getAnces(e.i) == getAnces(e.j))return false;//����ͬ���ȣ��ϲ��͹��ɻ�·
//	return true;
//}
//int main() {
//	cin >> n;
//
//	int count_e=0;
//	for (int i = 0; i < n - 1;++i)//n-1��ѭ������Ϊ�������һ����������
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
//	//���������
//	//�ߴ�С��������
//	qsort(edges, count_e, sizeof(edges[0]), cmp_edge);
//
//	
//	//��ʼ���õ��Ĳ��鼯
//	for (int i = 0; i < n; ++i)set[i] = i;//�����ʼ��ָ���Լ����Լ����Լ��ĸ�������Ϊһ������
//	//��С��������ߣ��������ɻ�·������ѡ
//	for (int i = 0; i < count_e; ++i) {
//		if (isCandidator(edges[i])) {
//			edges[i].tag = 1;//���Ϊ��ѡ
//			combine_nodes(edges[i].i, edges[i].j);//�ϲ������ӣ��ñߵ�����
//		}
//	}
//	//�����ѡ�߼���ֵ
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