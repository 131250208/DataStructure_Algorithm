/*
Accepted
错误次数：0

思路：
这个问题与前面所提到的最大子段有什么联系呢？
假设最大子矩阵的结果为从第r行到k行、从第i列到j列的子矩阵，如下所示(ari表示a[r][i],假设数组下标从1开始)：
| a11 …… a1i ……a1j ……a1n |
| a21 …… a2i ……a2j ……a2n |
|  .     .     .    .    .     .    .   |
|  .     .     .    .    .     .    .   |
| ar1 …… ari ……arj ……arn |
|  .     .     .    .    .     .    .   |
|  .     .     .    .    .     .    .   |
| ak1 …… aki ……akj ……akn |
|  .     .     .    .    .     .    .   |
| an1 …… ani ……anj ……ann |

那么我们将从第r行到第k行的每一行中相同列的加起来，可以得到一个一维数组如下：
(ar1+……+ak1, ar2+……+ak2, ……,arn+……+akn)
由此我们可以看出最后所求的就是此一维数组的最大子断和问题，到此我们已经将问题转化为上面的已经解决了的问题了。

*/
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
static int n;
static int matrix[100][100];
static int a[100];//转换的对应向量
static int b[100];//求向量最大子段和要用的状态数组
static int state[100];//以行为状态存储各个（行数）子矩阵的最大子矩阵和
int getSum_maxSubSeq(int start,int end) {//参数为行下标
	//转换成对应向量
	memset(a, 0, sizeof(a));

	for (int i = 0; i < n; ++i)//每列
		for (int j = start; j <= end; ++j)//行
			a[i] += matrix[j][i];

	//求向量的最大子段和
	b[0] = a[0];
	int res_max =b[0];
	for (int i = 1; i < n; ++i) {
		b[i] = max(b[i - 1] + a[i], a[i]);
		res_max = max(res_max, b[i]);
	}
	return res_max;
}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j)
//			cin >> matrix[i][j];
//
//	for(int i=1;i<=n;++i){//以矩阵的行数(i)为状态，遍历所有状态的子矩阵的对应向量的最大子段和
//		int res_max = -999999;
//		for (int j = 0; j < n - i + 1; ++j) {//j是行起始下标
//			res_max = max(getSum_maxSubSeq(j,j+i-1), res_max);
//		}
//		state[i - 1] = res_max;
//	}
//		
//	int res = -999999;
//	for (int i = 0; i < n; ++i) {
//		res = max(state[i], res);
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}