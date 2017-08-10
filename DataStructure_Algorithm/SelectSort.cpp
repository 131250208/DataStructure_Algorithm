/*÷±Ω”—°‘Ò≈≈–Ú*/

#include<iostream>
#include "MyKit.h"
using namespace std;


void selectSort(int records[], int n) {
	int smallest,j;
	for (int i = 0; i < n;++i) {
		smallest = i;
		for (j = i + 1; j < n;++j) {
			if (records[j]<records[smallest]) {
				smallest = j;
			}
		}
		swap(records, i, smallest);
	}
}

//int main() {
//	int records[] = { 3,2,7,5,7,3,2,5,6,90,76,43,12 };
//
//	selectSort(records, 13);
//	printRecords(records, 13);
//	system("pause");
//	return 0;
//}