#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int* arr;	// n층
	int* arr2;	// n+1층
	int size = 2;
	int max = -1;
	cin >> n;
	arr = new int[n];
	arr2 = new int[n];

	cin >> arr[0];
	while (size != n + 1)
	{
		for (int i = 0; i < size; i++)
		{
			cin >> arr2[i];
		}

		if (size != 2)
		{
			for (int i = 0; i < size - 2; i++)
			{
				if (arr[i] > arr[i + 1])
					arr2[i + 1] += arr[i];
				else
					arr2[i + 1] += arr[i + 1];
			}
			arr2[0] += arr[0];
			arr2[size - 1] += arr[size - 2];
		}
		else
			arr2[0] += arr[0], arr2[1] += arr[0];

		for (int i = 0; i < size; i++)
		{
			arr[i] = arr2[i];
		}
		size++;
	}
	for (int i = 0; i < n; i++)
		if (arr2[i] > max)
			max = arr2[i];

	cout << max;

	return 0;
}