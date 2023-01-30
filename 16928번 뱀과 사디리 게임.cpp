#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define all(a) a.begin(),a.end()

// beware of min & max value;
// 실수 연산은 정수연산보다 한참 느리다는 것을 기억하자
// 왠만하면 자료형은 적재적소에 맞추는게 기본!

/*
    DFS는 미로 찾기등과 같이 경로의 특징를 구할 때 적합하고
    BFS는 최단경로 찾는 문제들에 대해서 적합하다.
    BFS로 최단경로로 찾은 답이 최단경로라는 것이 보장되는 반면에 DFS는 보장되지 않는다.
    모든 정점을 탐색하는데 있어서는 둘의 시간복잡도는 동일하지만, 구현과정에서 어떤 조건이 추가되나에
    따라서 시간복잡도가 다를 수도 있다는 점을 명심해야한다.
*/

using namespace std;
void solve();
void move(const vector<int>& arr, int cost, int curr);
bool chk[100] = { 0 };
int ans = 101;

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

    vector<int> arr(101);

    for (int i = 0; i < 101; i++)
        arr[i] = i;

    // 아무것도 없으면 자기자신으로 이동

    for (int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x] = y;
    }

    move(arr, 0, 1);
}
void move(const vector<int>& arr, int cost, int curr) {
    queue<pair<int,int>> q;
    q.push({ cost,curr });

    while (!q.empty()) {
        int f = q.front().first;
        int s = q.front().second;
        q.pop();

        for (int i = 1; i < 7; i++) {
            int mov = s + i;
            
            if (mov >= 100)
                ans = min(ans, f + 1);
            else {
                if (!chk[mov]) { // 방문한 적이 없을 때
                    chk[mov] = true;
                    while (arr[mov] != mov) {
                        mov = arr[mov];
                    }
                    if (arr[mov] == mov) // 일반칸이면 전진
                        q.push({ f + 1, mov });
                }
                else
                    continue;
            }
        }
    }
    cout << ans;
}