/*Accepted
*/
#include<iostream>
#include<string.h>
using namespace std;
//获取最大ASCII码对应下标
int getIndex_max(char str[]) {
	int max = -1;
	for (int i = 0; i<strlen(str); ++i) {
		if (str[i] > str[max])max = i;
	}
	return max;
}
void insert_substr(char str[], char substr[]) {
	int len_str = strlen(str);
	int index_max = getIndex_max(str);
	//腾出位置
	for (int i = len_str; i > index_max; --i) {
		str[i + 3] = str[i];
	}
	//插入子串
	for (int i = 1; i <= 3; ++i) {
		str[index_max + i] = substr[i - 1];
	}

	cout << str<<endl;
}
//int main() {
//	char str[14],substr[4];
//	while (cin >> str&&cin >> substr) {
//		insert_substr(str,substr);
//	}
//	system("pause");
//	return 0;
//}