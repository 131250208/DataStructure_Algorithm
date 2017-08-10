
/*��ǰ��ϵ
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static char labyrinth[110][110];
static char sign[110][110];
static 	int n;
bool isLegal2790(int i,int j) {
	return i >= 0 && i < n&&j >= 0 && j < n&&labyrinth[i][j]=='.'&&sign[i][j]=='0';
}
void recurse_2790(int i,int j) {
	if (!isLegal2790(i, j))return;
	sign[i][j] = '@';
	recurse_2790(i - 1, j);
	recurse_2790(i + 1, j);
	recurse_2790(i , j - 1);
	recurse_2790(i , j + 1);
}
void del_group2790() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i)scanf("%s", &labyrinth[i]);
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	memset(sign, '0', sizeof(sign));
	recurse_2790(r1, c1);
	if (sign[r2][c2] == '@')printf("YES\n");
	else printf("NO\n");
}
//int main() {
//	int group;
//	scanf("%d", &group);
//	while (group--)
//	{
//		del_group2790();
//	}
//	system("pause");
//	return 0;
//}
/*Accepted
���������0

˼·��
����㿪ʼ�ݹ�Ѱ·���ɴ�ĵط������'1'�����еݹ�������ٿ�Ŀ�ĵ��Ƿ񱻱����'1'

ע�⣺
1������п��ܲ��ɴ�
2������յ����ͬһλ��

�߼�д�úã���������������㣬�������⴦��
*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//
//static char map[100][100];
//static char path_sign[100][100];
//static 	int n = 0;
//
//void find_path(int ha, int la) {
//	if (map[ha][la] == '.'&&path_sign[ha][la] == '0') {
//		path_sign[ha][la] = '1';
//		if ((ha - 1) >= 0)find_path(ha-1,la);
//		if ((ha + 1) < n )find_path(ha + 1, la);
//		if ((la - 1) >= 0)find_path(ha , la-1);
//		if ((la + 1) < n)find_path(ha, la+1);
//	}
//}
//void group_del() {
//	// ��ȡ����
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		cin >> map[i];
//	}
//	int ha, la, hb, lb;
//	cin >> ha; cin >> la; cin >> hb; cin >> lb;
//	//��ʼ�������·�����
//	memset(path_sign,'0', sizeof(char) * 10000);
//
//	//�ݹ�Ѱ·���ɴ���'1';
//	find_path(ha, la);
//	if (path_sign[hb][lb] == '1')cout << "YES"<<endl;
//	else cout << "NO"<<endl;
//}
//int main() {
//	int group = 0;
//	cin >> group;
//	for (int i = 0; i < group; ++i) {
//		group_del();
//	}
//	system("pause");
//	return 0;
//}