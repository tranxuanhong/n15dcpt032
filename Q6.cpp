#include <iostream>
#include <string>
using namespace std;

class employee {
private:
	int month, day, year;
	char slash1, slash2;
	int type;
	char *jobName;
	int empNum;
	float empComp;

	static int count;
public:
	employee() {
		month = day = year = 0;
		type;
		count++;
		empNum = count;
	}

	enum jobType {
		laborer = 1,
		secretary,
		manager,
		researcher,
		CEO
	};

	void getDate() {
		cout << "=====INFOMATION - EMPLOYEE " << empNum << " ====="<< endl;
		cout << "Enter renting date in mm/dd/yy format : ";
		cin >> month >> slash1 >> day >> slash2 >> year;
	}
	void getEmploy() {
		cout << "Please enter employee 's salary : "; cin >> empComp;
	}
	void putEmploy() {
		cout << "1.Laborer\n2.Secretary\n3.Manager\n4.Researcher\n5.CEO\n";
		cout << "Please enter your choice >> ";
		cin >> type;
		switch (type) {
		case laborer:
			jobName = "Laborer";
			break;
		case secretary:
			jobName = "Secretary";
			break;
		case manager:
			jobName = "Manager";
			break;
		case researcher:
			jobName = "Researcher";
			break;
		case CEO:
			jobName = "CEO";
			break;
		default:
			jobName = "Undefined";
			break;
		}
	}
	void showInfo() {
		cout << "=========================" << endl;
		cout << "The hiring date          : " << month << "/" << day << "/" << year << endl;
		cout << "The Employee 's number   : " << empNum << endl;
		cout << "The Employee 's salary   : " << empComp << endl;
		cout << "The Employee 's position : " << jobName << endl;
	}
};

int employee::count = 0;

int main() {
	employee A,B,C;
	A.getDate();
	A.putEmploy();
	A.getEmploy();
	A.showInfo();

	B.getDate();
	B.putEmploy();
	B.getEmploy();
	B.showInfo();

	C.getDate();
	C.putEmploy();
	C.getEmploy();
	C.showInfo();
	system("pause");
	return 0;
}