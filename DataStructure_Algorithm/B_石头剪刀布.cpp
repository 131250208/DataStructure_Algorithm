/*18min*/
#include<iostream>
#include<stdio.h>
using namespace std;

int win(int a,int b) {
	if (a == b)return 0;
	if ((a == 5 && b == 0) ||
		(a == 2 && b == 5) ||
		(a == 0 && b == 2))return 1;
	return -1;
}
//int main() {
//	int N,NA,NB;
//	scanf("%d %d %d", &N, &NA, &NB);
//
//	int moves_a[120];
//	int moves_b[120];
//	for (int i = 0; i < NA; ++i)scanf("%d", &moves_a[i]);
//	for (int i = 0; i < NB; ++i)scanf("%d", &moves_b[i]);
//
//	int win_a = 0;
//	int win_b = 0;
//	for (int i = 0; i < N; ++i) {
//		int move_a = moves_a[i%NA];
//		int move_b = moves_b[i%NB];
//		if (win(move_a, move_b) == 1)win_a++;
//		if (win(move_a, move_b) == -1)win_b++;
//	}
//
//	if (win_a > win_b)printf("A\n");
//	if (win_a < win_b)printf("B\n");
//	if(win_a==win_b)
//	{
//		printf("draw\n");
//	}
//	system("pause");
//	return 0;
//}