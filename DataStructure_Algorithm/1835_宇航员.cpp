/*Accepted
���������2
ԭ��
1�����û�л���
2��ÿ�����ǰû�����ó�ʼ״̬----23

˼·��
1����x,y,z�������״̬
2��faceto = 0,righthand=1,headto=2;����������ַ���ͷ������
3��ÿ��ת����������������ݣ��ٰ�����ķ�������Ӧ�ľ��룬����x,y,z

ע�⣺
1����Ƿ�������ּ�3ģ6�պ÷�ת
2��faceto ,righthand,headto�ĸ����໥֮���й�ϵ������ö��
*/
#include<iostream>
#include<string.h>
using namespace std;

static int x=0, y=0, z=0;//����״̬
//x��y��z������ֱ�Ϊ0��1��2��������ֱ�Ϊ3��4��5;��3ģ6�պ÷�ת
static int faceto = 0,righthand=1,headto=2;//����������ַ���ͬ��Ƿ���״̬
//���ó���״̬
void reset() {
	x = 0; y = 0; z = 0;
	faceto = 0; righthand = 1; headto = 2;
}
//��ǰ�ƶ�dis
void move(int dis) {
	switch (faceto)
	{
	case 0:x += dis;
		break;
	case 1:y += dis;
		break;
	case 2:z += dis;
		break;
	case 3:x -= dis;
		break;
	case 4:y -= dis;
		break;
	case 5:z -= dis;
		break;
	}
}
void updateState(char turn[], int dis) {
	//�ȵ�������������
	if (strcmp(turn, "back") == 0) {
		faceto = (faceto + 3) % 6;
		righthand = (righthand + 3) % 6;
	}
	if (strcmp(turn, "left") == 0) {
		int temp = faceto;
		faceto= (righthand + 3) % 6;
		righthand = temp;
	}
	if (strcmp(turn, "right") == 0) {
		int temp = righthand;
		righthand= (faceto + 3) % 6;
		faceto = temp;
	}
	if (strcmp(turn, "up") == 0) {
		int temp = headto;
		headto= (faceto + 3) % 6;
		faceto = temp;
	}
	if (strcmp(turn, "down") == 0) {
		int temp = faceto;
		faceto = (headto + 3) % 6;
		headto = temp;
	}
	//��faceto�ƶ�
	move(dis);
}
//��ÿ�������������״̬
void print_state_final() {
	reset();
	int n=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char turn[8]; int dis = 0;
		cin >> turn; cin >> dis;
		updateState(turn, dis);
	}
	//�������״̬
	cout << x << " " << y << " " << z << " " << faceto<<endl;
}
//int main() {
//	int group = 0;
//	cin >> group;
//	for (int i = 0; i < group; ++i) {
//		print_state_final();
//	}
//	system("pause");
//	return 0;
//}