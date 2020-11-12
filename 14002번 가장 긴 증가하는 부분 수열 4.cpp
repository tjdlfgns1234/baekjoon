#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int result = -1;
	cin >> n;
	int* arr = new int[n];
	int* dp = new int[n];
	int* bidx = new int[n];
	int idx = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i]; // 입력부분
	for (int i = 0; i < n; i++)
		dp[i] = 0,bidx[i] = -1;  // dp 배열 초기화

	for (int i = 0; i < n; i++)
	{
		if (dp[i] == 0)
			dp[i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i] > arr[j])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1,bidx[i] = j;
		}
	}

	for (int i = 0; i < n; i++)
		if (result < dp[i])
			result = dp[i],idx = i;

	cout << result << "\n";
	stack <int> s;
	while (idx != -1)
	{
		s.push(arr[idx]);
		idx = bidx[idx];
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	

	return 0;
}