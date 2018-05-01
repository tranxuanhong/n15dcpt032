#include <iostream>

using namespace std;

class Int {
private :
	int varInt;
public:
	Int() {
		varInt = 0;
	}
	Int(int varInt) {
		this->varInt = varInt;
	}
	void display() {
		cout << varInt << endl;
	}
	void addition(Int x, Int y) {
		this->varInt = x.varInt + y.varInt;
	}
};

int main() {
	Int x(5),y(10);
	Int Result;
	Result.addition(x, y);
	Result.display();

	system("pause");
	return 0;
}