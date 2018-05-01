#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class fraction {
private:
	int numerator;
	int denominator;
	char slash;
public:
	fraction(int numerator, int denominator) {
		this->denominator = denominator;
		this->numerator = numerator;
	}
	void assignment(int numerator, int denominator) {
		this->denominator = denominator;
		this->numerator = numerator;
	}
	void lowterms();
	void multiplication(fraction X, fraction Y);
	void input() {
		cout << "Enter fraction format a/b (EX: 3/5) " << endl;
		cin >> numerator >> slash >> denominator; // a/b format
	}
	void display1() {
		cout << "    " << numerator << "/" << denominator << "    " ;
	}
	void display2() {
		cout << numerator << "/" << denominator ;
	}
};

void fraction::lowterms() {
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
	denominator = denominator/ gcd; // to reduce frac to lowest terms
}

void fraction::multiplication(fraction X, fraction Y) {
	this->numerator = X.numerator*Y.numerator;
	this->denominator = X.denominator*Y.denominator;
}

int main() {
	fraction X(0,0),Y(0,0),Z(0,0);
	int Deno;
	cout << "Enter the Denominator >> "; cin >> Deno;
	for (int i = 0; i < Deno - 1;) {
		X.assignment(++i, Deno);
		X.lowterms();
		X.display1();
	}
	cout << "\n-----------------------------------------------" << endl;
	for (int j = 0; j < Deno - 1;) {
		cout << endl;
		X.assignment(++j, Deno);
		X.lowterms();
		X.display2();
		for (int k = 0; k < Deno - 1;) {
			Y.assignment(++k, Deno);
			Z.assignment(j, Deno);
			X.multiplication(Y, Z);
			X.lowterms();
			X.display1();
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
