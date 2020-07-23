#include <stdio.h>
#include <stdlib.h>

void n_queen(int n, int queen);	// n_queen 함수
int count;					// count 선언
int* board;					// 체스판 선언

int main(void)
{
	int n;	// n을 저장하는 변수
	
	scanf("%d", &n);	// 입력 받은 n을 변수에 저장
	board = (int*)calloc(n, sizeof(int));	// board에 n만큼 동적할당
	n_queen(n,0);	// n_queen 함수 호출

	printf("%d", count);	// 결과 출력

	return 0;
}
void n_queen(int n, int queen)
{
	int check; // 퀸이 배치가 가능한지 확인하는 플래그

	if(queen == n)	// 퀸의 갯수가 n개일때 정답이므로
	{
		count++;	// 경우의 수 증가
		return;		// 함수 종료
	}

	for (int i = 0; i < n; i++)
	{
		check = 1;	
		for (int j = 0; j < queen; j++) // for문의 j가 열을 확인해줌
		{
			// 이전 퀸 배치를 통해 설치 가능한지 확인 (제약 조건 부분)
			if (board[j] == i || abs(queen - j) == abs(i - board[j])) 
			{
				//  같은 행에 퀸이 위치하거나 대각선에 퀸이 존재할 경우
				check = 0;
				break;
			}
		}
		if (check == 1)	// 퀸이 서로 공격할 수 없을때(제약 조건을 만족할 때)
		{
			board[queen] = i;	   // i번째 위치에 퀸 배치
			n_queen(n, queen + 1); // 재귀 구조로 백트래킹 구현
		}
	}
	return;
}