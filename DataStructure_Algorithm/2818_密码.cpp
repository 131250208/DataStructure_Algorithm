/*Accepted
���������3
1����ʱ��ֱ��ģ�����K�λ��ж����ѭ������Ҫ�����������ĸ��Ӧλ�õ�ѭ�����ڣ�Ȼ��ȡģ�õ�����������Ϊ���ܴ���
2��ѭ��Ƕ��������ͬ�ı���i
3�������ʽ����ÿ�����һ����

��ע��
1����ȡһ���ַ���������ָ�������ÿո����д��
		memset(text, ' ', n);//���ÿո���������n
		cin.getline(text, n + 1);//��ȡһ��
		text[strlen(text)] = ' ';//��ĩβ������ȥ��
2������һ���ַ�������д��
	cin.ignore()
	getchar();
*/
#include<iostream>
#include<string.h>
using namespace std;

static int encode_key[210];
static int encode_key_cir[210];
static char text[210];
static char code[210];
static int n;
void cal_cir() {
	for (int i = 1; i <= n; ++i) {
		int ind = i;
		int count = 0;
		while (true)
		{
			ind = encode_key[ind - 1];
			++count;
			if (ind == i)break;
		}
		encode_key_cir[i-1] = count;
	}
}
void encode(int k) {
	for (int i = 1; i <= n; ++i) {
		int time_enc = k%encode_key_cir[i - 1];
		int index = i;

		for(int j=0;j<time_enc;++j)
		{
			index = encode_key[index - 1];
		}
		code[index - 1] = text[i-1];
	}
}
//int main() {
//
//	while (true)
//	{
//		cin >> n;
//		if (n == 0)break;
//		//ÿ�鿪ʼ
//		for (int i = 0; i < n; ++i)cin >> encode_key[i];
//		//�����ܳ׵�����
//		cal_cir();
//
//		int k;
//		while (true)
//		{
//			cin >> k;
//			if (k == 0)break;
//			//��ȡÿ��text
//			getchar();
//			memset(text, ' ', n);
//			cin.getline(text, n+1);
//			text[strlen(text)] = ' ';
//
//			encode(k);
//			for (int i = 0; i < n; ++i)cout << code[i];
//			cout << endl;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}