#include<iostream>
using namespace std;
static int path[1001] = {};

void findPath(int i) {
	if (path[i] == 1) {//xҲ�߹����ҵ��ⷵ��
		cout << i;
		return;
	}
	path[i] = 1;
	if (i == 1)return;//���������������ݹ�

	//���㸸�ڵ㲢�ݹ�
	int father = (i - 2) / 2 + 1;
	findPath(father);
}
//int main() {
//	int x = 0, y = 0;
//	cin >> x; cin >> y;
//	findPath(x);
//	findPath(y);
//
//	system("pause");
//	return 0;
//}