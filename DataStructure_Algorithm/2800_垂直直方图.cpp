#include<iostream>
using namespace std;

static char input[4][81];
static int count_letters[26];

void countLetters() {
	for (int i = 0; i < 26; ++i) {
		count_letters[i] = 0;
	}
	for (int i = 0; i < 4; ++i) {
		int j = 0;
		while(input[i][j] != '\0') {
			int index = (input[i][j] - 'A');
			if (index>=0&&index<26) {
				++count_letters[index];
			}
			++j;
		}
	}

	//求出最大值
	int max_count = 0;
	for (int i = 0; i < 26; ++i) {
		max_count = (count_letters[i] > max_count)? count_letters[i]: max_count;
	}
	//输出直方图
	for (int k = max_count; k >0;--k) {
		for (int i = 0; i < 26; ++i) {
			if (count_letters[i] >= k) {
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 26; ++i) cout << (char)(i + 'A')<<" ";
}

//int main() {
//	cin.getline(input[0], 81);
//	cin.getline(input[1], 81);
//	cin.getline(input[2], 81);
//	cin.getline(input[3], 81);
//
//	countLetters();
//	system("pause");
//	return 0;
//}