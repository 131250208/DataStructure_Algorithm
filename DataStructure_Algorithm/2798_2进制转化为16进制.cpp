#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
static char num_2[10010];
static char num_16r[2510];
static char mapping[] = "0123456789ABCDEF";

void tran_2_16() {
	cin >> num_2;
	int len = strlen(num_2);

	int index=0, count=0;//��������4
	int count_16 = 0;//������16�������ĸ���
	for (int i = len - 1; i >= 0; --i) {
		index +=(num_2[i]-'0')*pow(2., count);

		count = (count + 1) % 4;
		if (count == 0||i==0) {//��4λ���ߵ�ͷ�ˣ��ͽ��ۼƵ�indexӳ�䵽mapȡ��ĸ���������num_16r
			num_16r[count_16++] = mapping[index];
			index = 0;//����index����
		}
	}
	//�������num_16r
	for (int i = count_16-1; i >= 0; --i)cout << num_16r[i];
	cout << endl;
}
//int main() {
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		tran_2_16();
//	}
//	system("pause");
//	return 0;
//}

