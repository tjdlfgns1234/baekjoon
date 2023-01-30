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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector <int> cost(n + 1);
    vector<int> ans(n+1);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue <int> q;
    for (int i = 1; i < n + 1; i++) {
        q.push( i );
        bool* chk = new bool[n + 1];
        for (int j = 0; j < n+1; j++)
            chk[j] = false, cost[j] = INF;
        cost[i] = 0;
        while (!q.empty()) {
            int src = q.front();
            if (!chk[src])
                chk[src] = true;
            else {
                q.pop();
                continue;
            }
            q.pop();
            for (int j = 0; j < graph[src].size(); j++) {
                int dest = graph[src][j];
                if (cost[dest] > cost[src] + 1) {
                    cost[dest] = cost[src] + 1;
                    q.push(dest);
                }
            }
        }
        for (int j =1; j < n+1; j++)
            if(cost[j]!= INF)
              ans[i] +=  cost[j];
    }
    int idx = 1;
    int tmp = ans[1];
    for (int i = 2; i < n+1; i++) {
        if (tmp > ans[i])
            tmp = ans[i], idx = i;
    }
    cout << idx;
}