/*Accepted
错误次数：2
原因：
1、审题不清，要输出的是最短路径包括线段数，而不是经过的卡牌数
2、超时，少了一些优化策略，如当前步数已经超过目前最少步数，则应该停止递归
3、审题疏忽，输出格式错误，每组数据之间要求一个空行

二刷需要结合视频：
精简代码
*/
#include<iostream>
#include<string.h>
using namespace std;
static char map[77][77];
static char path_sign[77][77];
static int w, h;
static int len_min;
static int len_path=0;
static int direction = -1;//0,1,2,3---东南西北

void find(int x1, int y1, int x2, int y2) {
	if (map[y1][x1] == ' '&&path_sign[y1][x1] == '0') {
		if (len_path > len_min)return;
		path_sign[y1][x1] = '1';
		if (x1 == x2&&y1 == y2) {//找到一条路径,比较当前路径长与最短路径
			len_min = (len_path < len_min) ? len_path : len_min;
		}
		//四周递归
		int dir_pre = direction;
		if ((x1 - 1) >= 0) {
			if (direction != 3) {
				++len_path; direction = 3;
				find(x1 - 1, y1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1 - 1, y1, x2, y2);
		}
		if ((y1 - 1) >= 0) {
			if (direction != 2) {
				++len_path; direction = 2;
				find(x1, y1 - 1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1, y1 - 1, x2, y2);
		}
		if ((x1 + 1) <= w + 1) {
			if (direction != 1) {
				++len_path; direction = 1;
				find(x1 + 1, y1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1 + 1, y1, x2, y2);
		}
		if ((y1 + 1) <= h + 1) {
			if (direction != 0) {
				++len_path; direction = 0;
				find(x1, y1 + 1, x2, y2);
				direction = dir_pre; --len_path;
			}
			else find(x1, y1 + 1, x2, y2);
		}

		//回溯标记撤回
		path_sign[y1][x1] = '0';
	}
}
int find_path(int x1, int y1, int x2, int y2) {
	//清空初始化路径标记
	memset(path_sign, '0', sizeof(char) * 77 * 77);
	len_min= 10000;
	len_path = 0;

	map[y1][x1] = ' ';
	map[y2][x2] = ' ';//为了方便寻路，把起点终点都设为无卡可达

	find(x1, y1, x2, y2);

	map[y1][x1] = 'X';//恢复起点与终点的卡牌
	map[y2][x2] = 'X';

	return len_min;
}
//int main() {
//	int group = 1;
//	while (true)
//	{
//		cin >> w; cin >> h;
//		cin.ignore();
//		if (w == 0 && h == 0)break;
//		//输出组号
//		cout << "Board #" << group << ":" << endl;
//		++group;
//		//初始化地图
//		memset(map, '*', sizeof(char) * 77 * 77);
//
//		memset(map[0],' ', sizeof(char)*(w + 2));
//		for (int i = 1; i <=h; ++i) {
//			map[i][0] = ' ';
//			cin.getline(map[i] + 1, w + 1);
//			map[i][w + 1] = ' ';//删除结束符
//		}
//		memset(map[h+1], ' ', sizeof(char)*(w + 2));
//
//		//根据输入卡牌进行输出
//		int x1, y1, x2, y2;
//		int pair = 1;
//		while (true)
//		{
//			cin >> x1; cin >> y1; cin >> x2; cin >> y2;
//			if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)break;
//			int len_min=find_path(x1, y1, x2, y2);
//			cout << "Pair " << pair << ": ";
//			if (len_min == 10000)cout << "impossible."<<endl;
//			else cout<<len_min<<" segments."<<endl;
//			++pair;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}