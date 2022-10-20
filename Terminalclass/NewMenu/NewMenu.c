// ����������
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

// ���������� �������� ����������
#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3

// �������� �����, ������� ����� ����������

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

void generate(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &mass[i]);
    }
}
void show(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", mass[i]);
    }
}
// ���������� ������� �������
int main() {
    // ���������
    setlocale(LC_ALL, "rus");
    srand(time(0));
    // ������ �������� ����������� ����
    system("title Application");

    // ������������� �������������� � �������� �������
    SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������

    // �������� ���������� ���� ��� �������� � �������
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���������� ������� ������� � ������� (� ����� ���� ������ ������)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // ������ ����� ��� �� ���� �������
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // ������� �����, ����� ��������� ����� �����������
    system("cls");

    // ���������� ����������
    int* mass = {0};
    int size = 0;
    int choose_pos = 0;                    // ���������� ��� �������� ���������� ������ ����
    int iKey;                          // ���������� ��� �������� ������� �������
    int exit_flag = 0;                     // ���� �� ���������� ���������
    int return_flag = 0;
    COORD cursorPos;                   // ���������� ���������� �������, ����� ������ ��������� �����

    char* menu_start[MENU_SIZE] = { "���������", "���������", "�����" };
    char* menu_algor[MENU_SIZE] = { "�����", "����������", "�����" };
    char* menu_setting[MENU_SIZE] = { "������ ������", "���������� ������� ������", "�����"};

    while (!exit_flag) {
        /* 1. ����� ���� � ������������� */

        // ����� ������� � ��������� ���������
        system("cls");
        iKey = 67;
        cursorPos = (COORD){ 0, 0 };
        SetConsoleCursorPosition(hStdOut, cursorPos);

        // �������� ������� ������
        while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
            return_flag = 0;
            switch (iKey) {
            case KEY_ARROW_UP:
                choose_pos--;
                break;
            case KEY_ARROW_DOWN:
                choose_pos++;
                break;
            }

            system("cls");

            // ������������ �������������� ����
            if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
            if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu_start[i]);
            }

            // ����������� ��������� �������
            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu_start[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            // �������� ������ ������ �������
            iKey = _getch();
        }

        /* 2. ������� ����� ��������� */
        switch (choose_pos) {
        case 0:
            system("cls");
            printf("Game part in development\n");
            system("pause");
            break;
        case 1:
            system("cls");
            choose_pos = 0;
            while (!return_flag) {
                iKey = 67;
                cursorPos = (COORD){ 0, 0 };
                SetConsoleCursorPosition(hStdOut, cursorPos);

                while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                    switch (iKey) {
                    case KEY_ARROW_UP:
                        choose_pos--;
                        break;
                    case KEY_ARROW_DOWN:
                        choose_pos++;
                        break;
                    }

                    system("cls");

                    if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
                    if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

                    for (int i = 0; i < MENU_SIZE; i++) {
                        cursorPos = (COORD){ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", menu_setting[i]);
                    }

                    cursorPos = (COORD){ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf("<<", iKey);
                    cursorPos = (COORD){ strlen(menu_setting[choose_pos]) + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");

                    iKey = _getch();
                }
                switch (choose_pos) {
                case 0:
                    system("cls");
                    printf("������� ������ �������: ");
                    scanf_s("%d", &size);
                    system("cls");
                    mass = (int*)malloc(sizeof(int) * size);
                    printf("������� �������� �������: ");
                    generate(mass, size);
                    system("cls");
                    printf("������ ������������!\n");
                    system("pause");
                    break;
                case 1:
                    system("cls");
                    if (size == 0) {
                        printf("������ ��� �� �����!\n");
                        system("pause");
                        break;
                    }
                    else {
                        system("cls");
                        printf("������� ������: ");
                        show(mass, size);
                        printf("\n");
                        system("pause");
                        break;
                    }
                case 2:
                    return_flag = 1;
                    break;
                }
            }
            break;
        case 2:
            exit_flag = 1;
            break;
        }
    }

    // ����� ����������
    system("cls");
    printf("Goodbay!\n");

    // ���������� ���������
    system("pause");
    return 0;
}