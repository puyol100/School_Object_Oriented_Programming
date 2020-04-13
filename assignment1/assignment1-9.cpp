# include <iostream>
# include <ctime>//header for clock time
using namespace std;//set namespace
int main(void) {//func for main
	
	int matrix[9][3] = { 0, };//setting matrix
	int row = 9;
	int column = 3;//sett row, column
	srand((unsigned int)time(0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrix[i][j] = rand() % (64 + 1);
		}
	}//set the matrix entries randommly
	cout << "<Original>" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%5d", matrix[i][j]);
		}
		cout << endl<<endl;//print orgin matrix
	}
	cout << endl << endl << "<Transposed>" << endl;
	for (int i = 0; i < column; i++) {//print transposed matrix
		for (int j = 0; j < row; j++) {
			printf("%5d", matrix[i][j]);
		}
		cout << endl<<endl;
	}
	return 0;
}