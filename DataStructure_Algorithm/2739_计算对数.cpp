/*把问题想复杂了，肯定有简单的办法
*/
#include<iostream>
#include<string.h>
using namespace std;

bool check(char a[], char b[],int x) {
	if (x == 0) {
		if (strcmp("1", b) <= 0 && strcmp(a, b) > 0)return true;
		return false;
	}
	//计算a的x次方
	//先反转存储在int数组中
	int a_int[100];
	int len_a = strlen(a);
	for (int i =0; i<len_a; ++i) {
		a_int[i] = a[len_a - 1 - i]-'0';//*
	}
	//用于存储结果的数组
	int res[100] = {};
	res[0] = 1;
	int multi[100];//作为每次被乘数
	int a_x[100], a_x_1[100];

	for (int k = 1; k <=x+1; ++k) {//x次方
		memcpy(multi, res, sizeof(int) * 100);//每次结果作为下一个被乘数
		memset(res, 0, sizeof(int) * 100);//清空res用于下一次存储

		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				res[i + j] = a_int[i]*multi[j];//*
			}
		}
		//处理res进位
		int c = 0, temp = 0;
		for (int i = 0; i < 100; ++i) {
			temp = res[i] + c;
			c = temp / 10;
			res[i] = temp % 10;
		}
		if (k == x)memcpy(a_x, res, sizeof(int) * 100);
		if (k == x+1)memcpy(a_x_1, res, sizeof(int) * 100);
	}
	//还原成char数组再进行比较
	char a_x_c[101];
	char a_x_1_c[101];
	int start = 0;
	int j = 0;
	for (int i = 99; i >= 0; --i) {
		if (a_x[i] != 0 || start) {
			a_x_c[j] = (char)(a_x[i] + '0');
			start = 1;
			++j;
		}
	}
	a_x_c[j] = '\0';

	start = 0;
	j = 0;
	for (int i = 99; i >= 0; --i) {
		if (a_x_1[i] != 0 || start) {
			a_x_1_c[j] = (char)(a_x_1[i] + '0');
			start = 1;
			++j;
		}
	}
	a_x_1_c[j] = '\0';
	//比较并返回结果
	if (strcmp(a_x_c, b) <= 0 && strcmp(a_x_1_c,b) > 0)return true;
	return false;
}
//int main() {
//	char a[101];
//	char b[101];
//	cin >> a;
//	cin >> b;
//	for (int x = 0; x <= 20; ++x) {
//		if (check(a, b, x))cout << x;
//	}
//	system("pause");
//	return 0;
//}