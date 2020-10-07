#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector <string> mp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string buf;

	int n;
	int in=0, de=0;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> buf, mp.push_back(buf);

	for (int i = 0; i < n-1; i++)
		if (mp[i] < mp[i+1])
			in++;
		else if (mp[i] > mp[i + 1])
			de++;

	if (in == n - 1)
		cout << "INCREASING";
	else if (de == n - 1)
		cout << "DECREASING";
	else
		cout << "NEITHER";


	return 0;
}