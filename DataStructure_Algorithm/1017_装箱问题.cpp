/*Accepted
�ͼ�����
ʣ���2*2ת����1*1Ҫ��4�������ǳ�2

��ע��
1��ȡ���޷�ʽ��e.g.(order[3] + 3) / 4--------ģ4ȡ����
2����ʣ��1*1��λ�������㷨
	��Ҫ�ۼӣ��׳����ÿ�����ܿռ��ȥ����1*1�����������õ��Ŀռ�
*/

#include<iostream>
#include<string.h>
using namespace std;
static int left_pla[3];//����ʣ��sizeΪ1��2�Ŀ�λ
static int order[7];//����

/*������㷨*/
int del_order_1017_1(int order[]) {
	memset(left_pla, 0, sizeof(left_pla));

	int count = 0;
	count = order[6] + order[5] + order[4] + (order[3] + 3) / 4;

	left_pla[2] += 5 * order[4];
	int left_3 = order[3] % 4;
	switch (left_3)
	{
	case 1:left_pla[2] += 5;
		break;
	case 2:left_pla[2] += 3;
		break;
	case 3:left_pla[2] += 1;
		break;
	}
	if (order[2] > left_pla[2])
		count += ((order[2] - left_pla[2]) + 8) / 9;

	left_pla[1] = count * 36 - order[6] * 36 - order[5] * 25 - order[4] * 16 - order[3] * 9 - order[2] * 4;
	if (order[1] > left_pla[1])
		count += ((order[1] - left_pla[1]) + 35) / 36;

	return count;
}

//int main() {
//	while (true)
//	{
//		for (int i = 1; i <= 6; ++i)cin >> order[i];
//		if (order[1] == 0 && order[2] == 0 && order[3] == 0
//			&& order[4] == 0 && order[5] == 0 && order[6] == 0) {
//			break;
//		}
//		cout<<del_order_1017_1(order)<<endl;
//	}
//	system("pause");
//	return 0;
//}

/*���δӴ�С����ķ���,�������ϴ�*/
int del_order_1017_2(int order[]) {
	memset(left_pla, 0, sizeof(left_pla));

	int count = 0;
	count += order[6];

	count += order[5];
	left_pla[1] += 11 * order[5];

	count += order[4];
	left_pla[2] += 5 * order[4];

	int left_3 = order[3] % 4;
	if (left_3 == 0)count += order[3] / 4;
	else {
		count += order[3] / 4 + 1;
		switch (left_3)
		{
		case 1:left_pla[1] += 7; left_pla[2] += 5;
			break;
		case 2:left_pla[1] += 6; left_pla[2] += 3;
			break;
		case 3:left_pla[1] += 5; left_pla[2]++;
			break;
		}
	}

	if (order[2] > left_pla[2]) {
		order[2] -= left_pla[2];
		if (order[2] % 9 == 0)count += order[2] / 9;
		else
		{
			count += order[2] / 9 + 1;
			left_pla[1] += (9 - order[2] % 9) * 4;
		}
	}
	else
	{
		left_pla[1] += (left_pla[2] - order[2]) * 4;
	}

	if (order[1] > left_pla[1]) {
		order[1] -= left_pla[1];
		if (order[1] % 36 == 0)count += order[1] / 36;
		else
		{
			count += order[1] / 36 + 1;
		}
	}

	return count;
}