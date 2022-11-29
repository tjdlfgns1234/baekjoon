#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007LL
#define INF 1234567890
#define all(a) a.begin(),a.end()

// Beware of min & max Value;
// Always Think Edge & Coner case;

// 1. 중복 조합
// 2. 각각의 자릿수 기준으로 계산
// 공통적으로 하위문제의 답으로 상위문제의 답을 찾아냄.


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
    int n;
    cin >> n;

    vector <int> dp(10);
    dp[0]=1;

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < 10; j++) {
            dp[j] = (dp[j] + dp[j - 1])%10007;
        }
    }
    int ans= 0;
    for (auto i : dp)
        ans+=i;
    cout << ans % 10007;
}