#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n,result=0,check=1;
	char tmp[81];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", tmp);
		for (int j = 0; j < strlen(tmp); j++)
		{
			if ((tmp[j]-'O')==0)
			{
				result = result + check;
				check++;
			}
			else if ((tmp[j] - 'X') == 0)
			{
				check = 1;
			}
		}
		printf("%d\n", result);
		result = 0, check = 1;
	}

	return 0;
}