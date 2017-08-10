/*Accepted
错误：1
原因：char只能只收一位的数字，要用int数组而不是char数组
注意：
next_permutation函数的使用，#include<algorithm>
与之相对的，prev_permutation
相应笔记记录在印象笔记中
*/
#include<iostream>
#include<algorithm>
using namespace std;
void print_permutation(int n, int k, int per[]) {
	for (int i = 0; i < k; ++i) {
		next_permutation(per, per + n);
	}
	for (int i = 0; i < n; ++i) {
		cout << per[i] << " ";
	}
	cout << endl;
}
//int main() {
//	int group = 0;
//	cin >> group;
//	int n = 0, k = 0;
//	int per[1024];
//	for (int i = 0; i < group; ++i) {
//		cin >> n; cin >> k;
//		for (int i = 0; i < n; ++i)cin >> per[i];
//		per[n] = '\0';
//		print_permutation(n, k, per);
//	}
//	system("pause");
//	return 0;
//}