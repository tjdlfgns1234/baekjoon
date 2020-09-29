#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> mapping;

int formula(int n);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	printf("%d", formula(n));

	return 0;
}
int formula(int n)
{
	mapping[1] = 1;
	int sum = mapping[1];

	if (n == 1)
	{
		return 1;
	}

	for (int i = 2; i < n; i++)
	{ 
		mapping[i] = 1 + mapping[i - mapping[mapping[i - 1]]];
		sum += mapping[i];

		if (sum >= n)
			return i;
	}

	return 0;
}