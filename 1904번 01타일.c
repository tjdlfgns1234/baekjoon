#include <stdio.h>
#include <stdlib.h>

int dp[1000000] = { 1,2,3,5 };
void formula(int n);

int main(void)
{
	int n;
	scanf("%d", &n);

	formula(n);

	return 0;
}
void formula(int n)
{
	if (dp[n - 1] == 0)
	{
		for (int i = 4; i < n; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2])%15746;
		}
		printf("%d\n", dp[n - 1]);
		return;
	}
	printf("%d\n", dp[n - 1]);
	return;
}