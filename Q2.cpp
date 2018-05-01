#include <iostream>
using namespace std;

class tollBooth {
private:
	unsigned int numOfCars;
	double amountOfMoney;
public:
	tollBooth() {
		numOfCars = 0;
		amountOfMoney = 0;
	}
	void payingCar() {
		numOfCars++;
		amountOfMoney += 0.50;
	}
	void nopayCar() {
		numOfCars++;
		amountOfMoney = amountOfMoney;
	}
	void display() {
		cout << "Total number of Cars : " << numOfCars << endl;
		cout << "Total amount of money : " << amountOfMoney << endl;
	}

};

int main() {
	char choice;
	tollBooth Booth;

	do {
		do
		{
			cout << "1.Press 'p' to count up the paying car " << endl;
			cout << "2.Press 'n' to count up the nonpaying car " << endl;
			cout << "3.Press 'e' to print out the result and exit " << endl;
			cout << "Please enter you choice >> "; cin >> choice;
			if (choice != 'p' && choice != 'n' && choice != 'e')
				cout << "You MUST enter the right character !!! \n\n";
		} while ((choice != 'p') && (choice != 'n') && (choice != 'e'));


		switch (choice)
		{
		case 'p':
			Booth.payingCar();
			cout << "One paying car is passed " << endl;
			break;
		case 'n':
			Booth.nopayCar();
			cout << "One non-paying car is passed " << endl;
			break;
		case 'e':
			cout << "Result : " << endl;
			Booth.display();
			break;
		default:
			break;
		}
	} while (choice 
		== 'p' || choice == 'n');

	system("pause");
	return 0;
}