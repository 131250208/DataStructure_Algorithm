/*Accepted
��map��Ϊ�ֵ�

��ע��
1������Ĵ���
	gets_s(input);//���Ի�ȡһ��ֱ���س��������ո��Ʊ��
	if (strlen(input) == 0)break;
	sscanf(input,"%s %s",word1,word2);//��get����һ��input��Ϊ���������뵽����word����
2��string �� char����֮��ת��
	char c[xx]=string.c_str();
	string s=c;
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;

static map<string, string> dictionary;
//int main() {
//	char input[100];
//	char word1[50];
//	char word2[50];
//	while (true)
//	{
//		gets_s(input);
//		if (strlen(input) == 0)break;
//		sscanf(input,"%s %s",word1,word2);
//
//		dictionary[word2] = word1;
//	}
//
//	char key[50];
//	while (scanf("%s",key)!=EOF)
//	{
//		if (dictionary.find(key) != dictionary.end()) {
//			printf("%s\n", dictionary[key].c_str());
//		}
//		else printf("eh\n");
//	}
//	system("pause");
//	return 0;
//}