/*错了好多次
低级错误：
1、价格用了整数，导致浮点数转换成整数时，有丢失
2、money第一天不是50，是N，审题不清
*/
#include<iostream>
#include<stdio.h>
using namespace std;
//int main() {
//	double N, K;
//	scanf("%lf %lf", &N, &K);
//
//	double money;
//	double price = 200;
//	double rate = 1 + K/ 100;
//	for (int i = 2; i <= 20; ++i) {
//		money =i*N;
//		price *= rate;
//		if (money >= price) {
//			printf("%d\n", i);
//			system("pause");
//			return 0;
//		}
//	}
//	printf("Impossible\n");
//	system("pause");
//	return 0;
//}