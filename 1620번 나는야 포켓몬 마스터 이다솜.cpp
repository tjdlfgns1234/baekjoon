#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
map<string, string> mp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string buffer;
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> buffer;
		mp.insert(make_pair(buffer, to_string(i)));
		mp.insert(make_pair(to_string(i), buffer));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> buffer;
		cout << mp[buffer] << "\n";
	}


	return 0;
}