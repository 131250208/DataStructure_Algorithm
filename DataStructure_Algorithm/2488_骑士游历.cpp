/*��ǰ��ϰAccepted
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static int p, q;
static char sign[30][30];
static bool found;
static char path[2000];
static int ind_2488;
static int num_group;

bool isLegal_2488(int i,int j) {
	return i >= 0 && i < p&&j >= 0&&j < q&&sign[i][j] == '0';
}
void dfs_2488(int i,int j,int layer) {
	if (!isLegal_2488(i, j) || found)return;
	path[ind_2488++] = j + 'A';
	path[ind_2488++] = i + '1';
	sign[i][j] = '@';
	if (layer == p*q) {
		path[ind_2488] = '\0';
		printf("Scenario #%d:\n",num_group++);
		printf("%s\n", path);
		found = true;
		return;
	}

	dfs_2488(i - 1, j - 2, layer + 1);
	dfs_2488(i + 1, j - 2, layer + 1);
	dfs_2488(i - 2, j - 1, layer + 1);
	dfs_2488(i + 2, j - 1, layer + 1);
	dfs_2488(i - 2, j + 1, layer + 1);
	dfs_2488(i + 2, j + 1, layer + 1);
	dfs_2488(i - 1, j + 2, layer + 1);
	dfs_2488(i + 1, j + 2, layer + 1);

	sign[i][j] = '0';
	ind_2488 -= 2;
}
void del_group_2488() {
	scanf("%d %d", &p, &q);
	found = false;
	ind_2488 = 0;
	memset(sign, '0', sizeof(sign));

	dfs_2488(0, 0, 1);

	if (found == false) {
		printf("Scenario #%d:\nimpossible\n",num_group++);
	}
}
//int main() {
//	int n;
//	scanf("%d", &n);
//	num_group = 1;
//	for (int i = 0; i < n; ++i) {
//		del_group_2488();
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
/*Accepted
˼·�����ѡ�����
1��Խ����߹��Ĳ���
2����¼�߹���λ�ã��������������
ע�⣺
1�����ѵ�˳���ֵ���
2�����������֡���������ĸ
3����������㣬��ƽʱϰ�ߵ����ϲ�ͬ

*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//
//static int nums, letters;
//static int chess[30][30];
//static char path[2000];
//static int count_step = 0;
//static int square_left;
//static bool isover;
//static int number_group=0;
//bool islegal(int i,int j) {
//	if (i >= 1 && i <= nums&&j >= 1 && j <= letters)return true;
//	return false;
//}
//
//void recurse_2488(int i,int j) {
//	if (islegal(i, j) && chess[i][j] != 1&&!isover) {//����Ϸ���δ�߹��ҵ�ǰ�ݹ�δ����
//		chess[i][j] = 1;
//		--square_left;
//		path[count_step++] = (char)('A' + j - 1);
//		path[count_step++] = '0' + i;
//
//		if (square_left == 0) {
//			//�ҵ�һ��·��
//			path[count_step] = '\0';
//			//���
//			cout << "Scenario #"<<++number_group<<":" << endl;
//			cout << path << endl<<endl;
//			//����
//			isover = true;
//		}
//		//�ݹ�8������
//		recurse_2488(i - 1, j - 2);
//		recurse_2488(i + 1, j - 2);
//		recurse_2488(i - 2, j - 1);
//		recurse_2488(i + 2, j - 1);
//		recurse_2488(i - 2, j + 1);
//		recurse_2488(i + 2, j + 1);
//		recurse_2488(i - 1, j + 2);
//		recurse_2488(i + 1, j + 2);
//		//����
//		chess[i][j] = 0;
//		++square_left;
//		count_step -= 2;
//		path[count_step] = '\0';
//	}
//}
//void del_group_2488() {
//	cin >> nums; cin >> letters;
//	memset(chess, 0, sizeof(chess));
//	square_left = nums*letters;
//	isover = false;
//	count_step = 0;
//	recurse_2488(1, 1);//��A1���ݹ�
//	if (isover == false) { 
//		cout << "Scenario #" << ++number_group << ":" << endl;
//		cout << "impossible\n" << endl; 
//	}
//}
//int main() {
//	int group;
//	cin >> group;
//	for (int i = 0; i < group; ++i)del_group_2488();
//	system("pause");
//	return 0;
//}