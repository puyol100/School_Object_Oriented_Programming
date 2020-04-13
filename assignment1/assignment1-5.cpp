# include <iostream>
# include <string>
# include <iomanip>//setting header
using namespace std;//set namespace

int main(void) {//func for main
	string str1;//string for input
	float size = 0;
	float arr[26] = { 0, };
	float cal = 0;
	cout << "Input: ";
	getline(cin, str1);//get input string
	cout << endl;
	cout << "Output" << endl;
	for (int i = 0; str1[i] != NULL; i++) {//loop for find character and counting
		for (int j = 0; j < 26; j++) {
			if (str1[i] == 65 + j || str1[i] == 97 + j) {
				arr[j] = arr[j] + 1; size = size+1;//check character and length
			}
		}
	}
	for (int i = 0; i < 26; i++) {//loop for print
		if (arr[i] != 0) {
			cal = arr[i] / size;
			cout << (char)(i + 65) << '(' << (char)(i + 97) << ")  ";
			cout <<fixed<< setprecision(6) << cal << endl;
			
		}
	}
	return 0;
}