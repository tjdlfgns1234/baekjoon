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

void dfs(vector<int> arr, int sum);
int ans = 0;

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

    vector<int> arr(n);
    for (auto& i : arr)cin >> i;
    
    dfs(arr, 0);
    cout << ans;
}
void dfs(vector<int> arr, int sum) {
    ans = max(ans, sum);
    for (int i = 1; i < arr.size()-1; i++) {
        vector<int> tmp = arr;
        tmp.erase(tmp.begin() + i);
        dfs(tmp, sum + arr[i - 1] * arr[i + 1]);
    }
}