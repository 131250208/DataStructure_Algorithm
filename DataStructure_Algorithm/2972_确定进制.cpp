/*
���������2
ԭ��
1��ע��b��������λ����С��b����Ϊ��bҪ��λ
����11*11=121��С������3����2
2����Ҫ����û�з��ϵ����0
*/
#include<iostream>
#include<cmath>
using namespace std;

int trans_10(int num,int b) {
	int res = num % 10;//ȡ�ø�λ
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