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

using namespace std;
void solve();
struct pi {
    int x, y, flag, cost;
};

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


    vector<string> arr(n);
    int** dp = new int* [n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool** chk = new bool* [n];
    for (int i = 0; i < n; i++)
        chk[i] = new bool[m],dp[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            chk[i][j] = false, dp[i][j] = -1;

    int ans = INF;
    queue<pi> q; // 부실수 있는 벽, 현재 좌표
    // 먼저 도달하면 무조건 최단거리임이 보장됨.(BFS이기 떄문)
    // 도착점과 시작점에서 각벽까지 거리를 계산하자.

    pi s;
    s.x = 0;
    s.y = 0;
    s.cost = 0;
    s.flag = 1;

    q.push(s);

    while (!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        int nflag = q.front().flag;
        int ncost = q.front().cost;
        pi tmp;

        q.pop();
        if (chk[nx][ny])
            continue;
  
        chk[nx][ny] = true;

        if (nx == n - 1 && ny == m - 1) {
            ans = ncost + 1;
            continue;
        }

        if (arr[nx][ny] == '1') {// 도착점이 벽일때
            dp[nx][ny] = ncost;
        }
        else if (arr[nx][ny] == '0') { // 경로일때
            if (nx - 1 >= 0) {
                tmp.cost = ncost + 1, tmp.x = nx - 1;
                tmp.y = ny, tmp.flag = nflag;
                q.push(tmp);
            }
            if (nx + 1 < n) {
                tmp.cost = ncost + 1, tmp.x = nx + 1;
                tmp.y = ny, tmp.flag = nflag;
                q.push(tmp);
            }
            if (ny - 1 >= 0) {
                tmp.cost = ncost + 1, tmp.x = nx;
                tmp.y = ny - 1, tmp.flag = nflag;
                q.push(tmp);
            }
            if (ny + 1 < m) {
                tmp.cost = ncost + 1, tmp.x = nx ;
                tmp.y = ny+1, tmp.flag = nflag;
                q.push(tmp);
            }
        }
    }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            chk[i][j] = false;
    s.x = n-1;
    s.y = m-1;
    s.cost = 0;
    s.flag = 1;

    q.push(s);

    // 도착점 시작
    while (!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        int nflag = q.front().flag;
        int ncost = q.front().cost;
        pi tmp;

        q.pop();
        if (chk[nx][ny])
            continue;

        if (ans < ncost)
            continue;

        chk[nx][ny] = true;

        if (arr[nx][ny] == '1') {// 도착점이 벽일때
            if (dp[nx][ny] != -1)
                ans = min(ncost + dp[nx][ny] + 1, ans);
        }
        else if (arr[nx][ny] == '0') { // 경로일때
            if (nx - 1 >= 0) {
                tmp.cost = ncost + 1, tmp.x = nx - 1;
                tmp.y = ny, tmp.flag = nflag;
                q.push(tmp);
            }
            if (nx + 1 < n) {
                tmp.cost = ncost + 1, tmp.x = nx + 1;
                tmp.y = ny, tmp.flag = nflag;
                q.push(tmp);
            }
            if (ny - 1 >= 0) {
                tmp.cost = ncost + 1, tmp.x = nx;
                tmp.y = ny - 1, tmp.flag = nflag;
                q.push(tmp);
            }
            if (ny + 1 < m) {
                tmp.cost = ncost + 1, tmp.x = nx;
                tmp.y = ny + 1, tmp.flag = nflag;
                q.push(tmp);
            }
        }
    }


    if (ans != INF)
        cout << ans;
    else
        cout << -1;
}