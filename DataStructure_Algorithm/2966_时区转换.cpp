/*
出现的失误：
strcmp()的返回结果是0时是相等，而不是1时
map忘记初始化
赋值失误-----line24、25的两个时区索引搞反
注意：
分钟固定2位用0补齐
h小时的计算前后0和12要换算，题设的起始是12，而我们习惯用0作起始----38、55
*/
#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;
static map<string, double> map_timeTrans;

void initMap() {
	string timezones[32] = { "UTC","GMT" ,"BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD",
		"AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT"
		,"AEST","AEDT","ACST","ACDT","AWST" };
	double timegap[32] = {0.,0.,1.,1.,0.,1.,1.,2.,2.,3.,3.,4.,-4.,-3.,-3.5,-2.5,-5.,-4.,-6.,-5.,-7.,-6.,-8.,-7.,-10.,-9.,-8.,10.,11.,9.5,10.5,8.};
	for (int i = 0; i < 32; ++i) {
		map_timeTrans.insert(pair<string, double>(timezones[i], timegap[i]));
	}
}
void transTime(char time[],string a_p,string timezone1,string timezone2) {
	double gap_tz1 = map_timeTrans[timezone1];//*
	double gap_tz2= map_timeTrans[timezone2];//*
	double gap = gap_tz2 - gap_tz1;

	int h=atoi(strtok(time, ":"));
	int min = atoi(strtok(NULL, ":"));

	int gap_min = gap * 60+min;
	int gap_h = gap_min / 60;//算出小时的加减
	int gap_min_left = gap_min % 60;//算出分钟部分

	if (h == 12)h = 0;//*
	if ((gap_h + h) < 0 || (gap_h + h) >= 12) {
		if (a_p == "a.m.")a_p = "p.m.";
		else if (a_p == "p.m.")a_p = "a.m.";
	}

	h = (gap_h + h + 12) % 12;


	if (gap_min_left >= 0) {
		min = gap_min_left;
	}
	else
	{
		min=60+ gap_min_left;
		--h;
	}
	if (h == 0)h = 12;//*

	if (h == 12 && min == 0 && a_p == "a.m.")cout << "midnight" << endl;
	else if (h == 12 && min == 0 && a_p == "p.m.")cout << "noon" << endl;
	else {
		cout << h << ":";
		cout.fill('0');//*
		cout.width(2);//*

		cout << min;
		cout << " " << a_p << endl;
	}
}
//int main() {
//	int n = 0;
//	cin >> n;
//	initMap();//*
//	for (int i = 0; i < n; ++i) {
//		char time[9]; char a_p[5]; char tz1[5]; char tz2[5];
//		cin >> time;
//		if (strcmp(time, "noon")==0) {//*
//			strcpy(time, "12:00");
//			strcpy(a_p, "p.m.");
//		}
//		else if (strcmp(time, "midnight")==0) {//*
//			strcpy(time, "12:00");
//			strcpy(a_p, "a.m.");
//		}
//		else
//		{
//			cin >> a_p;
//		}
//		cin >> tz1;
//		cin >> tz2;
//
//		string a_p_s = a_p;
//		string tz1_s = tz1;
//		string tz2_s = tz2;
//		transTime(time, a_p_s, tz1_s, tz2_s);
//	}
//	system("pause");
//	return 0;
//}