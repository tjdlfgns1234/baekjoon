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
    int t;
    cin >> t;

    while (t--) {
        int n, k,w;
        cin >> n >> k;

        // w를 건설완료 하는데 드는 최소시간

        vector<int> cost(n+1);
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1);
        vector<int> ans(n + 1);
        for (int i = 1; i < n + 1;i++) cin >> cost[i];

        int x, y; // 우선순위 
        for (int i = 1; i < k + 1; i++) {
            cin >> x >> y;
            graph[x].push_back(y), indegree[y]++;
        }

        cin >> w;

        queue <int> q; // 가장 하위 건물 집합

        for (int i = 1; i < n + 1; i++)  // indegree 가 0인 집합
            if (indegree[i] == 0)
                q.push(i);


        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ans[now] += cost[now];
            for (auto i : graph[now]) {
                indegree[i]--;
                ans[i] = max(ans[now],ans[i]);
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        cout << ans[w] << '\n';
    }
}