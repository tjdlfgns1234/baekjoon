#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	stack <int>s;
	vector <char> ans;
	int* arr = new int[n];
	for(int i = 0 ; i < n;i++)
		cin >> arr[i];
	int j = 0;
	for (int i = 1; i <= n; i++)
	{
		s.push(i);
		ans.push_back('+');

		while (!s.empty())
		{
			if (s.top() == arr[j])
			{
				s.pop();
				ans.push_back('-');
				j++;
			}
			else
				break;
		}
	}

	if (!s.empty())
		cout << "NO";
	else
		for (auto i : ans)
			cout << i << '\n';

	return 0;
}
