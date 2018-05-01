#include <iostream>
using namespace std;

class date {
private:
	int month, day, year;
	char slash1, slash2;
public:
	date() {
		month = day = year = 0;
	}
	void getDate() {
		cout << "Enter date in mm/dd/yy format : ";
		cin >> month >> slash1 >> day >> slash2 >> year;
	}
	void showDate() {
		cout << "Result : " << month << "/" << day << "/" << year << endl;
	}
};

int main() {
	date Date;
	Date.getDate();
	Date.showDate();
	system("pause");
	return 0;
}