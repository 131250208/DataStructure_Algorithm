/*��ǰ��ϰ
���������1
һ��Ҫ��pos_tmp�ȼ�¼�µ�ǰ���ɵĴ����ҵ�һ���ٸ��Ƶ����������
���ֱ���ڽ�����������ɣ��ڶ�����֮������ˣ���Ϊ����ʱ����µķ��������Ĵ�ʱ��֮ǰ���ַ����ڵ�һ��λ����
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static char pos_tmp[9];
static char pos[92][9];
static int ind_2754=0;
bool isLegal_2754(char num,int end) {
	for (int i = 0; i < end; ++i) {
		if (pos_tmp[i] == num || abs(i - end) == abs(pos_tmp[i] - num))return false;
	}
	return true;
}
void recurse_2754(int i) {
	if (i == 8) {
		pos_tmp[8] = '\0';
		memcpy(pos[ind_2754++], pos_tmp, sizeof(pos_tmp));
	}
	for (int j = 1; j <= 8; ++j) {
		if (isLegal_2754(j + '0', i)) {
			pos_tmp[i] = j + '0';
			recurse_2754(i + 1);
		}
	}
}
//int main() {
//	recurse_2754(0);
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i) {
//		int ind;
//		scanf("%d", &ind);
//		printf("%s\n", pos[ind-1]);
//	}
//	system("pause");
//	return 0;
//}

/*Accepted
˼·��
1��ÿһ��ֻ�ܷ�һ���ʺ�
2�����еݹ飬ÿ��ö������������ҵ��Ϸ���ѡ�񼴿ɵݹ���һ��
3��ÿ���������Ҫ�ж��Ƿ�Ϸ���������б����

ע�⣺
1����Ϊ���еݹ飬�������ж��Ƿ���һ����
2���Ƿ��ڶԽ����ϵ��ж���䣺abs(i - pos) == abs(Qstr[i] - Qstr[pos])------20//�����в����ֵ��Ⱦ��ڶԽ�����
*/
#include<iostream>
#include<string.h>
using namespace std;
static int Qstr[8];
static int Qstrs[92][8];
static int count_qstr = 0;
bool legal(int pos) {//�жϸ�λ���Ƿ���Լ����ݹ���ȥ,�����±�posΪ�кţ���Ӧ����ֵΪ�к�
	for (int i = 0; i < pos; ++i) {//��֮ǰѡ����λ�����Ƚ�
		//�еȻ���бͬ����false����Ϊ�ݹ�Ϊ�б仯�����迼���е�
		if (Qstr[i] == Qstr[pos] || abs(i - pos) == abs(Qstr[i] - Qstr[pos]))return false;
	}
	return true;
}
void check_pos(int pos) {
	if (pos == 8) {//pos�Ǵ�0��ʼ�ģ����Ե��ݹ鵽pos=8˵�����һ��pos=7�Ѿ��ҵ����Ϲ����λ��
		memcpy(Qstrs[count_qstr], Qstr, sizeof(int) * 8);
		++count_qstr;
	}
	else {
		for (int i = 1; i <= 8; ++i) {//ö����һ�е�ÿһ�г���
			Qstr[pos] = i;
			if (legal(pos))check_pos(pos + 1);
		}
	}
}
//int main() {
//	int n = 0;
//	cin >> n;
//	check_pos(0);
//	for (int i = 0; i < n; ++i) {
//		int index = 0;
//		cin >> index;
//		for (int j = 0; j < 8; ++j)cout << Qstrs[index - 1][j];
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}