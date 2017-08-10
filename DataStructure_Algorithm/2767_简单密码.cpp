/*
注意输出要转换成char
17行 要考虑到index减完5以后可能是负数，后要加了26再模26*/

#include<iostream>
using namespace std;

//int main() {
//	char chars[201];
//	cin.getline(chars, 201);
//	int i = 0;
//	while (chars[i]!='\0')
//	{
//		char c_temp = chars[i];
//		int index = (c_temp - 'A');
//		if (index >=0&& index<26) {
//			cout << (char)(((index- 5+26)% 26)+'A');
//		}
//		else
//		{
//			cout << c_temp;
//		}
//		++i;
//	}
//	system("pause");
//	return 0;
//}