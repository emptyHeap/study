#include <iostream>
#include <vector>
#include <cmath>

int const verboseEach = 1000000;
using namespace std;

class Number {
	public:
		int value;
		int friendly;
		Number() { }
		Number(int value):
			value(value)
		{
			vector<int> delimeters;
			int to = sqrt(value);
			for (int i = 2; i <= to; i++) {
				if (value % i == 0) {
					delimeters.push_back(i);
					if (i != value/i) {
						delimeters.push_back(value/i);
					}
				}
			}
			//for (int i = 1; i < value / 2 + 1; i++){
			//	if (value % i == 0) delimeters.push_back(i);
			//}
			friendly = 0;
			for (int delimeter : delimeters) {
			//	cout << delimeter << ", ";
			       	friendly += delimeter;
			}
			friendly += 1;
			//cout << "\n";
		}
};

int main (void) {
	int from;
	int to;
	cin >> from >> to;
	//Number numbers [to - from];
	vector<Number> numbers;
	for (int i = from; i <= to; i++) {
		numbers.push_back(Number(i));
		if (i%verboseEach == 0) {
			cout << "\n - " << i << " - completed\n";
		}
	}

	vector<Number> result;
	for (Number number : numbers) {
		if (number.friendly >= number.value && number.friendly <= to) {
			Number friendly = numbers.at(number.friendly - from);
			if (friendly.friendly == number.value) {
				result.push_back(number);
			}
		}
	}

	if (result.size() == 0) {
		cout << "no friendly numbers founded\n";
	} else {
		for (Number number : result){
			cout << number.value << " - " << number.friendly << "\n";
		}
	}
	return 0;
}
