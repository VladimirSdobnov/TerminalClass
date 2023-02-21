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

class Mines {
	char field[6][6];
	int quant_mines;
	int len, wid;
public:
	Mines() {
		quant_mines = 1;
		set_fields( 3, 3, 1);
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
			} while (field[x][y] == '!');
			field[x][y] = '!';
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < wid; j++) {
				if (i + 1 < len && field[i + 1][j] == '!') { field[i][j] += 1; }
				if (i + 1 < len && j + 1 < wid && field[i + 1][j + 1] == '!') { field[i][j] += 1; }
				if (j + 1 < wid && field[i][j + 1] == '!') { field[i][j] += 1; }
				if (i - 1 > -1 && j + 1 && field[i - 1][j + 1] == '!') { field[i][j] += 1; }
				if (i - 1 > -1 && field[i - 1][j] == '!') { field[i][j] += 1; }
				if (i - 1 > -1 && j - 1 > -1 && field[i - 1][j - 1] == '!') { field[i][j] += 1; }
				if (j - 1 > -1 && field[i][j - 1] == '!') { field[i][j] += 1; }
				if (i + 1 < len && j - 1 < -1 && field[i + 1][j - 1] == '!') { field[i][j] += 1; }
			}
		}
	}
public:
	void start_game() {

	}
};

int main() {
	srand(time(0));
	Mines field(1, 4, 4);
}