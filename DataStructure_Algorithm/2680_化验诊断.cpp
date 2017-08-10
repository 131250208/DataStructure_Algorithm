/*
17、18行 struct中有string是对象 ，不要用malloc
new 返回的是指针
*/

#include<iostream>
#include<string>
using namespace std;

typedef struct {
	string gender;
	double WBC, RBC, HGB, HCT, PLT, num_abnormal;
}Patient;
//int main() {
//	int n = 0;
//	cin >> n;
//	/*Patient *patients = (Patient *)malloc(n * sizeof(Patient));*/
//	Patient *patients = new Patient[n];
//
//	for (int i = 0; i < n; ++i) {
//
//		cin >> patients[i].gender;
//		string gender= patients[i].gender;
//		cin >> patients[i].WBC;
//		cin >> patients[i].RBC;
//		cin >> patients[i].HGB;
//		cin >> patients[i].HCT;
//		cin >> patients[i].PLT;
//
//		int num_abnormal = 0;
//		if (patients[i].WBC<4.0 || patients[i].WBC>10.0)++num_abnormal;
//		if (patients[i].RBC<3.5 || patients[i].RBC>5.5)++num_abnormal;
//		if (gender == "male") {
//			if (patients[i].HGB<120.0 || patients[i].HGB>160.0)++num_abnormal;
//			if (patients[i].HCT<42.0 || patients[i].HCT>48.0)++num_abnormal;
//		}
//		else
//		{
//			if (patients[i].HGB<110.0 || patients[i].HGB>150.0)++num_abnormal;
//			if (patients[i].HCT<36.0 || patients[i].HCT>40.0)++num_abnormal;
//		}
//		if (patients[i].PLT<100.0 || patients[i].PLT>300.0)++num_abnormal;
//
//		patients[i].num_abnormal = num_abnormal;
//	}
//
//	for (int i = 0; i < n; ++i) {
//		if (patients[i].num_abnormal==0) {
//			cout << "normal" << endl;
//		}
//		else
//		{
//			cout << patients[i].num_abnormal << endl;
//		}
//	}
//	delete[]patients;
//	system("pause");
//	return 0;
//}