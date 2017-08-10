/*Accepted
错误次数：2
原因：
1、输出没有换行
2、每组操作前没有重置初始状态----23

思路：
1、用x,y,z标记坐标状态
2、faceto = 0,righthand=1,headto=2;标记面向、右手方向、头顶方向
3、每个转向更新以上三个数据，再按面向的方向走相应的距离，更新x,y,z

注意：
1、标记方向的数字加3模6刚好反转
2、faceto ,righthand,headto的更新相互之间有关系，不必枚举
*/
#include<iostream>
#include<string.h>
using namespace std;

static int x=0, y=0, z=0;//坐标状态
//x，y，z正方向分别为0，1，2，负方向分别为3，4，5;加3模6刚好反转
static int faceto = 0,righthand=1,headto=2;//面向方向和右手方向共同标记方向状态
//重置初试状态
void reset() {
	x = 0; y = 0; z = 0;
	faceto = 0; righthand = 1; headto = 2;
}
//向前移动dis
void move(int dis) {
	switch (faceto)
	{
	case 0:x += dis;
		break;
	case 1:y += dis;
		break;
	case 2:z += dis;
		break;
	case 3:x -= dis;
		break;
	case 4:y -= dis;
		break;
	case 5:z -= dis;
		break;
	}
}
void updateState(char turn[], int dis) {
	//先调整三个面向方向
	if (strcmp(turn, "back") == 0) {
		faceto = (faceto + 3) % 6;
		righthand = (righthand + 3) % 6;
	}
	if (strcmp(turn, "left") == 0) {
		int temp = faceto;
		faceto= (righthand + 3) % 6;
		righthand = temp;
	}
	if (strcmp(turn, "right") == 0) {
		int temp = righthand;
		righthand= (faceto + 3) % 6;
		faceto = temp;
	}
	if (strcmp(turn, "up") == 0) {
		int temp = headto;
		headto= (faceto + 3) % 6;
		faceto = temp;
	}
	if (strcmp(turn, "down") == 0) {
		int temp = faceto;
		faceto = (headto + 3) % 6;
		headto = temp;
	}
	//朝faceto移动
	move(dis);
}
//对每组数组输出最终状态
void print_state_final() {
	reset();
	int n=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char turn[8]; int dis = 0;
		cin >> turn; cin >> dis;
		updateState(turn, dis);
	}
	//输出最终状态
	cout << x << " " << y << " " << z << " " << faceto<<endl;
}
//int main() {
//	int group = 0;
//	cin >> group;
//	for (int i = 0; i < group; ++i) {
//		print_state_final();
//	}
//	system("pause");
//	return 0;
//}