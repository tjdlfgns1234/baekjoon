#include <stdio.h>
#include <stdlib.h>
#define PSIZE 10

int check_doom(int n);

int main(void)
{
	int n;
	int count = 1;
	int tmp = 1665;
	scanf("%d", &n);

	if (n == 1)
	{
		printf("666");
		return 0;
	}
		
	while (1)
	{
		tmp++;
		if (check_doom(tmp))
			count++;
		if (n == count)
			break;
	}
	printf("%d", tmp);


	return 0;
}
int check_doom(int n)
{
	int place[PSIZE] = { 0 };
	int tmp = 1, tmp2 = 10;
	int count = 0;	// 자릿수를 저장하는 변수
	int cnt = 0;
	for (int i = 0; i < PSIZE; i++)
	{
		place[i] = (n % tmp2) / tmp;
		tmp *= 10, tmp2 *= 10;
	}

	for (int i = PSIZE - 1; i > 0; i--)	//자릿수 확인
	{
		if (place[i] != 0)
		{
			count = i;
			break;
		}
	}

	for (int i = 0; i < count -1; i++)
	{
		if(place[i] == 6 && place[i+1] == 6 && place[i+2]== 6)
		{
			cnt++;
			break;
		}

	}

	if (cnt)
		return 1;
	else
		return 0;
}