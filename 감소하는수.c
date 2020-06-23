#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1023

long long dp[SIZE];
int count = 10;

int main(void)
{
	int n, num[10] = { 0 };
	long long sum2 = 10, sum=1,tmp=1;
	int check=0,check2=0;
	scanf("%d", &n);
	for (int j = 0; j < 10; j++)
		dp[j] = j;
	if (n == 0)
	{
		printf("0");
		return 0;
	}
	if (n >= 1023)
	{
		printf("-1");
		return 0;
	}
	else if (n == 1022)
	{
		printf("9876543210");
		return 0;
	}
	for (long long i = 10; i <= (long long)987654321; i++)
	{
		num[0] =i % 10;
		for (int j = 1; j < 10; j++)
		{
			sum2 = sum2 * 10;
			sum = sum * 10;
			num[j] = (i%sum2)/sum;
		}

		for (int j =9; j >0; j--)
		{
			if (num[j] != 0)
			{
				check2=j; //자릿수 계산
				break;
			}
		}

		for (int j = 9; j > 0; j--)
		{
			if (num[j] > num[j-1])
			{
				check++;// 감소하는 수인지 값 비교
			}
		}
		

		if (check2 == check)
		{
			if (count <= 1000000)
			{
				dp[count] = i;
				count++;
			}
			else
			{
				break;
			}
		}
		//자릿수를 확인해서 넘어가는 if문
		
		for (int m = check2; m > 0; m--)
		{
			if (num[m] < num[m - 1])
			{
				for (int k = 0; k < m - 1; k++)
				{
					tmp = tmp * 10;
				}
				i += tmp - 1;
				tmp = 1;
			}
		}
		

		check = 0, check2 = 0;
		sum2 = 10, sum = 1;
		for (int j = 0; j < 10; j++)
		{
			num[j] = 0; //자릿수 확인하는 배열 초기화
		}
		if (dp[n] != 0)
		{
			printf("%lld", dp[n]);
			return 0;
		}
	}
	if (n == 0)
	{
		printf("0");
	}
	if (dp[n] != 0)
	{
		printf("%lld", dp[n]);
		return 0;
	}
	else
	{
		printf("-1");
	}
	return 0;
}