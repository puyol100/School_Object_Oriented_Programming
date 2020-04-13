# include <iostream>
#include <math.h>//set header
using namespace std;//set namespace

int main(void) {//func for main
	int num = 0, dis1 = 0, dis2 = 0;
	int **arr = new int *[6];//memort allocation
	int length1 = 0, length2 = 0;
	cin >> num;
	for (int i = 0; i < 6; ++i) {
		arr[i] = new int[num];
	}
	for (int column = 0; column < num; column++) {
		for (int i = 0; i < 6; i++) {
			cin >> arr[i][column];
		}//arr[0] = x1, arr[1] = y1, arr[2]=d1, arr[3]= x2, arr[4] = y2, arr[5] d2
	}

	for (int i = 0; i < num; i++) {
		if (arr[0][i] == arr[3][i] && arr[1][i] == arr[4][i] && arr[2][i] == arr[5][i]) {
			cout << -1 << endl;
		}
		else {
			length1 = arr[0][i] - arr[3][i];
			length2 = arr[1][i] - arr[4][i];
			dis1 = (length1 * length1) + (length2 * length2);// distance between circles
			dis2 = (arr[2][i] + arr[5][i]) * (arr[2][i] + arr[5][i]);//sum of setting distance
			if (dis1 > dis2) {//case for none spot
				cout << 0 << endl;
			}
			else if (dis1 < dis2) {//case for two spot
				cout << 2 << endl;
			}
			else {//case for one spot
				cout << 1 << endl;
			}
		}
	}


	for (int i = 0; i < 6; ++i) {
		delete[] arr[i];//free the dynamic allocation
	}
	delete[] arr;//free the dynamic allocation
	return 0;
}