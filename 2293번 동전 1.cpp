#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007LL
#define all(a) a.begin(),a.end()

// Beware of min & max Value;

using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(NULL);
    cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n, k;
    cin >> n >> k;

    int coin;
    vector<int> dp(k + 1);

    // 가치의 합은 1만, 동전의 최댓값은 10만
    // 1만 초과의 동전은 무시

    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        cin >> coin;
        for (int i = 1; i < k + 1; i++) {
            if (i >= coin)
                dp[i] += dp[i - coin];
        }
    }

    cout << dp[k];
}