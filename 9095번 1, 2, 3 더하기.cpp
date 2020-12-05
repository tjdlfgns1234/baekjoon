#include <iostream>
#include <algorithm>

using namespace std;

void ans(long long  n);

long long dp[12] = { 0 };

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    long long query;
    for (int i = 0; i < n; i++)
        cin >> query, ans(query);

    return 0;
}
void ans(long long  n)
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    cout << dp[n] << "\n";
}