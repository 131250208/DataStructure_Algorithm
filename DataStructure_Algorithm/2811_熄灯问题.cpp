/*Accepted
���������0
˼·��
1��ֻö�ٰ����ĵ�һ�л��У�֮����л��оͱ�Ψһȷ��������ֻ��Ҫö�٣�2^6��2^5�Σ�
2���ھ���������Ҽ�һ�У��У�ȫΪ0�ı߽磬�Լ��߼��ж�
3������ɿ�������Ƶ
*/

#include<iostream>
using namespace std;

static int state[6][8] = {};
static int press[6][8] = {};

bool guess() {
	//����һ�а����Ѿ�ȷ�������Ƴ���һ�а���
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j < 7; ++j) {
			press[i + 1][j] = (state[i][j] + +press[i][j]+press[i - 1][j] + press[i][j - 1] + press[i][j + 1]) % 2;
		}
	}
	//�ж����һ���Ƿ�ȫϨ��
	for (int j = 1; j < 7; ++j) {
		if ((state[5][j] + +press[5][j] + press[5 - 1][j] + press[5][j - 1] + press[5][j + 1]) % 2 == 1)return false;
	}
	return true;
}
void enumerate() {//�ö������ۼ���ö�ٵ�һ�а���
	for (int i = 1; i < 7; ++i) {
		press[1][i] = 0;
	}
	//ģ��������ۼӽ�λ
	while (guess()==false)//ֻҪ��δ������ȷ��ö�٣���һֱ���ж������ۼ�ö��
	{
		++press[1][1];
		//�����λ
		int c = 0,temp=0;
		for (int i = 1; i < 7; ++i) {
			temp=press[1][i] + c;
			c = temp / 2;
			press[1][i] = temp % 2;
		}
	}
}
//int main() {
//	for (int i = 1; i < 6; ++i) {
//		for (int j = 1; j < 7; ++j) {
//			cin >> state[i][j];
//		}
//	}
//	enumerate();
//	for (int i = 1; i < 6; ++i) {
//		for (int j = 1; j < 7; ++j) {
//			cout<<press[i][j]<<" ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}