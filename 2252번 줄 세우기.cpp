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
    int n, m;
    cin >> n >> m;
    // 학생들의 번호는 1번부터 N번이다.

    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1);
    
    int a, b;
    for (int i = 0; i < m; i++) {       
        cin >> a >> b;
        graph[a].push_back(b), indegree[b]++; // BFS와 동일
    }

    queue<int> q;
    
    for (int i = 1; i < n + 1; i++) 
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << ' ';
        for (auto i : graph[now]) {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

}
