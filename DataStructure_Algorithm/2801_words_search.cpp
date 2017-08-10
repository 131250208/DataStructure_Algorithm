/*用到strcmp函数要加头文件
#include <string.h>
#include <string>
using std::string;
qsort函数在#include<stdlib.h>
*/

#include<iostream>
#include<stdlib.h>
#include <string.h>  
#include <string>  
using std::string;
using namespace std;

int matrix_temp_sign[10][11];
int matrix_sign[10][11];
char matrix[10][11];
char words[100][101];
int k, m, p;
void show_matrix_int(int matrix[][11]);
int found = 0;

//矩阵复制
void copy_matrix(int matrix_des[][11], int matrix_res[][11]) {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix_des[i][j] = matrix_res[i][j];
		}
	}
	//show_matrix_int(matrix_res);
	//show_matrix_int(matrix_des);
}
//递归寻找字母
void search(int sign[][11], int x, int y, char words[], int i) {
	if (words[i] != '\0') {
		if (matrix[x][y] == words[i]) {
			if (matrix_temp_sign[x][y] == 1) {//若该位置未访问
				matrix_temp_sign[x][y] = 0;
				//检查四周
				if (x - 1 >= 0&&found==0) {//上移后坐标合法
					search(matrix_temp_sign, x - 1, y, words, i + 1);
				}
				if (y - 1 >= 0 && found == 0) {//左移后坐标合法
					search(matrix_temp_sign, x, y - 1, words, i + 1);
				}
				if (x + 1 <= k&&found == 0) {//下移后坐标合法
					search(matrix_temp_sign, x + 1, y, words, i + 1);
				}
				if (y + 1 <= m&&found == 0) {//右移后坐标合法
					search(matrix_temp_sign, x, y + 1, words, i + 1);
				}
			}
		}
	}
	else
	{
		copy_matrix(matrix_sign, matrix_temp_sign);//遇到结束字符，说明前面已经全部找到
		found = 1;
	}

}

void init() {//初始化数据
	cin >> k;
	cin >> m;
	cin >> p;
	//初始化字母矩阵
	for (int i = 0; i < k; ++i) {
		cin >> matrix[i];
	}
	//初始化要找的单词数组

	for (int i = 0; i < p; ++i) {
		cin >> words[i];
	}

	//初始化标记矩阵
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix_sign[i][j] = 1;
		}
	}
}

//输出矩阵内容
void show_matrix_int(int matrix[][11]) {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void show_matrix_char(char matrix[][11]) {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int cmp1(const void *a, const void*b) {
	char *s1 = (char *)a;
	char *s2 = (char *)b;
	return strcmp(s1, s2);
}

//int main() {
//	init();
//	for (int k = 0; k < p;++k) {//遍历所有单词		
//		int x, y = -1;
//		for (int i = 0; i < n; ++i) {//遍历矩阵找到所到此开头字母
//			for (int j = 0; j < m; ++j) {
//				if (matrix[i][j] == words[k][0]&& matrix_sign[i][j]==1) {//如果是开头字母，则进行剪枝递归
//					x = i;
//					y = j;
//					if (x != -1 && y != -1) {
//						copy_matrix(matrix_temp_sign, matrix_sign);
//						found = 0;//剪枝标志重置为0
//						search(matrix_temp_sign, x, y, words[k], 0);
//					}
//				}
//			}
//		}
//		
//	}
//	//输出剩余字母
//	char word_left[101];
//	int count = 0;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			if (matrix_sign[i][j]==1) {
//				word_left[count] = matrix[i][j];
//				++count;
//			}
//		}
//	}
//
//	word_left[count] = '\0';
//	qsort(word_left,count,sizeof(word_left[0]),cmp1);
//	cout << word_left;
//
//	system("pause");
//	return 0;
//}


