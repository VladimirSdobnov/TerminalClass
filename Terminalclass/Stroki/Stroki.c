#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	char* str;
	int size;

	printf("Enter str length: ");
	scanf_s("%d", &size);

	str = (char*)malloc(sizeof(char) * size);
	
	gets(str);//��������� ������
	puts(str);// ������� �������
	printf("%s", str);


	free(str);
	return 0;
}