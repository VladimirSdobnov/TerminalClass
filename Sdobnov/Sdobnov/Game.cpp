#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ENTER 13
#define KEY_ESCAPE 27

void null_mass(bool* mass, int size) {
	for (int i = 0; i < size; i++) { mass[i] = 0; }
}

bool check_game(bool* mass, int size) {
	for (int i = 0; i < size; i++) {
		if (mass[i] == 0) {
			return 0;
		}
	}
	return 1;
}

class Game {
private:
	char cards[26];
	int quant_par;
public:
	Game() {
		quant_par = 3;
		set_par();
		shuffle();
	}
	Game(Game& _game) {
		quant_par = _game.quant_par;
		for (int i = 0; i < quant_par * 2; i++) {
			cards[i] = _game.cards[i];
		}
	}
	Game(int _quant_par) {
		quant_par = _quant_par;
		set_par();
		shuffle();
	}
private:
	void set_par() {
		for (int i = 0; i < quant_par * 2; i += 2) {
			if (i / 2 + 2 < 11) {
				cards[i] = 48 + i / 2 + 2;
				cards[i + 1] = 48 + i / 2 + 2 ;
			}
			else if (i / 2 + 2 == 11) { cards[i] = 'J'; cards[i + 1] = 'J'; }
			else if (i / 2 + 2 == 12) { cards[i] = 'Q'; cards[i + 1] = 'Q'; }
			else if (i / 2 + 2 == 13) { cards[i] = 'K'; cards[i + 1] = 'K'; }
			else if (i / 2 + 2 == 14) { cards[i] = 'A'; cards[i + 1] = 'A'; }
		}
	}
	void shuffle() {
		for (int i = 0; i < quant_par * 2; i ++) {
			int x;
			do {
				x = rand() % (quant_par * 2);
			} while (x == i);

			std::swap(cards[i], cards[x]);
		}
	}
public:
	void Strat_game() {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		system("cls");

		short choose_pos = 0;
		int iKey;
		int exit_flag = 0;
		short choosen_card = 200;
		bool true_choose[26];
		null_mass(true_choose, 26);
		COORD cursorPos;

		while (!exit_flag) {
			system("cls");
			iKey = 67;
			int open_card = 0;
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			while (iKey != KEY_ENTER && iKey != KEY_ESCAPE) {
				switch (iKey) {
				case KEY_ARROW_LEFT:
					choose_pos--;
					break;
				case KEY_ARROW_RIGHT:
					choose_pos++;
					break;
				}
				system("cls");

				if (choose_pos < 0) { choose_pos = quant_par * 2 - 1; }
				if (choose_pos > quant_par * 2 - 1) { choose_pos = 0; }

				for (int i = 0; i < quant_par * 2; i++) {
					short x = i * 3;
					cursorPos = { x, 0 };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					if (true_choose[i] == 1 || choosen_card == i) { std::cout << "[" << cards[i] << "]"; }
					else { std::cout << "[ ]"; }
				}

				short x = choose_pos * 3 + 1;
				cursorPos = { x, 1 };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << "^";

				iKey = _getch();

			}
			if (iKey == KEY_ESCAPE) { exit_flag = 1; }
			else {
				short x = choose_pos * 3 + 1;
				cursorPos = { x, 0 };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << cards[choose_pos];
				cursorPos = { 0, 3 };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				system("pause");
				if (choosen_card < 30) {
					if (cards[choose_pos] == cards[choosen_card] && choosen_card != choose_pos) {
						true_choose[choose_pos] = 1;
						true_choose[choosen_card] = 1;
						
					}
					choosen_card = 200;
				}
				else { choosen_card = choose_pos; }
			}
			if (check_game(true_choose, quant_par * 2)) {
				system("cls");
				cursorPos = { 0, 3 };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << "You are WINNER!!!!\n";
				system("pause");
				exit_flag = 1;
			}
		}
		system("cls");
		std::cout << "Thanks for playing";
	}
};




int main() {
	srand(time(0));
	int quant_pair = 0;
	while (quant_pair < 1 || quant_pair > 13) {
		std::cout << "Enter quant of pair: ";
		std::cin >> quant_pair;
	}
	Game game(quant_pair);
	game.Strat_game();
	system("cls");
	printf("%c%c%c\n%c%c%c", 218, 196, 191, 192, 196, 217);
}