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
#define MAX_CARDS 26

enum ERRORS {OUT_OF_RANGE};

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
	char cards[MAX_CARDS];
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

	void create_inter() {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;

		for (int i = 0; i < quant_par * 2; i++) {
			short x = i * 4;
			cursorPos = { x, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			std::cout << "[  ]";
		}
	}

	void cursor_move(COORD* cursorPos, short* choose_pos, int* iKey) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		while (*iKey != KEY_ENTER && *iKey != KEY_ESCAPE) {
			short _x = 0;
			switch (*iKey) {
			case KEY_ARROW_LEFT:
				_x = *choose_pos * 4 + 1;
				*cursorPos = { _x, 1 };
				SetConsoleCursorPosition(hStdOut, *cursorPos);
				std::cout << " ";
				*choose_pos -= 1;
				break;
			case KEY_ARROW_RIGHT:
				_x = *choose_pos * 4 + 1;
				*cursorPos = { _x, 1 };
				SetConsoleCursorPosition(hStdOut, *cursorPos);
				std::cout << " ";
				*choose_pos += 1;
				break;
			}

			if (*choose_pos < 0) { *choose_pos = quant_par * 2 - 1; }
			if (*choose_pos > quant_par * 2 - 1) { *choose_pos = 0; }

			short x = *choose_pos * 4 + 1;
			*cursorPos = { x, 1 };
			SetConsoleCursorPosition(hStdOut, *cursorPos);
			std::cout << "^";

			*iKey = _getch();
		}
	}

	void open_card(COORD* cursorPos, short* choose_pos) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		short x;
		x = *choose_pos * 4 + 1;
		*cursorPos = { x, 0 };
		SetConsoleCursorPosition(hStdOut, *cursorPos);
		if (cards[*choose_pos] == ':') {
			std::cout << "10";
		}
		else {
			std::cout << cards[*choose_pos];
		}
		*cursorPos = { 0, 3 };
		SetConsoleCursorPosition(hStdOut, *cursorPos);
		system("pause");
	}

	void check_pair(COORD* cursorPos, short* choose_pos, short* choosen_card, bool* true_choose) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	}

public:
	void Start_game() {
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
		bool true_choose[MAX_CARDS];
		null_mass(true_choose, MAX_CARDS);
		COORD cursorPos;

		create_inter();

		while (!exit_flag) {
			iKey = 67;
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			cursor_move(&cursorPos, &choose_pos, &iKey);

			if (iKey == KEY_ESCAPE) { exit_flag = 1; }
			else {
				short x;
				x = choose_pos * 4 + 1;
				open_card(&cursorPos, &choose_pos);
				if (choosen_card < 200) {
					if (cards[choose_pos] == cards[choosen_card] && choosen_card != choose_pos) {
						true_choose[choose_pos] = 1;
						true_choose[choosen_card] = 1;
					}
					else {
						cursorPos = { x, 0 };
						SetConsoleCursorPosition(hStdOut, cursorPos);
						std::cout << "  ";
						x = choosen_card * 4 + 1;
						cursorPos = { x, 0 };
						SetConsoleCursorPosition(hStdOut, cursorPos);
						std::cout << "  ";
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
	while (quant_pair < 1 || quant_pair > MAX_CARDS / 2) {
		system("cls");
		std::cout << "Enter quant of pair: ";
		std::cin >> quant_pair;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.get();
		}
	}
	Game game(quant_pair);
	game.Start_game();
}