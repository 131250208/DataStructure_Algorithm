/*�������븴���ˣ��϶��м򵥵İ취
*/
#include<iostream>
#include<string.h>
using namespace std;

bool check(char a[], char b[],int x) {
	if (x == 0) {
		if (strcmp("1", b) <= 0 && strcmp(a, b) > 0)return true;
		return false;
	}
	//����a��x�η�
	//�ȷ�ת�洢��int������
	int a_int[100];
	int len_a = strlen(a);
	for (int i =0; i<len_a; ++i) {
		a_int[i] = a[len_a - 1 - i]-'0';//*
	}
	//���ڴ洢���������
	int res[100] = {};
	res[0] = 1;
	int multi[100];//��Ϊÿ�α�����
	int a_x[100], a_x_1[100];

	for (int k = 1; k <=x+1; ++k) {//x�η�
		memcpy(multi, res, sizeof(int) * 100);//ÿ�ν����Ϊ��һ��������
		memset(res, 0, sizeof(int) * 100);//���res������һ�δ洢

		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				res[i + j] = a_int[i]*multi[j];//*
			}
		}
		//����res��λ
		int c = 0, temp = 0;
		for (int i = 0; i < 100; ++i) {
			temp = res[i] + c;
			c = temp / 10;
			res[i] = temp % 10;
		}
		if (k == x)memcpy(a_x, res, sizeof(int) * 100);
		if (k == x+1)memcpy(a_x_1, res, sizeof(int) * 100);
	}
	//��ԭ��char�����ٽ��бȽ�
	char a_x_c[101];
	char a_x_1_c[101];
	int start = 0;
	int j = 0;
	for (int i = 99; i >= 0; --i) {
		if (a_x[i] != 0 || start) {
			a_x_c[j] = (char)(a_x[i] + '0');
			start = 1;
			++j;
		}
	}
	a_x_c[j] = '\0';

	start = 0;
	j = 0;
	for (int i = 99; i >= 0; --i) {
		if (a_x_1[i] != 0 || start) {
			a_x_1_c[j] = (char)(a_x_1[i] + '0');
			start = 1;
			++j;
		}
	}
	a_x_1_c[j] = '\0';
	//�Ƚϲ����ؽ��
	if (strcmp(a_x_c, b) <= 0 && strcmp(a_x_1_c,b) > 0)return true;
	return false;
}
//int main() {
//	char a[101];
//	char b[101];
//	cin >> a;
//	cin >> b;
//	for (int x = 0; x <= 20; ++x) {
//		if (check(a, b, x))cout << x;
//	}
//	system("pause");
//	return 0;
//}