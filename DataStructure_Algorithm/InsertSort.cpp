/*��������*/

#include<iostream>
using namespace std;

void insertSort(int records[],int n) {

	for (int i = 1; i < n;++i) {//���γ��м�¼records[i]��ǰ�Ƚ�
		int temp = records[i];//��ʱ����Ҫ�Ƚϵ���
		int j;
		for ( j= i - 1; j >= 0&& temp<records[j]; --j) {//�Ƚϵ�С�ڵ��ڵ����������ѭ����
														//��records[i]��������
			//����������ƶ�
			records[j + 1] = records[j];

		}

		records[j+1] = temp;//Ҫ�ӻ����-��1
	}
}

//int main() {
//	int records[] = {3,2,7,5,7,3,2,5,6,90,76,43,12};
//	insertSort(records, 13);
//
//	printRecords(records, 13);
//
//	system("pause");
//	return 0;
//}

