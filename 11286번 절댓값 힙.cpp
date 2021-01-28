#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	priority_queue<int, vector<int>,greater<int>> pos;
	priority_queue<int, vector<int>, less<int>>neg;
	while (t--)
	{
		int x;
		cin >> x;

		
		if(x==0)
		{
			if (pos.empty())
				if (neg.empty())
					cout << 0 << "\n";
				else
					cout << neg.top() << "\n", neg.pop();
			else
				if (neg.empty())
					cout << pos.top() << "\n", pos.pop();
				else
					if (-neg.top() <= pos.top())
						cout << neg.top() << "\n", neg.pop();
					else
						cout << pos.top() << "\n", pos.pop();
		}
		else
		{
			if (x < 0)
				neg.push(x);
			else
				pos.push(x);
		}
	}

	return 0;
}