/*Accepted
���������0
˼·��
����ö�ٿɽ⣬�������ڶ�̬�滮����ϰ�����֪why��
*/
#include<iostream>
using namespace std;
static int A[10000];
static int B[10000];
void del_group_2792() {
	int s,a,b,count=0;
	cin >> s;
	cin >> a;
	for (int i = 0; i < a; ++i)cin >> A[i];
	cin >> b;
	for (int i = 0; i < b; ++i)cin >> B[i];

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			if (s == A[i] + B[j])++count;
		}
	}
	cout << count << endl;
}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		del_group_2792();
//	}
//	system("pause");
//	return 0;
//}