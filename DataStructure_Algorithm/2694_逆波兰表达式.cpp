/*��ǰ��ϰ*/
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
���������1
ԭ�����û�б���С������0
˼·���ݹ�
1����ȡ�����ţ��ݹ��������num�������ݶ�ȡ���ķ��ż���������
2����ȡ�����֣�ת���ɸ�����ֱ�ӷ���
ע�⣺
cout<<���������С������0��
printf("%f\n", v);�ܱ���С������0
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