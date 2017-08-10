/*Accepted
错误次数：1
原因：
错误语句maxlen[0]=input[0];
正确应为maxlen[0] = 1;---------------28
因为以第一个数结尾的序列的最长上升子序列，就是它本身，长度为1

思路：
动态规划，从第一个数开始，递推出以每一个数结尾的序列的最长上升子序列长度储存起来，最后再从其中找出最大的长度输出
递推：举例
假如第5个数为7，则遍历前面的4个数，找出其中小于7的数ai，遍历以ai结尾的最长上升子序列的长度，
找出最长的长度再+1，得到以7（第五个）结尾的最长上升子序列长度
详细参考《程序设计导引》10.3
*/
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
//int main() {
//	int n;
//	cin >> n;
//
//	int input[1000];
//	for (int i = 0; i < n; ++i)cin >> input[i];
//
//	int maxlen[1000];//储存以input[k]结尾的序列的最长上升子序列
//	memset(maxlen, 0, sizeof(maxlen));
//	maxlen[0] = 1;
//
//	for (int k = 1; k < n; ++k) {
//		int maxlen_temp = 0;
//		for (int i = 0; i < k; ++i) {
//			if (input[i] < input[k]) {
//				maxlen_temp = max(maxlen[i], maxlen_temp);
//			}
//		}
//		maxlen[k] = maxlen_temp + 1;
//	}
//
//	int res = 0;
//	for (int i = 0; i < n; ++i) {
//		res = max(res, maxlen[i]);
//	}
//	cout << res<<endl;
//	system("pause");
//	return 0;
//}