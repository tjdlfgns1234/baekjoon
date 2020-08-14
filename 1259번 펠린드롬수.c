#include <stdio.h>
#include <stdlib.h>
#define PSIZE 5

int check_pelindrome(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	while (n!=0)
	{
		if (check_pelindrome(n))
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
		scanf("%d", &n);
	}
	return 0;
}
int check_pelindrome(int n)
{
	int place[PSIZE] = { 0 };
	int tmp = 1, tmp2 = 10;
	int count = 0;	// 자릿수를 저장하는 변수
	for (int i = 0; i < PSIZE; i++)
	{
		place[i] = (n%tmp2)/tmp;
		tmp *= 10, tmp2 *= 10;
	}

	for (int i = PSIZE - 1; i > 0; i--)
	{
		if (place[i] != 0)
		{
			count = i;
			break;
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (place[count - i] != place[i])
		{
			return 0;
		}

	}
	// 여기 까지 왔으면 펠린드롬 수
	return 1;
}