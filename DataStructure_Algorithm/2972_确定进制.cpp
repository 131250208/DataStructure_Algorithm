/*
错误次数：2
原因：
1、注意b进制数各位必须小于b，因为满b要进位
所以11*11=121最小进制是3不是2
2、不要忘了没有符合的输出0
*/
#include<iostream>
#include<cmath>
using namespace std;

int trans_10(int num,int b) {
	int res = num % 10;//取得个位
	if (res >= b)return -1;
	int i = 1;
	while (true)
	{
		num = num / 10;
		if (num == 0) break;
		int temp = num % 10;
		if (temp >= b)return -1;
		res+=(int)temp*pow((double)b, (double)i);
		++i;
	}
	return res;
}

//int main() {
//	int p = 0, q = 0,r = 0;
//	cin >> p;
//	cin >> q;
//	cin >> r;
//	for (int b = 2; b <= 16; ++b) {
//		int p_10 = trans_10(p, b), q_10 = trans_10(q, b), r_10 = trans_10(r, b);
//		if (p_10 == -1 || q_10 == -1 || r_10 == -1)continue;
//		if (p_10*q_10 == r_10) { 
//			cout << b;
//			break;
//		}
//		else if(b==16)
//		{
//			cout << 0;
//		}
//	}
//	system("pause");
//	return 0;
//}