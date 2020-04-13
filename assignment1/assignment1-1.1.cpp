#include <iostream>//set head
using namespace std;//set namespace
int main(void) {//func for main
	int num = 0;
	for (;;) {//loop 
		cout << "Enter the size of asterisk:";
		cin >> num;//input number
		if (num < 5 || num >29 || num % 2 == 0) cout << "Please input odd number ranging from 5 to 29" << endl;//exception point
		else break;
	}
	int j = num;
	for (; j > 0; j = j - 2) {//loop for blank
		for (int k = j / 2; k < num / 2; k++)
			cout << " ";
		if (j == 1)cout << " ";
		for (int i = j; i > 0; i--) {//loop for print $
			if (i == 1) cout << "$ ";
			else if (2 * i - 1 == j) cout << "$ ";
			else if (i == j) cout << "$ ";
			else cout << " ";
		}
		cout << endl;
	}
	for (j = j + 4; j <= num; j = j + 2) {
		for (int k = j / 2; k < num / 2; k++)
			cout << " ";
		for (int i = j; i > 0; i--) {//loop for print lower shape
			if (i == 1) cout << "$ ";
			else if (2 * i - 1 == j) cout << "$ ";
			else if (i == j) cout << "$ ";
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}
