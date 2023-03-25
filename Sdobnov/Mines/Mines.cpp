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
	int wid, len;
public:
	Mines() {
		wid = 3;
		len = 3;
		field = new char* [wid];
		for (int i = 0; i < wid; i++) {
			field[i] = new char[len];
			for (int j = 0; j < len; j++) {
				field[i][j] = '0';
			}
		}
		bool_field = new short int* [wid];
		for (int i = 0; i < wid; i++) {
			bool_field[i] = new short int[len];
			for (int j = 0; j < len; j++) {
				bool_field[i][j] = 0;
			}
		}
		quant_mines = 1;

		set_fields();
	}
	Mines(Mines& _mines) {
		wid = _mines.wid;
		len = _mines.len;
		quant_mines = _mines.quant_mines;
		field = new char* [wid];
		for (int i = 0; i < wid; i++) {
			field[i] = new char[len];
		}
		for (int i = 0; i < wid; i++) {
			for (int j = 0; j < len; j++) {
				field[i][j] = _mines.field[i][j];
			}
		}
		bool_field = new short int* [wid];
		for (int i = 0; i < wid; i++) {
			bool_field[i] = new short int[len];
			for (int j = 0; j < len; j++) {
				bool_field[i][j] = _mines.bool_field[i][j];
			}
		}
	}
	Mines(int _quant_mines, int _len, int _wid) {
		quant_mines = _quant_mines;
		wid = _len;
		len = _wid;
		field = new char* [wid];
		for (int i = 0; i < wid; i++) {
			field[i] = new char[len];
			for (int j = 0; j < len; j++) {
				field[i][j] = '0';
			}
		}
		bool_field = new short int* [wid];
		for (int i = 0; i < wid; i++) {
			bool_field[i] = new short int[len];
			for (int j = 0; j < len; j++) {
				bool_field[i][j] = 0;
			}
		}

		set_fields();
	}
	~Mines() {
		for (int i = 0; i < wid; i++) {
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
				x = rand() % wid;
				y = rand() % len;
			} while (field[x][y] == MINE_CODE);
			field[x][y] = MINE_CODE;
		}
		for (int i = 0; i < wid; i++) {
			for (int j = 0; j < len; j++) {
				if (field[i][j] != 15) {
					if (i + 1 < wid && field[i + 1][j] == MINE_CODE) { field[i][j] += 1; }
					if (i + 1 < wid && j + 1 < len && field[i + 1][j + 1] == MINE_CODE) { field[i][j] += 1; }
					if (i + 1 < wid && j - 1 > -1 && field[i + 1][j - 1] == MINE_CODE) { field[i][j] += 1; }
					if (i - 1 > -1 && field[i - 1][j] == MINE_CODE) { field[i][j] += 1; }
					if (i - 1 > -1 && j + 1 < len && field[i - 1][j + 1] == MINE_CODE) { field[i][j] += 1; }
					if (i - 1 > -1 && j - 1 > -1 && field[i - 1][j - 1] == MINE_CODE) { field[i][j] += 1; }
					if (j + 1 < len && field[i][j + 1] == MINE_CODE) { field[i][j] += 1; }
					if (j - 1 > -1 && field[i][j - 1] == MINE_CODE) { field[i][j] += 1; }
				}
			}
		}
	}
	void create_inter() {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;

		for (short i = 0; i < wid * 4 + 1; i++) {
			if (i % 4 != 0) {
				for (short j = 0; j < len * 4 + 1; j += 4) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%c", 196);
				}
			}
			else if (i > 0 && i < wid * 4) {
				for (short j = 0; j < len * 4 + 1; j++) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					if (j % 4 != 0) {
						printf("%c", 179);
					}
					else if (j > 0 && j < len * 4) {
						printf("%c", 197);
					}
					if (j == 0) { printf("%c", 194); }
					if (j == len * 4) { printf("%c", 193); }
				}
			}
			if (i == 0) {
				for (short j = 0; j < len * 4 + 1; j++) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					if (j % 4 != 0) {
						printf("%c", 179);
					}
					else if (j > 0 && j < len * 4) {
						printf("%c", 195);
					}
					if (j == 0) { printf("%c", 218); }
					if (j == len * 4) { printf("%c", 192); }
				}
			}
			if (i == wid * 4) {
				for (short j = 0; j < len * 4 + 1; j++) {
					cursorPos = { i, j };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					if (j % 4 != 0) {
						printf("%c", 179);
					}
					else if (j > 0 && j < len * 4) {
						printf("%c", 180);
					}
					if (j == 0) { printf("%c", 191); }
					if (j == len * 4) { printf("%c", 217); }
				}
			}
		}
	}
	void cursor_move_field(short* choose_pos_x, short* choose_pos_y, int* iKey) {
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

			if (*choose_pos_x < 0) { *choose_pos_x = wid - 1; }
			if (*choose_pos_x > wid - 1) { *choose_pos_x = 0; }
			if (*choose_pos_y < 0) { *choose_pos_y = len - 1; }
			if (*choose_pos_y > len - 1) { *choose_pos_y = 0; }

			short x = *choose_pos_x * 4 + 2;
			short y = *choose_pos_y * 4 + 3;
			cursorPos = { x, y };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			std::cout << "^";

			*iKey = _getch();
		}
	}
	void cursor_move_setting(short* choose_pos, int* iKey) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;
		short x;

		while (*iKey != KEY_ENTER) {
			switch (*iKey) {
			case KEY_ARROW_UP:
				x = *choose_pos * 4 + 2;
				cursorPos = { x, };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << " ";
				break;
			case KEY_ARROW_DOWN:
				x = *choose_pos * 4 + 2;
				cursorPos = { x, };
				SetConsoleCursorPosition(hStdOut, cursorPos);
				std::cout << " ";
				break;
			}

			if (*choose_pos < 0) { *choose_pos = wid - 1; }
			if (*choose_pos > wid - 1) { *choose_pos = 0; }

			short x = *choose_pos * 4 + 2;
			cursorPos = { x,  };
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
			if (choose_pos_y + 1 < len && bool_field[choose_pos_x][choose_pos_y + 1] == 0) { open_cell(choose_pos_x, choose_pos_y + 1); }
			if (choose_pos_y - 1 >= 0 && bool_field[choose_pos_x][choose_pos_y - 1] == 0) { open_cell(choose_pos_x, choose_pos_y - 1); }
			if (choose_pos_x + 1 < wid && bool_field[choose_pos_x + 1][choose_pos_y] == 0) { open_cell(choose_pos_x + 1, choose_pos_y); }
			if (choose_pos_x - 1 >= 0 && bool_field[choose_pos_x - 1][choose_pos_y] == 0) { open_cell(choose_pos_x - 1, choose_pos_y); }
			if (choose_pos_x + 1 < wid && choose_pos_y + 1 < len && bool_field[choose_pos_x + 1][choose_pos_y + 1] == 0) { open_cell(choose_pos_x + 1, choose_pos_y + 1); }
			if (choose_pos_y - 1 >= 0 && choose_pos_x - 1 >= 0 && bool_field[choose_pos_x - 1][choose_pos_y - 1] == 0) { open_cell(choose_pos_x - 1, choose_pos_y - 1); }
			if (choose_pos_x + 1 < wid && choose_pos_y - 1 >= 0 && bool_field[choose_pos_x + 1][choose_pos_y - 1] == 0) { open_cell(choose_pos_x + 1, choose_pos_y - 1); }
			if (choose_pos_x - 1 >= 0 && choose_pos_y + 1 < len && bool_field[choose_pos_x - 1][choose_pos_y + 1] == 0) { open_cell(choose_pos_x - 1, choose_pos_y + 1); }
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

			cursor_move_field(&choose_pos_x, &choose_pos_y, &iKey);

			if (iKey == KEY_ENTER) { exit_flag = open_cell(choose_pos_x, choose_pos_y); }
			else if (iKey == KEY_SPACE) { set_flag(choose_pos_x, choose_pos_y); }
			else if (iKey == KEY_ESCAPE) { exit_flag = 1; }

			check_game(&exit_flag);
		}
		system("cls");
		std::cout << "Thanks for playing";
	}
	void setting() {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		system("cls");

		short choose_pos = 0;
		int iKey;
		bool exit_flag = FALSE;
		COORD cursorPos;

		std::cout << "Length of field:   \n";
		std::cout << "Width of field:    \n";
		std::cout << "Quantity of mines: ";

		while (!exit_flag) {
			iKey = 67;
			cursorPos = { 0, 0 };
			SetConsoleCursorPosition(hStdOut, cursorPos);
		}
	}
};

void cursor_move(std::string* menu_names, int menu_size, short* choose_pos, int* iKey) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos;
	short x;
	while (*iKey != KEY_ENTER) {
		switch (*iKey) {
		case KEY_ARROW_UP:
			cursorPos = { 0, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			x = menu_names[*choose_pos].length() + 4;
			cursorPos = { x, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			(*choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			cursorPos = { 0, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			x = menu_names[*choose_pos].length() + 4;
			cursorPos = { x, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			(*choose_pos)++;
			break;
		}
		if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
		if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
		cursorPos = { 0, *choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("<<");
		x = menu_names[*choose_pos].length() + 4;
		cursorPos = { x, *choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		*iKey = _getch();
	}

}
void constract_MainMenu() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	system("cls");

	std::string menu_names[3] = { "START", "SETTINGS", "EXIT" };
	short choose_pos = 0;
	int menu_size = 3;
	int iKey;
	int flag;
	COORD cursorPos;
	system("cls");
	iKey = 67;
	cursorPos = { 0, 0 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	for (short i = 0; i < menu_size; i++) {
		cursorPos = { 3, i };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		std::cout << menu_names[i];
	}
	cursor_move(menu_names, menu_size, &choose_pos, &iKey);

	Mines field(4, 5, 6);

	switch (choose_pos) {
	case 0:
		system("cls");
		field.start_game();
		break;
	case 1:
		system("cls");
		field.setting();
		break;
	case 2:
		system("cls");

		break;
	}
}

int main() {
	srand(time(0));
	constract_MainMenu();
}