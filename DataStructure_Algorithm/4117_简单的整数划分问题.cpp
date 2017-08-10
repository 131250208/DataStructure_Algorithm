#include<iostream>
#include<stdio.h>
using namespace std;

//将n划分成若干不大于m的整数（分情况讨论版）---递归
//int recurse_4117(int n, int m) {
//	if (n == 1 || m == 1)return 1;
//	if (n < m)return recurse_4117(n, n);
//	if (n == m)return recurse_4117(n, m - 1) + 1;
//	if (n > m)return recurse_4117(n - m, m) + recurse_4117(n, m - 1);
//}

//将n划分成若干不大于m的整数（简化版）---递归
int recurse_4117(int n, int m) {
	if (n == 0)return 1;//状态（n,n）的一个分支，即n划分成不大于n中的，包含n的情况（即只有n），所以情况唯一，返回1
	if (n < 0)return 0;
	if (n == 1 || m == 1)return 1;
	return recurse_4117(n - m, m) + recurse_4117(n, m - 1);//有m的情况+没有m的情况
															//有m的情况：减去1个m，剩下的和再划分成不大于m的（整数可相同，还可能有m）
															//没有m的情况：那相当于n划分成不大于m-1的情况数量
}

//将n划分成若干不大于m的整数（动态规划版---不推荐，数据量较小，递归重复计算也不多）
static int matrix[60][60];//存储各状态结果的矩阵(n,m)
//动态规划计算各个状态的结果
void dp_4117() {
	//初始化基本状态的数据
	for (int i = 0; i <= 50; ++i) {
		matrix[0][i] = 1;
		matrix[1][i] = 1;
	}
	for (int i = 0; i <= 50; ++i) {
		matrix[i][0] = 0;
		matrix[i][1] = 1;
	}

	for (int i = 2; i <= 50; ++i) {
		for (int j = 2; j <= 50; ++j) {
			if (i - j < 0)matrix[i][j] = matrix[i][j-1];
			else
			{
				matrix[i][j] = matrix[i - j][j] + matrix[i][j-1];
			}
		}
	}
}
//int main() {
//	//dp_4117();
//	int n; 
//	while (scanf("%d",&n)!=EOF)
//	{
//		int res = recurse_4117(n, n);
//		//int res = matrix[n][n];
//		printf("%d\n", res);
//	}
//	system("pause");
//	return 0;
//}