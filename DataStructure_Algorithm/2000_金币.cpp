/*10min*/
#include<iostream>
#include<stdio.h>
using namespace std;

int getMoney(int days) {
	int money = 0;
	for (int i = 1;; ++i) {
		for (int j = 0; j < i; ++j) {
			money += i;
			--days;
			if (days == 0)return money;
		}
	}
	return -1;
}
//int main() {
//	int days;
//	while (true)
//	{
//		scanf("%d", &days);
//		if (days == 0)break;
//
//		int money = getMoney(days);
//		printf("%d %d\n", days, money);
//	}
//	system("pause");
//	return 0;
//}