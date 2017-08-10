/*考前练习
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
错误次数：1
原因：
一个块对应的数字转换成二进制时出错，申请的数组没有初始化为全0，导致返回的结果错误-------24

思路：
1、输入数据转换成二进制，方便判断哪个方向是可以通过的，进行递归寻路，一边记录块数
2、主方法里便利每一个块作为起始块寻路，但必须保证之前的寻路没有走过该块，故还需要一个辅助数组记录走过的块

注意：递归时要注意判断是否走过该块
*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//static int castle[50][50];
//static int castle_sign[50][50] = {};
//
//static int num_block_max = 0;
//static int num_block_temp = 0;
////转换成2进制后，每一位即可表示一个方向的墙，0位即没有墙
//int* trans_2(int num) {
//	int* res = new int[4];
//	//int* res = (int *)malloc(sizeof(int) * 4);
//	memset(res, 0, sizeof(int) * 4);//*初始化数组为全0
//	res[3] = num % 2;
//	int i = 1;
//	while ((num=num / 2) != 0) {
//		res[3 - i] = num % 2;
//		++i;
//	}
//	return res;
//}
////从i，j开始走计算房间的块数。
//void count_blocks(int i,int j) {
//	if (castle_sign[i][j] == 1)return;//走过的地方不再重复计数
//	castle_sign[i][j] = 1;
//	++num_block_temp;
//	num_block_max = (num_block_temp > num_block_max) ? num_block_temp : num_block_max;//实时更新最大块
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
//				num_block_temp = 0;//新房间块重新计数
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