/*Accepted
����2
ԭ��
1��memset���÷������󣬵����������ǰ��ֽ����size----------17
	memset(res, 0, sizeof(int)*400);//*------��ȷ
	memset(res, 0, 400);//*-------��������ֻ������ǰ100������Ϊ0

2��©����һ����Ϊ����������Ĵ������Ϊ0ʱû������κζ���--------15
3������ж�̫�򵥣��ų�������0�����Խ��ĩβ��0δ���---------34��38
*/
#include<string.h>
#include<iostream>
using namespace std;
void multi(char multi1[], char multi2[]) {
	if (strcmp(multi1, "0") == 0 || strcmp(multi2, "0") == 0) { cout << 0; return; }//*2
	int res[400];
	memset(res, 0, sizeof(int)*400);//*1
	int len_multi1 = strlen(multi1);
	int len_multi2 = strlen(multi2);
	for (int i = len_multi1-1; i >=0 ; --i) {
		for (int j = len_multi2-1; j >=0 ; --j) {
			int index_res = (len_multi1 - 1 - i) + (len_multi2 - 1 - j);
			res[index_res] += (multi1[i] - '0')*(multi2[j] - '0');
		}
	}
	//�����λ
	int c = 0;
	int temp = 0;
	for (int i = 0; i < 400; ++i) {
		temp = res[i] + c;
		c= temp/ 10;
		res[i] = temp % 10;
	}
	int start = 0;//*3
	for (int i = 399; i >= 0; --i) {
		if (res[i] != 0 || start) {
			cout << res[i];
			start = 1;//*3
		}
	}
}
//int main() {
//	char multi1[201];
//	char multi2[201];
//	cin >> multi1;
//	cin >> multi2;
//	multi(multi1, multi2);
//	system("pause");
//	return 0;
//}