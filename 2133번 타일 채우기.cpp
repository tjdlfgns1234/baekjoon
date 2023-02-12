#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define INF 100000007
#define SIZE 9
#define all(a) a.begin(),a.end()

// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.

using namespace std;
void solve();

ll pow2(ll a,ll b) {
    ll sum = 1;
    while (b--) {
        sum*= a;
    }
    return sum;
}


int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    ll n;
    cin >> n;

    ll dp[31] = { 0, 0,3 };
    
    for (int i = 4; i < 31; i += 2) {
        dp[i] = dp[i - 2] * 3 + 2;
        for (int j = i-4; j >= 2; j -= 2) {
            dp[i] += dp[j]*2;
        }
    }

    if (n & 1)
        cout << 0;
    else
        cout << dp[n];
}