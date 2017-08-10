#include<iostream>
using namespace std;

static int num_student = 0;
typedef struct {
	char name[21];
	int grade_term = 0;
	int grade_class = 0;
	char isLeader = 'N';
	char isWestern = 'N';
	int num_paper = 0;

	int scholarship = 0;
}Student;

//int main() {
//	cin >> num_student;
//
//	Student *students= (Student *)malloc(num_student * sizeof(Student));
//	int scholarship_total = 0;
//	for (int i = 0; i < num_student;++i) {
//		cin >> students[i].name;
//		cin >> students[i].grade_term;
//		cin >> students[i].grade_class;
//		cin >> students[i].isLeader;
//		cin >> students[i].isWestern;
//		cin >> students[i].num_paper;
//		students[i].scholarship = 0;
//
//		if (students[i].grade_term>80&&students[i].num_paper>=1) {
//			students[i].scholarship += 8000;
//		}
//		if (students[i].grade_term > 85 && students[i].grade_class > 80)students[i].scholarship += 4000;
//		if (students[i].grade_term > 90)students[i].scholarship += 2000;
//		if (students[i].grade_term > 85 && students[i].isWestern == 'Y')students[i].scholarship += 1000;
//		if (students[i].grade_class > 80 && students[i].isLeader == 'Y')students[i].scholarship += 850;
//		
//		scholarship_total += students[i].scholarship;
//	}
//
//	int max_index = 0;
//	int max_scholarship = 0;
//	for (int i = 0; i < num_student; ++i) {
//		if (students[i].scholarship > max_scholarship) {
//			max_index = i;
//			max_scholarship = students[i].scholarship;
//		}
//	}
//
//	cout << students[max_index].name<<endl;
//	cout << max_scholarship << endl;
//	cout << scholarship_total;
//
//	system("pause");
//	return 0;
//}