/*wrong
不知哪里错
思路：二分查找适合的小段长度，贪心找最大的
*/
#include<iostream>
using namespace std;
static int n, k,len=0;
static int logs[10000];
void bisection(int start,int end) {
	if (start > end) return;
	//二分小段长度并计算能够切得的小段数目
	int mid = (start + end) / 2;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		count += logs[i] / mid;
	}

	if (count < k)bisection(start, mid - 1);
	if (count > k)bisection(mid + 1, end);
	if (count == k) {
		len = mid;
		bisection(mid + 1, end);
	}
}
//int main() {
//
//	int len_logs=0;
//	cin >> n; cin >> k;
//	for (int i = 0; i < n; ++i) {
//		cin>>logs[i];
//		len_logs += logs[i];
//	}
//	int max = len_logs / k;//小段可能的最大长度
//	if (max < 1)cout << 0 << endl;
//	else
//	{
//		bisection(1, max);
//		cout << len << endl;
//	}
//	
//	system("pause");
//	return 0;
//}