/*Accepted

���������1
1��û�п��������пո�����----31

˼·��
1������������ת���ɶ����ƴ洢
2��дһ��������������������������ȡ�ַ���ȡ�����Ժ�ͷ���'0'����
3��������---��ͷ����---��ͷ����---��ͷ���Ͻ�ȡ�õ��ַ������֤��ѭ��ֱ������������������һ����Ǿ�����������Ѿ��߹��ĵط�
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

char getchar_fr_num2() {//��ǰ��������ȡ���ַ�������ȡ��ͷ���'0'
	ind_num2--;//��ת����2���ƵĹ����Ѿ��ۼӺ���
	if (ind_num2 >= 0)return txt_num2[ind_num2];
	return '0';
}
void trans_to_txt_num2(char txt[]) {//Ϊ���㣬����ת����2���ƴ洢��txt_num2
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
		while (ind_num2 < ((len - i) * 5))txt_num2[ind_num2++] = '0';//ÿ����ĸ��Ҫ����5λ
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