#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
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

    vector <int> arr(101);
    bool chk[101];
    int cnt = 0;
    for (auto& i : arr)
        chk[cnt] = false , i = cnt++;


    for (int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x] = y;
    }

    queue <pair<int, int>> q;  // pos, cost
    q.push({ 1,0 });
    while (!q.empty()) {
        int pos = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (pos >= 100) {
            cout << cost;
            return;
        }

        if (chk[pos])
            continue;
        else
            chk[pos] = true;

      
        for (int i = 1; i < 6 + 1; i++) {
            int next = pos + i;
            if (next < 100) {
                while (arr[next] != next) {
                    next = arr[next];
                }
            }
            else {
                cout << cost + 1;
                return;
            }
            q.push({ next,cost + 1 });
        }
    }
    
}