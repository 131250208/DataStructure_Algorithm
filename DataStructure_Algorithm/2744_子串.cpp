/*��ǰ��ϰAccepted
���������
1��G++û��strrev����Ҫ�Լ�д��ת����
2��strncpy,�������Ӵ���βû�н������ţ���Ҫ�Լ���ӣ�ע�����'\0'���±�
3���߼�����ֻҪ�����Ӵ�����һ���Ϳ��ԣ�����
	strstr(strs[j], substr) == NULL
	��strstr(strs[j], substr_rev) == NULLӦ����&&��������ʾ�������ھ��ж�false
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
			substr[len] = '\0';//*ԭ�������substr[len-1] = '\0'
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
//	for (int len_sub = len; len_sub> 0;--len_sub) {//�Ӵ����ȵݼ����������Ӵ�		
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
//			if (leg)return len_sub;//ֻҪ��һ������Ϊlen_sub���Ӵ������������ɷ���
//		}
//	}
//	return 0;//������϶�û�з��ϵķ��أ�������0����ʾ�������Ӵ�ֻ�пմ�
//}
//int main() {
//
//	cin >> n_group;
//	for (int i = 0; i < n_group;++i) {
//		cin >> n_line;
//		cin.ignore();
//		int len_minStr =100;
//		int index_minStr = -1;
//		for (int j = 0; j < n_line; ++j) {//����ÿ�У����ҳ���̴�
//			cin.getline(input[j], 100);
//			int len_temp = strlen(input[j]);
//			if (len_temp < len_minStr) {
//				len_minStr = len_temp;
//				index_minStr = j;
//			}
//		}
//
//		//����̴��������Ӵ������Ӵ��ҳ��������
//		cout << searchLen_MaxSubStr(input[index_minStr], len_minStr)<<endl;
//	}
//	system("pause");
//	return 0;
//}