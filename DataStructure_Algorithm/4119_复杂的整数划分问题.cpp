#include<iostream>
#include<stdio.h>
using namespace std;

//问题1 将n划分成k个数
int recurse_4119_1(int n,int k) {
	if (n < k)return 0;//n最多划分成n个1，超过n则返回0
	if (k == 1)return 1;//如果是划分成1个数只有一种情况
	return recurse_4119_1(n - 1, k - 1) + recurse_4119_1(n - k, k);
}

//问题2 将n划分成不同整数
int recurse_4119_2(int n, int m) {//将n划分成若干不大于m且不同的整数的情况数量的递归函数
	if (m == 1 && n > m)return 0;//大于1的数划分成不大于1的若干整数，一定会出现相同的1，不符合题意
	if ( n == 1||n==0)return 1;
	if (n < 0)return 0;
	return recurse_4119_2(n - m, m - 1) + recurse_4119_2(n, m - 1);//有m的情况+没有m的情况
																	//有m的情况=n减去m剩余的和划分成不大于m-1（因划分的
																	//数不能相同，可相同则还是m）的情况数量
}

//问题3 将n划分成若干个奇正整数
int recurse_4119_3(int n, int m) {//将n划分成若干不大于m的奇正整数的情况数量的递归函数
	if (m % 2 == 0)return recurse_4119_3(n, m - 1);//如果m是偶数，相当于将n划分成不大于m-1（与m相邻的一个奇数）的……
	if (m == 1 || n == 1 || n == 0)return 1;
	if (n < 0)return 0;
	return recurse_4119_3(n - m, m) + recurse_4119_3(n, m - 2);
}
//int main() {
//	int n, k;
//	while (scanf("%d %d", &n, &k) != EOF)
//	{
//		int res1 = recurse_4119_1(n, k);
//		int res2 = recurse_4119_2(n, n);
//		int res3 = recurse_4119_3(n, n);
//		printf("%d\n", res1);
//		printf("%d\n", res2);
//		printf("%d\n", res3);
//	}
//	system("pause");
//	return 0;
//}