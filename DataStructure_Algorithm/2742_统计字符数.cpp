#include<iostream>
using namespace std;

void getCount_max(char input[]) {
	int count[26] = {};
	int i = 0;
	while (true)
	{
		if (input[i] == '\0')break;
		int index=input[i] - 'a';
		++count[index];
		++i;
	}
	int index_max = 0;
	for (int i = 0; i < 26; ++i) {
		index_max = (count[i] > count[index_max]) ? i : index_max;
	}
	cout << (char)('a' + index_max) << " " << count[index_max];
}
//int main() {
//	int n;
//	cin >> n;
//	cin.ignore();
//	for (int i = 0; i < n; ++i) {
//		char input[1001];
//		cin.getline(input, 1001);
//		getCount_max(input);
//		if (i != n - 1) {//如果不是最后一行
//			cin.ignore();//忽略一个空行
//			cout << endl;//输出一个回车
//		}
//	}
//	system("pause");
//	return 0;
//}