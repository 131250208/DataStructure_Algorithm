/*
�ύ�����accept
���������
��Ŀδ�������жϣ������õ���while(ture)
�ύ����ǳ�ʱ,��cin>>��䱾���ж��Ƿ������룬��line28
*/

#include<iostream>
#include<string.h>
using namespace std;

void isSubsequence(char s[],char t[]) {
	int i = 0, j = 0;
	int len_s = strlen(s);
	int len_t = strlen(t);

	while (true)
	{
		if (j == len_t&&i != len_s) { cout << "No"<<endl; break; }
		if (i == len_s) {
			cout << "Yes"<<endl; break;
		}
		if (s[i] == t[j]) { ++i; ++j; }
		else {++j; }
	}
}
//int main() {
//	char s[100001];
//	char t[100001];
//	while (cin >> s&&cin >> t)
//	{
//		isSubsequence(s, t);
//	}
//	system("pause");
//	return 0;
//}