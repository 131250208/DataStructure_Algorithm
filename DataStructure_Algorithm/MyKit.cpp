#include<iostream>
#include "MyKit.h"
#include <stdlib.h> 
#include <time.h> 
#include<cmath>
using namespace std;


//����ת��,����-1��Ϊ����ת�������д��ڽ��ƻ��ص���
int trans_asis(int num,int a,int b) {
	int res = num % a;
	if (res >= b)return -1;

	int i = 1;
	while (true)
	{
		num = num / a;
		if (num == 0)break;
		int temp = num % a;
		if (temp >= b)return -1;
		res += temp*pow((double)b, (double)i);
		++i;
	}
	return res;
}
int _trans_ten(int num,int b) {//ת����10����
	return trans_asis(num, 10, b);
}
int ten_trans_(int num,int b) {//��10����ת��������
	return trans_asis(num, b, 10);
}
#define maxsize 500
//��ӡ��¼
void printRecords(int records[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << records[i] << " ";
	}
}
//��������Ԫ��
void swap(int records[], int i, int j) {
	int temp;
	temp = records[i];
	records[i] = records[j];
	records[j] = temp;
}
//������ɲ���Ԫ��
void giveBirthToSomeSample(int *&records) {
	records = (int *)malloc(maxsize*sizeof(int));

	srand((unsigned)time(NULL));

	for (int i = 0; i < maxsize;++i) {
		records[i] = rand()%1000+1;
	}
}