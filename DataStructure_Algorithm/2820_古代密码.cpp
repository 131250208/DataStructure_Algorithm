/*
 原思路错误：每个字母加密后都存在于code即yes
 正确思路：每个字母加密后频数与code对应字母相等
 然而还是没通过
 */
#include<iostream>
#include<string.h>
using namespace std;
//替换c成c后第n个字母
void encode(char text[], int n) {
	for (int i = 0; i < strlen(text); ++i) {
		int index_pre = text[i] - 'A';
		int index_post = (index_pre + n) % 26;
		text[i]=(char)(index_post + 'A');
	}
}
int* getFrequency(char text[]) {
	int* frequecy = (int *)malloc(sizeof(int) * 26);
	memset(frequecy, 0, sizeof(int) * 26);
	for (int i = 0; i < strlen(text); ++i) {
		++frequecy[text[i] - 'A'];
	}
	return frequecy;
}
bool equals(int fre1[],int fre2[]) {
	for (int i = 0; i < 26;++i) {
		if (fre1[i] != fre2[i])return false;
	}
	return true;
}
void isReplace_Rearrange(char text[],char code[]){
	int len_t = strlen(text);
	int len_c = strlen(code);
	if (len_c != len_t) { cout << "NO"; return; }

	for (int i = 0; i < 26; ++i) {
		encode(text, i);
		int *fre_t = getFrequency(text);//加密后的text的频数数组
		int *fre_c = getFrequency(code);
		if (equals(fre_t, fre_c)) {
			cout << "YES"; return;
		}
	}
	cout << "NO";
}
//int main() {
//	char code[101];
//	char text[101];
//	cin.getline(code, 101);
//	cin.getline(text, 101);
//	isReplace_Rearrange(text, code);
//	system("pause");
//	return 0;
//}