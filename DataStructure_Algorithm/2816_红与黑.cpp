/*��ǰ��ϰ
*/
//#include<iostream>
//#include<stdio.h>
//#include<string.h>
//using namespace std;
//static char matri[30][30];
//static char sign[30][30];
//static int r, c;
//static int count_tiles;
//bool isLegal2816(int i,int j) {
//	return i >= 0 && i < r&&j >= 0 && j < c&&sign[i][j] == '0'&&matri[i][j] != '#';
//}
//void recurse_2816(int i,int j) {
//	if (!isLegal2816(i, j))return;
//	sign[i][j] = '@';
//	count_tiles++;
//	recurse_2816(i - 1, j);
//	recurse_2816(i + 1, j);
//	recurse_2816(i , j + 1);
//	recurse_2816(i , j - 1);
//}
//int main() {
//	while (true)
//	{
//		scanf("%d %d", &c, &r);
//		if (c == 0 && r == 0)break;
//	
//		memset(sign, '0', sizeof(sign));
//		count_tiles = 0;
//		int i_0, j_0;
//		for (int i = 0; i < r; ++i) {
//			cin.ignore(10, '\n');
//			for (int j = 0; j < c; ++j) {
//				scanf("%c", &matri[i][j]);
//				if (matri[i][j] == '@') {
//					i_0 = i; j_0 = j;
//				}
//			}
//		}
//
//		recurse_2816(i_0, j_0);
//		printf("%d\n", count_tiles);
//	}
//}
/*Accepted 
����ĵݹ�Ѱ·��������ע�⣺����߹��ĵط�
*/
//#include<string.h>
//#include<iostream>
//using namespace std;
//static char map[20][21];
//static int map_sign[20][20];
//static int count_available = 0;
//static int w = 0, h = 0;
//
//void go_sign(int i,int j) {
//	if ((map[i][j] == '@' || map[i][j] == '.')&&map_sign[i][j]==0) {//����Ǻڵ���û�߹�
//		map_sign[i][j] = 1;
//		++count_available;
//		//�ݹ��������ң��������Ϸ��Ļ�
//		if ((i - 1) >= 0)go_sign(i - 1, j);
//		if ((i + 1) < h)go_sign(i + 1, j);
//		if ((j - 1) >= 0)go_sign(i , j-1);
//		if ((j + 1) < w)go_sign(i, j+1);
//	}
//}
//void cal_num_group() {
//	//��ȡ�µ�ͼ
//	for (int i = 0; i < h; ++i) {
//		cin >> map[i];
//	}
//	//��ʼ����ͼ���
//	memset(map_sign, 0, sizeof(int) * 400);
//	//��ʼ������
//	count_available = 0;
//	//Ѱ����㲢��ʼ�ݹ�Ѱ·
//	for (int i = 0; i < h; ++i) {
//		for (int j = 0; j< w; ++j) {
//			if (map[i][j] == '@') {
//				go_sign(i, j);
//				break;
//			}
//		}
//	}
//	//���
//	cout << count_available << endl;
//}
//int main() {
//	while (true)
//	{
//		cin >> w; cin >> h;
//		if (w == 0 && h == 0)break;
//		cal_num_group();
//	}
//	
//	system("pause");
//	return 0;
//}