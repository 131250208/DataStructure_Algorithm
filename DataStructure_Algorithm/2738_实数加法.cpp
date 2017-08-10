/*Accepted
错误次数：2
原因：
1、结果的整数部分是0时，要保留一个0，原代码直接去除了开头所有0
2、结果从后往前第一个非零数的index计算失误

思路：
通过寻找"."的index将两个数对齐并转存成int数组
相加结果去除首位的0

注意：
1、结果数组多预留一位，因可能最高位进位
2、结果的整数部分是0时，保留一个0
*/
#include<iostream>
#include<string>

using namespace std;

void add_f(char addend1[], char addend2[]) {
	//找点的位置
	string add1_s = addend1;
	string add2_s = addend2;
	int index_dot_add1 = add1_s.find('.');
	int index_dot_add2 = add2_s.find('.');
	int index_dot_res = (index_dot_add1 > index_dot_add2) ? index_dot_add1 : index_dot_add2;

	//转换成整型数组并对齐
	int add1_int[101] = {};
	int add2_int[101] = {};
	int gap1 = index_dot_res - index_dot_add1 + 1;//对齐，并留出开头一位给可能的进位
	int gap2 = index_dot_res - index_dot_add2 + 1;
	//int len_max = (add1_s.length() > add2_s.length()) ? add1_s.length() : add2_s.length();

	for (int i = 0; i < add1_s.length(); ++i) {
		if (addend1[i] != '.') {
			add1_int[i + gap1] = addend1[i] - '0';
		}
		else add1_int[i + gap1] = -1;//用-1标记"."的位置
	}
	for (int i = 0; i < add2_s.length(); ++i) {
		if (addend2[i] != '.') {
			add2_int[i + gap2] = addend2[i] - '0';
		}
		else add2_int[i + gap2] = -1;//用-1标记"."的位置
	}
	//相加
	int c = 0;
	int temp = 0;
	for (int i = 100; i >= 0;--i) {
		if (add1_int[i] == -1 && add2_int[i] == -1)continue;
		temp = add1_int[i] + add2_int[i] + c;
		c=temp / 10;
		add1_int[i] = temp % 10;//结果存储在加数1的数组
	}

	//计算结尾index
	int index_end = -1;
	for (int i = 100; i >= 0; --i) {
		if (add1_int[i] != 0) {
			index_end = i; break;
		}
	}
	int start = 0;
	for (int i = 0; i <= index_end; ++i) {
		if (add1_int[i] == 0 && add1_int[i + 1] != -1&&start!=1) continue;
		start = 1;
		if (add1_int[i] == -1)cout << ".";
		else cout << add1_int[i];
	}
}
//int main() {
//	char addend1[101];
//	char addend2[101];
//
//	cin >> addend1;
//	cin >> addend2;
//	
//	add_f(addend1, addend2);
//	system("pause");
//	return 0;
//}