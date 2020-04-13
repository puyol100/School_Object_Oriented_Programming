#include <iostream>//set header
using namespace std;//set namespace
int main(void) {//func for main
	int num = 0;
	for (;;) {
		cout << "Enter the size of diamond:";
		cin >> num;//input diamond size
		if (num < 5 || num >29 || num % 2 == 0) cout << "Please input odd number ranging from 5 to 29" << endl;//exception
		else break;
	}
	int i = num / 2;
	for (; i > 0; i--) {//print upper shape
		for (int j = 2*i; j > 0; j--) {//loop for blank
			cout << " ";
		}
		for (int k = 2 * i; k < num; k++) {
			cout << "$ ";
		}
		cout << endl;
	}
	i = num;
	for (i = num; i > 0; i--)
		cout << "$ ";//print middle shape
	cout << endl;
	i = num / 2;
	for (; i > 0; i--) {//prnit lower shape
		for (int j = 2*i; j <= num; j++) {//loop for blank
			cout << " ";
		}
		for (int k = 2 * i - 1; k > 0; k--) {//loop for lower shape
			cout << "$ ";
		}
		cout << endl;
	}
	return 0;
}
