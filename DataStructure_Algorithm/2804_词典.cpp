/*Accepted
用map作为字典

关注：
1、输入的处理
	gets_s(input);//可以获取一行直到回车，包括空格制表符
	if (strlen(input) == 0)break;
	sscanf(input,"%s %s",word1,word2);//将get到的一行input作为输入流输入到两个word数组
2、string 与 char数组之间转换
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