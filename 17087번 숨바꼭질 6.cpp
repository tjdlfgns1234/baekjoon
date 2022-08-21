#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define INF 1000000007
using namespace std;

void solve();
int gcd(int a, int b);

int main(void)
{
	ios::sync_with_stdio(NULL);
	::cout.tie(NULL), cin.tie(NULL);

	solve();

	return 0;
}
void solve() {
	int n, s;
	int ans = 0;
	cin >> n >> s;

	vector<int> a(n);

	for (auto& i: a)
		cin >> i;

	if(n == 1)
		ans = abs(s - a[0]);
	else {
		ans = s - a[0];
		for (int i = 1; i < n; i++) {
			ans = gcd(abs(ans), abs(s - a[i]));
		}
	}

	cout << ans;
	
}
int gcd(int a, int b)
{
	int tmp = a, tmp2 = b;
	while (tmp2 != 0)
	{
		int r = tmp % tmp2;
		tmp = tmp2;
		tmp2 = r;
	}
	return tmp;
}