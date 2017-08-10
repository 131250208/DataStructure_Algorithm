/*错误次数：1
scanf的格式很严格，不要随便加多余空格
*/
#include<iostream>
#include<stdio.h>
using namespace std;

int getMethods(int M, int N) {//M个苹果分到N个盘的分法
	if (M < N)return 0;
	if (N == 1)return 1;
	return getMethods(M - 1, N - 1) + getMethods(M - N, N);
}
//int main() {
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int M, N;
//		scanf("%d %d", &M, &N);
//		int methods = 0;
//		for (int i = 1; i <= N; ++i) {
//			methods += getMethods(M, i);
//		}
//		printf("%d\n", methods);
//	}
//	system("pause");
//	return 0;
//}