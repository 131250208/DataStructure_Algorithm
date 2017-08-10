/*
错误次数：3
1、坐标可达判断失误，第一步就不可达，导致全"oop!"------20
2、关键记录初始化疏漏，没有在每一组深搜开始前初始化steps和steps_min,导致新的组用旧的数据开始计算---54
3、坐标可达判断失误，坐标是从0开始的，r和c都应不可达-----20
*/

/*深搜+回溯+剪枝 耗时较长---超过100sm*/
//#include<iostream>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define big_num 1<<30
//static char labyrinth[210][210];
//static char sign[210][210];
//static int steps_least[210][210];
//static int r, c;
//static int steps = 0;
//static int steps_min = big_num;
//
//bool check_38(int i, int j) {
//	return i >= 0 && i< r&&j >= 0 && j < c&&(sign[i][j]=='0')&&(labyrinth[i][j]!='#');
//	//原错误代码：return i >= 0 && i<= r&&j >= 0 && j <= c && (sign[i][j] == '0') && (labyrinth[i][j] == '.');//第一点是S，进不了深搜
//}
//void recurse_38(int i,int j) {
//	if (!check_38(i, j))return;
//	if (labyrinth[i][j] == 'E') {
//		steps_min = min(steps_min,steps);
//		return;
//	}
//	sign[i][j] = '@';
//	steps++;
//	if (steps >= steps_min) {//最优化剪枝
//		sign[i][j] = '0';
//		steps--;
//		return;
//	}
//	if (steps >= steps_least[i][j]) {
//		sign[i][j] = '0';
//		steps--;
//		return;
//	}
//	steps_least[i][j] = steps;
//
//	recurse_38(i - 1, j);
//	recurse_38(i + 1, j);
//	recurse_38(i, j - 1);
//	recurse_38(i, j + 1);
//
//	sign[i][j] = '0';
//	steps--;
//}
//void del_group_38() {
//	scanf("%d %d", &r, &c);
//	getchar();
//	int i_0, j_0;
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			scanf("%c", &labyrinth[i][j]);
//			if (labyrinth[i][j] == 'S') {//标记起点
//				i_0 = i;
//				j_0 = j;
//			}
//			steps_least[i][j] = big_num;
//		}
//		getchar();
//	}
//
//	steps = 0; steps_min = big_num;//*
//	memset(sign, '0', sizeof(sign));
//
//	recurse_38(i_0, j_0);
//	if (steps_min == big_num)printf("oop!\n");
//	else
//	{
//		printf("%d\n", steps_min);
//	}
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		del_group_38();
//	}
//	system("pause");
//	return 0;
//}

/*广搜---较深搜快，10sm*/
/*Accepted
错误次数：1
1、结构体作参数，要加&符号，引用，不然只是在栈空间复制一个队里，不能修改到原来的队里
*/
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
static char labyrinth[210][210];
static char sign[210][210];
static int r, c;
struct Dot_38
{
	int i, j,layer; char value;
	Dot_38(){}
	Dot_38(int ii,int jj,char vv,int lay):i(ii),j(jj),value(vv),layer(lay) {}
};

bool check_38(int i, int j) {
	return i >= 0 && i< r&&j >= 0 && j < c&&(sign[i][j]=='0')&&(labyrinth[i][j]!='#');
}

int find_son(queue<Dot_38> &que,int i_1,int j_1,int l_1) {
	if (check_38(i_1, j_1)) {
		char v_1 = labyrinth[i_1][j_1];
		if (v_1 == 'E')return l_1;
		que.push(Dot_38(i_1, j_1, v_1, l_1));
		sign[i_1][j_1] = '@';
	}
	return -1;
}
int del_group_38() {
	scanf("%d %d", &r, &c);

	int i_0, j_0;
	for (int i = 0; i < r; ++i) {
		getchar();//处理回车
		for (int j = 0; j < c; ++j) {
			scanf("%c", &labyrinth[i][j]);
			if (labyrinth[i][j] == 'S') { i_0 = i; j_0 = j; }
		}
	}

	memset(sign, '0', sizeof(sign));
	queue<Dot_38> que;
	que.push(Dot_38(i_0, j_0, 'S', 0));
	sign[i_0][j_0] = '@';

	while (!que.empty())
	{
		Dot_38 dot = que.front();
		que.pop();

		int res_son = -1;
		int l_1 = dot.layer + 1;

		int i_1 = dot.i - 1,j_1= dot.j;
		res_son = find_son(que, i_1, j_1, l_1);
		if (res_son != -1)return res_son;

		i_1 = dot.i + 1, j_1 = dot.j;
		res_son = find_son(que, i_1, j_1, l_1);
		if (res_son != -1)return res_son;


		i_1 = dot.i, j_1 = dot.j-1;
		res_son = find_son(que, i_1, j_1, l_1);
		if (res_son != -1)return res_son;

		i_1 = dot.i, j_1 = dot.j+1;
		res_son = find_son(que, i_1, j_1, l_1);
		if (res_son != -1)return res_son;
	}
	return -1;
}
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		int res=del_group_38();
//		if (res == -1)printf("oop!\n");
//		else printf("%d\n", res);
//	}
//	system("pause");
//	return 0;
//}