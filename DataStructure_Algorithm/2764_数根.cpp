/*
Accepted
错误次数：0
解题思路：
模拟
从最后一位向前
后一位与前一位相加，个位数相加，十位最多为1
*/
#include<iostream>
#include<string.h>
using namespace std;
//int main() {
//	char num[1001];
//	cin >> num;
//
//	int len = strlen(num);
//	int root=0;
//	for (int i = len - 1; i >= 0; --i) {
//		root += num[i] - '0';
//		if (root >= 10) {
//			root = root % 10 + 1;
//		}
//	}
//	cout << root;
//	system("pause");
//	return 0;
//}