/*wrong
*/
#include<iostream>
#include<string.h>
using namespace std;
static char map[8][9];
static int scheme[8];
static int n, k, num_scheme;
bool legal_1321(int i) {
	for (int j = 0; j < i; ++j) {
		if (scheme[j] == scheme[i])return false;
	}
	return true;
}
void count_schemes(int i) {
	if (i==n) {
		if (k == 0)++num_scheme;
	}
	else
	{
		for (int j = 0; j <= n; ++j) {
			if (j == n)count_schemes(i + 1);
			if (map[i][j] == '#') {
				scheme[i] = j;
				if (legal_1321(i)) {
					--k;
					count_schemes(i + 1);
					++k;
				}
			}
		}
	}
}
//int main() {
//	while (true)
//	{
//		cin >> n; cin >> k;
//		if (n == -1 && k == -1)break;
//		for (int i = 0; i < n; ++i) {
//			cin >> map[i];
//		}
//		memset(scheme, -1, sizeof(int) * 8);
//		num_scheme = 0;
//		count_schemes(0);
//		cout << num_scheme << endl;
//	}
//
//	system("pause");
//	return 0;
//}