#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input[3];
	int tmp[3] = { 0 }, tmp4 = 0;
	int check = 0;
	for(;;)
	{
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		if (input[0] == 0 && input[1] == 0 && input[2] == 0)
		{
			break;
		}
		check = 0;
		tmp[0] = input[0] * input[0] + input[1] * input[1];
		tmp[1] = input[2] * input[2] + input[1] * input[1];
		tmp[2] = input[0] * input[0] + input[2] * input[2];

		for (int i = 0; i < 3; i++)
		{
			tmp4 = input[i] * input[i];
			for (int j = 0; j < 3; j++)
			{
				if (tmp[j] == tmp4)
				{
					check = 1;
				}
			}
		}
		if (check == 0)
		{
			printf("wrong\n");
		}
		else if(check==1)
		{
			printf("right\n");
		}
	}

	return 0;
}