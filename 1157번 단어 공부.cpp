#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	string s;
	cin >> s;

	map <char, int> mp;

	int size = s.length();
	for (int i=0;i<size;i++)
		if (islower(s[i]))
			s[i] = toupper(s[i]);

	for (int i = 0; i < size; i++)
		if (mp.count(s[i]) == 0)
			mp.insert({ s[i],1 });
		else
			mp.find(s[i])->second++;

	map <char, int> ::iterator it;
	int max = 0;
	bool chk = false;
	char ans;
	for (it = mp.begin(); it != mp.end(); it++)
		if (it->second > max)
			max = it->second,chk = false,ans = it->first;
		else if (it->second == max)
			chk = true;

	if (chk)
		cout << '?';
	else
		cout << ans;

	return 0;
}