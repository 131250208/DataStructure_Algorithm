/*
跟视频基本一致
但是提交后run time erro

注意：
结构体不能用static修饰
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Region
{
	double left, right;
	Region(){}
	Region(double l, double r) :left(l), right(r) {
	}
};

static Region regions[1010];
static 	int n, d;
static	double right_min;//当前小岛对应区域组的最小右端点
bool operator < (const Region &a, const Region &b) {
	return a.left < b.left;
}
int del_group_1328() {
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y > d)return -1;
		double dis = sqrt(d*d - y*y);
		regions[i] = Region((double)x - dis, (double)x + dis);
	}
	sort(regions, regions + n);
	
	right_min = regions[0].right;
	int num_radar = 1;

	for (int i = 1; i < n; ++i) {
		if (regions[i].left <= right_min) {
			right_min = min(right_min, regions[i].right);
		}
		else//如果是不在当前组的公共范围内（左端点大于当前组的最小右端点）
		{
			//新开一个雷达，更新当前组的最小右端点，因为区域已经按左端点升序排列，
			//所以后面的区域不会再跟前面的组有交集，只需要关注当前组
			++num_radar;
			right_min = regions[i].right;
		}
	}

	return num_radar;
}
//int main() {
//
//	int num_group = 1;
//	while (true)
//	{
//		cin >> n >> d;
//		if (n == 0 && d == 0)break;
//		int num_radar=del_group_1328();
//		cout << "Case " << num_group++ << ": " << num_radar << endl;
//	}
//	system("pause");
//	return 0;
//}