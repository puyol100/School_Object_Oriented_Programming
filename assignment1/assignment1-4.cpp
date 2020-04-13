# include <iostream>
# include <string>//set header
using namespace std;//set namespace
int main(void) {//function for main
	double a, b, c = 0;//value for coefficient
	double max, min;
	double corner_x = 0;
	int for_int = 0;
	cout << "Input a:";
	cin >> a;//input first coefficient
	cout << "Input b:";
	cin >> b;//input second coefficient
	cout << "Input c:";
	cin >> c;//input third coefficient
	corner_x = -b / (2 * a);//value for corner
	for_int = int(corner_x);
	if (a < 0) {//Convex up
		if (corner_x < -30) {//if corner <-30
			max = a * (-30)*(-30) + b * (-30) + c;
			min = a * (30) *(30) + b * (30) + c;
		}
		else if (corner_x > -30 && corner_x < 30) {//case for -30<corner<30
			max = a * (for_int) * (for_int)+b * (for_int)+c;
			if (corner_x >= 0) { min = a * (-30) * (-30) + b * (-30) + c; }
			else if (corner_x < 0) { min = a * 30 * 30 + b * 30 + c; }
		}
		else if (corner_x > 30) {//case for corner>30
			min = a * (-30)*(-30) + b * (-30) + c;
			max = a * (30) *(30) + b * (30) + c;
		}
		else {//else case
			if (corner_x == 30) {
				max = a * (30) * (30) + b * (30) + c;
				min = a * (-30) * (-30) + b * (-30) + c;
			}
			else if (corner_x == -30) {
				min = a * (30) * (30) + b * (30) + c;
				max = a * (-30) * (-30) + b * (-30) + c;
			}
		}
	}
	else if (a > 0) {//Convex down
		if (corner_x < -30) {//case for corner_x<-30
			min = a * (-30)*(-30) + b * (-30) + c;
			max = a * (30) *(30) + b * (30) + c;
		}
		else if (corner_x > -30 && corner_x < 30) {//case for -30<corner_x<30
			min = a * (for_int) * (for_int)+b * (for_int)+c;
			if (corner_x >= 0) { max = a * (-30) * (-30) + b * (-30) + c; }
			else if (corner_x < 0) { max = a * 30 * 30 + b * 30 + c; }
		}
		else if (corner_x > 30) {//case for corner_x>30
			max = a * (-30)*(-30) + b * (-30) + c;
			min = a * (30) *(30) + b * (30) + c;
		}
		else {//case for else
			if (corner_x == 30) {
				min = a * (30) * (30) + b * (30) + c;
				max = a * (-30) * (-30) + b * (-30) + c;
			}
			else if (corner_x == -30) {
				max = a * (30) * (30) + b * (30) + c;
				min = a * (-30) * (-30) + b * (-30) + c;
			}
		}
	}
	else {//a==0
		if (b > 0) {
			max = b * 30 + c;
			min = b * (-30) + c;
		}
		else if (b < 0) {
			min = b * 30 + c;
			max = b * (-30) + c;
		}
		else {
			max = c;
			min = c;
		}
	}
	cout << "max: " << max << endl;
	cout << "min " << min << endl;
	return 0;
}