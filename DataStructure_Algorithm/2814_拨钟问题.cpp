/*Accepted
思路：
枚举所有方案：9重循环
每种操作可以有4种选择，分别拨动0~3下，因拨4下与0下一样的结果
结果与拨钟操作的顺序无关
*/
#include<iostream>
#include<string.h>
using namespace std;
static int clocks[9];
static char map[9][10];
void init_map() {
	strcpy(map[0], "110110000");
	strcpy(map[1], "111000000");
	strcpy(map[2], "011011000");
	strcpy(map[3], "100100100");
	strcpy(map[4], "010111010");
	strcpy(map[5], "001001001");
	strcpy(map[6], "000110110");
	strcpy(map[7], "000000111");
	strcpy(map[8], "000011011");
}
void setClock(int clocks[], int num, int times) {//num号操作，拨动times次
	for (int i = 0; i < 9; ++i) {
		if (map[num][i] == '1')clocks[i] = (clocks[i] + times) % 4;
	}
}
bool check(int clocks[]) {
	for (int i = 0; i < 9; ++i) {
		if (clocks[i] != 0)return false;
	}
	return true;
}
void enumerate_clockSet() {
	int min_times = 50;
	int times[9];
	for (int op1 = 0; op1 < 4; ++op1) {
		for (int op2 = 0; op2 < 4; ++op2) {
			for (int op3 = 0; op3 < 4; ++op3) {
				for (int op4 = 0; op4 < 4; ++op4) {
					for (int op5 = 0; op5 < 4; ++op5) {
						for (int op6 = 0; op6 < 4; ++op6) {
							for (int op7 = 0; op7 < 4; ++op7) {
								for (int op8 = 0; op8 < 4; ++op8) {
									for (int op9 = 0; op9 < 4; ++op9) {
										int clock_temp[9];
										memcpy(clock_temp, clocks, 9 * sizeof(int));

										//进行拨钟操作
										setClock(clock_temp, 0, op1);
										setClock(clock_temp, 1, op2);
										setClock(clock_temp, 2, op3);
										setClock(clock_temp, 3, op4);
										setClock(clock_temp, 4, op5);
										setClock(clock_temp, 5, op6);
										setClock(clock_temp, 6, op7);
										setClock(clock_temp, 7, op8);
										setClock(clock_temp, 8, op9);

										if (check(clock_temp)) {//如果符合要求,找出最短序列
											int len = op1 + op2 + op3 + op4 + op5 + op6 + op7 + op8 + op9;
											if (len < min_times) {
												min_times = len;
												times[0] = op1; times[1] = op2; times[2] = op3; times[3] = op4; times[4] = op5;
												times[5] = op6; times[6] = op7; times[7] = op8; times[8] = op9;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < times[i]; ++j) {
			cout << i + 1 << " ";
		}
	}
}
//int main() {
//	
//	for (int i = 0; i < 9; ++i)cin >> clocks[i];
//	init_map();
//	enumerate_clockSet();
//	system("pause");
//	return 0;
//}