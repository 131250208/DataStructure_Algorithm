/*��ǰ��ϰ---��������
*/
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define INF_1724 1<<30
using namespace std;

struct Edge_1724
{
	int S, D, L, T;
	Edge_1724(int ss,int dd,int ll,int tt):S(ss),D(dd),L(ll),T(tt){}
};

static vector<Edge_1724> edges[110];//�����±�ΪԴ
static char sign[110];
static int cost[110][10010];//ĳλ�û�ʣĳ�̲�ʱ���ߵ������·����
static 	int K, N, R;
static int len_min;
void dfs_1724(int pos, int k, int len) {
	if (sign[pos] == '@')return;
	if (k < 0)return;
	//�������Ż���֦
	if (len > len_min)return;
	if (len >= cost[pos][k])return;
	cost[pos][k] = len;

	sign[pos] = '@';

	if (pos == N) {
		len_min = min(len_min, len);
		return;
	}

	for (int i = 0; i < edges[pos].size(); ++i) {
		dfs_1724(edges[pos][i].D, k - edges[pos][i].T, len + edges[pos][i].L);
	}
	sign[pos] = '0';//����
}
//int main() {
//
//	scanf("%d", &K);
//	scanf("%d", &N);
//	scanf("%d", &R);
//	for (int i = 0; i < R; ++i) {
//		int S, D, L, T;
//		scanf("%d %d %d %d", &S, &D, &L ,&T);
//		edges[S].push_back(Edge_1724(S, D, L, T));
//	}
//	//��ʼ��
//	memset(sign, '0', sizeof(sign));
//	len_min = INF_1724;
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 0; j < 10010; ++j) {
//			cost[i][j] = INF_1724;
//		}
//	}
//	//����
//	dfs_1724(1, K, 0);
//
//	if (len_min == INF_1724)printf("-1\n");
//	else printf("%d\n", len_min);
//
//	system("pause");
//	return 0;
//}
/*Accepted

���������4
1������߹��õ㣬����ʱ©��ȡ�������---------------------------------------------------------------------72
2����ʱ���������һ����֦���ԣ���ǰ·���������Ѿ���¼�����·��ʱ�������ٵݹ���ȥ��Ӧ�û���---------------62
3��©���Ҳ���һ��·��������������Ӧ�����-1-------------------------------------------------------------91
4����ʱ������һ����֦���������ߵ�����srcʱ����ʣǮΪkʱ����ǰ·����֮ǰ�洢�ĸ����·�������򲻱��ٵݹ�---50

˼·��
1�����ѡ�����ʱ�ѻ���Ǯ�ӻ������ۼ�·����
2������������1��û������δ�߹��Ŀɴ���� 2��Ǯ������
3���ؼ���һ��·�ߵ�Ŀ��ʱ���õ�ǰ·�����Ƚ����·������ȡ�̵Ĵ���
4��Notice that different roads may have the same source and destination cities.
	��ͬ��Դ����ͬ�Ļ�����ж���·����Ӧ�ò��ö�̬���飨�ڽӱ��洢�ߣ���Ӧ�����ٽӾ���
5��ע��Ҫ��ȡһЩ��֦���ܽ�ʡʱ��
*/
//#include<iostream>
//#include<string.h>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//#define inf 200
//#define inf_path 1500000
//typedef struct {
//	int src=-1, des=-1, len= inf, toll= inf;
//}Edge;
//
//Edge* getIns_edge(int src,int des,int len,int toll) {
//	Edge* edge = (Edge*)malloc(sizeof(Edge));
//	edge->src = src;
//	edge->des = des;
//	edge->len = len;
//	edge->toll = toll;
//	return edge;
//}
////static Edge matrix[101][101];//���1��ʼ����
//static vector<Edge> adjac_list[101];
//static int sign[101];//���Ŀǰ�߹��ĵ�
//static int k, n, r;
//static int len_min = inf_path;
//static int len_path=0;
//static int midl[101][10100];
//void ds_path(int src) {
//	if (sign[src] == 1)return;
//	if (src == n) {//����ִ�Ŀ�ģ��Ƚ�·����
//		len_min = min(len_path, len_min);
//	}
//	//*��֦
//	if (len_path >= midl[src][k])return;
//	midl[src][k] = len_path;
//
//	sign[src] = 1;//����߹������
//	
//	for (int i = 0; i < adjac_list[src].size(); ++i) {
//		int toll = adjac_list[src][i].toll;
//		if (toll > k)continue;//��֦������̲�����ֱ�ӻ�������һ��·
//		int len = adjac_list[src][i].len;
//		k -= toll;
//		len_path += len;
//		if (len_path > len_min) {//*��֦������·�Ѿ����ڵ�ǰ��С·��,����
//			k += toll;
//			len_path -= len;
//			continue;
//		}
//		ds_path(adjac_list[src][i].des);//�Կɴ����Ϊ�µ�Դ�ݹ�
//		//����
//		k += toll;
//		len_path -= len;
//	}
//	sign[src] = 0;//*ȡ�����
//}
//int main() {
//	cin >> k; cin >> n; cin >> r;
//	for (int i = 0; i < r; ++i) {
//		int src, des, len, toll;
//		cin >> src; cin >> des; cin >> len; cin >> toll;
//		Edge edge = *getIns_edge(src, des, len, toll);
//		adjac_list[src].push_back(edge);
//	}
//
//	//������ϣ���ʼ����
//	for (int i = 1; i <= 100; ++i)
//		for (int j = 0; j < 10100; ++j)
//			midl[i][j] = inf_path;
//
//	memset(sign, 0, sizeof(sign));
//	ds_path(1);
//
//	if (len_min == inf_path)cout << -1 << endl;
//	else cout << len_min<<endl;
//	system("pause");
//	return 0;
//}