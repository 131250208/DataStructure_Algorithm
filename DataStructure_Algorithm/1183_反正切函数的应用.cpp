/*
题意：
b*c-1=a*(b+c)
解b+c一定为整数
求任意a得到b+c的解


*/

#include<iostream>
using namespace std;

long long get_b_add_c(long long a) {
	long long m;
	for (m = a; m >= 1; --m) {
		if ((a*a + 1) % m == 0) {
			cout << "b:" << m+a << "---" << "c:" << (a*a + 1) / m+a << endl;
			return (a*a + 1) / m + m + 2 * a;
		}
	}
	return -1;
}
//int main() {
//	long long a = 0;
//	cin >> a;
//	cout << get_b_add_c(a);
//	system("pause");
//	return 0;
//}