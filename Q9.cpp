#include <iostream>
#include <stdlib.h>
using namespace std;

class fraction {
private:
	double numerator;
	double denominator;
	char slash ;
	static char count;
	char order; // to count the order of the fraction
public:
	fraction() {
		numerator = 0;
		denominator = 0;
		order = count;
		count++;
	}
	void input() {
		cout << "Enter fraction format a/b, Example : 3/5 " << endl;
		cout<< "Fraction " << order << " : ";
		cin >> numerator >> slash >> denominator; // a/b format
	}
	void display() {
		cout << "Fraction "<< order << " : " << numerator << "/" << denominator << endl;
	}
	void lowterms() {
		long tnum, tden, temp, gcd;
		tnum = labs(numerator); // use non-negative copies
		tden = labs(denominator); // (needs cmath)
		if (tden == 0) // check for n/0
		{
			cout << "Illegal fraction : division by 0"; exit(1);
		}
		else if (tnum == 0) // check for 0/n
		{
			numerator = 0; denominator = 1; return;
		}
		while (tnum != 0)
		{
			if (tnum < tden) // ensure numerator larger
			{
				temp = tnum; tnum = tden; tden = temp;
			} // swap them
			tnum = tnum - tden; // subtract them
		}
		gcd = tden; // this is greatest common divisor
		numerator = numerator / gcd; // divide both num and den by gcd
		denominator = denominator / gcd; // to reduce frac to lowest terms
	}
	void addition(fraction A, fraction B) {
		if (A.denominator == B.denominator) {
			this->numerator = A.numerator + B.numerator;
			this->denominator = A.denominator;
		}
		else {
			this->numerator = A.numerator*B.denominator + B.numerator*A.denominator;
			this->denominator = A.denominator*B.denominator;
		}
	}
};

char fraction::count = 'A';

int main() {
	char choice;
	do {
		fraction A, B, Result;
		A.input();
		A.display();
		B.input();
		B.display();
		Result.addition(A, B);
		Result.lowterms();
		Result.display();
		cout << "Do you want to continue (Y/N) ? >> "; cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	system("pause");
	return 0;
}
