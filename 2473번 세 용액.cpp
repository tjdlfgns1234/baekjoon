#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define INF 100000007
#define all(a) a.begin(),a.end()

// beware of min & max value;
// 실수 연산은 정수연산보다 한참 느리다는 것을 기억하자
// 왠만하면 자료형은 적재적소에 맞추는게 기본!

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

    vector<ll> arr(n);
    for (auto& i : arr)
        cin >> i;

    sort(all(arr));

    ll value = 3000000000ll;
    vector <ll> ans(3);
    ll sum = 0;


    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1; // 가장 작은 값과 큰 값에서 시작

        while (left < right) {
            ll sum = arr[left] + arr[right] + arr[i];

            
            if (left != i && right != i) {
                if (abs(sum) < abs(value)) {
                    value = sum;
                    ans[0] = arr[left], ans[1] = arr[right], ans[2] = arr[i];
                }
            }

            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else
                break;

        }
    }

    sort(all(ans));
    cout << ans[0] << " " << ans[1] << " " << ans[2];

}