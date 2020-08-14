#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PSIZE 10

int check_pelindrome(int n);
int check_prime(int n);
int result;

/*
	1~100만 까지 소수를 찾아 배열에 저장하고
	그중에서 펠린 스롬인 수만 골라서 또 다른 배열에 저장
	n보다 크거나 같은 펠린드롭인 소수를 찾아서 출력
	100만에 가까운 소수 중 펠림드롭 수를 찾아서 마지막 값 해결
*/

int main(void)
{
	int n;
	scanf("%d", &n);

	while (1)
	{
		if (check_prime(n))
		{
			if (check_pelindrome(n))
			{
				printf("%d", result);
				break;
			}
		}
		n++;
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
	result = n;
	return 1;
}
int check_prime(int n)
{
	double to = sqrt(n);
	if (n == 2)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 0;
	}
	
	
	for (int i = 3; i <= to; i=i+2)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	// 여기까지 왔으면 소수이다.
	return 1;
}