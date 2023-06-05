#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int i;
	char* A;
	int sum = 0;

	scanf("%d", &n);

	A = (char*)malloc(sizeof(char) * (n + 1));

	scanf("%s", A);
	for (i = 0; A[i] != '\0'; i++) {
		sum += A[i] - '0';
	}
	printf("%d\n", sum);

	free(A);

	return 0;
}