#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> ans;
	queue <int> q;
	for (int i = 1; i< n+1; i++) 
		q.push(i);
	
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		ans.push_back(q.front());
		q.pop();
	}


	int size = ans.size();
	cout << "<";
	for (int i = 0; i < size - 1; i++)
		cout << ans[i] << ", ";
	cout << ans[size - 1];
	cout << ">";

	return 0;
}