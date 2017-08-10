/*考前练习Accepted
错误次数：1
1、k取模，如果某组个数为0，可能会出现除0运行时异常
*/
#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
static char code[100];
static char map[] = "11111111122222222233333333";
static queue<char> que1;
static queue<char> que2;
static queue<char> que3;
static int k1, k2, k3;
char getGroupNum(char c) {
	if (c == '_')return '3';
	else
	{
		return map[c - 'a'];
	}
}
void del_group_2819() {
	cin.ignore(10, '\n');
	scanf("%s", &code);
	int len = strlen(code);
	//k取模
	int count_1 = 0, count_2 = 0, count_3 = 0;
	for (int i = 0; i < len; ++i) {
		switch (getGroupNum(code[i]))
		{
			case '1':count_1++;
				break; 
			case '2':count_2++;
				break;
			case '3':count_3++;
				break;
		}
	}
	if (count_1 != 0)k1 %= count_1;
	if (count_2 != 0)k2 %= count_2;
	if (count_3 != 0)k3 %= count_3;
	//右旋k
	for (int i = 0; i < len; ++i) {
		switch (getGroupNum(code[i]))
		{
		case '1':
			que1.push(code[i]);
			if (que1.size() > k1) { code[i] = que1.front(); que1.pop(); }
			break;
		case '2':
			que2.push(code[i]);
			if (que2.size() > k2) { code[i] = que2.front(); que2.pop(); }
			break;
		case '3':
			que3.push(code[i]);
			if (que3.size() > k3) { code[i] = que3.front(); que3.pop(); }
			break;
		}
	}
	for (int i = 0; i < len; ++i) {
		switch (getGroupNum(code[i]))
		{
		case '1':
			if (que1.size() > 0) { code[i] = que1.front(); que1.pop(); }
			break;
		case '2':
			if (que2.size() > 0) { code[i] = que2.front(); que2.pop(); }
			break;
		case '3':
			if (que3.size() > 0) { code[i] = que3.front(); que3.pop(); }
			break;
		}
	}
	printf("%s\n", code);
}
//int main() {
//	while (true)
//	{
//		scanf("%d %d %d", &k1, &k2, &k3);
//		if (k1 == 0 && k2 == 0 && k3 == 0)break;
//		del_group_2819();
//	}
//	system("pause");
//	return 0;
//}
/*
思路：用队列实现右旋，遍历密码字符，入队至k个，超过k则弹出一个到指针位置，再遍历一次将队中余下的字符归位
自测样例输出正确，提交错误……
k值大于密码中的对应组内字符数时要取模
*/
//#include<iostream>
//#include<queue>
//#include<string.h>
//using namespace std;
//
//static int k1 = 0, k2 = 0, k3 = 0;
//static queue<char> que1;
//static queue<char> que2;
//static queue<char> que3;
//
//char getGroupNum(char c) {
//	char map[] = "11111111122222222233333333";
//	if (c == '_')return '3';
//	else
//	{
//		return map[c - 'a'];
//	}
//}
//
//void decode(char code[]) {
//	int len = strlen(code);
//	//k值大于密码中的对应组内字符数时要取模
//	int count1 = 0, count2 = 0, count3 = 0;
//	for (int i = 0; i < len; ++i) {//遍历计算各组字符数
//		switch (getGroupNum(code[i]))
//		{
//		case '1':++count1;
//			break;
//		case '2':++count2;
//			break;
//		case '3':++count3;
//			break;
//		}
//	}
//	if (k1 >= count1&&count1 != 0)k1 = k1%count1;
//	if (k2 >= count2&&count2 != 0)k2 = k2%count2;
//	if (k3 >= count3&&count3 != 0)k3 = k3%count3;
//
//	for (int i = 0; i < len;++i) {
//		//判断组，入队
//		switch (getGroupNum(code[i]))
//		{
//		case '1':que1.push(code[i]);
//			break;
//		case '2':que2.push(code[i]);
//			break;
//		case '3':que3.push(code[i]);
//			break;
//		}
//		//超过k值出队赋值
//		if (que1.size() > k1) { code[i] = que1.front(); que1.pop();}
//		if (que2.size() > k2) { code[i] = que2.front(); que2.pop(); }
//		if (que3.size() > k3) { code[i] = que3.front(); que3.pop(); }
//	}
//	//第二次遍历，把队中余下字符归位
//	int j = 0;
//	while (que1.size()!=0|| que2.size() != 0|| que3.size() != 0)
//	{
//		if (getGroupNum(code[j]) == '1'&&que1.size() != 0) { code[j] = que1.front(); que1.pop(); }
//		if (getGroupNum(code[j]) == '2'&&que2.size() != 0) { code[j] = que2.front(); que2.pop(); }
//		if (getGroupNum(code[j]) == '3'&&que3.size() != 0) { code[j] = que3.front(); que3.pop(); }
//		++j;
//	}
//
//	cout << code << endl;
//}
//int main() {
//	while (true)
//	{
//		cin >> k1; cin >> k2; cin >> k3;
//		if (k1 == 0 && k2 == 0 && k3 == 0)break;
//		cin.ignore();
//		char code[81];
//		cin.getline(code, 81);
//		decode(code);
//	}
//	system("pause");
//	return 0;
//}