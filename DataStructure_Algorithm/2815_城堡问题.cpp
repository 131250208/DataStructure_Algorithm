/*��ǰ��ϰ
*/
//#include<iostream>
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//static int r, c;
//static int castle[60][60];
//static char sign[60][60];
//static int num_blo_max;
//static int num_blo;
//
//bool noWall(int num,int dir) {
//	while (--dir)num /=2;
//	return !(num % 2);
//}
//void recurse_2815(int i, int j) {
//	if (sign[i][j] == '@')return;
//	sign[i][j] = '@';
//	num_blo++;
//	if (noWall(castle[i][j], 1))recurse_2815(i, j - 1);
//	if (noWall(castle[i][j], 2))recurse_2815(i - 1, j);
//	if (noWall(castle[i][j], 3))recurse_2815(i, j + 1);
//	if (noWall(castle[i][j], 4))recurse_2815(i + 1, j);
//}
//int main() {
//	scanf("%d %d", &r, &c);
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			scanf("%d", &castle[i][j]);
//		}
//	}
//
//	memset(sign, '0', sizeof(sign));
//	int count_room = 0;
//	num_blo_max = -1;
//	num_blo = 0;
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			if (sign[i][j] == '0') {
//				count_room++;
//				recurse_2815(i, j);
//				num_blo_max = max(num_blo_max, num_blo);
//				num_blo = 0;
//			}
//		}
//	}
//	printf("%d\n", count_room);
//	printf("%d\n", num_blo_max);
//	system("pause");
//	return 0;
//}
/*Accepted
���������1
ԭ��
һ�����Ӧ������ת���ɶ�����ʱ�������������û�г�ʼ��Ϊȫ0�����·��صĽ������-------24

˼·��
1����������ת���ɶ����ƣ������ж��ĸ������ǿ���ͨ���ģ����еݹ�Ѱ·��һ�߼�¼����
2�������������ÿһ������Ϊ��ʼ��Ѱ·�������뱣֤֮ǰ��Ѱ·û���߹��ÿ飬�ʻ���Ҫһ�����������¼�߹��Ŀ�

ע�⣺�ݹ�ʱҪע���ж��Ƿ��߹��ÿ�
*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//static int castle[50][50];
//static int castle_sign[50][50] = {};
//
//static int num_block_max = 0;
//static int num_block_temp = 0;
////ת����2���ƺ�ÿһλ���ɱ�ʾһ�������ǽ��0λ��û��ǽ
//int* trans_2(int num) {
//	int* res = new int[4];
//	//int* res = (int *)malloc(sizeof(int) * 4);
//	memset(res, 0, sizeof(int) * 4);//*��ʼ������Ϊȫ0
//	res[3] = num % 2;
//	int i = 1;
//	while ((num=num / 2) != 0) {
//		res[3 - i] = num % 2;
//		++i;
//	}
//	return res;
//}
////��i��j��ʼ�߼��㷿��Ŀ�����
//void count_blocks(int i,int j) {
//	if (castle_sign[i][j] == 1)return;//�߹��ĵط������ظ�����
//	castle_sign[i][j] = 1;
//	++num_block_temp;
//	num_block_max = (num_block_temp > num_block_max) ? num_block_temp : num_block_max;//ʵʱ��������
//
//	int* block_state = trans_2(castle[i][j]);
//	if (block_state[3] == 0)count_blocks(i, j - 1);
//	if (block_state[2] == 0)count_blocks(i-1, j );
//	if (block_state[1] == 0)count_blocks(i, j + 1);
//	if (block_state[0] == 0)count_blocks(i+1, j );
//}
//int main() {
//	int m = 0, n = 0;
//	cin >> m; cin >> n;
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			cin >> castle[i][j];
//		}
//	}
//
//	int num_room = 0;
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			if (castle_sign[i][j] == 0) {
//				++num_room;
//				num_block_temp = 0;//�·�������¼���
//				count_blocks(i, j);
//			}
//		}
//	}
//
//	cout << num_room << endl;
//	cout << num_block_max << endl;
//	system("pause");
//	return 0;
//}