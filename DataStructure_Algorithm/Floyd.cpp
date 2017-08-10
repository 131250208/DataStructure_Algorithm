/*
	Floyd�㷨
	ͼ�����ⶥ��Ե����·���㷨
	
	�㷨˼�룺
		�������ж��㣬������Ϊ�м�㣬
		��������������������м������·����
		�Ƿ��������ԭ�������·����Ҫ��
		����ǣ���������·��
*/

#include<iostream>
using namespace std;

#define n 4//����size
#define INFINITY 999

int adj[n][n];//���·����������
int path[n][n];//pre�ڵ�����

void floyd_go(int graph[][n],int adj[][n],int path[][n]) {
	//��ʼ��adj��path����
	for (int i = 0; i < n;++i) {
		for (int j = 0; j < n;++j) {
			adj[i][j] = graph[i][j];
			if (graph[i][j] != INFINITY) {//�����·�������pre���±��¼
				path[i][j] = i;
			}
		}
	}

	//����ѭ��ʵ�ֺ����㷨
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n;++i) {
			for (int j = 0; j < n;++j) {
				if (adj[i][k] + adj[k][j] < adj[i][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];	//�������·����
					path[i][j] = k;						//����pre�±�
				}
			}
		}
	}
}

//�������
void print_matrix(int group[][n]) {
	for (int i = 0; i < n;++i) {
		for (int j= 0; j < n; ++j) {
			cout <<group[i][j]<<" ";
		}
		cout << endl;
	}
}
//���·��
void print_path(int u,int v,int path[][n]) {
	if (path[u][v]==u) {//��ȵ�Ϊ����˵��û��pre��
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


