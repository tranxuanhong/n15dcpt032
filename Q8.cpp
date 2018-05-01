#include <iostream>
using namespace std;

class serialNumber {
private:
	int serialNum;
	static int count;
public:
	serialNumber() {
		count++;
		serialNum = count;
	}
	void display() {
		cout << "Hello, I am Object " << serialNum << endl;
	}
};

int serialNumber::count = 0;

int main() {
	serialNumber A, B, C;
	A.display();
	B.display();
	C.display();
	system("pause");
	return 0;
}