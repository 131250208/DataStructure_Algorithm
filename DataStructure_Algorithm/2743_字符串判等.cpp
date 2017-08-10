/*考前练习
错误次数：1
1、字符串比较函数一定要判定==0，==0是相等
注意：
去空格的方法
while ((ind = s1.find(" ")) != string::npos)s1.erase(ind,1);//别忘了erase函数第二个参数是擦除的字符个数
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
//int main() {
//	char str1[500];
//	char str2[500];
//	gets_s(str1);
//	gets_s(str2);
//
//	string s1 = str1;
//	string s2 = str2;
//	int ind;
//	while ((ind = s1.find(" ")) != string::npos)s1.erase(ind,1);
//	while ((ind=s2.find(" "))!=string::npos)s2.erase(ind,1);
//
//	if (_stricmp(s1.c_str(), s2.c_str())==0)printf("YES\n");
//	else printf("NO\n");
//	system("pause");
//	return 0;
//}
/*
百炼上的编译器是在linux环境下
stricmp不能通过编译，而用strcasecmp可以
*/
//#include<iostream>
//#include<string>
//#include<string.h>
//using namespace std;

//int main() {
//	char line1[100];
//	char line2[100];
//	cin.getline(line1, 100);
//	cin.getline(line2, 100);
//	string s1 = line1;
//	string s2 = line2;
//	//去空格
//	int index = 0;
//	while ((index=s1.find(" "))!=string::npos) {
//		s1 = s1.erase(index, 1);
//	}
//	while ((index = s2.find(" ")) != string::npos) {
//		s2 = s2.erase(index, 1);
//	}
//
//	if(_stricmp(s1.c_str(),s2.c_str())==0)cout << "YES";
//	else
//	{
//		cout << "NO";
//	}
//	system("pause");
//	return 0;
//}