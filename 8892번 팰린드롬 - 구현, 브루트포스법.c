#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

void palindrome();		 //펠린드롭을 구해주는 함수 (O(n^2))
char buffer[101][SIZE+1];	 //문자열을 저장할 배열 선언

int main(void)
{
	int t;	// t : 테스트 케이스를 저장하는 변수
	scanf("%d", &t);
	for(int i = 0 ; i<t;i++)	// 테스트 케이스 만큼 펠린드롬 함수 호출
		palindrome();

	return 0;
}
void palindrome()
{
	int n;	// n : 문자의 개수
	int size;	// buffer의 크기
	int check = 0;	//펠린드롭은 찾았는지 확인하는 변수
	char temp[SIZE + 1];	// 문자열을 합친것을 임시로 저장하는 변수
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &buffer[i][0]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// 뒤에 문자열 붙이기
			strcpy(temp, &buffer[i][0]);
			strcat(temp, &buffer[j][0]);
			size = strlen(temp);
			check = 0;
			for (int k = 0; k < size; k++)
			{
				if (temp[k] != temp[size - k - 1])
				{
					check = 1;	//펠린드롭이 아니면
					break;	//for문 탈출
				}
			}
			if (check == 0)	//펠린드롭이면 출력하고 탈출
			{
				printf("%s\n", temp);
				return;
			}
		}
		for (int j = i + 1; j < n; j++)
		{
			// 앞에 문자열 붙이기
			strcpy(temp, &buffer[j][0]);
			strcat(temp, &buffer[i][0]);
			size = strlen(temp);
			check = 0;
			for (int k = 0; k < size; k++)
			{
				if (temp[k] != temp[size - k - 1])
				{
					check = 1;	//펠린드롭이 아니면
					break;	//for문 탈출
				}
			}
			if (check == 0)//펠린드롭이면 출력하고 함수 종료
			{
				printf("%s\n", temp);
				return;
			}
		}
	}
	// 여기까지 왔으면 펠린드롭을 만들수 있는 조합이 없다.
	printf("0\n");	//따라서 0 출력
}