/*Accepted
 记住计算月份间天数的思想----统一月份天数，再算每月差补

 提交错误次数：1
 原因与纠正：细菌数目要用long型
 */

#include<iostream>
#include<cmath>
using namespace std;

int getDays(int m1,int d1,int m2,int d2) {
	char map[13] = "303232332323";//补超过28的天数
	//接下来用每月28天来算
	int dur = 0;
	for (int i = m1-1 ; i < m2-1; ++i)dur += 28+(map[i]-'0');

	int res = dur -d1 + d2;
	return res;
}
//int main() {
//	int n = 0;
//	cin >> n;
//	int m1 = 0, d1 = 0, m2 = 0, d2 = 0, num_bacteria = 0;
//	for (int i = 0; i < n; ++i) {
//		cin >> m1; cin >> d1; cin >> num_bacteria; cin >> m2; cin >> d2;
//		int days = getDays(m1, d1, m2, d2);
//		long num = num_bacteria*pow(2., (double)days);
//		cout << num<<endl;
//	}
//	system("pause");
//	return 0;
//}