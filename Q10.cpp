#include <iostream>
using namespace std;

class ship {
private:
	int shipNum;
	int degrees;
	float minutes;
	char direction;
	static int count;
public:
	ship() {
		count++;
		shipNum = count;
	}
	void getAngle();
	void display() {
		cout << "Position of ship " << shipNum << " is : " ;
		cout << degrees<< "\xF8" << minutes << "' " << direction << endl;
		cout << "===============================" << endl;
	}
};
int ship::count = 0;

void ship::getAngle() {
	cout << "Please enter degree of ship " << shipNum << " : "; cin >> degrees;
	cout << "Please enter minutes of ship " << shipNum << " : "; cin >> minutes;
	cout << "Please enter direction of ship " << shipNum << " : "; cin >> direction;
	if (direction > 96 && direction < 124) {
		direction = direction - 32;
		// if enter letter e -> E 
	}
	else {
		// else print E
		direction = direction;
	}
}

int main() {
	ship A, B, C;
	A.getAngle();
	A.display();

	B.getAngle();
	B.display();
	C.getAngle();
	C.display();

	system("pause");
	return 0;
}