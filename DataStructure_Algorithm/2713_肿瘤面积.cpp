/*
�߽����⣺36��˵��
û����ȫ����ѭ���������������ѭ����©��Խ������������Զ������255��
*/

#include<iostream>
using namespace std;

int region[1000][1001];
int n = 0;
int getPx_tumour() {
	//�ҵ�������ʼ���ص�
	int x = 0, y = 0,out=0;
	for (int i = 0; i < n;++i) {
		for (int j = 0; j < n;++j) {
			if (region[i][j]==0) {
				x = i;
				y = j;
				out = 1;
				break;
			}
		}
		if (out == 1) {
			break;
		}
	}

	int l = 0,w=0;//�����������Ϳ�
	while (true)
	{
		if (region[x][y]==255||x>=n) {//��0����xԽ�磬����ѭ��
			break;
		}
		++x;
		++w;
	}
	--x;//��Ϊ�ϸ�ѭ����x�Ѿ���Խ���
	while (true)
	{
		if (region[x][y] == 255||y>=n) {
			break;
		}
		++l;
		++y;
	}
	return (l - 2)*(w - 2);
}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n;++i) {
//		for (int j = 0; j < n;++j) {
//			cin >> region[i][j];
//		}
//	}
//
//	cout << getPx_tumour();
//	system("pause");
//	return 0;
//}