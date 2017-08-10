/*数p太大
直接算2的次方不太现实，另寻他法
*/
#include<iostream>
using namespace std;
//int main() {
//	int p = 0;
//	cin >> p;
//	int res[1000000];
//	memset(res, 0, sizeof(int) * 1000000);
//	res[0] = 1;
//
//	int c = 0, temp = 0;
//	for (int j = 0; j < p; ++j) {
//		for (int i = 0; i < 1000000; ++i) {
//			temp = 2 * res[i] + c;
//			c = temp / 10;
//			res[i] = temp % 10;
//		}
//	}
//	int index_start = -1;
//	for (int i = 999999; i >= 0; --i) {
//		if (res[i] != 0)index_start = i;
//	}
//	cout << index_start + 1;
//	system("pause");
//	return 0;
//}