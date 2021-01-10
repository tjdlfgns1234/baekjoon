#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[26] = { 0 };

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	string s;
	cin >> s;
	
	int n = s.length();
	for (int i = 0;i<26;i++)
		arr[i] = -1;

	for (int i = 0; i < n; i++)
		if(arr[s[i] - 'a']==-1)
			arr[s[i] - 'a'] = i;

	for (auto i : arr)
		cout << i << ' ';

	return 0;
}