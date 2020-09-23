#include <stdio.h>
#include <stdlib.h>
#define SIZE 69

int main(void)
{
	int t;
	int n;
	long long dp[SIZE + 1] = { 1,1,2,4 };

	scanf("%d", &t);

	for (int i = 4; i < SIZE+1; i++)
	{
		dp[i] = dp[i - 1] + dp[ i - 2 ]+dp[i - 3] + dp[i - 4];
	}
	
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}