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
		string s1,s2;
		cin >> s1>>s2;
		int ans=0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
				ans++;
		}
		cout << "Hamming distance is " << ans << '.' << '\n';
	}

	return 0;
}