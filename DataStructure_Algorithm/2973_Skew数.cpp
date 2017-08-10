/*
输入200000000000000000000000000000超过int和long long范围
应该用字符串操作
char转int用 char-'0'
*/
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

int trans_skew(char num[]) {
	int length = strlen(num);
	int res = 0;
	for (int i = 0; i < length;++i) {
		int now = (num[i])-'0';
		if(now!=0)res += now*(pow(2.0, (double)(length - i)) - 1);
		if (now == 2)break;
	}
	return res;
}

//int main() {
//	while (true)
//	{
//		char input[32];
//		cin.getline(input, 32);
//		if (input[0]=='0')break;
//		cout << trans_skew(input)<<endl;
//	}
//	system("pause");
//	return 0;
//}