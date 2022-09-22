#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

/*    
*  문제 풀때 Edge Case 생각 잘하기
*  시간복잡도 증명은 좋았으나 가장 간단한 경우인
* n = 1인 경우와 n = k+1로 확장하는 부분에서 실수가
* 있었고, continue문의 의미를 생각못하는 실수가 있었다.
*/
void solve();

int main(void)
{
	ios::sync_with_stdio(NULL);
	::cout.tie(NULL), ::cin.tie(NULL);

	solve();

	return 0;
}
void solve() {
	int n, k;
	cin >> n >> k;

	vector <int> arr(n), chk(k+1);
	for (auto& i : arr)
		cin >> i;
	for (auto& i : chk)
		i = 0;

	if (n == 1) {
		cout << 0;
		return;
	}
	else if (k == 1) {
		cout << 1;
		return;
	}

	int l = 0, r = 1;
	int num = 0;
	int ans = INT_MAX;

	if (chk[arr[l]] == 0)
		chk[arr[l]]++, num++;
	else
		chk[arr[l]]++;

	if (chk[arr[r]] == 0)
		chk[arr[r]]++, num++;
	else
		chk[arr[r]]++;

	while (1) {
		if (num == k) {
			// 여집합 확인에서 배열 확인
			vector <int> chk2(k+1);
			int num2 = 0;
			for (auto& i : chk2)
				i = 0;
			int l2 = l - 1, r2 = r + 1;
			for (int i = l2; i >= 0; i--)
				if (chk2[arr[i]] == 0)
					chk2[arr[i]]++, num2++;
				else
					chk2[arr[i]]++;
			for (int i = r2; i < n; i++)
				if (chk2[arr[i]] == 0)
					chk2[arr[i]]++, num2++;
				else
					chk2[arr[i]]++;
			// 여집합에 색이 다 있을 경우
			if (num2 == k ) {
				ans = min(r - l + 1, ans);
				chk[arr[l]]--;
				if (chk[arr[l]] == 0)
					num--;
				l++;
				continue;
			}
			else {
				chk[arr[l]]--;
				if (chk[arr[l]] == 0)
					num--;
				l++;
				continue;
			}
		}
		r++;

		if (l >= r || r == n)
			break;

		if (chk[arr[r]] == 0)
			chk[arr[r]]++, num++;
		else
			chk[arr[r]]++;
	}

	if (ans == INT_MAX)
		cout << 0;
	else
		cout << ans;
}