#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define INF 100000007
#define SIZE 9
#define all(a) a.begin(),a.end()

// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.

using namespace std;
void solve();
void bfs(vector<string>& arr, vector <vector<int>>  &ans, int x, int y);
void bfs2(vector<string>& arr, vector <vector<int>>& dp, vector <vector<int>>& ans, int x, int y);
void init(int n, int m);
bool chk[1000][1000] = { false };
int n, m;
bool flag = false;

int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {

    cin >> n >> m;

    vector <string> arr(n);
    vector <vector<int>>  dp(n, vector<int>(m, 0));
    vector <vector<int>>  ans(n, vector<int>(m, 0));

    for (auto& i : arr)
        cin >> i;
    init(n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == '0')
                if(dp[i][j] == 0)
                   bfs(arr,dp, i, j);
    void init(int n, int m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == '0')
                if(!chk[i][j])
                    bfs2(arr, dp,ans, i, j);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (ans[i][j] != 0)
                cout << (ans[i][j] + 1) % 10;
            else
                if (arr[i][j] == '1')
                    cout << 1;
                else
                    cout << 0;
        cout << '\n';
    }
}
void bfs2(vector<string>& arr, vector <vector<int>>& dp, vector <vector<int>>& ans, int x, int y) {
    queue<pair<int, int>> q;

    q.push({ x,y });

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if (chk[nx][ny])
            continue;

        if (arr[nx][ny] == '1') {
            ans[nx][ny] += dp[x][y];
            chk[nx][ny] = true;
            continue;
        }
        chk[nx][ny] = true;

        if (nx + 1 < n)
            q.push({ nx + 1,ny });
        if (ny + 1 < m)
            q.push({ nx , ny + 1 });
        if (nx - 1 >= 0)
            q.push({ nx - 1, ny });
        if (ny - 1 >= 0)
            q.push({ nx , ny - 1 });
    }
    q.push({ x,y });

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();


        if (!chk[nx][ny])
            continue;

        if (arr[nx][ny] == '1') {
            chk[nx][ny] = false;
            continue;
        }
        chk[nx][ny] = false;

        if (nx + 1 < n)
            q.push({ nx + 1,ny });
        if (ny + 1 < m)
            q.push({ nx , ny + 1 });
        if (nx - 1 >= 0)
            q.push({ nx - 1, ny });
        if (ny - 1 >= 0)
            q.push({ nx , ny - 1 });
    }

    q.push({ x,y });

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if (chk[nx][ny])
            continue;

        if (arr[nx][ny] == '1') {
            continue;
        }
        chk[nx][ny] = true;

        if (nx + 1 < n)
            q.push({ nx + 1,ny });
        if (ny + 1 < m)
            q.push({ nx , ny + 1 });
        if (nx - 1 >= 0)
            q.push({ nx - 1, ny });
        if (ny - 1 >= 0)
            q.push({ nx , ny - 1 });
    }
}
void bfs(vector<string>& arr, vector <vector<int>>& dp, int x, int y) {
    queue<pair<int, int>> q;

    q.push({ x,y });

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if (flag)
            break;

        if (arr[nx][ny] == '1')
            continue;
        if (chk[nx][ny])
            continue;

        chk[nx][ny] = true;
        if (dp[nx][ny] != 0) {
            dp[x][y] = dp[nx][ny], flag = true;
        }
        else
            dp[x][y]++;

        if (nx + 1 < n)
            q.push({ nx + 1,ny });
        if (ny + 1 < m)
            q.push({ nx , ny + 1 });
        if (nx - 1 >= 0)
            q.push({ nx - 1, ny });
        if (ny - 1 >= 0)
            q.push({ nx , ny - 1 });
    }

    q.push({ x,y });
    flag = false;

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if (arr[nx][ny] == '1')
            continue;
        if (!chk[nx][ny])
            continue;

        chk[nx][ny] = false;
        if (dp[nx][ny] == 0) {
            dp[nx][ny] = dp[x][y];
        }

        if (nx + 1 < n)
            q.push({ nx + 1,ny });
        if (ny + 1 < m)
            q.push({ nx , ny + 1 });
        if (nx - 1 >= 0)
            q.push({ nx - 1, ny });
        if (ny - 1 >= 0)
            q.push({ nx , ny - 1 });
    }
}
void init(int n, int m) {
    flag = false;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            chk[i][j] = false;
}