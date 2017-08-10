//#include<iostream>
//#include<stdio.h>
//#include<string.h>
//using namespace std;
//static int readers[210];
//static int book[210];
//
//int main() {
//	memset(book, 0, sizeof(book));
//	int N, M;
//	scanf("%d %d ", &N, &M);
//	for (int i = 0; i < N; ++i) {
//		scanf("%d", &readers[i]);
//		book[readers[i]]++;
//	}
//	for (int i = 0; i < N; ++i) {
//		int num = book[readers[i]]-1;
//		if (num == 0)printf("BeiJu\n");
//		else printf("%d\n", num);
//	}
//	system("pause");
//	return 0;
//}