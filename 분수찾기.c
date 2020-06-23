#include <stdio.h>

int main(void)
{
	int X,check=0,i,oe=0;
	int sum=0;
	scanf("%d", &X);

	for (i = 1; i < X+1; i++)	//±º¼ö¿­ Ã£±â
	{
		sum += i;
		check = X - sum;
		if (check <= 0)
		{
			break;
		}
	}

	oe = i % 2;	//È¦Â¦ ÆÇº°
	if (oe == 0)	//Â¦¼öÀÏ¶§
	{
		printf("%d/%d", i+check,-check+1);
	}
	else   //È¦¼ö ÀÏ¶§
	{
		printf("%d/%d", -check+1, i+check);
	}

	return 0;
}