#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(void)
{
	long long a, b;
	
	scanf("%lld %lld", &a, &b);

	printf("%lld",(a+b)*(abs((a-b))+1)/2);

	return 0;
}