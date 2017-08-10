/*考前练习Accepted
错误次数：
1、G++没有strrev，需要自己写反转函数
2、strncpy,拷贝的子串结尾没有结束符号，需要自己添加，注意添加'\0'的下标
3、逻辑错误，只要正反子串存在一个就可以，所以
	strstr(strs[j], substr) == NULL
	和strstr(strs[j], substr_rev) == NULL应该用&&相连，表示都不存在就判定false
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static char strs[110][110];
static char substr[110];
static int n;
void strrev_2744(char str[]) {
	int l = 0, r = strlen(str) - 1;
	while (l<r)
	{
		char c;
		c = str[l];
		str[l] = str[r];
		str[r] = c;
		l++;
		r--;
	}
}
void del_group_2744() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &strs[i]);
	}


	for (int len = strlen(strs[0]); len >= 1; --len) {
		for (int i = 0; i <= strlen(strs[0]) - len; ++i) {
			strncpy(substr, strs[0] + i, len);
			substr[len] = '\0';//*原错误代码substr[len-1] = '\0'
			bool exist = true;
			for (int j = 1; j < n; ++j) {
				if (strstr(strs[j], substr) == NULL) {
					strrev_2744(substr);
					if (strstr(strs[j], substr) == NULL) {
						exist = false;
						break;
					}
				}
			}
			if (exist) {
				printf("%d\n", len);
				return;
			}
		}
	}

	printf("0\n");
}
//int main() {
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		del_group_2744();
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string.h>
//using namespace std;
//
//static char input[100][101];
//static int n_group = 0;
//static int n_line = 0;
//
//int searchLen_MaxSubStr(char *minStr,int len) { 
//	for (int len_sub = len; len_sub> 0;--len_sub) {//子串长度递减遍历所有子串		
//		for (int j = 0; j <= len - len_sub; ++j) {
//			char substr[101];
//			char substr_rev[101];
//			strncpy(substr,(minStr+j), len_sub);
//			strncpy(substr_rev, minStr + j, len_sub);
//			substr[len_sub] = '\0';
//			substr_rev[len_sub] = '\0';
//			_strrev(substr_rev);
//
//			int leg = 1;
//			for (int k = 0; k < n_line; ++k) {
//				if (strstr(input[k], substr) == NULL&&strstr(input[k], substr_rev) == NULL) { leg = 0; break; }
//			}
//			if (leg)return len_sub;//只要有一个长度为len_sub的子串符合条件即可返回
//		}
//	}
//	return 0;//遍历完毕都没有符合的返回，即返回0，表示这样的子串只有空串
//}
//int main() {
//
//	cin >> n_group;
//	for (int i = 0; i < n_group;++i) {
//		cin >> n_line;
//		cin.ignore();
//		int len_minStr =100;
//		int index_minStr = -1;
//		for (int j = 0; j < n_line; ++j) {//读入每行，并找出最短串
//			cin.getline(input[j], 100);
//			int len_temp = strlen(input[j]);
//			if (len_temp < len_minStr) {
//				len_minStr = len_temp;
//				index_minStr = j;
//			}
//		}
//
//		//用最短串的所有子串或反序子串找出结果长度
//		cout << searchLen_MaxSubStr(input[index_minStr], len_minStr)<<endl;
//	}
//	system("pause");
//	return 0;
//}