#include<iostream>
using namespace std;
//��ʱ���鼯�������洢�ṹ���±��ǽ����룬ֵΪ�������룬��1��ʼ�洢
static int set[100] = {0,1,1,1,2,2,2,7,7,7,7 };

//���游���
int getAncestor(int node) {
	if (set[node] == node)return node;//����������Ǳ�����ô�����游���
	set[node] = getAncestor(set[node]);//����ָ��Ϊ�������游��Ҳ���Ǳ������游,����һ��ѹ������
	return set[node];
}
//�ϲ�
void combine_mine(int a, int b) {//a,b���ڼ��Ͻ��кϲ���b���游��a���游�ϲ�
	set[getAncestor(b)]=getAncestor(a);//b�游�ĸ��׸�Ϊa���游
}

//int main() {
//	combine_mine(6, 9);
//	for (int i = 1; i <= 10; ++i)cout << set[i] << ",";
//	system("pause");
//	return 0;
//}