/*Accepted
提交错误次数：1
思路：时间和日期分开换算，因为一天的长度是相等的，关键在于计算与2000.1.1的间隔天数，注意闰年的判断

出现的失误：
char数组map修改时修改成了数字----41
闰年判断是&&写成了||-------19
判断闰年的函数少写了实参i-------29
字符串分割函数除了第一次，后面的实参都要用NULL------66、67、70、71
新旧日历的秒长度不一（因题设说明两种日历的一天是一样长的），需要换算-------34
该题假设能被3200整除的是闰年----20
*/
#include<iostream>
#include<string.h>
using namespace std;
//判断是否闰年
bool isBissextile(int y) {
	if (y % 4==0) {
		if (y % 100 == 0 && y % 400 != 0) return false;//*
		//if (y % 3200 == 0)return false;
		return true;
	}
	return false;
}
int getDays_y(int y) {
	int days = 0;
	for (int i = 2000; i < y; ++i) {
		days += 365;
		if (isBissextile(i))++days;//*闰年再加1天
	}
	return days;
}
void transCalendar(int h, int min, int s, int d, int month, int y) {
	int second =(s + min * 60 + h*3600)/0.864;//*当天时分秒全换算成特殊日历法的秒，两种秒的长度不同
	int second_s = second % 100;
	int min_s = (second / 100) % 100;
	int h_s = second / 10000;

	int days = 0;
	char map[] = "303232332323";
	if (isBissextile(y))map[1] ='1';//*如果是闰年，2月+1天
	for (int i = 0; i < month - 1; ++i) {
		days += 28 + (map[i] - '0');
	}
	days = days + d - 1;
	days += getDays_y(y);

	int day_s = days % 100;
	int m_s = (days / 100) % 10;
	int y_s = days / 1000;

	cout << h_s << ":" << min_s << ":" << second_s << " " << day_s+1 << "." << m_s+1 << "." << y_s << endl;
}
//int main() {
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		char time[9]; char date[11];
//		cin >> time;
//		cin >> date;
//
//		//分解
//		int h=0,min=0,s=0;
//		int d = 0, month = 0, y = 0;
//		h=atoi(strtok(time, ":"));
//		min = atoi(strtok(NULL, ":"));
//		s = atoi(strtok(NULL, ":"));
//
//		d = atoi(strtok(date, "."));
//		month = atoi(strtok(NULL, "."));
//		y = atoi(strtok(NULL, "."));
//
//		transCalendar(h, min, s, d, month, y);
//	}
//	
//
//	system("pause");
//	return 0;
//}