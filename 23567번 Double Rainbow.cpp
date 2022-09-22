#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

void solve();

int main(void)
{
	ios::sync_with_stdio(NULL);
	::cout.tie(NULL), cin.tie(NULL);

	solve();

	return 0;
}
void solve() {
	int n, k;
	cin >> n >> k;

	vector <int> arr(n), chk(k);
	for (auto& i : arr)
		cin >> i;
	for (auto& i : chk)
		i = 0;
	if (n == 1) {
		cout << 0;
		return;
	}
	if (k == 1) {
		cout << 1;
		return;
	}

	int l = 0, r = 1;
	int num = 0;
	int ans = INT_MAX;

	if (chk[arr[l] - 1] == 0)
		chk[arr[l] - 1]++, num++;
	else
		chk[arr[l] - 1]++;

	if (chk[arr[r] - 1] == 0)
		chk[arr[r] - 1]++, num++;
	else
		chk[arr[r] - 1]++;

	while (1) {
		if (num == k) {
			// 차집합 확인에서 배열 확인
			vector <int> chk2(k);
			int num2 = 0;
			for (auto& i : chk2)
				i = 0;
			int l2 = l - 1, r2 = r + 1;
			for (int i = l2; i >= 0; i--)
				if (chk2[arr[i] - 1] == 0)
					chk2[arr[i] - 1]++, num2++;
				else
					chk2[arr[i] - 1]++;
			for (int i = r2; i < n; i++)
				if (chk2[arr[i] - 1] == 0)
					chk2[arr[i] - 1]++, num2++;
				else
					chk2[arr[i] - 1]++;

			if (num2 == k ) {
				ans = min(r - l + 1, ans);
				chk[arr[l] - 1]--;
				if (chk[arr[l] - 1] == 0)
					num--;
				l++;
				continue;
			}
			else {
				chk[arr[l] - 1]--;
				if (chk[arr[l] - 1] == 0)
					num--;
				l++;
				continue;
			}
		}
		r++;

		if (l >= r || r == n)
			break;

		if (chk[arr[r] - 1] == 0)
			chk[arr[r] - 1]++, num++;
		else
			chk[arr[r] - 1]++;
	}

	if (ans == INT_MAX)
		cout << 0;
	else
		cout << ans;

}