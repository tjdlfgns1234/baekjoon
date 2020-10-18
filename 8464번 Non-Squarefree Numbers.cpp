#include <algorithm>
#include <iostream>
#define MAX 900000000000
#define SIZE 1000000


// 이진 탐색에서 lower + upper 오버 플로 조심!

using namespace std;
int mobius[SIZE + 1];

long long result(long long n);
long long bisearch(long long n);
void cal_mobius();

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	cal_mobius();
	cout << bisearch(n);;

	return 0;
}
void cal_mobius()	// 뫼비우스 함수 계산
{
	for (int i = 1; i < SIZE + 1; i++)
		mobius[i] = 1;
	for (int i = 2; i * i < SIZE + 1; i++)
	{
		if (mobius[i] == 1)
		{
			for (int j = i; j < SIZE + 1; j += i)
				mobius[j] *= -i;  // 소인수 개수 세기
			for (int j = i * i; j < SIZE + 1; j += i * i)
				mobius[j] = 0; // 제곱수로 나누어 지는 경우
		}
	}
	// 제곱 인자를 갖지 않는 수들에 대해서
	for (int i = 2; i < SIZE + 1; i++)
	{
		if (mobius[i] == i)	// 자기자신
			mobius[i] = 1;
		else if (mobius[i] == -i)	// 자기자신만 소인수로 가지는 경우
			mobius[i] = -1;
		else if (mobius[i] < 0)	// 짝수개의 소인수를 가지는 경우
			mobius[i] = 1;
		else if (mobius[i] > 0) // 홀수개의 소인수를 가지는 경우
			mobius[i] = -1;
	}
}
long long result(long long n) // n이하의 제곱 ㄴㄴ수 계산
{
	long long ans = 0;

	for (long long i = 1; i * i <= n; i++)
		ans += (mobius[i] * (n / (i * i)));

	return ans;
}
long long bisearch(long long n)	// 제곱 ㄴㄴ수가 n개가 되는 수 찾기(이진탐색)
{
	long long lower = 0;
	long long upper = MAX;
	while (lower + 1 < upper)
	{
		long long mid = (lower + upper) / 2;
		if (mid - result(mid) < n)
			lower = mid;
		else
			upper = mid;
	}
	return upper;
}