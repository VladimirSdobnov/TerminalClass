#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

#define Traders_quant 10
#define Storage_capasity 1000;

struct PRODUCT {
	int id;
	char* name[100];
	float cost;
	int quantity;
};

struct TRADERS{
	char logins[Traders_quant][100];
	char passwords[Traders_quant][100];
};

struct STORAGE {
	int capacity;
	struct PRODUCT* prdoucts;
};

void add_product(struct STORAGE storage) {
	int i = 0;
	while (storage.prdoucts[i].id != 0) {
		i++;
	}
	storage.prdoucts[i].id = i + 1;
	printf("Enter product name: ");
	gets(storage.prdoucts[i].name);
	printf("Enter product's cost: ");
	scanf_s("%f", &storage.prdoucts[i].cost);
	printf("Enter products's quantity: ");
	scanf_s("%d", &storage.prdoucts[i].quantity);
}

void login(struct TRADERS Traders) {
	char login[100];
	char password[100];
	int flag = 0;

	printf("Login:");
	gets(login);
	printf("Password: ");
	gets(password);

	for (int i = 0; i < Traders_quant; i++) {
		if (login == Traders.logins[i] && password == Traders.passwords[i]) {
			return 1;
		}
	}
	if (!flag) {
		return 0;
	}
}

void Adminisrator_log(int* flag) {
	char login[100];
	char password[100];

	printf("Login: ");
	gets(login);
	printf("Password: ");
	gets(password);

	if (login == "Vova" && password == "1234") {
		*flag = 1;
	}
	else {
		*flag = 0;
	}
}

void constractMenu_Login(HANDLE hStdOut) {
	char* menu_names[3] = {"Trader", "Byer", "Administrator"};
	int choose_pos = 0;
	int menu_size = 3;
	int iKey;
	int flag;
	COORD cursorPos;
	system("cls");
	iKey = 67;
	cursorPos = (COORD){ 0, 0 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
		switch (iKey) {
		case KEY_ARROW_UP:
			(choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			(choose_pos)++;
			break;
		}
		system("cls");
		if (choose_pos < 0) { choose_pos = menu_size - 1; }
		if (choose_pos > menu_size - 1) { choose_pos = 0; }
		for (int i = 0; i < menu_size; i++) {
			cursorPos = (COORD){ 3, i };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("%s \n", menu_names[i]);
		}
		cursorPos = (COORD){ 0, choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("<<", iKey);
		cursorPos = (COORD){ strlen(menu_names[choose_pos]) + 3 + 1, choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		iKey = _getch();
	}

	switch (choose_pos) {
	case 0:
		system("cls");
		constructMenu_trader(hStdOut);
		break;
	case 1:
		system("cls");
		printf("Byu");
		break;
	case 2:
		system("cls");
		Adminisrator_log(&flag);
		if (flag) {
			printf("Yes");
		}
		else {
			printf("No");
		}
		system("pause");
		break;
	}
}

void constructMenu_trader(HANDLE hStdout) {
	char* menu_names[4] = { "Add product", "Remove product", "Change product", };
	int choose_pos = 0;
	int menu_size = 3;
	int iKey;
	int flag;
	COORD cursorPos;
	system("cls");
	iKey = 67;
	cursorPos = (COORD){ 0, 0 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
		switch (iKey) {
		case KEY_ARROW_UP:
			(choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			(choose_pos)++;
			break;
		}
		system("cls");
		if (choose_pos < 0) { choose_pos = menu_size - 1; }
		if (choose_pos > menu_size - 1) { choose_pos = 0; }
		for (int i = 0; i < menu_size; i++) {
			cursorPos = (COORD){ 3, i };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("%s \n", menu_names[i]);
		}
		cursorPos = (COORD){ 0, choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("<<", iKey);
		cursorPos = (COORD){ strlen(menu_names[choose_pos]) + 3 + 1, choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		iKey = _getch();
	}

	switch (choose_pos) {
	case 0:
		system("cls");
		printf("Tr");
		break;
	case 1:
		system("cls");
		printf("Byu");
		break;
	case 2:
		system("cls");
		Adminisrator_log(&flag);
		if (flag) {
			printf("Yes");
		}
		else {
			printf("No");
		}
		system("pause");
		break;
	}
}

int main() {
	int exit_flag;
	struct STORAGE storage;

	storage.capacity = Storage_capasity;
	storage.prdoucts = (struct PRODUCT*)malloc(sizeof(struct PRODUCT) * storage.capacity);

	for (int i = 0; i < storage.capacity; i++) {
		storage.prdoucts[i].id = 0;
	}
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	constractMenu_Login(hStdOut);
}