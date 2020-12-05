#include <iostream>
#include <algorithm>
#define SIZE 50000

using namespace std;
int dp[SIZE + 1] = { 0 };
int square[224] = { 0 };

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < SIZE + 1; i++)
        dp[i] = i;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);

    cout << dp[n];
    return 0;
}