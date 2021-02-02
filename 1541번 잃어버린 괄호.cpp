#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	char s[51];
	cin >> s;
	char buf[6];
	// Greedy : -가 나오면 다음 -기호가 나올때 까지 음수로 집어넣으면 됨.
	int n = strlen(s);
	int idx = 0;
	int ans = 0;
	bool chk = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '-')
		{
			buf[idx] = NULL;
			if (chk)
				ans += -atoi(buf);
			else
				ans += atoi(buf);
			chk = true;
			idx = 0;
			
		}
		else if (s[i] == '+')
		{
			buf[idx] = NULL;
			if (chk)
				ans += -atoi(buf);
			else
				ans += atoi(buf);
			idx = 0;
		}
		else
			buf[idx] = s[i],idx++;
	}
	buf[idx] = NULL;
	if (chk)
		ans += -atoi(buf);
	else
		ans += atoi(buf);

	cout << ans;

	return 0;
}