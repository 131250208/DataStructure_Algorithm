/*wrong
��֪�����
˼·�����ֲ����ʺϵ�С�γ��ȣ�̰��������
*/
#include<iostream>
using namespace std;
static int n, k,len=0;
static int logs[10000];
void bisection(int start,int end) {
	if (start > end) return;
	//����С�γ��Ȳ������ܹ��еõ�С����Ŀ
	int mid = (start + end) / 2;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		count += logs[i] / mid;
	}

	if (count < k)bisection(start, mid - 1);
	if (count > k)bisection(mid + 1, end);
	if (count == k) {
		len = mid;
		bisection(mid + 1, end);
	}
}
//int main() {
//
//	int len_logs=0;
//	cin >> n; cin >> k;
//	for (int i = 0; i < n; ++i) {
//		cin>>logs[i];
//		len_logs += logs[i];
//	}
//	int max = len_logs / k;//С�ο��ܵ���󳤶�
//	if (max < 1)cout << 0 << endl;
//	else
//	{
//		bisection(1, max);
//		cout << len << endl;
//	}
//	
//	system("pause");
//	return 0;
//}