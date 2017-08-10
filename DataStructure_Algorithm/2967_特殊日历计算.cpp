/*Accepted
�ύ���������1
˼·��ʱ������ڷֿ����㣬��Ϊһ��ĳ�������ȵģ��ؼ����ڼ�����2000.1.1�ļ��������ע��������ж�

���ֵ�ʧ��
char����map�޸�ʱ�޸ĳ�������----41
�����ж���&&д����||-------19
�ж�����ĺ�����д��ʵ��i-------29
�ַ����ָ�����˵�һ�Σ������ʵ�ζ�Ҫ��NULL------66��67��70��71
�¾��������볤�Ȳ�һ��������˵������������һ����һ�����ģ�����Ҫ����-------34
��������ܱ�3200������������----20
*/
#include<iostream>
#include<string.h>
using namespace std;
//�ж��Ƿ�����
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
		if (isBissextile(i))++days;//*�����ټ�1��
	}
	return days;
}
void transCalendar(int h, int min, int s, int d, int month, int y) {
	int second =(s + min * 60 + h*3600)/0.864;//*����ʱ����ȫ������������������룬������ĳ��Ȳ�ͬ
	int second_s = second % 100;
	int min_s = (second / 100) % 100;
	int h_s = second / 10000;

	int days = 0;
	char map[] = "303232332323";
	if (isBissextile(y))map[1] ='1';//*��������꣬2��+1��
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
//		//�ֽ�
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