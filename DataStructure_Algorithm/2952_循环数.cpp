/*Accepted
���������0
ע�⣺
1�����������60λ��Ҫ���ַ���ģ��˷�
2����˽�����һλ��λ���ɷ񶨣���Ϊλ����һ�²�������ѭ����
˼·��
3��һ��Ҫ���������е�ÿһλ�����뿪ͷ��ͬ��λ�ã����ǿ�ʼ���Աȣ���һλ���Լ��ɽ�����ζԱȣ�
����һ����num��ͷ��ͬ�ĵط���ʼ�Ƚ�
*/
#include<iostream>
#include<string.h>
using namespace std;

bool isCircle(char num[], char num_new[],int len) {
	for (int i = 0; i < len; ++i) {//��������ÿһλ
		if (num_new[i] == num[0]) {//����������ͬ��ͷ���ֵ�λ�ó���
			int isCircle = 1;
			for (int j = 1; j < len; ++j) {
				if (num[j] != num_new[(i + j) % len])isCircle = 0;//ֻҪ��һλ�����Ͳ���
			}
			if (isCircle)return true;
		}
	}
	return false;
}
int isCircle(char num[]) {
	int len = strlen(num);
	char* num_multi = (char*)malloc(sizeof(char)*len);
	//���
	int c = 0;//��λ
	for (int i = 2; i <= len; ++i) {//��2��ʼ������Ϊ��1�˿϶����
		for (int j = len - 1; j >= 0; --j) {//ģ��˷�
			int temp = i*(num[j] - '0');
			temp += c;
			c = temp / 10;
			num_multi[j] = (char)('0' + temp % 10);
		}
		if (c != 0)return 0;//������һλ��˽�λ��������λ������1��һ������ѭ����
		if (!isCircle(num, num_multi,len))return 0;//һ������������Ƚϣ���һ����������Ͳ���ѭ����
	}
	return 1;
}
//int main() {
//	char num[61];
//	cin >> num;
//	cout << isCircle(num);
//	system("pause");
//	return 0;
//}