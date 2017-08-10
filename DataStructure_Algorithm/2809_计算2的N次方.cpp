/*Accepted
错误次数：0
思路：
	1、高精度计算：1、两个多位相乘---最后再处理进位  2、多位数与1位相乘，每乘完1位更新一次进位
	2、此题为后者，不断地用2乘上一个结果
	3、注意n=0时，结果为1，故res初始化为1。
*/
#include<iostream>
using namespace std;

static int res[40] = {};
void print_pow_2(int n) {
	res[39] = 1;
	for (int i = 0; i < n; ++i) {
		int c = 0,temp=0;
		for (int j = 39; j >= 0;--j) {
			temp = res[j] * 2 + c;
			c = temp / 10;
			res[j] = temp % 10;
		}
	}
	int start_output = 0;
	for (int i = 0; i < 40; ++i) {
		if (res[i] != 0||start_output==1) {
			cout << res[i]; start_output = 1;
		}
	}
}
//int main() {
//	int n = 0;
//	cin >> n;
//	print_pow_2(n);
//	system("pause");
//	return 0;
//}