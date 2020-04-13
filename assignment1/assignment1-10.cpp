# include <iostream>
# include <string>//set headerr
using namespace std;
void Magic_square(int num) {//fun for Magic_square
	int **magic = new int*[num + 1];//allocate two array dynamic allocation
	int init = 2;//setting  inti num
	int i = 1;
	int j = num / 2;
	for (int i = 0; i < num + 1; i++) {
		magic[i] = new int[num + 1];
		memset(magic[i], 0, sizeof(int)*(num + 1));
	}//magic[num+1][num+1]
	magic[0][num] = -1;//exception edge
	magic[1][num / 2] = 1;//first row middle point ->1
	for (; magic[num][num / 2] != (num*num);) {//i=1, j=num/2
		if (magic[i - 1][j + 1] == 0) {
			magic[i - 1][j + 1] = init;
			if (i - 1 - num <= num && i - 1 - num >= 0) {
				if (magic[i - 1 - num][j + 1] == 0) {
					magic[i - 1 - num][j + 1] = init;
					i = i - 1 - num;
					j = j + 1;
				}
			}
			else if (j + 1 - num <= num && j + 1 - num >= 0) {
				if (magic[i - 1][j + 1 - num] == 0) {
					magic[i - 1][j + 1 - num] = init;
					i = i - 1;
					j = j + 1 - num;
				}
			}
			else if (j + 1 + num <= num && j + 1 + num >= 0) {
				if (magic[i - 1][j + 1 + num] == 0) {
					magic[i - 1][j + 1 + num] = init;
					i = i - 1;
					j = j + 1 + num;
				}
			}
			else if (i - 1 + num <= num && i - 1 + num >= 0) {
				if (magic[i - 1 + num][j + 1] == 0) {
					magic[i - 1 + num][j + 1] = init;
					i = i - 1 + num;
					j = j + 1;
				}
			}
			else {
				i = i - 1;
				j = j + 1;
			}
			init = init + 1;
		}
		else {
			magic[i + 1][j] = init;
			init = init + 1;
			i = i + 1;
		}
	}
	for (int a = 1; a <= num; a++) {//print magic_num
		for (int b = 0; b < num; b++) {
			cout.width(4);
			cout << magic[a][b] << "  ";
		}
		cout << endl << endl;
	}
	return;
}
int main(void) {//func for main
	int num = 0;
	for (;;) {
		cout << "Enter the size of Magic Square: ";//Enter size
		cin >> num;
		if (num < 3 || num >15 || num % 2 == 0) { cout << "Input num Error" << endl; }//print error
		else {
			cout << endl;
			break;
		}
	}
	Magic_square(num);//print Magic_square
	return 0;
}