#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int MaximumSubarray(int* arr, int n);

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << MaximumSubarray(arr, n);

	return 0;
}
int MaximumSubarray(int* arr, int n)
{	
	int now = arr[0];
	int end = arr[0];
	int remove = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (end < 0)
			end = arr[i];
		else
			end += arr[i];

		now = max(end, now);
	}

	return now;
}