/*Accepted
���������2
ԭ��
1�����ⲻ�壬Ҫ����������·�������߶����������Ǿ����Ŀ�����
2����ʱ������һЩ�Ż����ԣ��統ǰ�����Ѿ�����Ŀǰ���ٲ�������Ӧ��ֹͣ�ݹ�
3����������������ʽ����ÿ������֮��Ҫ��һ������

��ˢ��Ҫ�����Ƶ��
�������
*/
#include<iostream>
#include<string.h>
using namespace std;
static char map[77][77];
static char path_sign[77][77];
static int w, h;
static int len_min;
static int len_path=0;
static int direction = -1;//0,1,2,3---��������

void find(int x1, int y1, int x2, int y2) {
	if (map[y1][x1] == ' '&&path_sign[y1][x1] == '0') {
		if (len_path > len_min)return;
		path_sign[y1][x1] = '1';
		if (x1 == x2&&y1 == y2) {//�ҵ�һ��·��,�Ƚϵ�ǰ·���������·��
			len_min = (len_path < len_min) ? len_path : len_min;
		}
		//���ܵݹ�
		int dir_pre = direction;
		if ((x1 - 1) >= 0) {
			if (direction != 3) {
				++len_path; direction = 3;
				find(x1 - 1, y1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1 - 1, y1, x2, y2);
		}
		if ((y1 - 1) >= 0) {
			if (direction != 2) {
				++len_path; direction = 2;
				find(x1, y1 - 1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1, y1 - 1, x2, y2);
		}
		if ((x1 + 1) <= w + 1) {
			if (direction != 1) {
				++len_path; direction = 1;
				find(x1 + 1, y1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1 + 1, y1, x2, y2);
		}
		if ((y1 + 1) <= h + 1) {
			if (direction != 0) {
				++len_path; direction = 0;
				find(x1, y1 + 1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1, y1 + 1, x2, y2);
		}

		//���ݱ�ǳ���
		path_sign[y1][x1] = '0';
	}
}
int find_path(int x1, int y1, int x2, int y2) {
	//��ճ�ʼ��·�����
	memset(path_sign, '0', sizeof(char) * 77 * 77);
	len_min= 10000;
	len_path = 0;

	map[y1][x1] = ' ';
	map[y2][x2] = ' ';//Ϊ�˷���Ѱ·��������յ㶼��Ϊ�޿��ɴ�

	find(x1, y1, x2, y2);

	map[y1][x1] = 'X';//�ָ�������յ�Ŀ���
	map[y2][x2] = 'X';

	return len_min;
}
//int main() {
//	int group = 1;
//	while (true)
//	{
//		cin >> w; cin >> h;
//		cin.ignore();
//		if (w == 0 && h == 0)break;
//		//������
//		cout << "Board #" << group << ":" << endl;
//		++group;
//		//��ʼ����ͼ
//		memset(map, '*', sizeof(char) * 77 * 77);
//
//		memset(map[0],' ', sizeof(char)*(w + 2));
//		for (int i = 1; i <=h; ++i) {
//			map[i][0] = ' ';
//			cin.getline(map[i] + 1, w + 1);
//			map[i][w + 1] = ' ';//ɾ��������
//		}
//		memset(map[h+1], ' ', sizeof(char)*(w + 2));
//
//		//�������뿨�ƽ������
//		int x1, y1, x2, y2;
//		int pair = 1;
//		while (true)
//		{
//			cin >> x1; cin >> y1; cin >> x2; cin >> y2;
//			if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)break;
//			int len_min=find_path(x1, y1, x2, y2);
//			cout << "Pair " << pair << ": ";
//			if (len_min == 10000)cout << "impossible."<<endl;
//			else cout<<len_min<<" segments."<<endl;
//			++pair;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}