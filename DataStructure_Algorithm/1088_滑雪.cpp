/*��Ϊ���˷�
Accepted
���������2
1���㳤��ʱ������ֻ��ʼ�����һ�㣬Ҫȫ������ʼ��Ϊ1����Ϊ�����������ܷ���---33
2���ڶ���ʱ��������Χ�Ĳ���Ӧ������max��������ֱ��ȡ��---40~43
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct Dot_1088
{
	int i,j,h;
	Dot_1088() {}
	Dot_1088(int ii, int jj, int hh):i(ii), j(jj), h(hh) {}
};
static int matrix[110][110];
static int len_matri[110][110];
static Dot_1088 dots[10100];

bool operator < (const Dot_1088 &a,const Dot_1088 &b) {
	return a.h < b.h;
}
//int main() {
//	int R, C;
//	scanf("%d %d", &R, &C);
//	int count = 0;
//	for (int i = 1; i <= R; ++i) {
//		for (int j = 1; j <= C; ++j) {
//			scanf("%d", &matrix[i][j]);
//			dots[count++]=Dot_1088(i, j, matrix[i][j]);
//			len_matri[i][j] = 1;//*��ʼ����С����1
//		}
//	}
//	sort(dots, dots + count);
//
//	for (int i = 0; i < count-1; ++i) {
//		Dot_1088 dot = dots[i];
//		if (matrix[dot.i - 1][dot.j] > dot.h)len_matri[dot.i - 1][dot.j] = max(len_matri[dot.i - 1][dot.j],len_matri[dot.i][dot.j] + 1);
//		if (matrix[dot.i + 1][dot.j] > dot.h)len_matri[dot.i + 1][dot.j] = max(len_matri[dot.i + 1][dot.j], len_matri[dot.i][dot.j] + 1);
//		if (matrix[dot.i][dot.j - 1] > dot.h)len_matri[dot.i][dot.j - 1] = max(len_matri[dot.i][dot.j - 1], len_matri[dot.i][dot.j] + 1);
//		if (matrix[dot.i][dot.j + 1] > dot.h)len_matri[dot.i][dot.j + 1] = max(len_matri[dot.i][dot.j + 1], len_matri[dot.i][dot.j] + 1);
//	}
//
//	int len_max = -1;
//	for (int i = 1; i <= R; ++i) {
//		for (int j = 1; j <= C; ++j) {
//			len_max = max(len_max, len_matri[i][j]);
//		}
//	}
//	printf("%d\n", len_max);
//	system("pause");
//	return 0;
//}

/*����Ϊ�ҷ�*/
/*Accepted
����������2
ԭ��
1��qsort����ıȽϺ�������ֵ����
	��ȷ����ӦΪ��
	����---���ڷ���+1��С�ڷ���-1
	����---���ڷ���-1��С�ڷ���1
	sort�ıȽϺ�������ֵ�����ã�a>b��
2��dots��С�ˣ�100*100=10000����

ע�⣺qsort��sort���÷���sort�Ͽ죩
1����������鲻����ָ�룬�����ǽṹ�����
2���ȽϺ����ķ���
*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//static int map[105][105];
//static int len_reg[105][105];
//
//typedef struct {
//	int x, y, h;
//}Dot;
//Dot dots[10000];
//Dot* getInstance_dot(int x, int y, int h) {
//	Dot* dot = (Dot*)malloc(sizeof(Dot));
//	dot->x = x;dot->y = y;dot->h = h;
//	return dot;
//}
//int cmp_dot_1088(const void* d1, const void* d2) {
//	Dot* dot1 = (Dot*)d1;
//	Dot* dot2 = (Dot*)d2;
//	return dot1->h > dot2->h ? 1 : -1;
//}
//int main() {
//	int r, c;
//	cin >> r; cin >> c;
//	int count = 0,h;
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			cin >> h;
//			dots[count++] = *getInstance_dot(i + 1, j + 1, h);
//			map[i+1][j+1] = h;
//		}
//	}
//	//���㰴�߶�������
//	qsort(dots,count, sizeof(dots[0]), cmp_dot_1088);
//	//��������Ƴ���Ӧ����Ϊ��ߵ�����򳤶�
//	memset(len_reg, 0, sizeof(len_reg));
//	int x, y,max_around;
//	for (int i = 0; i < count; ++i) {
//		x = dots[i].x; y = dots[i].y; h = dots[i].h;
//		max_around = 0;
//		if (map[x - 1][y] < h) max_around = (len_reg[x - 1][y] > max_around) ? len_reg[x - 1][y] : max_around;
//		if (map[x + 1][y] < h) max_around = (len_reg[x + 1][y] > max_around) ? len_reg[x + 1][y] : max_around;
//		if (map[x][y-1] < h) max_around = (len_reg[x][y-1] > max_around) ? len_reg[x][y-1] : max_around;
//		if (map[x][y+1] < h) max_around = (len_reg[x][y+1] > max_around) ? len_reg[x][y+1] : max_around;
//
//		len_reg[x][y] = max_around + 1;
//	}
//	//�ҳ�������
//	int max_len = 0;
//	for (int i = 1; i <= r; ++i) {
//		for (int j = 1; j <= c; ++j) {
//			max_len = (len_reg[i][j] > max_len) ? len_reg[i][j] : max_len;
//		}
//	}
//	cout << max_len<<endl;
//	system("pause");
//	return 0; 
//}