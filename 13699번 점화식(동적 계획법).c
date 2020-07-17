#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, tmp = 1;;
	long long *dp;

	/* 입력 부분 */
	scanf("%d", &n);
	dp = (long long*)malloc(sizeof(long long) * n + 1);
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = 0;
	}
	/* 알고리즘 부분 */
	dp[0] = 1;
	while (tmp != n + 1)
	{
		if (dp[tmp] == 0)
		{
			dp[tmp] = 0;
			for (int i = 0; i < tmp ; i++)
			{
				dp[tmp] += dp[i] * dp[tmp - i - 1];
			
			}
		}
		tmp++;
	}
	printf("%lld", dp[n]);

	return 0;
}