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
ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c);
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

    vector <pair<ll, ll>> arr(n);


    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        arr[i].first = x, arr[i].second = y;
    }

    double ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans += ccw(arr[0], arr[i], arr[i + 1]) / (double)2;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans); // 방향값을 가지므로 절댓값
}
ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll tmp = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
    ll tmp2 = (b.first * a.second) + (c.first * b.second) + (a.first * c.second);
    return tmp - tmp2;
}