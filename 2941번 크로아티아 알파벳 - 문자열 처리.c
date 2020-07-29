#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void croatia_alpha(char* buffer);	// 크로아티아 알파벳을 찾는 함수

int main(void)
{
	char buffer[SIZE + 1];	// 버퍼
	scanf("%s", buffer);	// 버퍼에 글자 입력후 저장
	croatia_alpha(buffer);	// 크로아티아 알파벳 함수 호출

	return 0;	// 종료
}
void croatia_alpha(char* buffer)
{
	int count = 0;	// count : 갯수를 세는 변수
	int size = strlen(buffer);	// size : buffer에 담겨있는 문자열 길이
	for (int i = 0; i < size; i++)
	{
		// strncmp(str1, str2, MAXCOUNT)
		// st1과 str2가 MAXCOUNT번째 까지 같은지 확인해주는 함수
		if (!strncmp(buffer + i, "c=", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "c-", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "d-", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "lj", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "nj", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "s=", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "dz=", 3))
		{
			// dz=이 찾아지면 z=도 검색될것이기 때문에 count++만 해줌
			count++;
		}
		if (!strncmp(buffer + i, "z=", 2))
		{
			count++;
		}
	}
	printf("%d", size-count);	// 결과 출력
}