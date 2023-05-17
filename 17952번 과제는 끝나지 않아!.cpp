#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define mod 1000000007

// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.
// 배운거 내에서만 쓸 생각을 하자. 
// 평소 연습했던 대로!
// 행렬을 배열로도 쓸 생각하자
// 급하기 풀지 말자

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

    // 과제가 최근에 나온 순서대로하고 과제를 받으면 바로 시작한다.
    // 과제를 하던 도중 새로운 과제가 나온다면, 하던 과제를 중단하고 새로운 과제를 진행한다.
    // 새로운 과제가 끝났다면, 이전에 하던 과제를 바로 이어서함.(패널티 X)

    stack <pii> s;
    int flag, a=0, t=0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> flag;

        if (flag) { // 과제 가 나온다면
            cin >> a >> t;
            if (--t == 0)
                ans += a;
            else 
                s.push({ a,t });
            
        }
        else {
            if (!s.empty()) {
                if (--s.top().second == 0)
                    ans += s.top().first, s.pop();
            }
        }
    }
    cout << ans;

}