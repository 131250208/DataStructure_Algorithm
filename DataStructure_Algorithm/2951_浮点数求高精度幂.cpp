/*不知哪里出错，试了很多，计算结果输出都是对的
*/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void cout_pow(char num[], int n) {
	//确定'.'的index;
	string num_s = num;
	int len_num = num_s.length();
	int index_dot = ( len_num- 1 - num_s.find('.'))*n;
	//将num翻转存放在int数组中,不存'.'
	int num_int[6] = {};
	int j = 0;
	for (int i = 0; i < len_num; ++i) {
		num_int[j] = num[len_num - 1 - i]-'0';//*
		if (num[len_num - 1 - i] != '.')++j;
	}
	int res[130] = {};
	memcpy(res, num_int, sizeof(int)*(len_num - 1));
	for (int i = 1; i < n; ++i) {
		//将res数组的阶段性结果赋值到temp数组，进行一次次的大整乘法
		int multi[130];
		memcpy(multi, res, sizeof(int) * 130);//将res结果作为下一个乘数
		memset(res, 0, sizeof(int) * 130);//重新计算需清空res
		for (int j = 0; j < len_num - 1; ++j) {
			for (int k = 0; k < 130; ++k) {
				res[j + k] += num_int[j] * multi[k];
			}
		}
		//处理进位
		int c = 0, temp = 0;
		for (int i = 0; i < 130; ++i) {
			temp = res[i] + c;
			c = temp / 10;
			res[i] = temp % 10;
		}
	}
	
	//小数部分从后往前第一个非零坐标
	int index_no_0 = -1;
	for (int i = 0; i < 130;++i) {
		if (res[i] != 0) {
			index_no_0 = i;
			break;
		}
	}
	//输出结果
	int start = 0;
	for (int i = 129; i >= index_no_0; --i) {
		if (res[i] != 0 || start) {
			cout << res[i];
			start = 1;
			if (i == index_dot&&index_dot != index_no_0)cout << ".";
		}
		else if(i == index_dot)//还没遇到非0数先到达输出"."位置的情况，应开始输出
		{
			start = 1;
			if (index_dot != index_no_0)cout << ".";
		}
	}
	cout << endl;
}
//int main() {
//	char num[7]; int n = 0;
//	while (cin >> num&&cin >> n) {
//		cout_pow(num, n);
//	}
//	system("pause");
//	return 0;
//}