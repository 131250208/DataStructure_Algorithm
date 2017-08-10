/* Accepted

*/

#include<iostream>
#include<stdio.h>
using namespace std;
static int mapping_days_y[2] = {365,366};
static int mapping_days_mon[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};
static char mapping_week[][20] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

bool isLeapYear(int y) {
	if (y % 4==0) {
		if (y % 100 == 0 && y % 400 != 0)return false;
		return true;
	}
	return false;
}
//int main() {
//	int days;
//	while (scanf("%d",&days)!=EOF)
//	{
//		if (days == -1)break;
//		char* w = mapping_week[days % 7];
//		int y=2000, m=0;
//		for ( y= 2000; days >= mapping_days_y[isLeapYear(y)]; ++y) {
//			days -= mapping_days_y[isLeapYear(y)];
//		}
//		int ind = isLeapYear(y);
//		for (m = 0; days >= mapping_days_mon[ind][m]; ++m) {
//			days -= mapping_days_mon[ind][m];
//		}
//
//		printf("%d-%02d-%02d %s\n", y, m+1, days+1, w);
//	}
//	system("pause");
//	return 0;
//}
