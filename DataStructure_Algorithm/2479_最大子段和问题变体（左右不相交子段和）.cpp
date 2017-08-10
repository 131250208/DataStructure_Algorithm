/*Accepted
错误次数：3
原因：
1、超时，因为输入量大，用cin会超时，要用scanf
2、超时，重复计算，原来的代码思路是遍历每个数（作为左字段结尾），
两子段分别调用各自的函数（计算各个状态字段和的代码在里面）计算每个点的最大子段和。（循环体中多次调用函数，就多次计算了各个状态）
3、结果错误，最大值初值应该设为一个极小的值（-999999），原代码设置成了0，
如果计算出的结果是负数，与0比较输出了0就错了。

正确思路：
应该将两个方向的所有状态子段和统一计算好，
存放在数组中，最后再循环遍历各个数作为左子段结尾，求两子段最大和
*/
/*看一个较简单的问题（单个段的最大子段和）

我们来分析一下最大子段和的子结构，令b[j]表示从a[0]~a[j]的最大子段和，b[j]的当前值只有两种情况，(1) 最大子段一直连续到a[j]  (2) 以a[j]为起点的子段，不知有没有读者注意到还有一种情况，那就是最大字段没有包含a[j]，如果没有包含a[j]的话，那么在算b[j]之前的时候我们已经算出来了，注意我们只是算到位置为j的地方，所以最大子断在a[j]后面的情况我们可以暂时不考虑。
由此我们得出b[j]的状态转移方程为：b[j]=max{b[j-1]+a[j],a[j]},
所求的最大子断和为max{b[j],0<=j<n}。进一步我们可以将b[]数组用一个变量代替。

*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
static int n;
static int a[50000];
static int b[50000];
static int c[50000];

void cal_maxsum_subsequence() {
	b[0] = a[0];
	for (int i = 1; i <n; ++i) {
		b[i] = max(b[i - 1] + a[i], a[i]);//1、递推式，但并非表示以坐标i结尾的左子段的最大字段和，
											//因为这里只比较了两种情况，还有不包括a[i]的情况，之前的b[i-1]已计算出
											//所以还有第二步比较
	}
	for (int i = 1; i < n; ++i)b[i] = max(b[i], b[i - 1]);//2
															//1,2两步是求得各个状态最大子段和的的关键步骤
	c[n-1] = a[n-1];
	for (int i = n-2; i >= 0; --i) {
		c[i] = max(c[i + 1] + a[i], a[i]);
	}
	for (int i = n - 2; i >= 0; --i)c[i] = max(c[i], c[i + 1]);
}
void del_group_2479() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)scanf("%d", &a[i]);

	cal_maxsum_subsequence();

	int res_max= -99999;
	int sum;
	for (int i = 0; i < n-1; ++i) {
		sum = b[i] + c[i + 1];
		res_max = max(res_max, sum);
	}
	printf("%d\n", res_max);
}
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	for (int i = 0; i < T; ++i) {
//		del_group_2479();
//	}
//	system("pause");
//	return 0;
//}