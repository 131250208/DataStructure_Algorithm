/*考前练习*/
#include<iostream>
#include<stdio.h>
#include<string.h>
static char input[100];
using namespace std;

double recurse_2694() {
	scanf("%s", &input);
	if (strcmp(input, "+") == 0)return recurse_2694() + recurse_2694();
	else if (strcmp(input, "-") == 0)return recurse_2694() - recurse_2694();
	else if (strcmp(input, "*") == 0)return recurse_2694() * recurse_2694();
	else if (strcmp(input, "/") == 0)return recurse_2694() / recurse_2694();
	else
	{
		return atof(input);
	}
}
//int main() {
//	double res=recurse_2694();
//	printf("%f\n", res);
//	system("pause");
//	return 0;
//}
/*Accepted
错误次数：1
原因：输出没有保留小数点后的0
思路：递归
1、读取到符号，递归计算两个num，并根据读取到的符号计算结果返回
2、读取到数字，转换成浮点数直接返回
注意：
cout<<输出不保留小数点后的0；
printf("%f\n", v);能保留小数点后的0
*/
//#include<iostream>
//#include<stdlib.h>
//#include<string.h>
//using namespace std;
//static char input[20];
//double calculate() {
//	cin >> input;
//
//	if (strcmp(input, "+") == 0 || strcmp(input, "-") == 0 ||
//		strcmp(input, "*") == 0 || strcmp(input, "/") == 0) {
//		char op = input[0];
//		double num1 = calculate();
//		double num2 = calculate();
//		switch (op)
//		{
//		case '+':return num1 + num2;
//		case '-':return num1 - num2;
//		case '*':return num1 * num2;
//		case '/':return num1 / num2;
//		}
//	}
//	else
//	{
//		return atof(input);
//	}
//}
//int main() {
//	double v=calculate();
//	printf("%f\n", v);
//	system("pause");
//	return 0;
//}