#include<iostream>
#include<cmath>
using namespace std;

int transto_10(int num, int b) {
	int temp = num % 10;
	if (temp >= b)return -1;
	int res = temp;
	double count = 1;
	while ((num=num / 10) != 0)
	{
		temp = num % 10;
		if (temp >= b)return -1;
		res += temp*pow(b,count++);
	}
	return res;
}

//int main() {
//	int p, q, r;
//	cin >> p;
//	cin >> q;
//	cin >> r;
//
//	int p_10, q_10, r_10;
//	for (int i = 2; i <= 16; ++i) {
//		p_10 = transto_10(p, i);
//		q_10 = transto_10(q, i);
//		r_10 = transto_10(r, i);
//		if (p_10 == -1 || q_10 == -1 || r_10 == -1)continue;
//		if (p_10*q_10==r_10) {
//			cout << i << endl;
//			return 0;
//		}
//	}
//	cout << 0 << endl;//Ò×ÊèºöÂ©µô
//	system("pause");
//	return 0;
//}