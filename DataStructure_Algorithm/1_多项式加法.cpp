/*Accepted
错误次数：1
原因：不熟悉map 和 迭代器、反迭代器的使用，妄图用正迭代器逆序输出，造成异常
思路：
用map解决，幂数作key，对应值累加即可
用迭代器输出-------------------------36~39(需要熟悉)

注意：
1、map用红黑树实现，已经按key的自然顺序排列
2、map的增加键值对可以直接 multinomial[y] = x;
3、累加可以不用赋初值0----------------32
*/
#include<iostream>
#include<map>
using namespace std;

static map<int,int> multinomial;
void group() {
	int line = 2;
	while (true)
	{
		if (line <= 0)break;

		int x = 0, y = 0;
		cin >> x; cin >> y;
		if (y < 0) {
			--line;
			continue;
		}
		else
		{
			multinomial[y] += x;
		}

	}
	for (map<int, int>::reverse_iterator iter = multinomial.rbegin(); iter != multinomial.rend(); ++iter) {//逆迭代器的rbegin就是最后一个元素
		if (iter->second != 0) {
			cout << "[ " << iter->second << " " << iter->first << " ] ";
		}
	}
	cout << endl;
	//清空map
	multinomial.clear();
}
//int main() {
//
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n;++i) {
//		group();
//	}
//	system("pause");
//	return 0;
//}