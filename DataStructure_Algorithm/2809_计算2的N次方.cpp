/*Accepted
���������0
˼·��
	1���߾��ȼ��㣺1��������λ���---����ٴ����λ  2����λ����1λ��ˣ�ÿ����1λ����һ�ν�λ
	2������Ϊ���ߣ����ϵ���2����һ�����
	3��ע��n=0ʱ�����Ϊ1����res��ʼ��Ϊ1��
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