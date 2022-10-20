// библиотеки
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

// управл¤ющие консолью библиотеки
#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3

// основные ключи, которые могут пригодитьс¤

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
// объ¤вление главной функции
int main() {
    // настройки
    setlocale(LC_ALL, "rus");
    srand(time(0));
    // задаем название консольного окна
    system("title Application");

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

    // получаем дескриптор окна для обращени¤ к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // отключение мигания курсора в консоли (в нашем меню курсор лишний)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // задаем серый фон дл¤ окна консоли
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // очищаем экран, чтобы настройка цвета применилась
    system("cls");

    // объ¤вление переменных
    int* mass = {0};
    int size = 0;
    int choose_pos = 0;                    // переменная для хранения выбранного пункта меню
    int iKey;                          // переменная для фиксации нажатой клавиши
    int exit_flag = 0;                     // флаг на завершение программы
    int return_flag = 0;
    COORD cursorPos;                   // управление положением курсора, чтобы менять выводимый текст

    char* menu_start[MENU_SIZE] = { "Алгоритмы", "Настройки", "Выход" };
    char* menu_algor[MENU_SIZE] = { "Поиск", "Сортировка", "Назад" };
    char* menu_setting[MENU_SIZE] = { "Задать массив", "Посмотреть текущий массив", "Назад"};

    while (!exit_flag) {
        /* 1. вывод меню с переключением */

        // сброс консоли в стартовое положение
        system("cls");
        iKey = 67;
        cursorPos = (COORD){ 0, 0 };
        SetConsoleCursorPosition(hStdOut, cursorPos);

        // контроль нажатия клавиш
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

            // зацикливание перелистывания меню
            if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
            if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu_start[i]);
            }

            // обозначение выбранной позиции
            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu_start[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            // ожидание нового нажати¤ клавиши
            iKey = _getch();
        }

        /* 2. основна¤ часть программы */
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
                    printf("Введите размер массива: ");
                    scanf_s("%d", &size);
                    system("cls");
                    mass = (int*)malloc(sizeof(int) * size);
                    printf("Введите элементы массива: ");
                    generate(mass, size);
                    system("cls");
                    printf("Массив Сгенерирован!\n");
                    system("pause");
                    break;
                case 1:
                    system("cls");
                    if (size == 0) {
                        printf("Массив еще не задан!\n");
                        system("pause");
                        break;
                    }
                    else {
                        system("cls");
                        printf("Текущий массив: ");
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

    // вывод результата
    system("cls");
    printf("Goodbay!\n");

    // завершение программы
    system("pause");
    return 0;
}