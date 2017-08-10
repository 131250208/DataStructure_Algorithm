/*
	Floyd算法
	图的任意顶点对的最短路径算法
	
	算法思想：
		遍历所有顶点，将其作为中间点，
		检查所有其他两个点与中间点的最短路径和
		是否比两个点原来的最短路径还要短
		如果是，则更新最短路径
*/

#include<iostream>
using namespace std;

#define n 4//数组size
#define INFINITY 999

int adj[n][n];//最短路径长度数组
int path[n][n];//pre节点数组

void floyd_go(int graph[][n],int adj[][n],int path[][n]) {
	//初始化adj和path数组
	for (int i = 0; i < n;++i) {
		for (int j = 0; j < n;++j) {
			adj[i][j] = graph[i][j];
			if (graph[i][j] != INFINITY) {//如果有路径到达，则将pre的下标记录
				path[i][j] = i;
			}
		}
	}

	//三重循环实现核心算法
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n;++i) {
			for (int j = 0; j < n;++j) {
				if (adj[i][k] + adj[k][j] < adj[i][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];	//更新最短路径长
					path[i][j] = k;						//更新pre下标
				}
			}
		}
	}
}

//输出矩阵
void print_matrix(int group[][n]) {
	for (int i = 0; i < n;++i) {
		for (int j= 0; j < n; ++j) {
			cout <<group[i][j]<<" ";
		}
		cout << endl;
	}
}
//输出路径
void print_path(int u,int v,int path[][n]) {
	if (path[u][v]==u) {//入度点为本身，说明没有pre了
		cout << path[u][v] << " ";
	}
	else
	{
		int mid = path[u][v];
		print_path(u,mid,path);
		print_path(mid, v, path);
	}
}
//int main() {
//	int test[][4] = {
//		{0,5,999,7},
//		{999,0,4,2},
//		{3,3,0,2},
//		{999,999,1,0}
//	};
//	floyd_go(test, adj, path);
//	print_matrix(adj);
//	print_matrix(path);
//	print_path(1,0,path);
//	system("pause");
//	return 0;
//}


