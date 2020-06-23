#include <stdio.h>

int main(void)
{
	int A, B, V, day = 1;
	double check;
	scanf("%d %d %d", &A, &B, &V);
	check = (double)(V - A) / (double)(A - B);
	if (check-(int)check > 0)
	{
		day = day + 1;
	}
	printf("%d", day+(int)check);
	return 0;
}