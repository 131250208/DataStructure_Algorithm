/*考前练习
错误次数：1
一定要用pos_tmp先记录下当前生成的串，找到一个再复制到结果数组中
如果直接在结果数组中生成，第二串及之后就乱了，因为回溯时达成新的符合条件的串时，之前的字符还在第一个位置中
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static char pos_tmp[9];
static char pos[92][9];
static int ind_2754=0;
bool isLegal_2754(char num,int end) {
	for (int i = 0; i < end; ++i) {
		if (pos_tmp[i] == num || abs(i - end) == abs(pos_tmp[i] - num))return false;
	}
	return true;
}
void recurse_2754(int i) {
	if (i == 8) {
		pos_tmp[8] = '\0';
		memcpy(pos[ind_2754++], pos_tmp, sizeof(pos_tmp));
	}
	for (int j = 1; j <= 8; ++j) {
		if (isLegal_2754(j + '0', i)) {
			pos_tmp[i] = j + '0';
			recurse_2754(i + 1);
		}
	}
}
//int main() {
//	recurse_2754(0);
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i) {
//		int ind;
//		scanf("%d", &ind);
//		printf("%s\n", pos[ind-1]);
//	}
//	system("pause");
//	return 0;
//}

/*Accepted
思路：
1、每一行只能放一个皇后
2、以行递归，每行枚举所有情况，找到合法的选择即可递归下一行
3、每个情况都需要判断是否合法，即横竖斜向不重

注意：
1、因为以行递归，无需再判断是否在一行上
2、是否在对角线上的判断语句：abs(i - pos) == abs(Qstr[i] - Qstr[pos])------20//即行列差绝对值相等就在对角线上
*/
#include<iostream>
#include<string.h>
using namespace std;
static int Qstr[8];
static int Qstrs[92][8];
static int count_qstr = 0;
bool legal(int pos) {//判断该位置是否可以继续递归下去,数组下标pos为行号，对应数组值为列号
	for (int i = 0; i < pos; ++i) {//与之前选定的位置作比较
		//列等或者斜同返回false，因为递归为行变化，无需考虑行等
		if (Qstr[i] == Qstr[pos] || abs(i - pos) == abs(Qstr[i] - Qstr[pos]))return false;
	}
	return true;
}
void check_pos(int pos) {
	if (pos == 8) {//pos是从0开始的，所以当递归到pos=8说明最后一行pos=7已经找到符合规则的位置
		memcpy(Qstrs[count_qstr], Qstr, sizeof(int) * 8);
		++count_qstr;
	}
	else {
		for (int i = 1; i <= 8; ++i) {//枚举这一行的每一列尝试
			Qstr[pos] = i;
			if (legal(pos))check_pos(pos + 1);
		}
	}
}
//int main() {
//	int n = 0;
//	cin >> n;
//	check_pos(0);
//	for (int i = 0; i < n; ++i) {
//		int index = 0;
//		cin >> index;
//		for (int j = 0; j < 8; ++j)cout << Qstrs[index - 1][j];
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}