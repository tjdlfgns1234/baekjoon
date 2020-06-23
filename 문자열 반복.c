#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(void)
{
	int t,tmp2,h;
	char tmp[21] = {(char)NULL};

	scanf("%d", &t);

	for (int j = 0; j < t; j++)
	{
		scanf("%d %s", &tmp2, tmp);
		h = strlen(tmp);
		for (int i = 0; i < h; i++)
		{
			for (int k = 0; k < tmp2; k++)
			{
				printf("%c", tmp[i]);
			}
		}
		printf("\n");
	}

	return 0;
}