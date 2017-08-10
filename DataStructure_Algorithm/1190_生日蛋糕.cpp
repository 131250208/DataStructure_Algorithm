/*Accepted
错误次数:2
原因：
1、逻辑判断失误-----28
2、计算剩余层最大体积数时 r每次循环都多-1了-----18
*/
#include<iostream>
#include<algorithm>
using namespace std;
static int area,area_min=1<<30;//当前表面积，最小表面积
static int v_min[21];//最小体积
static int s_min[21];//最小侧表面积
static int N, M;//体积、层数
int getv_Max(int m, int r, int h) {//当前最大半径与最大高度为r,h时剩余m层的体积
	int v=0;
	while (m--)
	{
		v += r*r*h;//*这三行对应的原错误代码：v+=r--*r--*h--;
		--r;
		--h;
	}
	return v;
}
void dfs_1190(int n, int m, int r_max, int h_max) {//深搜，参数：剩余体积，剩余层数，该层最大半径，最大高度
	if (n == 0 && m == 0) {
		area_min = min(area, area_min);
		return;
	}
	else if (n <= 0 || m == 0)return;	//*原错误代码：else if (n <= 0 || m != 0)return;这样永远没法递归下去，因为m开始一定>0
										//注意剩余体积可能减到负数，而m是递减1，一定会经过0
	
	//同上逻辑
	/*if (m == 0) {
		if (n)return;
		else
		{
			area_min = min(area, area_min);
			return;
		}
	}
	if (n <= 0)return;*/

	//剪枝策略
	if (r_max < m || h_max < m)return;//该层最大半径或高度小于下限m(层号)
	if (v_min[m] > n)return;//剩余层的最小体积已经大于剩余体积
	if (getv_Max(m, r_max, h_max) < n)return;//剩余层最大体积小于剩余体积
	if (s_min[m] + area >= area_min)return;//最优化剪枝：如果当前表面积加上剩余层的最小表面积都大于当前已经得到的最小表面积，已经不必算下去了
	for (int r = r_max; r >= m; --r) {
		if (m == M)area = r*r;//剩余层数为M时（算第一层时），加上底面
		for (int h = h_max; h >= m; --h) {
			area += 2*r*h;
			dfs_1190(n - r*r*h, m - 1, r - 1, h - 1);//搜下一层，剩余体积减少，层数-1，下一层的最大半径与最大高度都比当前层少1
			area -= 2*r*h;//回溯
		}
	}
}
//int main() {
//	cin >> N; cin >> M;
//
//	//计算对应层数的最小体积与最小侧表面积
//	v_min[0] = 0;
//	s_min[0] = 0;
//	for (int i = 1; i <= M; ++i) {
//		v_min[i] = v_min[i - 1] + i*i*i;
//		s_min[i] = s_min[i - 1] + 2 * i*i;
//	}
//
//	if (v_min[M] > N) {
//		cout << 0 << endl;
//		return 0;
//	}
//	else if(v_min[M]==N)
//	{
//		cout << M*M+s_min[N] << endl;
//		return 0;
//	}
//
//	//计算底层最大高度和最大半径(上限)
//	int h_max, r_max;
//	h_max = (N - v_min[M - 1]) / M*M+1;
//	r_max = sqrt(double(N - v_min[M - 1]) / M)+1;
//
//	//初始化当前表面积与最小表面积，进行深搜
//	area = 0;
//	area_min = 1 << 30;
//	dfs_1190(N, M, r_max, h_max);//从最底层开始往上搜
//
//	if (area_min == 1 << 30)cout << 0 << endl;
//	else cout << area_min << endl;
//
//	system("pause");
//	return 0;
//}