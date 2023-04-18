#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()

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
    int n, l;
    cin >> n >> l;

    int d, r, g;
    cin >> d >> r >> g;

    int ans = 0;
    int q = 0;
    for (int i = 1; i < l; i++) {
        if (i == d) { // 신호등을 만나면
            int cycle = ans % (r + g);
            if (cycle <= r && cycle >=0) // 빨간불 인지 확인
                ans += r - cycle; // 빨간불이면 기다림
            q++;
            if(q != n)
                 cin >> d >> r >> g;
        }
        ans++;
    }
    cout << ans;

}