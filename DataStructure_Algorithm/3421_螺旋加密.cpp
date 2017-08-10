/*Accepted

错误次数：1
1、没有考虑输入有空格的情况----31

思路：
1、将输入逆向转换成二进制存储
2、写一个函数逆向从这个二进制数组中取字符，取完了以后就返回'0'来补
3、按向右---到头向下---到头向左---到头向上将取得的字符填入举证，循环直到矩阵填满，可以用一个标记矩阵辅助，标记已经走过的地方
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static char matrix[30][30];
static char sign[30][30];
static int R, C;
static char txt_num2[500];
static int ind_num2 = 0;

char getchar_fr_num2() {//往前遍历数组取出字符给矩阵，取完就返回'0'
	ind_num2--;//在转换成2进制的过程已经累加好了
	if (ind_num2 >= 0)return txt_num2[ind_num2];
	return '0';
}
void trans_to_txt_num2(char txt[]) {//为方便，逆序转换成2进制存储于txt_num2
	int len = strlen(txt);
	for (int i =len -1; i >= 0; --i) {
		int num;
		if (txt[i] == ' ')num = 0;//*
		else num = txt[i] - 'A' + 1;
		while (true)
		{
			txt_num2[ind_num2++]=char(num % 2+'0');
			if ((num = num / 2) == 0)break;
		}
		while (ind_num2 < ((len - i) * 5))txt_num2[ind_num2++] = '0';//每个字母都要补够5位
	}
}
bool in(int i, int j) {
	return i >= 0 && i < R&&j >= 0 && j < C && (sign[i][j] == '0');
}
//int main() {
//
//	char txt[100];
//	scanf("%d %d", &R, &C);
//	getchar();
//	gets_s(txt);
//	trans_to_txt_num2(txt);
//
//	int num_c = R*C;
//	memset(sign, '0', sizeof(sign));
//	int i = 0,j=-1;
//	while (num_c)
//	{
//		while (in(i,++j))
//		{
//			matrix[i][j]=getchar_fr_num2();
//			sign[i][j] = '@';
//			num_c--;
//		}
//		--j;
//		while (in(++i,j))
//		{
//			matrix[i][j] = getchar_fr_num2();
//			sign[i][j] = '@';
//			num_c--;
//		}
//		--i;
//		while (in(i, --j))
//		{
//			matrix[i][j] = getchar_fr_num2();
//			sign[i][j] = '@';
//			num_c--;
//		}
//		++j;
//		while (in(--i, j))
//		{
//			matrix[i][j] = getchar_fr_num2();
//			sign[i][j] = '@';
//			num_c--;
//		}
//		++i;
//	}
//
//	for (int i = 0; i < R; ++i) {
//		for(int j = 0; j < C; ++j) {
//			printf("%c", matrix[i][j]);
//		}
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}