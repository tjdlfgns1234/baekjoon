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
    int m, n;
    cin >> m >>n; // M : 가로, N : 세로
    vector <vector<int>> arr(n,vector<int>(m,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    queue <pair<int, int>> q; // x, y 좌표
    queue <pair<int, int>> q2; // x, y 좌표
    int day = 0;

    int one = 0,mone = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1)
                q2.push({ i,j }), one++;
            else if (arr[i][j] == -1)
                mone++;
        }
    }

    vector <vector<int>> chk(n, vector<int>(m, 0));

    if (mone + one == n * m) {
        cout << 0;
        return;
    }

    day = 0;
    bool flag = false;
    while (!q2.empty()) {
        q = q2;
        if(flag) // 익은 토마토가 있을 떄만 날짜 증가
            day++;

        while (!q2.empty())
            q2.pop();

        flag = false;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (arr[x][y] == 0)
                arr[x][y] = 1, flag =true;

            if (chk[x][y] == 0) // 방문체크
                chk[x][y] = 1;
            else
                continue;

            if (arr[x][y] != -1) {
                if (x + 1 < n)
                    q2.push({ x + 1,y });
                if (x - 1 >= 0)
                    q2.push({ x - 1,y });
                if (y + 1 < m)
                    q2.push({ x  ,y + 1 });
                if (y - 1 >= 0)
                    q2.push({ x,y - 1 });
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 0) {
                cout << -1;
                return;
            }
    }
    cout << day;
}