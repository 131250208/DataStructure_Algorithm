/*��֪����������˺ܶ࣬������������ǶԵ�
*/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void cout_pow(char num[], int n) {
	//ȷ��'.'��index;
	string num_s = num;
	int len_num = num_s.length();
	int index_dot = ( len_num- 1 - num_s.find('.'))*n;
	//��num��ת�����int������,����'.'
	int num_int[6] = {};
	int j = 0;
	for (int i = 0; i < len_num; ++i) {
		num_int[j] = num[len_num - 1 - i]-'0';//*
		if (num[len_num - 1 - i] != '.')++j;
	}
	int res[130] = {};
	memcpy(res, num_int, sizeof(int)*(len_num - 1));
	for (int i = 1; i < n; ++i) {
		//��res����Ľ׶��Խ����ֵ��temp���飬����һ�δεĴ����˷�
		int multi[130];
		memcpy(multi, res, sizeof(int) * 130);//��res�����Ϊ��һ������
		memset(res, 0, sizeof(int) * 130);//���¼��������res
		for (int j = 0; j < len_num - 1; ++j) {
			for (int k = 0; k < 130; ++k) {
				res[j + k] += num_int[j] * multi[k];
			}
		}
		//�����λ
		int c = 0, temp = 0;
		for (int i = 0; i < 130; ++i) {
			temp = res[i] + c;
			c = temp / 10;
			res[i] = temp % 10;
		}
	}
	
	//С�����ִӺ���ǰ��һ����������
	int index_no_0 = -1;
	for (int i = 0; i < 130;++i) {
		if (res[i] != 0) {
			index_no_0 = i;
			break;
		}
	}
	//������
	int start = 0;
	for (int i = 129; i >= index_no_0; --i) {
		if (res[i] != 0 || start) {
			cout << res[i];
			start = 1;
			if (i == index_dot&&index_dot != index_no_0)cout << ".";
		}
		else if(i == index_dot)//��û������0���ȵ������"."λ�õ������Ӧ��ʼ���
		{
			start = 1;
			if (index_dot != index_no_0)cout << ".";
		}
	}
	cout << endl;
}
//int main() {
//	char num[7]; int n = 0;
//	while (cin >> num&&cin >> n) {
//		cout_pow(num, n);
//	}
//	system("pause");
//	return 0;
//}