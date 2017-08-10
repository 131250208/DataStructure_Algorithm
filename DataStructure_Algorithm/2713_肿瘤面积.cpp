/*
边界问题：36行说明
没考虑全打破循环的条件，造成死循环（漏了越界的情况，即永远遇不到255）
*/

#include<iostream>
using namespace std;

int region[1000][1001];
int n = 0;
int getPx_tumour() {
	//找到肿瘤起始像素点
	int x = 0, y = 0,out=0;
	for (int i = 0; i < n;++i) {
		for (int j = 0; j < n;++j) {
			if (region[i][j]==0) {
				x = i;
				y = j;
				out = 1;
				break;
			}
		}
		if (out == 1) {
			break;
		}
	}

	int l = 0,w=0;//计算肿瘤长和宽
	while (true)
	{
		if (region[x][y]==255||x>=n) {//非0或者x越界，打破循环
			break;
		}
		++x;
		++w;
	}
	--x;//因为上个循环的x已经是越界的
	while (true)
	{
		if (region[x][y] == 255||y>=n) {
			break;
		}
		++l;
		++y;
	}
	return (l - 2)*(w - 2);
}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n;++i) {
//		for (int j = 0; j < n;++j) {
//			cin >> region[i][j];
//		}
//	}
//
//	cout << getPx_tumour();
//	system("pause");
//	return 0;
//}