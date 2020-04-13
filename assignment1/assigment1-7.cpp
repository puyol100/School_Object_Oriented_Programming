# include <iostream>
# include <string>
# include <map>//head for map func
using namespace std;//set namespace
string timelnWords(int h, int m) {//func for chage time to word
	map<int, string> time;
	if (h <= 0 || h > 12 || m < 0 || m >= 60) {
		return "Error";//exception
	}
	time.insert(make_pair(0, " o' clock"));
	time.insert(make_pair(1, "one"));
	time.insert(make_pair(2, "two"));
	time.insert(make_pair(3, "three"));
	time.insert(make_pair(4, "four"));
	time.insert(make_pair(5, "five"));
	time.insert(make_pair(6, "six"));
	time.insert(make_pair(7, "seven"));
	time.insert(make_pair(8, "eight"));
	time.insert(make_pair(9, "nine"));
	time.insert(make_pair(10, "ten"));
	time.insert(make_pair(11, "eleven"));
	time.insert(make_pair(12, "twelve"));
	time.insert(make_pair(13, "thirteen"));
	time.insert(make_pair(14, "fourteen"));
	time.insert(make_pair(15, "quarter"));
	time.insert(make_pair(16, "sixteen"));
	time.insert(make_pair(17, "seventeen"));
	time.insert(make_pair(18, "eighteen"));
	time.insert(make_pair(19, "nineteen"));
	time.insert(make_pair(20, "twenty"));
	time.insert(make_pair(21, "twenty one"));
	time.insert(make_pair(22, "twenty two"));
	time.insert(make_pair(23, "twenty three"));
	time.insert(make_pair(24, "twenty four"));
	time.insert(make_pair(25, "twenty five"));
	time.insert(make_pair(26, "twenty six"));
	time.insert(make_pair(27, "twenty seven"));
	time.insert(make_pair(28, "twenty eight"));
	time.insert(make_pair(29, "twenty nine"));
	time.insert(make_pair(30, "half"));
	//mapping clock to word
	if (m > 30) {//case for over 30 minutes
		m = 60 - m;
		h = h + 1;
		if (m == 1) {
			return time.find(m)->second + " minute" + " to " + time.find(h)->second;
		}
		else if (m == 15) {
			return time.find(m)->second + " to " + time.find(h)->second;
		}
		else {
			return time.find(m)->second + " minutes" + " to " + time.find(h)->second;
		}
	}
	else if (m < 30) {//case for under 30 minutes
		if (m == 0) {
			return time.find(h)->second + time.find(m)->second;
		}
		else if (m == 1) {
			return time.find(m)->second + " minute" + " past " + time.find(h)->second;
		}
		else if (m == 15) {
			return time.find(m)->second + " past " + time.find(h)->second;
		}
		else {
			return time.find(m)->second + " minutes" + " past " + time.find(h)->second;
		}
	}
	else {
		return time.find(m)->second + " past " + time.find(h)->second;
	}
}
int main(void) {//func for main
	int h = 0, m = 0;
	
		cin >> h;
		cout << endl;
		cin >> m;//input hour and minute
		cout << endl;
		cout << timelnWords(h, m) << endl;
	
	return 0;
}