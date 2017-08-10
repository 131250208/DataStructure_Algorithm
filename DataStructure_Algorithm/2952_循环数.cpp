/*Accepted
错误次数：0
注意：
1、输入最多有60位，要用字符串模拟乘法
2、相乘结果最后一位进位即可否定，因为位数不一致不可能是循环数
思路：
3、一定要遍历新数中的每一位与输入开头相同的位置，从那开始向后对比，有一位不对即可结束这次对比，
到下一个与num开头相同的地方开始比较
*/
#include<iostream>
#include<string.h>
using namespace std;

bool isCircle(char num[], char num_new[],int len) {
	for (int i = 0; i < len; ++i) {//遍历新数每一位
		if (num_new[i] == num[0]) {//从所有有相同开头数字的位置尝试
			int isCircle = 1;
			for (int j = 1; j < len; ++j) {
				if (num[j] != num_new[(i + j) % len])isCircle = 0;//只要有一位出差错就不是
			}
			if (isCircle)return true;
		}
	}
	return false;
}
int isCircle(char num[]) {
	int len = strlen(num);
	char* num_multi = (char*)malloc(sizeof(char)*len);
	//相乘
	int c = 0;//进位
	for (int i = 2; i <= len; ++i) {//从2开始乘起，因为与1乘肯定相等
		for (int j = len - 1; j >= 0; --j) {//模拟乘法
			int temp = i*(num[j] - '0');
			temp += c;
			c = temp / 10;
			num_multi[j] = (char)('0' + temp % 10);
		}
		if (c != 0)return 0;//如果最后一位相乘进位，则新数位数多了1，一定不是循环数
		if (!isCircle(num, num_multi,len))return 0;//一个新数与旧数比较，有一个结果不符就不是循环数
	}
	return 1;
}
//int main() {
//	char num[61];
//	cin >> num;
//	cout << isCircle(num);
//	system("pause");
//	return 0;
//}