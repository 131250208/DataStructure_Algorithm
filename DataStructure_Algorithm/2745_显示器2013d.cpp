#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static char numbers[100000010];
static int s;
static int len;
static int map[10][7] = {
	{ 1,1,1,0,1,1,1 },
	{ 0,0,1,0,0,1,0 },
	{1,0,1,1,1,0,1},
	{ 1,0,1,1,0,1,1 },
	{ 0,1,1,1,0,1,0 },
	{ 1,1,0,1,0,1,1 },
	{ 1,1,0,1,1,1,1 },
	{ 1,0,1,0,0,1,0 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,0,1,1 },
};
void draw_h(int h) {
	for (int i = 0; i < len; ++i) {
		printf(" ");
		if (map[numbers[i] - '0'][h]) {
			for (int j = 0; j < s; ++j)printf("-");
		}
		else { for (int j = 0; j < s; ++j)printf(" "); }
		printf("  ");
	}
	printf("\n");
}
void draw_v(int v1,int v2) {
	for (int j = 0; j < s; ++j) {
		for (int i = 0; i < len; ++i) {
			int num = numbers[i] - '0';
			if (map[num][v1])printf("|");
			else printf(" ");
			for (int k = 0; k < s; ++k)printf(" ");
			if (map[num][v2])printf("|");
			else printf(" ");
			printf(" ");
		}
		printf("\n");
	}
}
//int main() {
//	while (true)
//	{
//		scanf("%d %s", &s, &numbers);
//		if (s == 0 && strcmp(numbers, "0")==0)break;
//
//		len = strlen(numbers);
//		//0ºÅÎ»
//		draw_h(0);
//		//1¡¢2
//		draw_v(1, 2);
//		//3
//		draw_h(3);
//		//4¡¢5
//		draw_v(4, 5);
//		//6
//		draw_h(6);
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}