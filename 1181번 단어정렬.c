#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20000

int compare(const void* a, const void* b);

int main(void)
{
	int n;

	scanf("%d", &n);
	char word[SIZE][51];

	for (int i = 0; i < n; i++)
	{
		scanf("%s", word[i]);
	}

	qsort((void*)word, n, sizeof(char)*51, compare);

	for (int i = 0; i < n; i++)
	{
		if (i - 1 == -1)
		{
			printf("%s\n", word[i]);
		}
		else if(strcmp(word[i],word[i-1])!=0)
			printf("%s\n", word[i]);
	}

	return 0;
}
int compare(const void* a, const void* b)
{
	int a_len, b_len;
	a_len = strlen((char *)a), b_len = strlen((char*)b);

	if (a_len == b_len)
	{
		if (strcmp((char*)a, (char*)b) < 0)
			return -1;
		else if (strcmp((char*)a, (char*)b) == 0)
			return 0;
		else
			return 1;
	}
	else if (a_len < b_len) {
		return -1;
	}
	else
	{
		return 1;
	}
}