#include<iostream>
#include<windows.h>
using namespace std;

typedef struct {
	char num;
	bool use;
}number;

int win(number n[]) {
	int i, winner = 0;
	bool full = true;

	for (i = 0; i < 3; i++) {
		if (n[i].num == n[i + 3].num && n[i + 3].num == n[i + 6].num && n[i + 6].num == 'X') winner = 1;
		else if (n[i].num == n[i + 3].num && n[i + 3].num == n[i + 6].num && n[i + 6].num == 'O') winner = 2;
	}
	for (i = 0; i < 9; i += 3) {
		if (n[i].num == n[i + 1].num && n[i + 1].num == n[i + 2].num && n[i + 2].num == 'X') winner = 1;
		else if (n[i].num == n[i + 1].num && n[i + 1].num == n[i + 2].num && n[i + 2].num == 'O') winner = 2;
	}
	if (n[0].num == n[4].num && n[4].num == n[8].num && n[8].num == 'X') winner = 1;
	else if (n[0].num == n[4].num && n[4].num == n[8].num && n[8].num == 'O') winner = 2;

	if (n[2].num == n[4].num && n[4].num == n[6].num && n[6].num == 'X') winner = 1;
	else if (n[2].num == n[4].num && n[4].num == n[6].num && n[6].num == 'O') winner = 2;

	if (winner == 1) return 1;
	else if (winner == 2) return 2;

	for (i = 0; i < 9; i++) {
		if (n[i].num == i + '1') full = false;
	}
	if (full == true) return 3;

	return 0;
}

class TicTacToe {
public:
	number n[9];
	int input, player = 1;

	void run() {
		for (int i = 0; i < 9; i++) {
			n[i].num = i + '1';
			n[i].use = false;
		}
		while (1) {
			system("CLS");
			cout << "-- Tic Tac Toe -- CSIE@CGU\nPlayer 1 (X)   -   Player 2 (O)\n\n";
			cout << "     ■     ■     \n" << "  " << n[0].num << "  ■  " << n[1].num << "  ■  " << n[2].num << "  \n";
			cout << "     ■     ■     \n" << "■■■■■■■■■■\n";
			cout << "     ■     ■     \n" << "  " << n[3].num << "  ■  " << n[4].num << "  ■  " << n[5].num << "  \n";
			cout << "     ■     ■     \n" << "■■■■■■■■■■\n";
			cout << "     ■     ■     \n" << "  " << n[6].num << "  ■  " << n[7].num << "  ■  " << n[8].num << "  \n";
			cout << "     ■     ■     \n\n";

			if (win(n) == 0) {
				cout << "Player " << player << "，請輸入「1~9」之間的數字：";
			}
			else if (win(n) == 1) {
				cout << "==>Player 1 win";
				break;
			}
			else if (win(n) == 2) {
				cout << "==>Player 2 win";
				break;
			}
			else if (win(n) == 3) {
				cout << "==>Game draw";
				break;
			}

			cin >> input;

			if (player == 1) {
				if (n[input - 1].use == false) {
					n[input - 1].num = 'X';
					n[input - 1].use = true;
					player = 2;
				}
				else {
					cout << "\n請重新輸入下一步";
					Sleep(1500);
				}
			}
			else {
				if (n[input - 1].use == false) {
					n[input - 1].num = 'O';
					n[input - 1].use = true;
					player = 1;
				}
				else {
					cout << "\n請重新輸入下一步";
					Sleep(1500);
				}
			}
		}
	}
};

int main() {
	TicTacToe game;
	game.run();
	return 0;
}