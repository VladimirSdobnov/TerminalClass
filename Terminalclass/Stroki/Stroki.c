#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void catch (char* str, int size) {
	str[size] = '\0';
}

void swap(char* str, int a, int b) {
	char c;
	c = str[a];
	str[a] = str[b];
	str[b] = c;
}

void show(char* str) {
	int size = 0;
	printf("New str: ");
	while (str[size] != '\0') {
		printf("%c", str[size]);
		size++;
	}
	printf("\n");
}

int main() {
	char* str;
	int size, realsize = 0, want = 1;
	str = (char*)malloc(sizeof(char) * 1000);
	printf("Enter str: ");
	gets(str);
	printf("What are you want to do?(1 - enter new str, 2 - catch str, 3 - reverse str, 4 - change registr, 0 - Exit): ");
	scanf_s("%d", &want);

	while (want > 0) {
		while (str[realsize] != '\0') {
			realsize += 1;
		}

		if (want == 2) {
			printf("Enter size of catch: ");
			scanf_s("%d", &size);
			while (size > realsize || size < 0) {
				printf("Very strange catch, try again: ");
				scanf_s("%d", &size);
			}
			catch (str, size);
		}
		else if (want == 3) {
			for (int i = 0; i < realsize * 0.5; i++) {
				swap(str, i, realsize - i - 1);
			}
		}
		else if (want == 4) {
			printf("Choise registr(1 - Up, 2 - Down, 3 - Reverse): ");
			scanf_s("%d", &want);
			while (want > 3 || want < 1) {
				printf("Choise correct(1 - Up, 2 - Down, 3 - Reverse): ");
				scanf_s("%d", &want);
			}
			if (want == 1) {
				size = 0;
				while (str[size] != '\0') {
					if (str[size] < 123 && str[size] > 96) {
						str[size] -= 32;
					}
					size++;
				}
			}
			else if (want == 2) {
				size = 0;
				while (str[size] != '\0') {
					if (str[size] < 91 && str[size] > 64) {
						str[size] += 32;
					}
					size++;
				}
			}
			else if (want == 3) {
				size = 0;
				while (str[size] != '\0') {
					if (str[size] < 91 && str[size] > 64) {
						str[size] += 32;
					}
					else if (str[size] < 123 && str[size] > 96) {
						str[size] -= 32;
					}
					size++;
				}
			}


		}
		show(str);
		system("pause");
		system("cls");

		printf("Enter str: ");
		getchar();
		gets(str);

		printf("What are you want to do?(1 - enter new str, 2 - catch str, 3 - reverse str, 4 - change registr, 0 - Exit): ");
		scanf_s("%d", &want);
	}

	free(str);
	return 0;
}