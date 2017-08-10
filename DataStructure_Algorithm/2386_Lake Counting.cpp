/*考前练习Accepted*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

static char rect[110][110];
static char sign[110][110];
static int N, M;

bool isLegal_2386(int i,int j){
	return i >= 0 && i < N&&j >= 0 && j < M && sign[i][j]=='0' && rect[i][j] == 'W';
}

void recurse_2386(int i, int j) {
	if (!isLegal_2386(i, j))return;
	sign[i][j] = '@';
	recurse_2386(i - 1, j - 1);
	recurse_2386(i - 1, j);
	recurse_2386(i - 1, j + 1);
	recurse_2386(i, j - 1);
	recurse_2386(i, j + 1);
	recurse_2386(i + 1, j - 1);
	recurse_2386(i + 1, j );
	recurse_2386(i + 1, j + 1);
}
//int main() {
//	scanf("%d %d", &N, &M);
//	getchar();
//	for (int i = 0; i < N; ++i) {
//		gets_s(rect[i]);
//	}
//
//	memset(sign, '0', sizeof(sign));
//
//	int count_lake = 0;
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (isLegal_2386(i, j)) {
//				count_lake++;
//				recurse_2386(i, j);
//			}
//		}
//	}
//
//	printf("%d\n", count_lake);
//	system("pause");
//	return 0;
//}

/*Accepted
错误次数：1
原因：
1、寻找湖泊入口时少加一个判断（是否走过‘@’----43
*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//static char map[102][102];
//static char map_sign[102][102];
//
//void recurse_countlake2386(int i,int j) {
//	if (map_sign[i][j] == '@')return;//走过了
//	if (map[i][j] == 'W') {
//		map_sign[i][j] = '@';//标记
//		//递归周围8位置
//		recurse_countlake2386(i - 1, j - 1);
//		recurse_countlake2386(i - 1, j );
//		recurse_countlake2386(i - 1, j + 1);
//		recurse_countlake2386(i , j - 1);
//		recurse_countlake2386(i , j + 1);
//		recurse_countlake2386(i + 1, j - 1);
//		recurse_countlake2386(i + 1, j );
//		recurse_countlake2386(i+1, j+1);
//
//	}
//}
//int main() {
//	int n, m,count=0;
//	cin >> n; cin >> m;
//	cin.ignore();
//
//	memset(map, ' ', sizeof(map));
//	for (int i = 1; i <=n; ++i) {
//		cin.getline(map[i]+1, m+1);
//		map[i][m + 1] = ' ';
//	}
//
//	memset(map_sign, ' ', sizeof(map_sign));
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			if (map[i][j] == 'W'&&map_sign[i][j]!='@') { //*
//				++count;
//				recurse_countlake2386(i, j); 
//			}
//		}
//	}
//
//	cout << count<<endl;
//	system("pause");
//	return 0;
//}