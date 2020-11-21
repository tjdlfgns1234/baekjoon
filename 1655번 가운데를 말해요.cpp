#include <iostream>
#include <algorithm>
#include <queue>
#define SIZE 100000

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	priority_queue <int, vector<int>, greater<int>>low;
	priority_queue <int, vector<int>, less<int>>upper;
	int n;
	cin >> n;
	int query;

	for (int i = 0; i < n; i++)
	{
		cin >> query;
		if (low.size() < upper.size())
			low.push(query);
		else
			upper.push(query);

		if (!low.empty() && !upper.empty())
			if (upper.top() > low.top())
			{
				int tmp = upper.top();
				int tmp2 = low.top();
				upper.pop(),low.pop();
				low.push(tmp),upper.push(tmp2);
			}
		cout << upper.top() << "\n";
	}

	return 0;
}