#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n,result=0;
	char tmp[101];
	scanf("%d", &n);
	scanf("%s", tmp);
	for (int i = 0; i < n; i++)
	{
		if ((tmp[i] - '1') == 0)
		{
			result += 1;
		}
		else if ((tmp[i] - '2') == 0)
		{
			result += 2;
		}
		else if ((tmp[i] - '3') == 0)
		{
			result += 3;
		}
		else if ((tmp[i] - '4') == 0)
		{
			result += 4;
		}
		else if ((tmp[i] - '5') == 0)
		{
			result += 5;
		}
		else if ((tmp[i] - '6') == 0)
		{
			result += 6;
		}
		else if ((tmp[i] - '7') == 0)
		{
			result += 7;
		}
		else if ((tmp[i] - '8') == 0)
		{
			result += 8;
		}
		else if ((tmp[i] - '9') == 0)
		{
			result += 9;
		}
	}
	printf("%d", result);
	return 0;
}