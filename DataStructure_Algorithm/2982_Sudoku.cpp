/*考前练习Accepted
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Pos_2982
{
	int i, j;
	Pos_2982(){}
	Pos_2982(int ii, int jj) :i(ii), j(jj) {}
};
static int rect[9][9];
static Pos_2982 blanks[100];
static char sign_row[9][10];
static char sign_col[9][10];
static char sign_group[9][10];
bool isLegal(int i, int j,int num) {
	return sign_row[i][num] == '0'&&sign_col[j][num] == '0'&&sign_group[i / 3 * 3 + j / 3][num] == '0';
}
void setflag(int i,int j,int num,char flag) {
	sign_row[i][num] = flag;
	sign_col[j][num] = flag;
	sign_group[i/3*3+j/3][num] = flag;
}

bool recurse_2982(int ind_blank) {
	if (ind_blank < 0)return true;

	Pos_2982 blank = blanks[ind_blank];
	int i = blank.i;
	int j = blank.j;
	for (int num = 1; num <= 9; ++num) {
		if (isLegal(i, j, num)) {
			setflag(i, j, num, '@');
			rect[i][j] = num;
			if (recurse_2982(ind_blank - 1))return true;
			setflag(i, j, num, '0');
			rect[i][j] = 0;
		}
	}
	return false;
}
void del_group2982() {
	memset(sign_row, '0', sizeof(sign_row));
	memset(sign_col, '0', sizeof(sign_col));
	memset(sign_group, '0', sizeof(sign_group));

	int ind = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%1d", &rect[i][j]);
			if (rect[i][j] == 0)blanks[ind++] = Pos_2982(i, j);
			setflag(i, j, rect[i][j], '@');
		}
	}

	if (recurse_2982(ind - 1)) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				printf("%d", rect[i][j]);
			}
			printf("\n");
		}
	}
}
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i) {
//		del_group2982();
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}


/*Accepted
错误次数：1
1、忽略了小组（3*3小方块）里也不能有相同数字------35\40\75
注意：
1、按坐标转换成小方块组号的方法------28
*/
//#include<iostream>
//#include<string.h>
//#include<vector>
//using namespace std;
//
//typedef struct {
//	int i=-1, j=-1;
//}Blank;
//Blank* getIns_blank(int i,int j) {
//	Blank* blank = (Blank*)malloc(sizeof(Blank));
//	blank->i = i;
//	blank->j = j;
//	return blank;
//}
//static int box[9][9];
//static int flag_row[9][10];
//static int flag_col[9][10];
//static int flag_group[9][10];//*
//
//static vector<Blank> blanks;
//static int num_blanks;
//int getInd_group(int i,int j) {//*
//	int ii = i / 3;
//	int jj = j / 3;
//	return ii * 3 + jj;
//}
//bool isLegal(int i,int j,int num) {
//	return !flag_row[i][num] && !flag_col[j][num]
//		&&!flag_group[getInd_group(i,j)][num];//*
//}
//void set_all_flags(int i,int j,int num,int flag) {
//	flag_row[i][num] = flag;
//	flag_col[j][num] = flag;
//	flag_group[getInd_group(i, j)][num] = flag;//*
//	if (flag) { 
//		box[i][j] = num; 
//	}
//}
//void show() {
//	for (int i = 0; i < 9; ++i) {
//		for (int j = 0; j < 9; ++j) {
//			cout << box[i][j];
//		}
//		cout << endl;
//	}
//}
//bool dfs_sudoku(int state) {
//	if (state == 0) {
//		return true;
//	}
//
//	Blank blank= blanks[state -1];
//	int r = blank.i;
//	int c = blank.j;
//	
//	for (int i = 1; i <= 9; ++i) {
//		if (isLegal(r, c, i)) {
//			set_all_flags(r, c, i, 1);
//			if(dfs_sudoku(state - 1))return true;
//			set_all_flags(r, c, i, 0);
//		}
//	}
//
//	return false;
//}
//void del_group_2982() {
//	memset(flag_row, 0, sizeof(flag_row));
//	memset(flag_col, 0, sizeof(flag_col));
//	memset(flag_group, 0, sizeof(flag_group));//*
//	blanks.clear();
//
//	num_blanks = 0;
//	for (int i = 0; i < 9; ++i) {
//		for (int j = 0; j < 9; ++j) {
//			char c;
//			cin >> c;
//			box[i][j]=c-'0';
//			if (box[i][j] != 0) {
//				flag_row[i][box[i][j]] = 1;
//				flag_col[j][box[i][j]] = 1;
//				flag_group[getInd_group(i, j)][box[i][j]]=1;
//			}
//			else
//			{
//				blanks.push_back(*getIns_blank(i, j));
//				++num_blanks;
//			}
//		}
//	}
//
//	if (dfs_sudoku(num_blanks)) {
//		show();
//	}
//		
//	
//}
//int main() {
//	int group;
//	cin >> group;
//	while (group--)
//	{
//		del_group_2982();
//	}
//	system("pause");
//	return 0;
//}