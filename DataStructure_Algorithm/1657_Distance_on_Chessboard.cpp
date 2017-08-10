
/*踩坑记录：
	赋值0
	int dis_K, dis_Q, dis_E, dis_C = 0;//错误
	int dis_K=0, dis_Q=0, dis_E=0, dis_C = 0;//正确

*/
#include<iostream>

using namespace std;

void trans_location(char input[],int &x,int &y) {
	x = input[0] - 'a';
	y = input[1] - '0';
	
}

int distance_King(int x1, int y1, int x2, int y2) {
	int dis_h = abs(x1 - x2);
	int dis_v = abs(y1 - y2);
	return (dis_h>dis_v)?dis_h:dis_v;
}

int distance_Queen(int x1, int y1, int x2, int y2) {
	int dis_h = abs(x1 - x2);
	int dis_v = abs(y1 - y2);
	if (x1 == x2 || y1 == y2 || dis_h == dis_v) {
		return 1;
	}
	return 2;
}

int distance_Elephant(int x1, int y1, int x2, int y2) {
	int dis_h = abs(x1 - x2);
	int dis_v = abs(y1 - y2);

	if (dis_h==dis_v) {
		return 1;
	}
	else if(abs(dis_h-dis_v)%2==0)//象只能走同色
	{
		return 2;
	}
	return -1;
}

int distance_Chariot(int x1, int y1, int x2, int y2) {
	if (x1 == x2 || y1 == y2) {
		return 1;
	}
	return 2;
}

void output(int x1, int y1, int x2, int y2,int end) {
	int dis_K=0, dis_Q=0, dis_E=0, dis_C = 0;
	if (x1 != x2||y1!=y2) {
		 dis_E = distance_Elephant(x1, y1, x2, y2);
		 dis_K = distance_King(x1, y1, x2, y2);
		 dis_Q = distance_Queen(x1, y1, x2, y2);
		 dis_C = distance_Chariot(x1, y1, x2, y2);
	}

	cout << dis_K << " " << dis_Q << " " << dis_C << " ";

	if (dis_E != -1) {
		cout << dis_E;
	}
	else
	{
		cout << "Inf";
	}
	if (end != 1) {
		cout << endl;
	}
	
}
//int main() {
//	int lines = 0;
//	cin >> lines;
//	char input1[20][3];
//	char input2[20][3];
//	for (int i = 0; i < lines;i++) {
//		cin >> input1[i];
//		cin >> input2[i];
//	}
//	for (int i = 0; i < lines; ++i) {
//		int x1, y1 = 0;
//		trans_location(input1[i], x1, y1);
//
//		int x2, y2 = 0;
//		trans_location(input2[i], x2, y2);
//		
//		if (i==lines-1) {
//			output(x1, y1, x2, y2,1);
//		}
//		else {
//			output(x1, y1, x2, y2,0);
//		}
//		
//	}
//	system("pause");
//	return 0;
//}