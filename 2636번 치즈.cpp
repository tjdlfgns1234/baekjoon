#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define SIZE 30000
#define mod 1000000007
#define e 0.0000000001


// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.
// 배운거 내에서만 쓸 생각을 하자. 
// for문을 쓰는 것보다 전체를 한번에 초기화 할 생각을 하자. => 상수 시간 최적화
// 함수 호출은 스택 메모리를 사용한다는 것에 유의하자.
// 행렬을 배열로도 쓸 생각하자
// 급하기 풀지 말자


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();

int dp[102][102];
int dx[4] = { -1,0,1,0};
int dy[4] = { 0,-1,0,1 };

int main()
{
    ios::sync_with_stdio(NULL);
    std::cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>>arr(n+1, vector<int>(m+1));

    // 판의 가장자리에서 각 턴 마다 BFS 전수 탐색 시작

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    queue<pii> q;
    memset(dp, false, sizeof(dp));


    int ans = 0;
    for (int i = 2; i <= 101; i++) {
        int pre = ans;
        q.push({ 0,0 });
        memset(dp, false, sizeof(dp));
        ans = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if (!dp[x][y])
                dp[x][y] = true;
            else
                continue;

            if (arr[x][y] == 1) {
                arr[x][y] = i; // 각 시간별로 녹은 치즈 2부터 시작
                ans++;         // 치즈를 녹임.
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx >= 0 && tx <= n && ty >= 0 && ty <= m)
                    if (!dp[tx][ty])
                        q.push({ tx,ty });
            }
        } 
        if (ans == 0) { // 치즈가 다 녹음
            cout << i - 2 << '\n' << pre;
            break;
        }
    }

    //for (int i = 1; i <=n; i++) {
    //    for (int j = 1; j <= m; j++)
    //        cout << arr[i][j] << " ";
    //    cout << '\n';
    //}
  
}