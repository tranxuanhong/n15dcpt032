#include <iostream>
#include <stdlib.h>
using namespace std;

class fraction {
private:
	double numerator;
	double denominator;
	char slash;
	int order;
	static int count;
public:
	fraction() {
		count++;
		order = count;
	}
	void lowterms();
	void addition(fraction X, fraction Y);
	void subtraction(fraction X, fraction Y);
	void multiplication(fraction X, fraction Y);
	void division(fraction X, fraction Y);
	void input() {
		cout << "Enter fraction format a/b (EX: 3/5) " << endl;
		cout << "Fraction " << order << " : ";
		cin >> numerator >> slash >> denominator; // a/b format
	}
	void display() {
		cout << "Result is : " << numerator << "/" << denominator << endl;
	}
};
int fraction::count = 0;

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

void fraction::addition(fraction X, fraction Y) {
	if (X.denominator == Y.denominator) {
		this->numerator = X.numerator + Y.numerator;
		this->denominator = X.numerator;
	}
	else {
		this->numerator = X.numerator*Y.denominator + X.denominator*Y.numerator;
		this->denominator = X.denominator*Y.denominator;
	}
	cout << X.numerator << "/" << X.denominator << " + " << Y.numerator << "/" << Y.denominator << endl;
}

void fraction::subtraction(fraction X, fraction Y) {
	if (X.denominator == Y.denominator) {
		this->numerator = X.numerator - Y.numerator;
		this->denominator = X.numerator;
	}
	else {
		this->numerator = X.numerator*Y.denominator - X.denominator*Y.numerator;
		this->denominator = X.denominator*Y.denominator;
	}
	cout << X.numerator << "/" << X.denominator << " - " << Y.numerator << "/" << Y.denominator << endl;
}

void fraction::multiplication(fraction X, fraction Y) {
	this->numerator = X.numerator*Y.numerator;
	this->denominator = X.denominator*Y.denominator;
	cout << X.numerator << "/" << X.denominator << " X " << Y.numerator << "/" << Y.denominator << endl;
}

void fraction::division(fraction X, fraction Y) {
	this->numerator = X.numerator*Y.denominator;
	this->denominator = X.denominator*Y.numerator;
	cout << X.numerator << "/" << X.denominator << " : " << Y.numerator << "/" << Y.denominator << endl;
}

int main() {
	fraction X, Y, Result;
	X.input();
	Y.input();
	Result.addition(X,Y);
	Result.lowterms();
	Result.display();

	Result.subtraction(X, Y);
	Result.lowterms();
	Result.display();

	Result.multiplication(X, Y);
	Result.lowterms();
	Result.display();

	Result.division(X, Y);
	Result.lowterms();
	Result.display();
	system("pause");
	return 0;
}
