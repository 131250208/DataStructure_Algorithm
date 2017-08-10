#include<iostream>
using namespace std;

static int region[100][101];// �������
static int n;

void detect_tumour() {
	int area=0;//���
	int perimeter=0;//�ܳ�

	for (int i = 0; i < n;++i) {
		for (int j = 0; j < n; ++j) {
			if (region[i][j] <= 50) {
				++area;
				//�ж��Ƿ��Ǳ߽�
				int isEdge = 0;
				if (i == 0||j==0||i==n-1||j==n-1) isEdge=1;
				else
				{
					if (region[i - 1][j] > 50) isEdge = 1;
					if (region[i + 1][j] > 50) isEdge = 1;
					if (region[i][j - 1] > 50) isEdge = 1;
					if (region[i][j + 1] > 50) isEdge = 1;
				}

				if (isEdge) {//����Ǳ߽�
					++perimeter;
				}
			}
		}
	}

	cout << area << " " << perimeter;
}

//int main() {

//	cin >> n;
//	for (int i = 0; i < n;++i) {
//		for (int j = 0; j < n; ++j) {
//			cin >> region[i][j];
//		}
//	}
//	detect_tumour();
//	system("pause");
//	return 0;
//}