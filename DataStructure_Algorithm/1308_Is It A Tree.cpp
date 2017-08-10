/*Accepted
错误次数：1
原因：漏掉一种情况---空树也是一棵树
思路：记录各个node 的入度即可。
1. 空树是一棵树----------map的记录是empty直接返回false---20
2. 自环不算树------------没有入度为0的root，返回false----26
3. 森林不算树------------root的入度超过1，返回false------26
4. 构成环路的不算树------有node的入度超过1，返回false----23
注意：
1、map迭代器的写法-----------------22
2、map寻找特定元素是否存在的写法---47---找不到返回end迭代器
*/
#include<iostream>
#include<map>
using namespace std;
static int node_fr, node_to;
static map<int, int> num_to;//记录节点的入度

bool del_group_1308() {
	if (num_to.empty())return true;
	int root = 0;
    for (map<int, int>::iterator it = num_to.begin(); it != num_to.end(); ++it) {
		if (it->second != 0 && it->second != 1)return false;//结点的入度只可能为0,1
		if (it->second == 0)++root;
	}
	if (root != 1)return false;
	return true;
}
//int main() {
//	int k = 1;
//	while (true)
//	{
//		cin >> node_fr; cin >> node_to;
//		if (node_fr == -1 && node_to == -1)break;
//		if (node_fr == 0 && node_to == 0) {
//			bool isTree=del_group_1308();
//			if (isTree) {
//				cout << "Case "<<k++<<" is a tree." << endl;
//			}
//			else
//			{
//				cout << "Case " << k++ << " is not a tree." << endl;
//			}
//			num_to.clear();
//			continue;
//		}
//		if (num_to.find(node_fr) == num_to.end()) {
//			num_to[node_fr] = 0;
//		}
//		++num_to[node_to];
//	}
//	system("pause");
//	return 0;
//}