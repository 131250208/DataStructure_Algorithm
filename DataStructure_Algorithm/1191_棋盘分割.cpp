/*Accepted
错误次数：2
1、min和max参数只能有2个，写成3个报了错
2、record的数组开小了，n可以取14，为了方便则record要开15（0~14）------13
*/
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm>
using namespace std;
static int chessboard[8][8];
static 	int n;
static int record[15][8][8][8][8];
//计算矩形的分数和
int calculate_goals(int x1,int y1,int x2,int y2) {
	int res = 0;
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			res += chessboard[i][j];
		}
	}
	return res;
}
//递归计算最小平方和
int fun(int n, int x1, int y1, int x2, int y2) {
	//有记录直接返回
	if (record[n][x1][y1][x2][y2] != -1)return record[n][x1][y1][x2][y2];
	//如果n==1，则不需要再分割，返回分数和的平方
	if (n == 1) {
		int t = calculate_goals(x1, y1, x2, y2);
		record[n][x1][y1][x2][y2] = t*t;
		return t*t;
	}
	//如果需要分割，则枚举所有可能的切割进行递归
	int Min = 10000000;
	int par1, par2;
	for (int i = x1; i < x2; ++i) {
		par1 = calculate_goals(x1, y1, i, y2);
		par2 = calculate_goals(i + 1, y1, x2, y2);
		int temp = min((par1*par1 + fun(n - 1, i + 1, y1, x2, y2)), (par2*par2 + fun(n - 1, x1, y1, i, y2)));
		Min = (temp < Min) ? temp : Min;
	}
	for (int i = y1; i < y2; ++i) {
		par1 = calculate_goals(x1, i+1, x2, y2);
		par2 = calculate_goals(x1, y1, x2, i);
		int temp = min((par1*par1 + fun(n - 1, x1, y1, x2, i)), (par2*par2 + fun(n - 1, x1, i + 1,  x2, y2)));
		Min = (temp < Min) ? temp : Min;
	}
	record[n][x1][y1][x2][y2] = Min;
	return Min;
}
//int main() {
//	memset(record, -1, sizeof(record));
//
//	cin >> n;
//	for (int i = 0; i < 8; ++i)
//		for (int j = 0; j < 8; ++j)
//			cin >> chessboard[i][j];
//
//	double xi_2=((fun(n, 0, 0, 7, 7)+0.0) / n);
//	double x_average=(calculate_goals(0, 0, 7, 7)+0.) / n;
//	double res = pow(xi_2 - x_average*x_average, 0.5);
//	cout << setiosflags(ios::fixed) << setprecision(3) << res << endl;
//	system("pause");
//	return 0;
//}