#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

// Beware of MAX & MIN value!

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	int MAX[3] = { 0 };
	int MIN[3] = { 0 };
	int tmp[3] = { 0 };
	int tmp2[3] = { 0 };

	while (n--)
	{
		for (int i = 0; i < 3; i++)
			cin >> tmp[i];

		tmp2[0] = tmp[0] + max(MAX[0], MAX[1]);
		tmp2[1] = tmp[1] + max(max(MAX[0], MAX[1]), MAX[2]);
		tmp2[2] = tmp[2] + max(MAX[1], MAX[2]);

		MAX[0] = tmp2[0];
		MAX[1] = tmp2[1];
		MAX[2] = tmp2[2];

		tmp2[0] = tmp[0] + min(MIN[0], MIN[1]);
		tmp2[1] = tmp[1] + min(min(MIN[0], MIN[1]), MIN[2]);
		tmp2[2] = tmp[2] + min(MIN[1], MIN[2]);

		MIN[0] = tmp2[0];
		MIN[1] = tmp2[1];
		MIN[2] = tmp2[2];
	}
	
	cout << max(max(MAX[0], MAX[1]), MAX[2]) << ' ';
	cout << min(min(MIN[0], MIN[1]), MIN[2]);
	

	return 0;
}