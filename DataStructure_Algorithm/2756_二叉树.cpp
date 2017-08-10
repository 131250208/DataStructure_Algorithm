#include<iostream>
using namespace std;
static int path[1001] = {};

void findPath(int i) {
	if (path[i] == 1) {//x也走过，找到解返回
		cout << i;
		return;
	}
	path[i] = 1;
	if (i == 1)return;//到达根，无需继续递归

	//计算父节点并递归
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