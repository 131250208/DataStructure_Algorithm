#include<iostream>
#include<stdio.h>
using namespace std;
static int pic[110][110];
static int n;
bool isBoundary(int i,int j) {
	if (i - 1 < 0 || i + 1 >= n || j - 1 < 0 || j + 1 >= n)return true;
	if (pic[i - 1][j] > 50 || pic[i + 1][j] > 50 || pic[i][j - 1] > 50 || pic[i][j + 1] > 50)return true;
	return false;
}
//int main() {
//
//	scanf("%d", &n);
//
//	int S=0, C=0;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			scanf("%d", &pic[i][j]);
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			if (pic[i][j] <= 50) {
//				S++;
//				if (isBoundary(i, j))C++;
//			}
//		}
//	}
//	printf("%d %d\n", S, C);
//
//	system("pause");
//	return 0;
//}