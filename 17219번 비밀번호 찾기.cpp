#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<string, string> mp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string buf, buf2,buf3;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> buf >> buf2;
		mp.insert(make_pair(buf, buf2));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> buf3;
		cout << mp[buf3] << "\n";
	}

	return 0;
}