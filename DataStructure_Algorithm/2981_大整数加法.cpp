/*Accepted
错误次数：2
错误原因：
1、没考虑到，0+0这种特殊情况时find_first_not_of('0')找不到pos，出现运行时异常------24
2、两个加数长短不一时的进位，不能像位数相等那样在结果前多输出一个1--------53、65

解题思路：(以下代码先去除了加数的0，导致后续进位处理产生了不必要的麻烦，这里只阐述更简便的思路)
1、两个加数都统一成201位；
2、不足的在前用0补（先声明一个200位全是0的数组，再把加数装填进去）-----memset(test, '0', 200);
3、模拟加法运算，最后结果再去0
4、去0可以找第一个非0的pos取子串(当加数用字符串数组时)，也可以遍历到非0再输出（字符串数组、整型数组都可以）

注意：
strlen与ss.length求得的字符串长度均不包括结尾的'\0'
*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void add(char addend1[], char addend2[]) {

	//清除前导0
	string add1 = addend1; string add2 = addend2;
	int index_start_add1 = 0;
	if ((index_start_add1 = add1.find_first_not_of('0')) != string::npos) {//*1
		add1 = add1.substr(index_start_add1);
	}
	else
	{
		add1 = "0";
	}
	int index_start_add2 = 0;
	if ((index_start_add2 = add2.find_first_not_of('0')) != string::npos) {
		add2 = add2.substr(index_start_add2);
	}
	else
	{
		add2 = "0";
	}
	

	int len1 = add1.length();
	int len2 = add2.length();
	//再转换成字符数组
	char* add1_c = (char*)malloc(sizeof(char)*len1+1);
	char* add2_c = (char*)malloc(sizeof(char)*len2+1);
	strcpy(add1_c, add1.c_str());
	strcpy(add2_c, add2.c_str());

	int c = 0;//进位
	if (len1 > len2) {
		while (len1>0) {
			int temp=add1_c[--len1]-'0'+c;//*
			if ((--len2) >= 0) temp+= add2_c[len2] - '0';//*2短的数组下标合法时才访问并累加,否则只计长数组数字与进位的和，
															//进位可能一直持续下去，尽管另一个数已经遍历完
			c = temp / 10;
			add1_c[len1] = (char)('0'+temp % 10);
		}
		if (c == 1)cout << c;
		cout << add1_c;
	}
	else
	{
		while (len2>0) {
			int temp = add2_c[--len2]-'0' + c;//*
			if ((--len1) >= 0)temp += add1_c[len1] - '0';//*短的数组下标合法时才访问并累加
			c = temp / 10;
			add2_c[len2] = (char)('0'+temp % 10);
		}
		if (c == 1)cout << c;
		cout << add2_c;
	}
}
//int main() {
//	char addend1[201];
//	char addend2[201];
//	cin >> addend1; 
//	cin >> addend2;
//	add(addend1, addend2);
//	system("pause");
//	return 0;
//}