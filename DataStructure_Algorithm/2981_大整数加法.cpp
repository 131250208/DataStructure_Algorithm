/*Accepted
���������2
����ԭ��
1��û���ǵ���0+0�����������ʱfind_first_not_of('0')�Ҳ���pos����������ʱ�쳣------24
2�������������̲�һʱ�Ľ�λ��������λ����������ڽ��ǰ�����һ��1--------53��65

����˼·��(���´�����ȥ���˼�����0�����º�����λ��������˲���Ҫ���鷳������ֻ����������˼·)
1������������ͳһ��201λ��
2���������ǰ��0����������һ��200λȫ��0�����飬�ٰѼ���װ���ȥ��-----memset(test, '0', 200);
3��ģ��ӷ����㣬�������ȥ0
4��ȥ0�����ҵ�һ����0��posȡ�Ӵ�(���������ַ�������ʱ)��Ҳ���Ա�������0��������ַ������顢�������鶼���ԣ�

ע�⣺
strlen��ss.length��õ��ַ������Ⱦ���������β��'\0'
*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void add(char addend1[], char addend2[]) {

	//���ǰ��0
	string add1 = addend1; string add2 = addend2;
	int index_start_add1 = 0;
	if ((index_start_add1 = add1.find_first_not_of('0')) != string::npos) {//*1
		add1 = add1.substr(index_start_add1);
	}
	else
	{
		add1 = "0";
	}
	int index_start_add2 = 0;
	if ((index_start_add2 = add2.find_first_not_of('0')) != string::npos) {
		add2 = add2.substr(index_start_add2);
	}
	else
	{
		add2 = "0";
	}
	

	int len1 = add1.length();
	int len2 = add2.length();
	//��ת�����ַ�����
	char* add1_c = (char*)malloc(sizeof(char)*len1+1);
	char* add2_c = (char*)malloc(sizeof(char)*len2+1);
	strcpy(add1_c, add1.c_str());
	strcpy(add2_c, add2.c_str());

	int c = 0;//��λ
	if (len1 > len2) {
		while (len1>0) {
			int temp=add1_c[--len1]-'0'+c;//*
			if ((--len2) >= 0) temp+= add2_c[len2] - '0';//*2�̵������±�Ϸ�ʱ�ŷ��ʲ��ۼ�,����ֻ�Ƴ������������λ�ĺͣ�
															//��λ����һֱ������ȥ��������һ�����Ѿ�������
			c = temp / 10;
			add1_c[len1] = (char)('0'+temp % 10);
		}
		if (c == 1)cout << c;
		cout << add1_c;
	}
	else
	{
		while (len2>0) {
			int temp = add2_c[--len2]-'0' + c;//*
			if ((--len1) >= 0)temp += add1_c[len1] - '0';//*�̵������±�Ϸ�ʱ�ŷ��ʲ��ۼ�
			c = temp / 10;
			add2_c[len2] = (char)('0'+temp % 10);
		}
		if (c == 1)cout << c;
		cout << add2_c;
	}
}
//int main() {
//	char addend1[201];
//	char addend2[201];
//	cin >> addend1; 
//	cin >> addend2;
//	add(addend1, addend2);
//	system("pause");
//	return 0;
//}