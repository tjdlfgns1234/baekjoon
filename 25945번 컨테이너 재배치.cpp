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

    int n;
    cin >> n;

    ll ans = 0, sum = 0;

    vector<int> arr(n);
    for (auto& i : arr)
        cin >> i;
    for (auto i : arr)
        sum+= i;
    sort(all(arr), less<>());
    for (int i = 0 ; i < n - (sum%n);i++)
        ans += abs(arr[i] - (sum/n));

    for (int i = n - (sum % n); i < n; i++)
        ans += abs(arr[i] -((sum / n)+1));

    cout << ans / 2;
}