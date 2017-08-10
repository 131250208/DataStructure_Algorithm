/*未解决
 题设要求最多小数达45位
 double精度8B=64bit（16个10进制数）
 long double 12B
 均不可达到目的
 得用
 setprecision(n)设置精度
 */

#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

double trans(char input[]) {
	int len = strlen(input);
	double res = 0.;//返回结果
	for (int i = 2; i < len;++i) {//从小数点后开始，每一位/8的i-1次方，并累加
		res += (double)(input[i] - '0') / pow(8., (double)i - 1);
	}
	return res;
}
//int main() {
//	
//	//char input[17];
//	//cin.getline(input, 17);
//
//	//cout <<input<<" [8] = "<< trans(input)<<" [10]";
//	system("pause");
//
//	return 0;
//}