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
#define MINE_CODE 15


class Mines {
	char field[100][100];
	int quant_mines;
	int len, wid;
public:
	Mines() {
		len = 3;
		wid = 3;
		quant_mines = 1;
		generate_fields( len, wid, quant_mines);
	}
	Mines(Mines& _mines) {
		quant_mines = _mines.quant_mines;
		for (int i = 0; i < _mines.len; i++) {
			for (int j = 0; j < _mines.wid; j++) {
				field[i][j] = _mines.field[i][j];
			}
		}
	}
	Mines(int _quant_mines, int _len, int _wid) {
		quant_mines = _quant_mines;
		len = _len;
		wid = _wid;
		generate_fields(len, wid, quant_mines);
	}
private:
	void generate_fields(int len, int wid, int quant_mines) {
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
			} while (field[x][y] == MINE_CODE);
			field[x][y] = MINE_CODE;
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < wid; j++) {
				if (field[i][j] != 15) {
					if (i + 1 < len && field[i + 1][j] == MINE_CODE) { field[i][j] += 1; }
					if (i + 1 < len && j + 1 < wid && field[i + 1][j + 1] == MINE_CODE) { field[i][j] += 1; }
					if (i + 1 < len && j - 1 > -1 && field[i + 1][j - 1] == MINE_CODE) { field[i][j] += 1; }
					if (i - 1 > -1 && field[i - 1][j] == MINE_CODE) { field[i][j] += 1; }
					if (i - 1 > -1 && j + 1 < wid && field[i - 1][j + 1] == MINE_CODE) { field[i][j] += 1; }
					if (i - 1 > -1 && j - 1 > -1 && field[i - 1][j - 1] == MINE_CODE) { field[i][j] += 1; }
					if (j + 1 < wid && field[i][j + 1] == MINE_CODE) { field[i][j] += 1; }
					if (j - 1 > -1 && field[i][j - 1] == MINE_CODE) { field[i][j] += 1; }
				}
			}
		}
	}
	void create_inter(int len, int wid) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
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
	}
	void cursor_move(int len, int wid, short* choose_pos_x, short* choose_pos_y, int* iKey) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;
		short x, y;

		while (*iKey != KEY_ENTER && *iKey != KEY_ESCAPE && *iKey != KEY_SPACE) {
			switch (*iKey) {
			case KEY_ARROW_LEFT:
				x = *choose_pos_x * 4 + 2;
				y = *choose_pos_y * 4 + 3;
				cursorPos = { x, y };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << " ";
				*choose_pos_x -= 1;
				break;
			case KEY_ARROW_RIGHT:
				x = *choose_pos_x * 4 + 2;
				y = *choose_pos_y * 4 + 3;
				cursorPos = { x, y };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << " ";
				*choose_pos_x += 1;
				break;
			case KEY_ARROW_UP:
				x = *choose_pos_x * 4 + 2;
				y = *choose_pos_y * 4 + 3;
				cursorPos = { x, y };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << " ";
				*choose_pos_y -= 1;
				break;
			case KEY_ARROW_DOWN:
				x = *choose_pos_x * 4 + 2;
				y = *choose_pos_y * 4 + 3;
				cursorPos = { x, y };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << " ";
				*choose_pos_y += 1;
				break;
			}

			if (*choose_pos_x < 0) { *choose_pos_x = len - 1; }
			if (*choose_pos_x > len - 1) { *choose_pos_x = 0; }
			if (*choose_pos_y < 0) { *choose_pos_y = wid - 1; }
			if (*choose_pos_y > wid - 1) { *choose_pos_y = 0; }

			short x = *choose_pos_x * 4 + 2;
			short y = *choose_pos_y * 4 + 3;
			cursorPos = { x, y };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			std::cout << "^";

			*iKey = _getch();
		}
	}
	bool open_cell(short choose_pos_x, short choose_pos_y) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;

		short x, y;
		x = choose_pos_x * 4 + 2;
		y = choose_pos_y * 4 + 2;
		cursorPos = { x, y };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		std::cout << field[choose_pos_x][choose_pos_y];
		if (field[choose_pos_x][choose_pos_y] == MINE_CODE || field[choose_pos_x][choose_pos_y] == 0) { return TRUE; }
		else { return FALSE; }
	}
	void set_flag(short choose_pos_x, short choose_pos_y) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;
		short x, y;
		x = choose_pos_x * 4 + 2;
		y = choose_pos_y * 4 + 2;

		cursorPos = { x, y };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("%c", 20);
		if (field[choose_pos_x][choose_pos_y] == 15) {
			quant_mines -= 1;
			field[choose_pos_x][choose_pos_y] = 0;
		}
	}
	void check_game(bool* exit_flag) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;
		if (*exit_flag == TRUE) {
			system("cls");
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			std::cout << "YOU LOSSER!!!\n";
			system("pause");
		}
		if (quant_mines == 0) {
			system("cls");
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			std::cout << "YOU WINNER!!!\n";
			system("pause");
			*exit_flag = TRUE;
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
		int iKey;
		bool exit_flag = FALSE;
		COORD cursorPos;

		create_inter(len, wid);

		while (!exit_flag) {
			iKey = 67;
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			cursor_move(len, wid, &choose_pos_x, &choose_pos_y, &iKey);

			if (iKey == KEY_ENTER) { exit_flag = open_cell(choose_pos_x, choose_pos_y); }
			else if (iKey == KEY_SPACE) { set_flag(choose_pos_x, choose_pos_y); }
			else if (iKey == KEY_ESCAPE) { exit_flag = 1; }

			check_game(&exit_flag);
		}
		system("cls");
		std::cout << "Thanks for playing";
	}
};

int main() {
	srand(time(0));
	Mines field(4, 5, 5);
	field.start_game();
}