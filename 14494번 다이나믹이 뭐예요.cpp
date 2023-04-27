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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, (vector<int>(m, 0)));

    for (int i = 0; i < m; i++)
        arr[0][i] = 1;
    for(int i = 0; i < n;i++)
        arr[i][0] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            arr[i][j] = (arr[i - 1][j - 1] +( arr[i - 1][j] + arr[i][j - 1])%mod)%mod;

    cout << arr[n - 1][m - 1];
}     