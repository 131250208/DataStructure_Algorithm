/*希尔排序*/

#include<iostream>
using namespace std;

void insertSort_delta(int records[], int start, int n, int delta);

void shellSort(int records[], int n) {
	int delta;//步长
	for (delta = n / 2; delta >= 1;delta/=2) {//步长每个循环减小一半
		for (int i = 0; i < delta;++i) {
			insertSort_delta(records, i,n, delta);
		}
	}
	insertSort_delta(records, 0, n, 1);
}

void insertSort_delta(int records[], int start,int n,int delta) {//以delta为步长直接插入排序
	for (int i = start+delta; i < n/delta; i+=delta) {//依次持有记录records[i]向前比较
		int temp = records[i];//暂时保存要比较的数
		int j;
		for (j = i - delta; j >= start && temp<records[j]; j-=delta) {//比较到小于等于的数，则结束循环，
														 //把records[i]放它后面
														 
			records[j + delta] = records[j];//大的数往后移动

		}

		records[j + delta] = temp;//要加回最后-的1
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