/*Accepted
���������2
ԭ��
1�����������������0ʱ��Ҫ����һ��0��ԭ����ֱ��ȥ���˿�ͷ����0
2������Ӻ���ǰ��һ����������index����ʧ��

˼·��
ͨ��Ѱ��"."��index�����������벢ת���int����
��ӽ��ȥ����λ��0

ע�⣺
1����������Ԥ��һλ����������λ��λ
2�����������������0ʱ������һ��0
*/
#include<iostream>
#include<string>

using namespace std;

void add_f(char addend1[], char addend2[]) {
	//�ҵ��λ��
	string add1_s = addend1;
	string add2_s = addend2;
	int index_dot_add1 = add1_s.find('.');
	int index_dot_add2 = add2_s.find('.');
	int index_dot_res = (index_dot_add1 > index_dot_add2) ? index_dot_add1 : index_dot_add2;

	//ת�����������鲢����
	int add1_int[101] = {};
	int add2_int[101] = {};
	int gap1 = index_dot_res - index_dot_add1 + 1;//���룬��������ͷһλ�����ܵĽ�λ
	int gap2 = index_dot_res - index_dot_add2 + 1;
	//int len_max = (add1_s.length() > add2_s.length()) ? add1_s.length() : add2_s.length();

	for (int i = 0; i < add1_s.length(); ++i) {
		if (addend1[i] != '.') {
			add1_int[i + gap1] = addend1[i] - '0';
		}
		else add1_int[i + gap1] = -1;//��-1���"."��λ��
	}
	for (int i = 0; i < add2_s.length(); ++i) {
		if (addend2[i] != '.') {
			add2_int[i + gap2] = addend2[i] - '0';
		}
		else add2_int[i + gap2] = -1;//��-1���"."��λ��
	}
	//���
	int c = 0;
	int temp = 0;
	for (int i = 100; i >= 0;--i) {
		if (add1_int[i] == -1 && add2_int[i] == -1)continue;
		temp = add1_int[i] + add2_int[i] + c;
		c=temp / 10;
		add1_int[i] = temp % 10;//����洢�ڼ���1������
	}

	//�����βindex
	int index_end = -1;
	for (int i = 100; i >= 0; --i) {
		if (add1_int[i] != 0) {
			index_end = i; break;
		}
	}
	int start = 0;
	for (int i = 0; i <= index_end; ++i) {
		if (add1_int[i] == 0 && add1_int[i + 1] != -1&&start!=1) continue;
		start = 1;
		if (add1_int[i] == -1)cout << ".";
		else cout << add1_int[i];
	}
}
//int main() {
//	char addend1[101];
//	char addend2[101];
//
//	cin >> addend1;
//	cin >> addend2;
//	
//	add_f(addend1, addend2);
//	system("pause");
//	return 0;
//}