#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
	int size;
	int index;
	int* item;
};

void push(int num);
void pop();
void size();
void empty();
void top();
struct stack s = { 0,-1,NULL };

int main(void)
{
	int n,tmp;
	char oper[6] = { NULL };
	scanf("%d", &n);
	s.item = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", oper);
		if (strcmp(oper, "push") == 0)
		{
			scanf("%d", &tmp);
			push(tmp);
		}
		else if (strcmp(oper, "pop") == 0)
		{
			pop();
		}
		else if (strcmp(oper, "size") == 0)
		{
			size();
		}
		else if (strcmp(oper, "empty") == 0)
		{
			empty();
		}
		else if (strcmp(oper, "top") == 0)
		{
			top();
		}
	}

	return 0;
}
void push(int num)
{
	s.index++;
	s.item[s.index] = num;
	s.size++;
}
void pop()
{
	if (s.index != -1)
	{
		printf("%d\n", s.item[s.index]);
		s.item[s.index] = -1;
		s.index--;
		s.size--;
	}
	else
	{
		printf("-1\n");
	}
}
void size()
{
	printf("%d\n",s.size);
}
void empty()
{
	if (s.index == -1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}
void top()
{
	if (s.index == s.size-1&&s.index!=-1)
	{
		printf("%d\n", s.item[s.index]);
	}
	else
	{
		printf("-1\n");
	}
	
}