/*Accepted
错误次数：1
pell的每一项求解都要取模32767，而不是递推完了再取第k项来取模

思路：
1、动态规划递推
2、带存储的递归
	带存储的递归，因为需要保存状态入栈，数值较大时产生栈溢出。说明开销比动态规划大，并不是等同
*/
#include<iostream>
#include<string.h>
using namespace std;
static int pell[1000000];

/*动态规划*/
//int main() {
//	memset(pell, -1, sizeof(pell));
//	pell[1] = 1;
//	pell[2] = 2;
//	for (int k = 3; k < 1000000; ++k) {
//		pell[k] = (2 * pell[k - 1] + pell[k - 2])% 32767;
//	}
//
//	int n;
//	cin >> n;
//	int k;
//	for (int i = 0; i < n; ++i) {
//		cin >> k;
//		cout << pell[k] << endl;
//	}
//	system("pause");
//	return 0;
//}

//int recurse_pell(int k) {
//	if (pell[k] == -1)pell[k] = (2 * recurse_pell(k-1) + recurse_pell(k-2)) % 32767;
//	return pell[k];
//}
///*带存储的递归*/
//int main() {
//	memset(pell, -1, sizeof(pell));
//	pell[1] = 1;
//	pell[2] = 2;
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		int k;
//		cin >> k;
//		cout<<recurse_pell(k)<<endl;
//	}
//	system("pause");
//	return 0;
//}