#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	char* str;
	int size, realsize = 0;

	printf("Enter str length: ");
	scanf_s("%d", &size);

	str = (char*)malloc(sizeof(char) * size);

	printf("Enter str: ");
	getchar();
	gets(str);//��������� ������
	puts(str);// ������� �������
	printf("%s", str);

	while (str[realsize] != '\0') {
		realsize += 1;
	}

	printf("\nYou enter str <%s> and it's length %d", str, realsize);

	free(str);
	return 0;
}