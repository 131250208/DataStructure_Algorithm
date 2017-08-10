/*Accepted
错误次数：0
思路：动态规划
用一个正方形矩阵储存状态，maxlen[i][j]表示str1的从开头到第i个字符的子串
与str2从开头到第j个字符的子串 的公共最长子序列长度
递推关系：
先将0行0列都置0

if (str1[i - 1] == str2[j - 1]) {//如果两个字符串对应的下一个字符相同，
									//因为字符从0下标存起，而i、j表示的是第几个字符，所以要对应-1（第1个字符在0下标）
maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
}
else
{
maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
}

详细见《程序设计导引》10.4
*/
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

static int maxlen[201][201];
int get_maxlen_substr(char str1[], char str2[]) {
	int len_s1 = strlen(str1);
	int len_s2 = strlen(str2);
	for (int i = 0; i <=len_s1; ++i)maxlen[i][0] = 0;
	for (int i = 0; i <=len_s2; ++i)maxlen[0][i]=0;
	for (int i = 1; i <=len_s1; ++i) {
		for (int j = 1; j <=len_s2; ++j) {
			if (str1[i - 1] == str2[j - 1]) {
				maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
			}
			else
			{
				maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
			}
		}
	}
	return maxlen[len_s1][len_s2];
}
//int main() {
//	char str1[201];
//	char str2[201];
//	while (cin>>str1&&cin>>str2)
//	{
//		cout << get_maxlen_substr(str1, str2)<<endl;
//	}
//	system("pause");
//	return 0;
//}