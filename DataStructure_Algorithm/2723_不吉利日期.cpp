/*Accepted
注意：
用map计算月份天数差的方法
*/
#include<iostream>
using namespace std;

int getDays(int m) {//计算m月13号距离1月1间隔有多少天
	char map[] = "303232332323" ;//每个月与28天的差
	int days = 0;
	for (int i = 0; i < m - 1; ++i) {
		days += 28+map[i] - '0';
	}
	return (days + 13 - 1)%7;
}
//int main() {
//	int w = 0;
//	cin >> w;
//	
//	for (int i = 1; i <= 12;++i) {
//		if ((w + getDays(i))%7==5){
//			cout << i << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}