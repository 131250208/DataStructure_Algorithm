/*Accepted
ע�⣺
��map�����·�������ķ���
*/
#include<iostream>
using namespace std;

int getDays(int m) {//����m��13�ž���1��1����ж�����
	char map[] = "303232332323" ;//ÿ������28��Ĳ�
	int days = 0;
	for (int i = 0; i < m - 1; ++i) {
		days += 28+map[i] - '0';
	}
	return (days + 13 - 1)%7;
}
//int main() {
//	int w = 0;
//	cin >> w;
//	
//	for (int i = 1; i <= 12;++i) {
//		if ((w + getDays(i))%7==5){
//			cout << i << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}