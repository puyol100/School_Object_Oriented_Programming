#include <iostream>
#include <string>//set header
using namespace std;//set namespace
string WARNINGS[] = {//func fofr Warnig
"Must contain at least 6 more characters.",
"Must contain at least 1 digit.",
"Must contain at least 1 lowercase English character.",
"Must contain at least 1 uppercase English character.",
"Must contain at least 1 special character."
};
int main()//func for main
{
	string password;
	int digit = 0;
	int uppercase = 0;
	int lowercase = 0;
	int special = 0;
	cin >> password;//input password
	if (password.length() < 1 || password.length() > 20) {
		cout << "Password size 1~20" << endl;//exception for Password size
		return 0;
	}
	for (int i = 0; i < password.length(); i++) {//checking password
		if (password[i] >= 65 && password[i] <= 90) {
			uppercase = uppercase + 1;//check uppercase
		}
		else if (password[i] >= 97 && password[i] <= 122) {
			lowercase = lowercase + 1;//check lowercase
		}
		else if (password[i] >= 48 && password[i] <= 57) {
			digit = digit + 1;//check num of digit
		}
		else if (password[i] == 33 || (password[i] >= 35 && password[i] <= 38) || (password[i] >= 40 && password[i] <= 43) || password[i] == 45 || password[i] == '^' || password[i] == 64) {
			special = special + 1;//check special character
		}
	}
	if (password.length() < 6) {//case for warnig[0]
		cout << WARNINGS[0] << endl << endl;
	}
	if (digit == 0) {//case for warnig[1]
		cout << WARNINGS[1] << endl << endl;
	}
	if (lowercase == 0) {//case for warnig[2]
		cout << WARNINGS[2] << endl << endl;
	}
	if (uppercase == 0) {//case for warnig[3]
		cout << WARNINGS[3] << endl << endl;
	}
	if (special == 0) {//case for warnig[4]
		cout << WARNINGS[4] << endl << endl;
	}
	if (password.length() >= 6 && digit != 0 && special != 0 && uppercase != 0 && lowercase != 0) {
		cout << "Thank you for signing up!" << endl << endl;
	}
	return 0;
}