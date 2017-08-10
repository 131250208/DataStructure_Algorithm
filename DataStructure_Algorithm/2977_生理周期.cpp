/*Accepted
错误次数：1
原因：
题目要求输出结果在d之后，且小于等于21252
且输出的是j-d;
所以遍历条件别忘了+d;
*/
#include<iostream>
using namespace std;
//int main() {
//	int p = 0, e = 0, i = 0, d = 0;
//	cin >> p; cin >> e; cin >> i; cin >> d;
//	for (int j = d + 1; j <= d + 21252; ++j) {
//		if ((j - p) % 23 == 0 && (j - e) % 28 == 0 && (j - i) % 33 == 0) {
//			cout << j - d;
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}