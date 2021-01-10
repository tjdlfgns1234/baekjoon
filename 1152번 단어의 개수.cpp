#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[1000001];

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	fgets(s,1000000,stdin);
	int ans = 0;
	bool chk = false;
	int idx = 0;
	while (1)
	{
		if (s[idx] == '\0')
			break;

		if (s[idx] != ' ' && s[idx] != '\n')
			if (!chk) // 이전이 공백이었으면
				ans++, chk = true;
			else
				chk = true;
		else
			chk = false;
		idx++;
	}

	cout << ans;

	return 0;
}