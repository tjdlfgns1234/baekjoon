#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int a, b,i,t;
	int* result;
	scanf("%d", &t);

	result = (int*)malloc(sizeof(int) * t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &a, &b);
		result[i] = a + b;
	}

	for (i = 0; i < t; i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}