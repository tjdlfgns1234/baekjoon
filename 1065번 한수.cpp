#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define mod 1000000007

// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.
// 우선순위 큐에 무엇을 넣을지도 잘 생각하자.
// 큐 쓰는 것도 좋았지만, 최적화는 잘해주자.
// 행렬을 배열로도 쓸 생각하자

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();

int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n;
    cin >> n;

    // 한수의 개수  총 한수는 144

    int arr[45] = { 111,123,135,147,159,
        210,222,234,246,258,
        321,333,345,357,369,
        420,432,444,456,468,
        531,543,555,567,579,
        630,642,654,666,678,
        741,753,765,777,789,
        840,852,864,876,888,
        951,963,975,987,999
    };

    int ans = 99;
    if (n < 100)  // 2자리는 모두 한수
        cout <<  n ;
    else {
        for (int i = 0; i < 45; i++)
            if (arr[i] <= n)
                ans++;
            else
                break;
        cout << ans;
    }
}