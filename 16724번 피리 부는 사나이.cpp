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
// 우선순위 큐에 무엇을 넣을지도 잘 생각하자.




using namespace std;
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

    vector<string> s(n);

    for (auto& i : s)
        cin >> i;

    int** chk = new int* [n];
    for (int i = 0; i < n; i++)
        chk[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            chk[i][j] = 0;

    queue <pair<int, int>> q;
    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            q.push({ i,j });
            cnt++; // 단계마다 cnt 저장
            ans++;
            if (chk[i][j] != 0) { // 방문했던 곳이면
                q.pop();
                ans--;
                continue;
            }

            while (!q.empty()) {
                int nx = q.front().first;
                int ny = q.front().second;
                q.pop();

                if (chk[nx][ny] == 0)
                    chk[nx][ny] = cnt;
                else if (chk[nx][ny] == cnt) // 현재 단계에서 방문헀으면
                    continue;
                else if (chk[nx][ny] != cnt) { // 앞선 단계에서 방문했으면
                    ans--;  // 답에서 하나 뺴줌
                    continue;
                }
  
                if (s[nx][ny] == 'U')
                    q.push({ nx - 1,ny });
                if (s[nx][ny] == 'D')
                    q.push({ nx + 1 ,ny });
                if (s[nx][ny] == 'L')
                    q.push({ nx,ny - 1 });
                if (s[nx][ny] == 'R')
                    q.push({ nx,ny + 1 });
            }
        }

    std::cout << ans;
}