#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


vector<int> result;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	int sum = 0;
	int result =1;
	string buf, buf2;
	cin >> n;

	for (int j = 0; j < n; j++)
	{
		unordered_map<string, int> mp;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> buf;
			cin >> buf2;
			if (mp.find(buf2) != mp.end())
			{
				++mp.find(buf2)->second;
			}
			else
			{
				mp.insert(make_pair(buf2, 1));
			}
		}
		unordered_map<string, int>::iterator iter;
		for (iter = mp.begin(); iter != mp.end(); iter++)
		{
			result *= (iter->second + 1);
		}
		cout << result -1 <<"\n";
		result = 1;
		mp.clear();
	}
	return 0;
}