/*Accepted
���������1
ԭ��©��һ�����---����Ҳ��һ����
˼·����¼����node ����ȼ��ɡ�
1. ������һ����----------map�ļ�¼��emptyֱ�ӷ���false---20
2. �Ի�������------------û�����Ϊ0��root������false----26
3. ɭ�ֲ�����------------root����ȳ���1������false------26
4. ���ɻ�·�Ĳ�����------��node����ȳ���1������false----23
ע�⣺
1��map��������д��-----------------22
2��mapѰ���ض�Ԫ���Ƿ���ڵ�д��---47---�Ҳ�������end������
*/
#include<iostream>
#include<map>
using namespace std;
static int node_fr, node_to;
static map<int, int> num_to;//��¼�ڵ�����

bool del_group_1308() {
	if (num_to.empty())return true;
	int root = 0;
    for (map<int, int>::iterator it = num_to.begin(); it != num_to.end(); ++it) {
		if (it->second != 0 && it->second != 1)return false;//�������ֻ����Ϊ0,1
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