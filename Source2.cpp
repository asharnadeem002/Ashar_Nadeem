#include <iostream>
#include <conio.h>
#include <cstdlib>
#include<fstream>
#include <ctime>
#include<thread>
#include <windows.h>
#include"Header.h"
using namespace std;
#define size 16
#define size1 32
#define noOfmines 32
enum { mines = -1, on = -2, off_1 = -3, off_2 = -4, flag = -5, unflag = -6 };
void timer(int& sec, int& stop) {
	sec = 0;
	while (stop == 0) {                                 /////// function for time
		Sleep(1000);
		sec++;
		gotoxy(50, 37);
		cout << "Timer: " << sec << "\n\n";
	}
}
void lettersnNumbers(char chr, int x1, int x2, int y1, int y2, int siz0, int R = 0, int G = 0, int B = 0) {
	x1 += 5;
	x2 -= 5;
	y1 += 5;
	y2 -= 5;
	int mid_x = (x1 + x2) / 2;
	int mid_y = (y1 + y2) / 2;

	if (chr == 'A') {
		myLine(mid_x, y1, x1, y2, R, G, B);
		myLine(mid_x, y1, x2, y2, R, G, B);
		myLine(x1 + 2, mid_y + siz0 / 2, x2 - 3, mid_y + siz0 / 2, R, G, B);
	}
	else if (chr == 'B') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + siz0 / 4, y1 + siz0 / 8, R, G, B);
		myLine(mid_x + siz0 / 4, y1 + siz0 / 8, mid_x, mid_y, R, G, B);
		myLine(x1, mid_y, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, x2, mid_y + siz0 / 4, R, G, B);
		myLine(x2, mid_y + siz0 / 4, mid_x + siz0 / 8, y2, R, G, B);
		myLine(mid_x + siz0 / 8, y2, x1, y2, R, G, B);
	}
	else if (chr == 'C') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, y1 + siz0 / 4, R, G, B);
		myLine(x2, y2, x2, y2 - siz0 / 4, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'D') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + siz0 / 4, y1 + siz0 / 4, R, G, B);
		myLine(mid_x + siz0 / 4, y1 + siz0 / 4, mid_x + siz0 / 4, y2 - siz0 / 4, R, G, B);
		myLine(mid_x + siz0 / 4, y2 - siz0 / 4, x1, y2, R, G, B);
	}
	else if (chr == 'E') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'F') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'G') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, y1 + siz0 / 4, R, G, B);
		myLine(x2, y2, x2, y2 - siz0 / 2, R, G, B);
		myLine(x2, y2 - siz0 / 2, mid_x, y2 - siz0 / 2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'H') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'I') {
		myLine(mid_x, y1, mid_x, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'J') {
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
		myLine(x1, y2, x1, y2 - siz0 / 2, R, G, B);
	}
	else if (chr == 'K') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, mid_y, x2, y1, R, G, B);
		myLine(x1, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'L') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'M') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, x2, y1, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'N') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'O') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'P') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + siz0 / 4, y1 + siz0 / 8, R, G, B);
		myLine(mid_x + siz0 / 4, y1 + siz0 / 8, mid_x, mid_y, R, G, B);
		myLine(x1, mid_y, mid_x, mid_y, R, G, B);

	}
	else if (chr == 'Q') {
		myLine(x1, y1, x1, y2 - 5, R, G, B);
		myLine(x1, y1, mid_x + 3, y1, R, G, B);
		myLine(mid_x + 3, y1, mid_x + 3, y2 - 5, R, G, B);
		myLine(x1, y2 - 5, mid_x + 3, y2 - 5, R, G, B);
		myLine(mid_x - 2, mid_y, mid_x + 3, y2 - 5, R, G, B);
		myLine(mid_x + 3, y2 - 5, x2, y2, R, G, B);
	}
	else if (chr == 'R') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + siz0 / 4, y1 + siz0 / 8, R, G, B);
		myLine(mid_x + siz0 / 4, y1 + siz0 / 8, mid_x, mid_y, R, G, B);
		myLine(x1, mid_y, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'S') {
		myLine(mid_x, y1, x2, y1 + siz0 / 2, R, G, B);
		myLine(mid_x, y1, x1, y1 + siz0 / 2, R, G, B);
		myLine(x1, y1 + siz0 / 2, x2, y2 - siz0 / 2, R, G, B);
		myLine(x2, y2 - siz0 / 2, mid_x, y2, R, G, B);
		myLine(mid_x, y2, x1, y2 - siz0 / 2, R, G, B);
	}
	else if (chr == 'T') {
		myLine(mid_x, y1, mid_x, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
	}
	else if (chr == 'U') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);

	}
	else if (chr == 'V') {
		myLine(x1, y1, mid_x, y2, R, G, B);
		myLine(mid_x, y2, x2, y1, R, G, B);
	}
	else if (chr == 'W') {
		myLine(x1, y1, mid_x - siz0 / 8, y2, R, G, B);
		myLine(mid_x - siz0 / 8, y2, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, mid_x + siz0 / 8, y2, R, G, B);
		myLine(mid_x + siz0 / 8, y2, x2, y1, R, G, B);
	}
	else if (chr == 'X') {
		myLine(x1, y1, x2, y2, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);

	}
	else if (chr == 'Y') {
		myLine(x1, y1, mid_x, mid_y, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);
	}
	else if (chr == 'Z') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '.') {
		myRect(x2, y2 - siz0 / 8, mid_x + siz0 / 4, y2, R, G, B);
	}
	else if (chr == ',') {
		myRect(x2, y2 - siz0 / 3, mid_x + siz0 / 4, y2 - siz0 / 6, R, G, B);
		myLine(x2, y2 - siz0 / 3, x2, y2, R, G, B);
		myLine(x2, y2, mid_x + siz0 / 4, y2, R, G, B);
	}
	else if (chr == '!') {
		myRect(mid_x - siz0 / 8, y1, mid_x - 1, y2 - siz0 / 3, R, G, B);
		myRect(mid_x - siz0 / 8, y2 - siz0 / 8, mid_x, y2, R, G, B);
	}
	else if (chr == ':') {
		myRect(x2, y2 - 20, mid_x + siz0 / 4, y2 - 16, R, G, B);
		myRect(x2, y2 - 4, mid_x + siz0 / 4, y2, R, G, B);
	}
	else if (chr == '0') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);
	}
	else if (chr == '1') {
		myLine(x1, mid_y - siz0 / 2, mid_x, y1, R, G, B);
		myLine(mid_x, y1, mid_x, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '2') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '3') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x1, mid_y, R, G, B);
		myLine(x2, mid_y, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '4') {
		myLine(x1, y1, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(mid_x + siz0 / 6, y1, mid_x + siz0 / 6, y2, R, G, B);
	}
	else if (chr == '5') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '6') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '7') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == '8') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '9') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '-')
		myRect(x1 - 5, y1 - 5, x2 + 5, y2 + 5, 0, 0, 0);
}
//This Function Converts a Cstring to uppercase
void Capitalizer(char text[]) {
	for (int i = 0; i < strlen(text); i++)
		if (text[i] >= 'a' && text[i] <= 'z')
			text[i] -= 32;
}
//This Function to print Text on Screen
void drawText(int siz0, int start_x, int start_y, int R, int G, int B, char text[], bool isNum = false, int num = 0) {
	int idx = 0;
	int idx_x = 0;
	int idx_y = 0;
	int x1, x2, y1, y2;
	int digit_count = 0;
	int len = strlen(text);
	char temp[100];

	strcpy_s(temp, text);
	//If this function takes a number to print then he converts the number into atring using following loop
	if (isNum == true) {
		int reverse_num = 0;
		int i;

		for (; num > 0; num /= 10, digit_count++)
			reverse_num = (reverse_num * 10) + num % 10;

		for (i = len; i - len < digit_count; i++, reverse_num /= 10)
			temp[i] = (reverse_num % 10) + 48;

		temp[i] = '\0';
	}
	//Now the cstring is converted into upper case letters
	Capitalizer(temp);
	//This loop prints each individual letter on the screen
	for (idx = 0; idx < strlen(temp); idx++)
	{
		x1 = start_x + siz0 * idx_x;
		x2 = start_x + siz0 * (idx_x + 1);

		if (x2 > 1585 - siz0) {
			idx_y++;
			idx_x = 0;
			x1 = start_x + siz0 * idx_x;
			x2 = start_x + siz0 * (idx_x + 1);

		}

		y1 = start_y + 2 * siz0 * idx_y;
		y2 = start_y + 2 * siz0 * (idx_y + 1);
		lettersnNumbers(temp[idx], x1, x2, y1, y2, siz0, R, G, B);
		idx_x++;
	}

}
class mine {
protected:
	int** Game;                                   // data members
	int game[size][size1];
public:
	mine() :game() {
		//Game = new int*[size];                     /////////// constructer called with game array
		//for (int i = 0; i < size1; i++)
		//{                                             /// dynamic
		//	Game[i] = new int[size1];
		//}                                                  
		displaymines();                              ////it displays the grid
		displaynumbers();
	}
	virtual void displaymines() {
		srand(time(NULL));                           /// creayes mines
		for (int i = 0; i < noOfmines; i++)
			game[rand() % (size - 1) + 1][rand() % (size1 - 1) + 1] = mines;
	}
	virtual void displaynumbers() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size1; ++j) {                       ////  count numbers
				if (game[i][j] == mines) {
					for (int k = i - 1; k <= i + 1; ++k) {
						for (int l = j - 1; l <= j + 1; ++l) {
							if (k<0 || l<0 || k>size || l>size1 || k == size || l == size1 || game[k][l] == mines)
								continue;
							game[k][l]++;
						}
					}
				}
			}
		}
	}
	void revealwhen0(int x, int y, int rea[size][size1], int disp[size][size1]) {
		if (rea[x][y] != -1 && disp[x][y] != on && x >= 0 && y >= 0 && x <= size && y <= size1) {
			disp[x][y] = on;
			if (rea[x][y] == 0) {
				revealwhen0(x, y + 1, rea, disp);
				revealwhen0(x, y - 1, rea, disp);
				revealwhen0(x - 1, y + 1, rea, disp);                   /// it reveals the boxes when there is zero
				revealwhen0(x - 1, y - 1, rea, disp);
				revealwhen0(x - 1, y, rea, disp);
				revealwhen0(x + 1, y + 1, rea, disp);
				revealwhen0(x + 1, y - 1, rea, disp);
				revealwhen0(x + 1, y, rea, disp);
			}
		}
	}
	~mine()
	{
		/*for (int i = 0; i < size1; i++)
		{
			delete[]Game[i];
													 /// destructer called
		}
		delete[]Game;*/

	}
};
class game_ :public mine {
public:
	int** Gameboard;
	int gameboard[size][size1];
	game_() {
		//Gameboard = new int* [size];
		//for (int i = 0; i < size1; i++)
		//{                                       //constructer
		//	Gameboard[i] = new int[size1];
		//}
		gameboard[0][0] = 0;                     /// initializing with zero
	}
	int movement(int a, int b) {
		if (a < 0 || b < 0 || a == size || b == size1 || a>size || b>size1 || gameboard[a][b] == on || gameboard[a][b] == flag) {
			return -10;
		}
		if (game[a][b] == mines) {                 /// to control the movement of x and y
			displaymines_screen();
			gameboard[a][b] = off_2;
			return -11;
		}
		else if (game[a][b] == 0) {
			revealwhen0(a, b, game, gameboard);
		}
		else
			gameboard[a][b] = on;
		bool istrue = true;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size1; j++) {              /// reveal the boxes
				if (game[i][j] == mines)
					continue;
				if (gameboard[i][j] != on)
					istrue = false;
			}
		}
		if (istrue) {
			return 1;
		}
		return 0;
	}
	void displaygame() {
		cout << "    ";
		for (int i = 0; i < 10; i++) {
			cout << i << "   ";
		}
		for (int i = 10; i < size1; i++) {                     //   it displays the game and controls it
			cout << i << "  ";
		}
		cout << endl << endl;
		for (int i = 0; i < size; i++) {
			if (i < 10)
			{
				cout << i << "   ";
			}
			else
				cout << i << "  ";
			int j = 0;
			for (; j < size1; j++) {
				switch (gameboard[i][j]) {
				case unflag: {
					cout << "-";                    // conditions that what to display
					break;
				}
				case on: {
					cout << game[i][j];
					break;
				}
				case off_1: {
					cout << "M";
					break;
				}
				case off_2: {
					cout << "*";
					break;
				}
				case flag: {
					cout << "F";
					break;
				}
				default:
					cout << "-";
					break;
				}
				cout << "   ";
			}
			cout << endl << endl;
		}
	}
	void displaymines_screen() {
		for (int i = 0; i < size; i++) {                         /// displayy mines when game is over
			int j = 0;
			for (; j < size1; j++) {
				if (game[i][j] == mines)
					gameboard[i][j] = off_1;
				else
					gameboard[i][j] = on;
			}
		}
	}
	~game_()
	{
		//for (int i = 0; i < size1; i++)
		//{                                  //destructer
		//	delete[]Gameboard[i];

		//}
		//delete[]Gameboard;
	}
};
int main() {
	myLine(90, 90, 85, 150, 255, 0, 0);
	myLine(90, 90, 95, 120, 255, 0, 0);
	myLine(95, 120, 100, 90, 255, 0, 0);
	myLine(100, 90, 105, 150, 255, 0, 0);
	myLine(120, 90, 150, 90, 255, 0, 0);
	myLine(120, 150, 150, 150, 255, 0, 0);
	myLine(135, 90, 135, 150, 255, 0, 0);
	myLine(165, 90, 165, 150, 255, 0, 0);
	myLine(165, 90, 185, 150, 255, 0, 0);
	myLine(185, 150, 185, 90, 255, 0, 0);
	myLine(200, 90, 200, 150, 255, 0, 0);
	myLine(200, 90, 230, 90, 255, 0, 0);
	myLine(200, 120, 230, 120, 255, 0, 0);
	myLine(200, 150, 230, 150, 255, 0, 0);
	myLine(270, 90, 300, 90, 255, 0, 0);
	myLine(270, 120, 300, 120, 255, 0, 0);
	myLine(270, 150, 300, 150, 255, 0, 0);
	myLine(270, 90, 270, 120, 255, 0, 0);
	myLine(300, 120, 300, 150, 255, 0, 0);
	myLine(315, 90, 330, 150, 255, 0, 0);                // minesweeper
	myLine(330, 150, 340, 120, 255, 0, 0);
	myLine(340, 120, 350, 150, 255, 0, 0);
	myLine(350, 150, 360, 90, 255, 0, 0);
	myLine(375, 90, 375, 150, 255, 0, 0);
	myLine(375, 90, 405, 90, 255, 0, 0);
	myLine(375, 120, 405, 120, 255, 0, 0);
	myLine(375, 150, 405, 150, 255, 0, 0);
	myLine(420, 90, 420, 150, 255, 0, 0);
	myLine(420, 90, 450, 90, 255, 0, 0);
	myLine(420, 120, 450, 120, 255, 0, 0);
	myLine(420, 150, 450, 150, 255, 0, 0);
	myLine(465, 90, 465, 150, 255, 0, 0);
	myLine(465, 90, 495, 90, 255, 0, 0);
	myLine(495, 90, 495, 120, 255, 0, 0);
	myLine(465, 120, 495, 120, 255, 0, 0);
	myLine(510, 90, 510, 150, 255, 0, 0);
	myLine(510, 90, 540, 90, 255, 0, 0);
	myLine(510, 120, 540, 120, 255, 0, 0);
	myLine(510, 150, 540, 150, 255, 0, 0);
	myLine(555, 90, 555, 150, 255, 0, 0);
	myLine(555, 90, 585, 90, 255, 0, 0);
	myLine(585, 90, 585, 120, 255, 0, 0);
	myLine(555, 120, 585, 120, 255, 0, 0);
	myLine(555, 120, 585, 150, 255, 0, 0);
	myLine(625, 90, 625, 140, 255, 0, 0);
	myLine(625, 148, 625, 154, 255, 0, 0);
	Sleep(2000);
	Sleep(100);

	//system("cls");
	game_ obj, obj1;
	int x = 0, y = 0, result, f, countFlag = 0, countT = 0;
	int sec = 0, stop = 0;
	thread time(&timer, ref(sec), ref(stop));
	while (true) {
		obj.displaygame();
		cout << "\nFlags Used: " << countFlag << endl;
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
		cout << "If flag press 1\nIf remove flag press 0\nelse press 2 :\n";
		cin >> f;
		if (f == 1) {
			obj1.gameboard[x][y] = obj.gameboard[x][y];
			obj.gameboard[x][y] = flag;
			countFlag++;
		}
		if (f == 0) {
			if (obj.gameboard[x][y] != -5) {
				cout << endl << "No flag there! ";
				system("cls");
				continue;
			}
			obj.gameboard[x][y] = unflag;
			countFlag--;
		}
		if (f < 0 || f > 2) {
			cout << "Invalid Flag! ";
			Sleep(300);
			system("cls");
			continue;
		}
		Sleep(300);
		result = obj.movement(x, y);
		if (result == -11) {
			cout << "Lost !!" << endl;
			Sleep(1400);
			break;
		}
		if (result == 1) {
			cout << "Winner winner Chicken Dinner !!" << endl;
			Sleep(1400);
			break;
		}
		if (result == -10) {
			cout << "Invalid Move" << endl;
			Sleep(1200);
		}
		Sleep(1000);
		countT++;
		system("cls");
		cout << endl;
	}
	system("cls");
	stop = 1;

	obj.displaygame();
	cout << "Flags Used: " << countFlag << endl << "Time: " << sec << endl;
	Sleep(2000);
	system("cls");
	//cout << "Gameover\nYou Lose!!" << endl;
	int mko = 0;
	system("cls");
	char temp[100] = "game over better luck next time";
	while (mko < 1000)
	{
		mko++;
		drawText(50, 100, 100, 255, 255, 204, temp, false, 0);
	}
	Sleep(2000);
	system("cls");
	string name;
	cout << "Enter the name: ";
	cin >> name;

	ofstream out("BestPlayer.txt", ios::app);
	out << "Name: " << name << " Time: " << sec << endl;
	system("pause");
	//return 0;
}