/*��ǰ��ϰ
���������1
1���ַ����ȽϺ���һ��Ҫ�ж�==0��==0�����
ע�⣺
ȥ�ո�ķ���
while ((ind = s1.find(" ")) != string::npos)s1.erase(ind,1);//������erase�����ڶ��������ǲ������ַ�����
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
//int main() {
//	char str1[500];
//	char str2[500];
//	gets_s(str1);
//	gets_s(str2);
//
//	string s1 = str1;
//	string s2 = str2;
//	int ind;
//	while ((ind = s1.find(" ")) != string::npos)s1.erase(ind,1);
//	while ((ind=s2.find(" "))!=string::npos)s2.erase(ind,1);
//
//	if (_stricmp(s1.c_str(), s2.c_str())==0)printf("YES\n");
//	else printf("NO\n");
//	system("pause");
//	return 0;
//}
/*
�����ϵı���������linux������
stricmp����ͨ�����룬����strcasecmp����
*/
//#include<iostream>
//#include<string>
//#include<string.h>
//using namespace std;

//int main() {
//	char line1[100];
//	char line2[100];
//	cin.getline(line1, 100);
//	cin.getline(line2, 100);
//	string s1 = line1;
//	string s2 = line2;
//	//ȥ�ո�
//	int index = 0;
//	while ((index=s1.find(" "))!=string::npos) {
//		s1 = s1.erase(index, 1);
//	}
//	while ((index = s2.find(" ")) != string::npos) {
//		s2 = s2.erase(index, 1);
//	}
//
//	if(_stricmp(s1.c_str(),s2.c_str())==0)cout << "YES";
//	else
//	{
//		cout << "NO";
//	}
//	system("pause");
//	return 0;
//}