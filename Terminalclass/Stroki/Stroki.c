#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	char* str;
	int size;

	printf("Enter str length: ");
	scanf_s("%d", &size);

	str = (char*)malloc(sizeof(char) * size);
	
	gets(str);//принимает строку
	puts(str);// выводит строчку
	printf("%s", str);


	free(str);
	return 0;
}