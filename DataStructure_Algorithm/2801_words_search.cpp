/*�õ�strcmp����Ҫ��ͷ�ļ�
#include <string.h>
#include <string>
using std::string;
qsort������#include<stdlib.h>
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

//������
void copy_matrix(int matrix_des[][11], int matrix_res[][11]) {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix_des[i][j] = matrix_res[i][j];
		}
	}
	//show_matrix_int(matrix_res);
	//show_matrix_int(matrix_des);
}
//�ݹ�Ѱ����ĸ
void search(int sign[][11], int x, int y, char words[], int i) {
	if (words[i] != '\0') {
		if (matrix[x][y] == words[i]) {
			if (matrix_temp_sign[x][y] == 1) {//����λ��δ����
				matrix_temp_sign[x][y] = 0;
				//�������
				if (x - 1 >= 0&&found==0) {//���ƺ�����Ϸ�
					search(matrix_temp_sign, x - 1, y, words, i + 1);
				}
				if (y - 1 >= 0 && found == 0) {//���ƺ�����Ϸ�
					search(matrix_temp_sign, x, y - 1, words, i + 1);
				}
				if (x + 1 <= k&&found == 0) {//���ƺ�����Ϸ�
					search(matrix_temp_sign, x + 1, y, words, i + 1);
				}
				if (y + 1 <= m&&found == 0) {//���ƺ�����Ϸ�
					search(matrix_temp_sign, x, y + 1, words, i + 1);
				}
			}
		}
	}
	else
	{
		copy_matrix(matrix_sign, matrix_temp_sign);//���������ַ���˵��ǰ���Ѿ�ȫ���ҵ�
		found = 1;
	}

}

void init() {//��ʼ������
	cin >> k;
	cin >> m;
	cin >> p;
	//��ʼ����ĸ����
	for (int i = 0; i < k; ++i) {
		cin >> matrix[i];
	}
	//��ʼ��Ҫ�ҵĵ�������

	for (int i = 0; i < p; ++i) {
		cin >> words[i];
	}

	//��ʼ����Ǿ���
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix_sign[i][j] = 1;
		}
	}
}

//�����������
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
//	for (int k = 0; k < p;++k) {//�������е���		
//		int x, y = -1;
//		for (int i = 0; i < n; ++i) {//���������ҵ������˿�ͷ��ĸ
//			for (int j = 0; j < m; ++j) {
//				if (matrix[i][j] == words[k][0]&& matrix_sign[i][j]==1) {//����ǿ�ͷ��ĸ������м�֦�ݹ�
//					x = i;
//					y = j;
//					if (x != -1 && y != -1) {
//						copy_matrix(matrix_temp_sign, matrix_sign);
//						found = 0;//��֦��־����Ϊ0
//						search(matrix_temp_sign, x, y, words[k], 0);
//					}
//				}
//			}
//		}
//		
//	}
//	//���ʣ����ĸ
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


