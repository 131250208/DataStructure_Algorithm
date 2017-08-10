#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void trans(char code[]) {
	for (int i = 0; i < strlen(code); ++i) {
		if (code[i] >= 'A'&&code[i] <= 'Z') {
			code[i]=(char)((code[i] - 'A' - 5 + 26) % 26 + 'A');
		}
	}
}
//int main() {

	//char end_or_str[20];
	//while (true)
	//{
	//	scanf("%s", end_or_str);
	//	if (strcmp(end_or_str, "ENDOFINPUT") == 0)break;

	//	char code[210];
	//	getchar();//ºöÂÔµô'\n'
	//	gets_s(code);
	//	trans(code);
	//	cin.ignore(10, '\n');//ºöÂÔµôend

	//	printf("%s\n", code);
	//}
//	system("pause");
//	return 0;
//}
//void translate(char code[]) {
//	int i = 0;
//	while (code[i]!='\0')
//	{
//		if (code[i] - 'A' >= 0 && code[i] - 'A' < 26) {
//			int index_code = code[i] - 'A';
//			int index_ori = (index_code - 5 + 26) % 26;
//			cout << (char)(index_ori + 'A');
//		}
//		else
//		{
//			cout << code[i];
//		}
//		++i;
//	}
//}

//int main() {
//	while (true)
//	{
//		char ENDOFINPUT[11];
//		cin.getline(ENDOFINPUT, 11);
//		if (strcmp(ENDOFINPUT, "ENDOFINPUT") == 0)break;
//
//		char code[201];
//		cin.getline(code, 201);
//		translate(code);
//		cout << endl;
//
//		cin.ignore(4, '\n');
//	}
//	system("pause");
//	return 0;
//}