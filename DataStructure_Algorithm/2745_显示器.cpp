/*Accepted
错误次数：0
注意：
换行的时机
解题思路：
用数字标记7个位置，每个位置一个map数组，用于判断某数字在这个position的输出（1为输出，0为空格）
各个pos对应位置参考下图
 111
2   3
2   3
2   3
 444 
5   6
5   6
5   6
 777
*/
#include<iostream>
#include<string.h>
using namespace std;

char pos1[] = "1011011111";
char pos2[] = "1000111011";
char pos3[] = "1111100111";
char pos4[] = "0011111011";
char pos5[] = "1010001010";
char pos6[] = "1101111111";
char pos7[] = "1011011011";

char print_c(int pos,char num) {
	switch (pos)
	{
	case 1:
		if (pos1[num - '0'] == '1')return '-';
		else return ' ';
		break;
	case 2:
		if (pos2[num - '0'] == '1')return '|';
		else return ' ';
		break;
	case 3:
		if (pos3[num - '0'] == '1')return '|';
		else return ' ';
		break;
	case 4:
		if (pos4[num - '0'] == '1')return '-';
		else return ' ';
		break;
	case 5:
		if (pos5[num - '0'] == '1')return '|';
		else return ' ';
		break;
	case 6:
		if (pos6[num - '0'] == '1')return '|';
		else return ' ';
		break;
	case 7:
		if (pos7[num - '0'] == '1')return '-';
		else return ' ';
		break;
	}
}
void print_line(char edge_l, char center,char edge_r,int s) {
	cout << edge_l;
	for (int j = 0; j < s; ++j)cout <<center;
	cout << edge_r;
	cout << " ";
}
void print_num(int size, char num[]) {
	//首行
	for (int i = 0; i < strlen(num); ++i) {
		print_line(' ', print_c(1, num[i]),' ',size);
	}
	cout << endl;
	//2、3
	for (int j = 0; j < size; ++j) {
		for (int i = 0; i < strlen(num); ++i) {
			print_line(print_c(2, num[i]), ' ', print_c(3, num[i]), size);
		}
		if(j!=size-1)cout << endl;
	}
	cout << endl;
	//4
	for (int i = 0; i < strlen(num); ++i) {
		print_line(' ', print_c(4, num[i]), ' ', size);
	}
	cout << endl;
	//5、6
	for (int j = 0; j < size; ++j) {
		for (int i = 0; i < strlen(num); ++i) {
			print_line(print_c(5, num[i]), ' ', print_c(6, num[i]), size);
		}
		if(j!=size-1)cout << endl;
	}
	cout << endl;
	//7
	for (int i = 0; i < strlen(num); ++i) {
		print_line(' ', print_c(7, num[i]), ' ', size);
	}
	cout << endl;
}
//int main() {
//	int size = 0;
//	char number[9];
//	while (true)
//	{
//		cin >> size; cin >> number;
//		if (size == 0 && strcmp(number, "0") == 0)break;
//		print_num(size,number);
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}