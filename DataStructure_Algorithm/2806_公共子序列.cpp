/*Accepted
���������0
˼·����̬�滮
��һ�������ξ��󴢴�״̬��maxlen[i][j]��ʾstr1�Ĵӿ�ͷ����i���ַ����Ӵ�
��str2�ӿ�ͷ����j���ַ����Ӵ� �Ĺ���������г���
���ƹ�ϵ��
�Ƚ�0��0�ж���0

if (str1[i - 1] == str2[j - 1]) {//��������ַ�����Ӧ����һ���ַ���ͬ��
									//��Ϊ�ַ���0�±���𣬶�i��j��ʾ���ǵڼ����ַ�������Ҫ��Ӧ-1����1���ַ���0�±꣩
maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
}
else
{
maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
}

��ϸ����������Ƶ�����10.4
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