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
    int n, b, a;
    cin >> n >> b >> a;

    vector<int> arr(n);
    vector<bool> chk(n);
    for (auto& i : arr) { cin >> i; }

    int cnt = 0;
    int ans = 0;
    int cur = 0;
    sort(all(arr));

    if (a == 0)
    {
        for (int i = 0; i < n; i++) {
            if (cur + arr[i] <= b)
                cur += arr[i], ans++;
        }
        cout << ans;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cur + arr[i] / 2 <= b)
            cur += arr[i] / 2, ans++;
    }
    int left = 0, right = ans-1;
    cnt = ans;
    while(1){
        if (left >= right)
            break;
        if (cnt > a) {
            if (cur + arr[left] / 2 <= b) {
                cur += arr[left] / 2;
                cnt--, left++;
            }
            else {
                cur -= arr[right]/2;
                ans--, right--, cnt--;
            }
        }
        else
            break;
    }

    cout << ans;
}