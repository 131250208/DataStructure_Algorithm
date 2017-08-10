/*插入排序*/

#include<iostream>
using namespace std;

void insertSort(int records[],int n) {

	for (int i = 1; i < n;++i) {//依次持有记录records[i]向前比较
		int temp = records[i];//暂时保存要比较的数
		int j;
		for ( j= i - 1; j >= 0&& temp<records[j]; --j) {//比较到小于等于的数，则结束循环，
														//把records[i]放它后面
			//大的数往后移动
			records[j + 1] = records[j];

		}

		records[j+1] = temp;//要加回最后-的1
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

