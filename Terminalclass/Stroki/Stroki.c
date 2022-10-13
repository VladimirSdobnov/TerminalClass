#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void catch (char* str, int size) {
	str[size] = '\0';
	printf("New str <%s>", str);
}

int main() {
	char* str;
	char old, new;
	int size, realsize = 0, want = 1;
	str = (char*)malloc(sizeof(char) * 100);
	printf("Enter str: ");
	gets(str);
	printf("What are you want to do?(1 - enter new str, 2 - catch str, 3 - remote element, 4 - change registr): ");
	scanf_s("%d", &want);

	while (want == 1) {
		printf("Enter str: ");
		getchar();
		gets(str);

		printf("What are you want to do?(1 - enter new str, 2 - catch str, 3 - remote element, 4 - change registr): ");
		scanf_s("%d", &want);
	}

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
		getchar();
		printf("Enter element wich you want remote: ");
		old = getchar();

		getchar();
		printf("Enter new element: ");
		new = getchar();
	}

	free(str);
	return 0;
}