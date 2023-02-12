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
// 상수 시간 복잡도도 무시하지말자.
// 시작점과 도착점을 거꾸로 하는 아이디어 고려할 것
// 매개변수를 멀로 설정할지 잘 생각하기
// 상황을 되고 안되고 2가지로 나누어 생각하기

using namespace std;
void solve();

int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n, c;
    cin >> n >> c;

    vector<ll> arr(n); // 집

    for (auto& i : arr)
        cin >> i;  
    sort(all(arr));

    ll ans = 0;

    ll right = 1000000000, left = 0;

  

    while (left <= right) {
        ll mid = (right + left)/2;

        ll a = 1; // 현재 공유기 설치 개수
        ll sum = 0; // 현재 거리

        // 공유기가 거리안에 설치되는지 판정
        for (int i = 1; i < n; i++) {
            sum += arr[i] - arr[i - 1];
            if (sum >= mid)
                a++, sum = 0;
        }

        //cout << left << " " << mid << " " << right << '\n';

        if (a >= c) {
            ans = max(ans, mid);
            left = mid+1;
        }
        else if (a < c)
            right = mid-1;
    }
    cout << ans;
}