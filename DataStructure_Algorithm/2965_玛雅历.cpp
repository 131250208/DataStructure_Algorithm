/*Accepted
关注：1、map的使用 2、atoi char数组转化成int
提交错误次数：0；
*/
#include<iostream>
#include<string>
#include<string.h>
#include<map>

using namespace std;

map <string, int> map_m_Haab;
map <int, string> map_d_Tzolkin;

void initialMap() {
	string m_str[19] = { "pop", "no", "zip", "zotz", "tzec", "xul",
		"yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac",
		"kankin", "muan", "pax", "koyab", "cumhu","uayet" };
	int m_int[19] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	for (int i = 0; i < 19; ++i) {
		map_m_Haab.insert(pair<string, int>(m_str[i], m_int[i]));
	}
	int d_int[20]= { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	string d_str[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik",
		"lamat", "muluk", "ok", "chuen", "eb", "ben",
		"ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
	for (int i = 0; i < 20;++i) {
		map_d_Tzolkin.insert(pair<int, string>(d_int[i], d_str[i]));
	}
}
int getDays(string m,int d) {//用月份日期计算今年过了多少天
	return (map_m_Haab[m] - 1) * 20 + d;
}
void cout_Tzolkin(int days) {
	int d_int = 0; string d_string; int y = 0;
	y = days / 260;
	int days_left = days % 260;
	d_int = (days_left % 13) + 1;
	d_string = map_d_Tzolkin[(days_left % 20) + 1];
	cout << d_int << " " << d_string << " " << y << endl;
}
//int main() {
//	int n = 0;
//	cin >> n;
//	cout << n << endl;
//	char d[4]; char m[7]; int y = 0;
//	int num_days = 0;//用于计算总天数
//	//初始化map
//	initialMap();
//	for (int i = 0; i < n; ++i) {
//		cin >> d; cin >> m; cin >> y;
//		num_days= y * 365;
//
//		d[strlen(d) - 1] = '\0';//将'.'换成结束符
//
//		string m_str = m;
//		int d_int = atoi(d);
//		num_days += getDays(m_str, d_int);
//
//		cout_Tzolkin(num_days);
//	}
//	system("pause");
//	return 0;
//}