# include <iostream>
# include <cstdlib>
# include <string>//set header
using namespace std;//set namespace
int main(void) {//func for main
	int arr[2][6] = {0,};//string array for matrix
	string str1;//input string
	int temp1;
	int temp2;
	string ID;//input ID
	int ID_int=0;
	string score;//input score
	int score_int = 0;
	for (;;) {//loop for program
		cout << "# Enter function :";
		cin >> str1;//input
		if (str1 == "Append") {
			cin >> ID >> score;//if input is Append then input ID, score
			ID_int = atoi(ID.c_str());
			score_int = atoi(score.c_str());//chang form srung to integer
			for (int i = 0; i < 6; i++) {//store ID, score
				for (int j = 0; j < 2; j++) {
					if (arr[j][i] == 0 && arr[j + 1][i] == 0) {//is there data?
						arr[j][i] = ID_int;
						arr[j + 1][i] = score_int;
						i = 6;
						break;
					}
				}
			}
			for (int i = 0; i < 2; i++) {//print matrix
				for (int j = 0; j < 6; j++) {
					if (arr[i][j] == 0) { cout << " "; }//if array data is empty then print blank
					else {
						cout << arr[i][j] << " ";//else print data
					}
				}
				cout << endl;
			}
		}
		else if (str1 == "Search") {//if str1 == Search
			cin >> ID;//input id
			ID_int = atoi(ID.c_str());//change ID form to integer
			for (int i = 0; i < 6; i++) {//find and print 
				for (int j = 0; j < 2; j++) {
					if (arr[j][i] == ID_int) {
						cout << arr[j][i] << endl << arr[j + 1][i];//print that data
						i = 6;
						break;
					}
				}
			}
			cout << endl;
		}
		else if (str1 == "Sort") {//input is sort
			cin >> str1;//then input ID
			if (str1 == "ID") {//if first input is Sort and second input is ID
				for (int j = 0; j < 5; j++) {
					for (int i = j; i < 5; i++) {
						if (arr[0][j] > arr[0][i + 1]) {
							if (arr[0][i + 1] ==0) {//if there is no data
								i = 5; break;
							}
							temp1 = arr[0][j];
							temp2 = arr[1][j];
							arr[0][j] = arr[0][i + 1];
							arr[1][j] = arr[1][i + 1];
							arr[0][i + 1] = temp1;
							arr[1][i + 1] = temp2;//sorting
						}//sort
					}
				}
				for (int i = 0; i < 2; i++) {//print matrix
					for (int j = 0; j < 6; j++) {
						if (arr[i][j] == 0) { cout << " "; }//if data empty
						else {
							cout << arr[i][j] << " ";
						}
					}
					cout << endl;
				}
			}
			else{ cout << "Wrong input" << endl; }//error message
		}
		else if (str1 == "Delete") {//if input is Delete
			cin >> ID;//input ID 
			ID_int = atoi(ID.c_str());//change string form to integer
			for (int i = 0; i < 6; i++) {//search id
				if (arr[0][i] == ID_int) {//Search Delete data 
					arr[0][i] =0;
					arr[1][i] =0;//deleting
					if (arr[0][i + 1] !=0) {//sorting after delete
						temp1 = arr[0][i];
						temp2 = arr[1][i];
						arr[0][i] = arr[0][i + 1];
						arr[1][i] = arr[1][i + 1];
						arr[0][i + 1] = temp1;
						arr[1][i + 1] = temp2;
						break;
					}
				}
			}
			for (int i = 0; i < 2; i++) {//print searched id
				for (int j = 0; j < 6; j++) {
					if (arr[i][j] == 0) { cout << " "; }
					else {
						cout << arr[i][j] << " ";
					}
				}
				cout << endl;
			}
		}
		else if (str1 == "End") { break; }
		else { cout << "Wrong input" << endl; }
	}
	return 0;
}