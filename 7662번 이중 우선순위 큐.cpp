#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		map<int, int> mp;
		map<int, int>::iterator it;
		map<int, int>::reverse_iterator reit;
		int k;
		cin >> k;
		char op;
		int n;
		for (int i = 0; i < k; i++)
		{
			cin >> op >> n;
			if (op == 'I')
				if (mp.count(n) == 0)
					mp.insert({ n,1 });
				else
					mp.find(n)->second++;
			else if (op == 'D')
			{
				if (!mp.empty())
				{
					it = mp.begin();
					reit = mp.rbegin();
					if (n == -1) // erase min
					{

						it->second--;
						if (it->second == 0)
							mp.erase(it->first);
					}
					else if (n == 1) // erase max
					{

						reit->second--;
						if (reit->second == 0)
							mp.erase(reit->first);

					}
				}
			}
		}
		it = mp.begin();
		reit = mp.rbegin();
		if (!mp.empty())
			cout << reit->first << ' ' << it->first<< '\n';
		else
			cout << "EMPTY" << "\n";
	}
	return 0;
}