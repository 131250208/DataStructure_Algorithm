/*ϣ������*/

#include<iostream>
using namespace std;

void insertSort_delta(int records[], int start, int n, int delta);

void shellSort(int records[], int n) {
	int delta;//����
	for (delta = n / 2; delta >= 1;delta/=2) {//����ÿ��ѭ����Сһ��
		for (int i = 0; i < delta;++i) {
			insertSort_delta(records, i,n, delta);
		}
	}
	insertSort_delta(records, 0, n, 1);
}

void insertSort_delta(int records[], int start,int n,int delta) {//��deltaΪ����ֱ�Ӳ�������
	for (int i = start+delta; i < n/delta; i+=delta) {//���γ��м�¼records[i]��ǰ�Ƚ�
		int temp = records[i];//��ʱ����Ҫ�Ƚϵ���
		int j;
		for (j = i - delta; j >= start && temp<records[j]; j-=delta) {//�Ƚϵ�С�ڵ��ڵ����������ѭ����
														 //��records[i]��������
														 
			records[j + delta] = records[j];//����������ƶ�

		}

		records[j + delta] = temp;//Ҫ�ӻ����-��1
	}
}



//int main() {
//	int records[] = { 3,2,7,5,7,3,2,5,6,90,76,43,12 };
//	shellSort(records, 13);
//
//	printRecords1(records, 13);
//
//	system("pause");
//	return 0;
//}