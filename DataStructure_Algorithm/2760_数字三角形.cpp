/* Accepted
错误次数：0
思路：动态规划：从底层递推，并储存于maxsum中----28
*/
#include<iostream>
#include<algorithm>
using namespace std;


//int main() {
//	int triangle[100][100];
//	int maxsum[100][100];
//
//	int n;
//	cin >> n;
//	for (int i = 0; i <n; ++i) {
//		for (int j = 0; j <= i; ++j) {
//			cin >> triangle[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; ++i) {
//		maxsum[n - 1][i] = triangle[n-1][i];
//	}
//
//	for (int i = n - 2; i >= 0; --i) {
//		for (int j = 0; j <= i; ++j) {
//			maxsum[i][j] = triangle[i][j] + max(maxsum[i+1][j],maxsum[i+1][j+1]);
//		}
//	}
//	cout << maxsum[0][0]<<endl;
//	system("pause");
//	return 0;
//}