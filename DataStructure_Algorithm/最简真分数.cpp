#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
static int nums[610];

bool isLegal_2012b(int a,int b) {//辗转相除求最大公约数，如果是1，则可以组成最简真分数
	int num;
	while ((num=b%a))
	{
		b = a;
		a = num;
	}
	if (a == 1)return true;
	else return false;
}
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i) {
//		scanf("%d", &nums[i]);
//	}
//
//	sort(nums, nums + n);
//
//	int count_2012b = 0;
//	for (int i = 0; i < n - 1; ++i) {
//		for (int j = i + 1; j < n; ++j) {
//			if (isLegal_2012b(nums[i], nums[j])) {
//				count_2012b++;
//			}
//		}
//	}
//
//	printf("%d\n", count_2012b);
//	system("pause");
//	return 0;
//}