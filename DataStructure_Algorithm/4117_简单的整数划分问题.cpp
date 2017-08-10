#include<iostream>
#include<stdio.h>
using namespace std;

//��n���ֳ����ɲ�����m����������������۰棩---�ݹ�
//int recurse_4117(int n, int m) {
//	if (n == 1 || m == 1)return 1;
//	if (n < m)return recurse_4117(n, n);
//	if (n == m)return recurse_4117(n, m - 1) + 1;
//	if (n > m)return recurse_4117(n - m, m) + recurse_4117(n, m - 1);
//}

//��n���ֳ����ɲ�����m���������򻯰棩---�ݹ�
int recurse_4117(int n, int m) {
	if (n == 0)return 1;//״̬��n,n����һ����֧����n���ֳɲ�����n�еģ�����n���������ֻ��n�����������Ψһ������1
	if (n < 0)return 0;
	if (n == 1 || m == 1)return 1;
	return recurse_4117(n - m, m) + recurse_4117(n, m - 1);//��m�����+û��m�����
															//��m���������ȥ1��m��ʣ�µĺ��ٻ��ֳɲ�����m�ģ���������ͬ����������m��
															//û��m����������൱��n���ֳɲ�����m-1���������
}

//��n���ֳ����ɲ�����m����������̬�滮��---���Ƽ�����������С���ݹ��ظ�����Ҳ���ࣩ
static int matrix[60][60];//�洢��״̬����ľ���(n,m)
//��̬�滮�������״̬�Ľ��
void dp_4117() {
	//��ʼ������״̬������
	for (int i = 0; i <= 50; ++i) {
		matrix[0][i] = 1;
		matrix[1][i] = 1;
	}
	for (int i = 0; i <= 50; ++i) {
		matrix[i][0] = 0;
		matrix[i][1] = 1;
	}

	for (int i = 2; i <= 50; ++i) {
		for (int j = 2; j <= 50; ++j) {
			if (i - j < 0)matrix[i][j] = matrix[i][j-1];
			else
			{
				matrix[i][j] = matrix[i - j][j] + matrix[i][j-1];
			}
		}
	}
}
//int main() {
//	//dp_4117();
//	int n; 
//	while (scanf("%d",&n)!=EOF)
//	{
//		int res = recurse_4117(n, n);
//		//int res = matrix[n][n];
//		printf("%d\n", res);
//	}
//	system("pause");
//	return 0;
//}