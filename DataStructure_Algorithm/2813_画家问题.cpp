/*Accepted
���������2
ԭ��
1��ѭ������д��----66
2�����ǿ��ǲ���Ϳ��ȫ�Ƶ����----72
*/
#include<iostream>
using namespace std;
static int n = 0;
static int wall[16][17] = {};
static int paint[16][17] = {};
bool guess_() {
	//��paint��һ�е�ö�ٿ�ʼ���ƺ�����
	for (int i = 1; i < n ; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			paint[i + 1][j] = (wall[i][j] + paint[i][j] + paint[i - 1][j] + paint[i][j - 1] + paint[i][j + 1]) % 2;
		}
	}
	//�ж����һ���Ƿ�ȫ��
	for (int j = 1; j < n + 1; ++j) {
		if ((wall[n][j] + paint[n][j] + paint[n - 1][j] + paint[n][j - 1] + paint[n][j + 1]) % 2 == 1)return false;
	}
	return true;
}
int getNum_paint() {
	int count = 0;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			count += paint[i][j];
		}
	}
	return count;
}
int enumerate_() {
	int min_paint = 250;
	while (true)
	{
		if (guess_()) {
			int num_paint = getNum_paint();
			min_paint = (num_paint < min_paint) ? num_paint : min_paint;
		}
		//������ö�ٲ���λ
		int isOver = 1;

		++paint[1][1];
		int c = 0,temp=0;
		//��λ
		for (int i = 1; i < n + 1; ++i) {
			temp = paint[1][i]+c;
			c = temp / 2;
			paint[1][i] = temp % 2;
			if (paint[1][i] == 1)isOver = 0;//ֻҪ��������һ������Ϊ0���Ͳ������
		}
		if (isOver)break;//���»ص�ȫ0״̬��˵��ö�����
	}
	return min_paint;
}
//int main() {
//	
//	cin >> n;
//	char wall_c[15][16];
//	for (int i = 0; i < n; ++i) {
//		cin >> wall_c[i];
//	}
//	//����Ϩ������Ľ���취���浽��������
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j< n; ++j) {//*ԭ����j<nд��i<n;
//			if (wall_c[i][j] == 'w')wall[i + 1][j + 1] = 1;//��ɫ�൱�����ŵĵƣ���Ҫ�أ�Ϳ��
//			else if(wall_c[i][j] == 'y')wall[i + 1][j + 1] = 0;
//		}
//	}
//	//ö�ٲ���������Ϳ������
//	if (enumerate_() == 250)cout << "inf";//*ԭ���������жϲ���Ϳ��ȫ�Ƶ����
//	else cout << enumerate_();
//	system("pause");
//	return 0;
//}