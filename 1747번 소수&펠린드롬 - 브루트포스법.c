#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PSIZE 10

int check_pelindrome(int n);
int check_prime(int n);
int result;

/*
	1~100�� ���� �Ҽ��� ã�� �迭�� �����ϰ�
	���߿��� �縰 ������ ���� ��� �� �ٸ� �迭�� ����
	n���� ũ�ų� ���� �縰����� �Ҽ��� ã�Ƽ� ���
	100���� ����� �Ҽ� �� �縲��� ���� ã�Ƽ� ������ �� �ذ�
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
	int count = 0;	// �ڸ����� �����ϴ� ����
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
	// ���� ���� ������ �縰��� ��
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
	// ������� ������ �Ҽ��̴�.
	return 1;
}