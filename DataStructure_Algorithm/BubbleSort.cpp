/*冒泡排序*/

#include<iostream>
#include "MyKit.h"
using namespace std;

void bubbleSort(int records[],int n) {
	for (int j = 1; j <= n - 1;++j) {//每一遍减少一个元素，即最后一个已经到位的不必再比较
		for (int i = 0; i < n - j; i++) {
			if (records[i]>records[i+1])//如果大于后一个，就交互位置
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