#include <iostream>
using namespace std;

class time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	time(int hours, int minutes, int seconds) {
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	void display() {
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}
	void addition(time x, time y) {
		this->seconds = x.seconds + y.seconds;
		this->minutes = x.minutes + y.minutes;
		this->hours = x.hours + y.hours;
		if (this->seconds > 59) {
			this->seconds -= 60;
			this->minutes++;
		}
		if (this->minutes > 59) {
			this->minutes -= 60;
			this->hours++;
		}
		if (this->hours > 23)
			this->hours -= 24;
	}
};

int main() {
	const time x(5, 10, 40), y(6, 40, 50);
	time result;
	result.addition(x, y);
	result.display();
	system("pause");
	return 0;
}