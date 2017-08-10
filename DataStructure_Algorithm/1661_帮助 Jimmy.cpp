/*wrong  题目样例通过，未知原因提交错误

错误次数：1
原因：
1、qsort的用来排序结构体时，排序的数组中应该直接存储对象，不应该存储指针，否则比较函数会出错
2、

思路：动态规划
从高度最低的板子开始遍历，在其上的板子都check一下是否可以从两端落到这个板子上，如果可以
就可以从低板子递推那个高板子的两端下落到地面的最短时间
*/
#include<iostream>
#include<algorithm>
using namespace std;

#define infinite 999999;
typedef struct {
	int x1, x2, h;
	int leftmin, rightmin;//该平台左右端点到地面的最短时间
}Platform;

Platform plats[1000];
static int  n, x, y, dis_max;

Platform* getInstance_platform(int x1, int x2, int h) {
	Platform* res = (Platform*)malloc(sizeof(Platform));
	res->x1 = x1;
	res->x2 = x2;
	res->h = h;
	if (h > dis_max) {
		res->leftmin = infinite;//先用高度做初值
		res->rightmin = infinite;
	}
	else
	{
		res->leftmin = h;//先用高度做初值
		res->rightmin = h;
	}
	return res;
}

//比较平台高度的函数
int cmp_platform(const void* p1, const void* p2) {
	Platform* plat1 = (Platform*)p1;
	Platform* plat2 = (Platform*)p2;
	int h1 = plat1->h;
	int h2 = plat2->h;
	return (h1> h2);
}

void del_group_1661() {
	
	cin >> n; cin >> x; cin >> y; cin >> dis_max;

	int x1, x2, h;
	for (int i = 0; i < n; ++i) {
		cin >> x1; cin >> x2; cin >> h;
		plats[i]=*getInstance_platform(x1, x2, h);
	}
	//给平台排序
	qsort(plats, n, sizeof(plats[0]), cmp_platform);

	//更新平台左右端到地面最短时间
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int dis = plats[j].h - plats[i].h;
			if (dis <= dis_max) {//首先高度差不大于max
				//更新左端点
				if (plats[j].x1 >= plats[i].x1&&plats[j].x1 <= plats[i].x2) {//如果j的左端点可以落在i上
					plats[j].leftmin = dis + min(plats[j].x1-plats[i].x1+plats[i].leftmin, plats[i].x2-plats[j].x1+plats[i].rightmin);
				}
				//更新右端点
				if (plats[j].x2 >= plats[i].x1&&plats[j].x2 <= plats[i].x2) {//如果j的右端点可以落在i上
					plats[j].rightmin = dis + min(plats[j].x2 - plats[i].x1 + plats[i].leftmin, plats[i].x2 - plats[j].x2 + plats[i].rightmin);
				}
			}
		}
	}

	//计算结果
	for (int i = n - 1; i >= 0; --i) {
		if (x >= plats[i].x1&&x <= plats[i].x2) {
			cout << (y - plats[i].h + min(x-plats[i].x1+plats[i].leftmin,plats[i].x2-x+plats[i].rightmin))<<endl;
			break;
		}
	}
}
//int main() {
//	int group;
//	cin >> group;
//	for (int i = 0; i < group; ++i) {
//		del_group_1661();
//	}
//
//	system("pause");
//	return 0;
//}