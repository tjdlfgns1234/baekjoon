#include <stdio.h>
#include <stdlib.h>

int cal_M(int j,int N);	//분해합을 구하는 함수(각 자리의 수의 합을 계산하고 빼주는 함수)

int main(void)
{
	int N,result=0;
	scanf("%d", &N);

	for (int i = 1; i < N+1; i++)
	{
		result = cal_M(i,N);	// 1부터 N까지 분해합을 구하는 함수를 호출
		if (result != 0)		// 구한 분해합의 값이 0이 아니면 반복문 탈출
			break;
	}

	printf("%d", result);	//결과 출력

	return 0;
}
int cal_M(int j, int N)
{
	int x[7] = { 0 };	//각 자리의 수를 저장하는 배열
	int y = 1000000, i = 6, sum = 0;	//연산을 위한 변수
	int result; //분해합을 저장하는 변수
	for (i = 6; i > -1; i--)  //각 자리수를 계산하여 배열x에 넣어줌
	{
		x[i] = (j % (10 * y) / y);
		y = y / 10;
	}
	for (i = 0; i < 7; i++)	//각 자리수의 합을 계산해줌
	{
		sum = sum + x[i];
	}
	result = j + sum;	//result변수에 분해합을 넣어줌
	if (result == N)
		return j;
	else
		return 0;
}