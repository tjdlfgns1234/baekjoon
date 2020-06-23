#include <stdio.h>

int main(void)
{
	int A, B, C,Bene=0,count=0;
	scanf("%d %d %d", &A, &B, &C);
	Bene = C-B;
	
	if (Bene <= 0)
	{
		printf("%d", -1);
		return 0;
	}

	count = A / Bene + 1;

	printf("%d", count);

	return 0;
}