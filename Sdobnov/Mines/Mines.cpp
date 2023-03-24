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
#define FLAG_CODE 20


class Mines {
	char** field;
	short int** bool_field;
	int quant_mines;
	int len, wid;
public:
	Mines() {
		len = 3;
		wid = 3;
		field = new char* [len];
		for (int i = 0; i < len; i++) {
			field[i] = new char[wid];
			for (int j = 0; j < wid; j++) {
				field[i][j] = '0';
			}
		}
		bool_field = new short int* [len];
		for (int i = 0; i < len; i++) {
			bool_field[i] = new short int[wid];
			for (int j = 0; j < wid; j++) {
				bool_field[i][j] = 0;
			}
		}
		quant_mines = 1;

		set_fields();
	}
	Mines(Mines& _mines) {
		len = _mines.len;
		wid = _mines.wid;
		quant_mines = _mines.quant_mines;
		field = new char* [len];
		for (int i = 0; i < len; i++) {
			field[i] = new char[wid];
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < wid; j++) {
				field[i][j] = _mines.field[i][j];
			}
		}
		bool_field = new short int* [len];
		for (int i = 0; i < len; i++) {
			bool_field[i] = new short int[wid];
			for (int j = 0; j < wid; j++) {
				bool_field[i][j] = _mines.bool_field[i][j];
			}
		}
	}
	Mines(int _quant_mines, int _len, int _wid) {
		quant_mines = _quant_mines;
		len = _len;
		wid = _wid;
		field = new char* [len];
		for (int i = 0; i < len; i++) {
			field[i] = new char[wid];
			for (int j = 0; j < wid; j++) {
				field[i][j] = '0';
			}
		}
		bool_field = new short int* [len];
		for (int i = 0; i < len; i++) {
			bool_field[i] = new short int[wid];
			for (int j = 0; j < wid; j++) {
				bool_field[i][j] = 0;
			}
		}

		set_fields();
	}
	~Mines() {
		for (int i = 0; i < len; i++) {
			delete[] field[i];
			delete[] bool_field[i];
		}
		delete[] field;
		delete[] bool_field;
	}
private:
	void set_fields() {
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
	void create_inter() {
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
	void cursor_move(short* choose_pos_x, short* choose_pos_y, int* iKey) {
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
		bool_field[choose_pos_x][choose_pos_y] = 1;
		if (field[choose_pos_x][choose_pos_y] == '0') {
			if (choose_pos_y + 1 < wid && bool_field[choose_pos_x][choose_pos_y + 1] == 0) { open_cell(choose_pos_x, choose_pos_y + 1); }
			if (choose_pos_y - 1 >= 0 && bool_field[choose_pos_x][choose_pos_y - 1] == 0) { open_cell(choose_pos_x, choose_pos_y - 1); }
			if (choose_pos_x + 1 < len && bool_field[choose_pos_x + 1][choose_pos_y] == 0) { open_cell(choose_pos_x + 1, choose_pos_y); }
			if (choose_pos_x - 1 >= 0 && bool_field[choose_pos_x - 1][choose_pos_y] == 0) { open_cell(choose_pos_x - 1, choose_pos_y); }
			if (choose_pos_x + 1 < len && choose_pos_y + 1 < wid && bool_field[choose_pos_x + 1][choose_pos_y + 1] == 0) { open_cell(choose_pos_x + 1, choose_pos_y + 1); }
			if (choose_pos_y - 1 >= 0 && choose_pos_x - 1 >= 0 && bool_field[choose_pos_x - 1][choose_pos_y - 1] == 0) { open_cell(choose_pos_x - 1, choose_pos_y - 1); }
			if (choose_pos_x + 1 < len && choose_pos_y - 1 >= 0 && bool_field[choose_pos_x + 1][choose_pos_y - 1] == 0) { open_cell(choose_pos_x + 1, choose_pos_y - 1); }
			if (choose_pos_x - 1 >= 0 && choose_pos_y + 1 < wid && bool_field[choose_pos_x - 1][choose_pos_y + 1] == 0) { open_cell(choose_pos_x - 1, choose_pos_y + 1); }
		}
		if (field[choose_pos_x][choose_pos_y] == MINE_CODE) { return TRUE; }
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
		if (bool_field[choose_pos_x][choose_pos_y] == 0) {
			printf("%c", FLAG_CODE);
			bool_field[choose_pos_x][choose_pos_y] = -1;
			if (field[choose_pos_x][choose_pos_y] == MINE_CODE) {
				quant_mines -= 1;
			}
		}
		else if (bool_field[choose_pos_x][choose_pos_y] == -1) {
			printf(" ");
			bool_field[choose_pos_x][choose_pos_y] = 0;
			if (field[choose_pos_x][choose_pos_y] == MINE_CODE) {
				quant_mines += 1;
			}
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

		create_inter();

		while (!exit_flag) {
			iKey = 67;
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);

			cursor_move(&choose_pos_x, &choose_pos_y, &iKey);

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