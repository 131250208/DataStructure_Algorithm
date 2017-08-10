/*考前练习---待检查错误
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

static vector<Edge_1724> edges[110];//数组下标为源
static char sign[110];
static int cost[110][10010];//某位置还剩某盘缠时能走到的最短路径长
static 	int K, N, R;
static int len_min;
void dfs_1724(int pos, int k, int len) {
	if (sign[pos] == '@')return;
	if (k < 0)return;
	//两个最优化剪枝
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
	sign[pos] = '0';//回溯
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
//	//初始化
//	memset(sign, '0', sizeof(sign));
//	len_min = INF_1724;
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 0; j < 10010; ++j) {
//			cost[i][j] = INF_1724;
//		}
//	}
//	//深搜
//	dfs_1724(1, K, 0);
//
//	if (len_min == INF_1724)printf("-1\n");
//	else printf("%d\n", len_min);
//
//	system("pause");
//	return 0;
//}
/*Accepted

错误次数：4
1、标记走过该点，回溯时漏掉取消标记了---------------------------------------------------------------------72
2、超时，疏忽少了一个剪枝策略：当前路径长超过已经记录的最短路径时，不必再递归下去，应该回溯---------------62
3、漏掉找不到一条路径的情况，该情况应该输出-1-------------------------------------------------------------91
4、超时，还有一个剪枝操作：当走到城市src时且所剩钱为k时，当前路径比之前存储的该情况路径长，则不必再递归---50

思路：
1、深搜、回溯时把花的钱加回来、累计路径长
2、回溯条件：1、没有其他未走过的可达点了 2、钱不够了
3、关键：一条路走到目标时，用当前路径长比较最短路径长，取短的储存
4、Notice that different roads may have the same source and destination cities.
	相同的源和相同的汇可能有多条路，故应该采用动态数组（邻接表）存储边，不应该用临接矩阵
5、注意要采取一些剪枝才能节省时间
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
////static Edge matrix[101][101];//点从1开始计数
//static vector<Edge> adjac_list[101];
//static int sign[101];//标记目前走过的点
//static int k, n, r;
//static int len_min = inf_path;
//static int len_path=0;
//static int midl[101][10100];
//void ds_path(int src) {
//	if (sign[src] == 1)return;
//	if (src == n) {//如果抵达目的，比较路径长
//		len_min = min(len_path, len_min);
//	}
//	//*剪枝
//	if (len_path >= midl[src][k])return;
//	midl[src][k] = len_path;
//
//	sign[src] = 1;//标记走过这个点
//	
//	for (int i = 0; i < adjac_list[src].size(); ++i) {
//		int toll = adjac_list[src][i].toll;
//		if (toll > k)continue;//剪枝，如果盘缠不够直接回溯找下一条路
//		int len = adjac_list[src][i].len;
//		k -= toll;
//		len_path += len;
//		if (len_path > len_min) {//*剪枝，这条路已经大于当前最小路径,回溯
//			k += toll;
//			len_path -= len;
//			continue;
//		}
//		ds_path(adjac_list[src][i].des);//以可达点作为新的源递归
//		//回溯
//		k += toll;
//		len_path -= len;
//	}
//	sign[src] = 0;//*取消标记
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
//	//输入完毕，开始深搜
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