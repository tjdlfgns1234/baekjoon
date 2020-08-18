#include<stdio.h>
#include<stdlib.h>

struct meeting {
	int start;
	int end;
}meeting;

int compare(struct meeting* a,struct meeting* b)
{
	if (a->end > b->end)
	{
		return 1;
	}
	else if (a->end == b->end)
	{
		if (a->start < b->start)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int n;
	int count = 0;
	int end;
	struct meeting* m;

	scanf("%d", &n);
	m = (struct meeting*)malloc(sizeof(struct meeting) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &m[i].start, &m[i].end);
	}

	qsort(m, n, sizeof(struct meeting), compare);

	end = m[0].end;
	count++;
	for (int i = 1; i < n; i++)
	{
		if (m[i].start >= end)
		{
			count++;
			end = m[i].end;
		}
	}

	printf("%d",count);

	return 0;
}