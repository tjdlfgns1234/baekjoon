#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	int one=0, two=0;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == 1)
			one++;
		else
			two++;
	}
	if (one < two)
		cout << "Junhee is not cute!";
	else
		cout << "Junhee is cute!";

	return 0;
}