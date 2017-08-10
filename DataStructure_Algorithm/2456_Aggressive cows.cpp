/*Accepted
错误次数：0
思路：
最大、最小问题可以转换成二分判断问题
1、二分查找合适的最大距离x
	1、确定x的范围
	2、进行二分查找
	3、打破循环后，
			最大问题---right是结果
			最小问题---left是结果
2、关键：判断函数---对于x（牛间距必须不小于x），判断是否能够将牛都安排完，能安排完就返回true；
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

static int stalls[100010];
static int n, c;
bool isOk(int x) {

	int pre = stalls[0];
	int count=c-1;

	for (int i = 1; i < n; i++)
	{
		if (stalls[i] - pre >= x) {
			pre = stalls[i];
			--count;
			if (count == 0)return true;
		}
	}

	return false;
}

//int main() {
//	
//	scanf("%d %d", &n,&c);
//
//	for (int i = 0; i < n; ++i) {
//		scanf("%d", &stalls[i]);
//	}
//
//	sort(stalls, stalls + n);
//	int dis_min = 1 << 30;//一个极大的数，1左移30位，2的30次方，不能再左移1位，1左移31位就是以1开头了（有符号的负数
//	for (int i = 1; i < n; ++i) {
//		int dis=stalls[i]-stalls[i-1];
//		dis_min = min(dis, dis_min);
//	}
//	int dis_max = stalls[n - 1] - stalls[0];
//
//	int left = dis_min,right=dis_max;
//	int mid;
//	while (left<=right)
//	{
//		mid = (left + right) / 2;
//		if (isOk(mid))left=mid+1;
//		else right = mid - 1;
//	}
//
//	printf("%d\n", right);
//
//	system("pause");
//	return 0;
//}