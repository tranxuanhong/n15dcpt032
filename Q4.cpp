#include <iostream>
using namespace std;

class employee {
private:
	int empNum;
	float empCompensation;
public:
	employee() {
		empNum = 0;
		empCompensation = 0;
	}
	void enterData() {
		cout << "Enter the Employee 's number : "; cin >> empNum;
		cout << "Enter the Employee 's compensation : "; cin >> empCompensation;
	}
	void display() {
		cout << "Employee 's number : " << empNum << endl;
		cout << "Employee 's Comp : " << empCompensation << endl;
	}
};

int main() {
	employee EmpA, EmpB, EmpC;
	cout << "Employee A : " << endl;
	EmpA.enterData();
	EmpA.display();
	cout << "Employee B : " << endl;
	EmpB.enterData();
	EmpB.display();
	cout << "Employee C : " << endl;
	EmpC.enterData();
	EmpC.display();
	system("pause");
	return 0;
}