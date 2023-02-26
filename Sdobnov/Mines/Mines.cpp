#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESCAPE 27



class Mines {
	char field[6][6];
	int quant_mines;
	int len, wid;
public:
	Mines() {
		len = 3;
		wid = 3;
		quant_mines = 1;
		set_fields( len, wid, quant_mines);
	}
	Mines(Mines& _mines) {
		quant_mines = _mines.quant_mines;
		for (int i = 0; i < _mines.len; i++) {
			for (int j = 0; j < _mines.wid; j++) {
				field[i][j] = _mines.field[i][j];
			}
		}
	}
	Mines(int _quant_mines = 1, int _len = 3, int _wid = 3) {
		quant_mines = _quant_mines;
		len = _len;
		wid = _wid;
		set_fields(len, wid, quant_mines);
	}
private:
	void set_fields(int len, int wid, int quant_mines) {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < wid; j++) {
				field[i][j] = '0';
			}
		}
		for (int i = 0; i < quant_mines; i++) {
			int x;
			int y;
			do {
				x = rand() % len;
				y = rand() % wid;
			} while (field[x][y] == 15);
			field[x][y] = 15;
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < wid; j++) {
				if (field[i][j] != 15) {
					if (i + 1 < len && field[i + 1][j] == 15) { field[i][j] += 1; }
					if (i + 1 < len && j + 1 < wid && field[i + 1][j + 1] == 15) { field[i][j] += 1; }
					if (i + 1 < len && j - 1 > -1 && field[i + 1][j - 1] == 15) { field[i][j] += 1; }
					if (i - 1 > -1 && field[i - 1][j] == 15) { field[i][j] += 1; }
					if (i - 1 > -1 && j + 1 < wid && field[i - 1][j + 1] == 15) { field[i][j] += 1; }
					if (i - 1 > -1 && j - 1 > -1 && field[i - 1][j - 1] == 15) { field[i][j] += 1; }
					if (j + 1 < wid && field[i][j + 1] == 15) { field[i][j] += 1; }
					if (j - 1 > -1 && field[i][j - 1] == 15) { field[i][j] += 1; }
				}
			}
		}
	}
public:
	void start_game() {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		system("cls");

		short choose_pos_x = 0;
		short choose_pos_y = 0;
		short x, y;
		int iKey;
		int exit_flag = 0;
		COORD cursorPos;

		for (short i = 0; i < len * 4 + 1; i++) {
			if (i % 4 != 0) {
				for (short j = 0; j < wid * 4 + 1; j += 4) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%c", 196);
				}
			}
			else if (i > 0 && i < len * 4) {
				for (short j = 0; j < wid * 4 + 1; j++) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					if (j % 4 != 0) {
						printf("%c", 179);
					}
					else if (j > 0 && j < wid * 4) {
						printf("%c", 197);
					}
					if (j == 0) { printf("%c", 194); }
					if (j == wid * 4) { printf("%c", 193); }
				}
			}
			if (i == 0) {
				for (short j = 0; j < wid * 4 + 1; j++) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					if (j % 4 != 0) {
						printf("%c", 179);
					}
					else if (j > 0 && j < wid * 4) {
						printf("%c", 195);
					}
					if (j == 0) { printf("%c", 218); }
					if (j == wid * 4) { printf("%c", 192); }
				}
			}
			if (i == len * 4) {
				for (short j = 0; j < wid * 4 + 1; j++) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					if (j % 4 != 0) {
						printf("%c", 179);
					}
					else if (j > 0 && j < wid * 4) {
						printf("%c", 180);
					}
					if (j == 0) { printf("%c", 191); }
					if (j == wid * 4) { printf("%c", 217); }
				}
			}
		}

		while (!exit_flag) {
			iKey = 67;
			int open_card = 0;
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			while (iKey != KEY_ENTER && iKey != KEY_ESCAPE && iKey != KEY_SPACE) {
				switch (iKey) {
				case KEY_ARROW_LEFT:
					x = choose_pos_x * 4 + 2;
					y = choose_pos_y * 4 + 3;
					cursorPos = { x, y };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					std::cout << " ";
					choose_pos_x--;
					break;
				case KEY_ARROW_RIGHT:
					x = choose_pos_x * 4 + 2;
					y = choose_pos_y * 4 + 3;
					cursorPos = { x, y };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					std::cout << " ";
					choose_pos_x++;
					break;
				case KEY_ARROW_UP:
					x = choose_pos_x * 4 + 2;
					y = choose_pos_y * 4 + 3;
					cursorPos = { x, y };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					std::cout << " ";
					choose_pos_y--;
					break;
				case KEY_ARROW_DOWN:
					x = choose_pos_x * 4 + 2;
					y = choose_pos_y * 4 + 3;
					cursorPos = { x, y };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					std::cout << " ";
					choose_pos_y++;
					break;
				}

				if (choose_pos_x < 0) { choose_pos_x = len - 1; }
				if (choose_pos_x > len - 1) { choose_pos_x = 0; }
				if (choose_pos_y < 0) { choose_pos_y = wid - 1; }
				if (choose_pos_y > wid - 1) { choose_pos_y = 0; }

				short x = choose_pos_x * 4 + 2;
				short y = choose_pos_y * 4 + 3;
				cursorPos = { x, y };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << "^";

				iKey = _getch();
			}
			short _x, _y;
			_x = choose_pos_x * 4 + 2;
			_y = choose_pos_y * 4 + 2;
			if (iKey == KEY_ENTER) {
				cursorPos = { _x, _y};
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << field[choose_pos_x][choose_pos_y];
				if (field[choose_pos_x][choose_pos_y] == 15) {
					exit_flag = 1;
					system("cls");
					cursorPos = { 0, 0 };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					std::cout << "BOOOOOM!!!!\n";
					system("pause");
				}
			}
			else if (iKey == KEY_SPACE) {
				cursorPos = { _x, _y };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				printf("%c", 20);
				if (field[choose_pos_x][choose_pos_y] == 15) { quant_mines -= 1; }
				if (quant_mines == 0) {
					exit_flag = 1;
					system("cls");
					cursorPos = { 0, 0 };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					std::cout << "You are WINNER!!!\n";
					system("pause");
				}
			}
			else if (iKey == KEY_ESCAPE) { exit_flag = 1; }

		}
		system("cls");
		std::cout << "Thanks for playing";
	}
};

int main() {
	srand(time(0));
	Mines field(3, 6, 4);
	field.start_game();
}