#include <iostream>//Header
using namespace std;//set namespace
int main(void) {//func main
	int total = 20000;//total allowance
	int fare = 720;//fare 
	int dis = 0;
	cout << "Initial balance: 20000" << endl<<endl;
	for (;;) {
		cout << "Entering each travel distance:";
		cin >> dis;//input distance
		cout << "-------------------------------------------------------------" << endl;
		if (dis == -1) break;//exit
		if (dis >= 4 && dis <= 40) {//Basic charge
			cout << "Fare: " << fare << endl<<endl;
			total = total - fare;
		}
		else if (dis > 40 && dis <= 178) {//Basic charge + extra charge
			dis = (dis - 40) / 8;//check over distance 
			cout << "Fare: " << (dis * 80) + fare << endl<<endl;//get fare
			total = total - (dis * 80) - fare;
		}
		else {
			cout << "Current balance: " << total << endl<<endl;//exception
			break;
		}
		cout << "Current balance: " << total << endl<<endl;
		if (total < 0) break;//if total allowance 0
	}
	cout << "Program exit" << endl;
	return 0;
}
