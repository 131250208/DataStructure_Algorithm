/*���������1
scanf�ĸ�ʽ���ϸ񣬲�Ҫ���Ӷ���ո�
*/
#include<iostream>
#include<stdio.h>
using namespace std;

int getMethods(int M, int N) {//M��ƻ���ֵ�N���̵ķַ�
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