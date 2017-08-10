/*Accepted
思路：从1开始枚举最后一个猴子分到的桃子数量，逆推到第一个猴子，
	能逆推完毕（每一步都可以整除）的第一个数就是符合的最小结果的情况下第一个猴子分到的真实数量
	再推出总数即可
*/
#include<iostream>
using namespace std;
static int n;
int check(int x) {
	for (int i = 0; i < n-1; ++i) {
		if ((x*n + 1) % (n - 1) == 0)x = (x*n + 1) / (n - 1);
		else return -1;
	}
	return x*n + 1;
}
//int main() {
//	while (true)
//	{
//		cin >> n;
//		if (n == 0)break;
//
//		int x = 1,res;
//		while (true)
//		{
//			res= check(x++);
//			if (res != -1)break;
//		}
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}