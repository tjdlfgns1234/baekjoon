#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

int ctoi(char s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s;
	int ans = 0;
	int tmp = 1;
	reverse(all(s));
	for (auto i : s)
		ans += ctoi(i)*tmp,tmp*=16;
	cout << ans;

	return 0;
}
int ctoi(char s)
{
	if ((s - '0') < 10)
		return s - '0';
	else
		return (s - '@') + 9;
}