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
struct stack s = { 0,-1,NULL };

int main(void)
{
	int k,tmp;
	long int sum = 0;
	scanf("%d", &k);
	s.item = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &tmp);
		if (tmp == 0)
		{
			pop();
		}
		else
		{
			push(tmp);
		}
	}
	for (int i = 0; i < s.size; i++)
	{
		sum += s.item[i];
	}
	printf("%d", sum);
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
	s.item[s.index] = -1;
	s.index--;
	s.size--;
}