#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007LL
#define all(a) a.begin(),a.end()

using namespace std;

void solve();
void dfs(int start);

vector<int> graph[100001];
bool chk[100001];
int ans[100001];

int main()
{
    ios::sync_with_stdio(NULL);
    cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {

    int n, m, start;
    cin >> n >> m >> start;

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(start);

    for (int i = 1; i < n + 1; i++)
        cout << ans[i] << '\n';

}
void dfs(int start) {
    queue<int> q;
    vector<int>::iterator it;
    int cnt = 2;
    ans[start] = 1;
    chk[start] = true;
    q.push(start);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        sort(all(graph[s]), less<>());
        for (it = graph[s].begin(); it != graph[s].end(); it++)
            if (!chk[*it]) {
                q.push(*it);
                ans[*it] = cnt++;
                chk[*it] = true;
            }
    }
}
