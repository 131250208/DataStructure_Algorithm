#include<iostream>
#include<stdio.h>
using namespace std;

//����1 ��n���ֳ�k����
int recurse_4119_1(int n,int k) {
	if (n < k)return 0;//n��໮�ֳ�n��1������n�򷵻�0
	if (k == 1)return 1;//����ǻ��ֳ�1����ֻ��һ�����
	return recurse_4119_1(n - 1, k - 1) + recurse_4119_1(n - k, k);
}

//����2 ��n���ֳɲ�ͬ����
int recurse_4119_2(int n, int m) {//��n���ֳ����ɲ�����m�Ҳ�ͬ����������������ĵݹ麯��
	if (m == 1 && n > m)return 0;//����1�������ֳɲ�����1������������һ���������ͬ��1������������
	if ( n == 1||n==0)return 1;
	if (n < 0)return 0;
	return recurse_4119_2(n - m, m - 1) + recurse_4119_2(n, m - 1);//��m�����+û��m�����
																	//��m�����=n��ȥmʣ��ĺͻ��ֳɲ�����m-1���򻮷ֵ�
																	//��������ͬ������ͬ����m�����������
}

//����3 ��n���ֳ����ɸ���������
int recurse_4119_3(int n, int m) {//��n���ֳ����ɲ�����m��������������������ĵݹ麯��
	if (m % 2 == 0)return recurse_4119_3(n, m - 1);//���m��ż�����൱�ڽ�n���ֳɲ�����m-1����m���ڵ�һ���������ġ���
	if (m == 1 || n == 1 || n == 0)return 1;
	if (n < 0)return 0;
	return recurse_4119_3(n - m, m) + recurse_4119_3(n, m - 2);
}
//int main() {
//	int n, k;
//	while (scanf("%d %d", &n, &k) != EOF)
//	{
//		int res1 = recurse_4119_1(n, k);
//		int res2 = recurse_4119_2(n, n);
//		int res3 = recurse_4119_3(n, n);
//		printf("%d\n", res1);
//		printf("%d\n", res2);
//		printf("%d\n", res3);
//	}
//	system("pause");
//	return 0;
//}