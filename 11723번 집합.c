#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(void)
{
	int s[SIZE+1] = { 0 };
	int check =0;
	int m;
	int tmp;
	char buffer[7];
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", buffer);
		if (!strcmp(buffer, "add"))
		{
			scanf("%d", &tmp);
			if (s[tmp] == 0)
			{
				s[tmp] = 1;
			}
		}
		else if (!strcmp(buffer,"remove"))
		{
			scanf("%d", &tmp);
			if (s[tmp] == 1)
			{
				s[tmp] = 0;
			}
		}
		else if (!strcmp(buffer, "check"))
		{
			scanf("%d", &tmp);
			printf("%d\n", s[tmp]);
		}
		else if (!strcmp(buffer, "toggle"))
		{
			scanf("%d", &tmp);
			s[tmp] = !s[tmp];
		}
		else if (!strcmp(buffer, "all"))
		{
			for (int j = 1; j < SIZE+1; j++)
			{
				s[j] = 1;
			}
		}
		else if (!strcmp(buffer, "empty"))
		{
			for (int j = 1; j < SIZE + 1; j++)
			{
				s[j] = 0;
			}
		}
	}
	return 0;
}