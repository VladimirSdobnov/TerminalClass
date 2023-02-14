#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ENTER 13

class Game {
public:
	int cards[28];
	int quant_par;
	Game() {
		quant_par = 3;
		set_par();
		shuffle();
	}
	Game(Game& _game) {
		quant_par = _game.quant_par;
		for (int i; i < quant_par * 2; i++) {
			cards[i] = _game.cards[i];
		}
	}
	Game(int _quant_par) {
		quant_par = _quant_par;
		set_par();
		shuffle();
	}
	void set_par() {
		for (int i = 0; i < quant_par * 2; i += 2) {
			cards[i] = 2 + rand() % 12 + 1;
			cards[i + 1] = cards[i];
		}
	}
	void shuffle() {
		for (int i = 0; i < quant_par * 2; i+=2) {
			int x = rand() % quant_par * 2 + 1;
			while (x == i) {
				x = rand() % quant_par * 2 + 1;
			}
			std::swap(cards[i], cards[x]);
		}
	}
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
		COORD cursorPos;

		while (!exit_flag) {
			system("cls");
			iKey = 67;
			int open_card = 0;
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			while (iKey != KEY_ENTER) {
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
					std::cout << "[ ]";
				}

				short x = choose_pos * 3 + 1;
				cursorPos = { x, 1 };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << "^";

				iKey = _getch();

			}
		}
	}
};


int main() {
	int quant_pair = 0;
	while (quant_pair < 1 || quant_pair > 14) {
		std::cout << "Enter quant of pair: ";
		std::cin >> quant_pair;
	}
	Game game(quant_pair);
	game.Strat_game();
}