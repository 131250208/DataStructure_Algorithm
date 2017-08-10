/*
提交结果：accept
错误分析：
题目未给结束判断，输入用的是while(ture)
提交结果是超时,用cin>>语句本身判断是否还有输入，如line28
*/

#include<iostream>
#include<string.h>
using namespace std;

void isSubsequence(char s[],char t[]) {
	int i = 0, j = 0;
	int len_s = strlen(s);
	int len_t = strlen(t);

	while (true)
	{
		if (j == len_t&&i != len_s) { cout << "No"<<endl; break; }
		if (i == len_s) {
			cout << "Yes"<<endl; break;
		}
		if (s[i] == t[j]) { ++i; ++j; }
		else {++j; }
	}
}
//int main() {
//	char s[100001];
//	char t[100001];
//	while (cin >> s&&cin >> t)
//	{
//		isSubsequence(s, t);
//	}
//	system("pause");
//	return 0;
//}