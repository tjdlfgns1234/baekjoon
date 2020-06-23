#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main(void)
{
	char input[101];

	while (fgets(input,100,stdin) != NULL)
	{
		printf("%s", input);
	}

	return 0;
}