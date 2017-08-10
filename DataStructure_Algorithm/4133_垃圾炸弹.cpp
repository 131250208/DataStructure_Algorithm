/*��֪ԭ���run time error
˼·��ö������������Ͷ�ŵ�
*/
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

static int screen[1025][1025];
static char sign[1025][1025];
static int d;
static int num_dot = 1, num_rubbish_max = -1;//Ͷ�ŵ������������������
struct Dot_intersection
{
	int x, y;
	Dot_intersection(){}
	Dot_intersection(int xx,int yy):x(xx),y(yy){}
};
bool inScreen(int x, int y) {
	return x >= 0 && x <= 1024
		&& y >= 0 && y <= 1024;
}
int getNum_rub(int x, int y) {//��Ͷ�ŵ������������
	int num = 0;
	for (int i = x - d; i <= x + d; ++i) {
		for (int j = y - d; j <= y + d; ++j) {
			if (!inScreen(i, j))continue;
			num += screen[i][j];
		}
	}
	return num;
}
void enum_dot(int x, int y) {//������Ϊ����ö�����������Ŀɴ�Ͷ�ŵ�
	for (int i = x - d; i <= x + d; ++i) {
		for (int j = y - d; j <= y + d; ++j) {
			if (sign[i][j] == '@'||!inScreen(i,j))continue;//�������߹��Ļ��߽߱����
			int num = getNum_rub(i, j);
			if (num> num_rubbish_max) {
				num_dot = 1;
				num_rubbish_max = num;
			}
			else if (num == num_rubbish_max)
			{
				num_dot++;
			}
			//����Ѿ��������Ͷ�ŵ㣬�����ظ�
			sign[i][j] = '@';
		}
	}
}
//int main() {
//
//	cin >> d;
//	int n;
//	cin >> n;
//
//	Dot_intersection dots[20];
//	int count = 0;
//
//	memset(screen, 0, sizeof(screen));
//	for (int i = 0; i < n; ++i) {
//		int x, y, num_rubbish;
//		cin >> x >> y >> num_rubbish;
//		screen[x][y] = num_rubbish;
//		dots[count++] = Dot_intersection(x, y);
//	}
//
//	memset(sign, '0', sizeof(sign));
//
//	for (int i = 0; i < count; ++i) {
//		 enum_dot(dots[i].x, dots[i].y);
//	}
//
//	cout << num_dot << " " << num_rubbish_max<<endl;
//	system("pause");
//	return 0;
//}