/*Accepted
���������1
ԭ�򣺲���Ϥmap �� ������������������ʹ�ã���ͼ�����������������������쳣
˼·��
��map�����������key����Ӧֵ�ۼӼ���
�õ��������-------------------------36~39(��Ҫ��Ϥ)

ע�⣺
1��map�ú����ʵ�֣��Ѿ���key����Ȼ˳������
2��map�����Ӽ�ֵ�Կ���ֱ�� multinomial[y] = x;
3���ۼӿ��Բ��ø���ֵ0----------------32
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
	for (map<int, int>::reverse_iterator iter = multinomial.rbegin(); iter != multinomial.rend(); ++iter) {//���������rbegin�������һ��Ԫ��
		if (iter->second != 0) {
			cout << "[ " << iter->second << " " << iter->first << " ] ";
		}
	}
	cout << endl;
	//���map
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