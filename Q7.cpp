#include <iostream>
using namespace std;

class angle {
private:
	int degrees;
	float minutes;
	char direction;
public:
	angle(int degrees, float minutes, char direction) {
		this->degrees = degrees;
		this->minutes = minutes;
		this->direction = direction;
	}
	void getAngle(int degrees, float minutes, char direction);
	void display() {
		cout << degrees<< "\xF8" << minutes << "' " << direction << endl;
	}
	~angle() {

	}
};

void angle::getAngle(int degrees, float minutes, char direction) {
	this->degrees = degrees;
	this->minutes = minutes;
	if (direction > 96 && direction < 124) {
		this->direction = direction - 32;
		// if enter letter a -> A 
	}
	else {
		// else print A
		this->direction = direction;
	}
}

int main() {
	angle A(100, 35.5, 'E');
	A.display();
	A.getAngle(66, 55.4, 's');
	A.display();

	system("pause");
	return 0;
}