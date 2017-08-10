/*Accepted
错误次数：0
关注：
1、结构体比较的方法------------26,39
2、运算符的重载--------------------26
3、结构体的多种构造函数--------------16,19
*/
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
using namespace std;

struct Box {
	double v, w, density;
	Box() {//*

	}
	Box(double vv, double ww) :v(vv), w(ww) {//*
		density = v / w;
	}
};

static Box boxes[100];
//重载boxes的比较<
bool operator < (const Box &a,const Box &b) {//*
	return a.density > b.density;
}
//int main() {
	//int n;
	//double w_max;
	//cin >> n >> w_max;
	//for (int i = 0; i < n; ++i) {
	//	int v, w;
	//	cin >> v >> w;
	//	boxes[i] = Box(v, w);
	//}
	////给boxes排序
	//sort(boxes, boxes + n);//*

	//double w_left = w_max;
	//double v_get = 0;
	//for (int i = 0; i < n; ++i) {
	//	if (boxes[i].w <= w_left) {
	//		w_left -= boxes[i].w;
	//		v_get += boxes[i].v;
	//	}
	//	else
	//	{
	//		v_get += boxes[i].density*(w_left);
	//		w_left = 0;
	//		break;
	//	}
	//}

	//cout <<setiosflags(ios::fixed)<<setprecision(1)<<v_get << endl;

//	system("pause");
//	return 0;
//}