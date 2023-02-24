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
// 큐 쓰는 것도 좋았지만, 최적화는 잘해주자.

using namespace std;
void solve();
void dfs(vector<int>& arr, vector<int>& chk, int start, int cnt);

int ans;
queue<int> q;

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
        int n;
        cin >> n;
        ans = n;

        vector<int> arr(n);
        vector<int> chk(n);
        for (auto& i : arr) cin >> i;
        for (auto& i : chk) i = 0;

        for (int i = 0; i < n; i++) {
            if (chk[i] == 0)
              dfs(arr, chk, i + 1, i + 1);
            
            int s = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                if (chk[curr-1] == 0 || chk[curr-1] == -2) {
                    s++, chk[curr-1] = -1;
                    q.push(arr[curr-1]);
                }
                else
                    break;
            }
            ans -= s;
        }

        cout << ans << '\n';
    }
}
void dfs(vector<int>& arr, vector<int>& chk, int start, int cnt)
{
    if (start == arr[start-1]) { // 자기자신은 사이클
        if(chk[start-1] == 0)
           ans--;
        chk[start - 1] = cnt;
        return;
    }
    else if (chk[start-1] == cnt) { // 이 단계에서 이미 방문 했던 곳이면 사이클
        q.push(start); // 사이클 시작점 기록
        return;
    }
    else if (chk[start - 1] != 0) { // 이전에 방문 했던 곳이면 pass
        return;
    }
    else if(chk[start-1]==0) // 방문한적 없는 곳이면 탐색
    { 
        chk[start-1] = cnt;
        dfs(arr, chk, arr[start-1], cnt);
        chk[start - 1] = -2;
    }
}