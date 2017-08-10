/*Accepted
错误次数：0
思路：辗转相除法求最大公约数
1、即两个数的最大公约数就是 大数除小数所得余数 与 小数 的最大公约数
2、由1得递推关系，直到模得的余数为0，最后的小数（除数）就是最大公约数
3、最小公倍数为两数相乘再除最大公约数

详细见：印象笔记-算法积累
*/
#include<iostream>
using namespace std;
//int main() {
//	int num1, num2;
//	int multi;
//	while (cin>>num1>>num2)
//	{
//		int r = num1%num2;
//		multi = num1*num2;
//		while (r!=0)
//		{
//			num1 = num2;
//			num2 = r;
//			r = num1%num2;
//		}
//		
//		cout << "最大公约数为" << num2 << endl;
//		cout << "最小公倍数为"<<multi/num2 << endl;
//	}
//	system("pause");
//	return 0;
//}