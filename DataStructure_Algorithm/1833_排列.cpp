/*Accepted
����1
ԭ��charֻ��ֻ��һλ�����֣�Ҫ��int���������char����
ע�⣺
next_permutation������ʹ�ã�#include<algorithm>
��֮��Եģ�prev_permutation
��Ӧ�ʼǼ�¼��ӡ��ʼ���
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