/*ð������*/

#include<iostream>
#include "MyKit.h"
using namespace std;

void bubbleSort(int records[],int n) {
	for (int j = 1; j <= n - 1;++j) {//ÿһ�����һ��Ԫ�أ������һ���Ѿ���λ�Ĳ����ٱȽ�
		for (int i = 0; i < n - j; i++) {
			if (records[i]>records[i+1])//������ں�һ�����ͽ���λ��
			{
				swap(records, i, i + 1);
			}
		}
	}
}

//int main() {
//	int *records = NULL;
//	giveBirthToSomeSample(records);
//
//	bubbleSort(records, 500);
//	printRecords(records, 500);
//
//	system("pause");
//	return 0;
//}