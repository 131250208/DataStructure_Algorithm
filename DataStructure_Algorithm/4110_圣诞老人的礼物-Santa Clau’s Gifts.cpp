/*Accepted
���������0
��ע��
1���ṹ��Ƚϵķ���------------26,39
2�������������--------------------26
3���ṹ��Ķ��ֹ��캯��--------------16,19
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
//����boxes�ıȽ�<
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
	////��boxes����
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