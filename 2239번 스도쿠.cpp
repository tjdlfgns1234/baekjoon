#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define INF 100000007
#define SIZE 9
#define all(a) a.begin(),a.end()

// beware of min & max value;

using namespace std;
void solve();
void dfs(vector<string>& arr, int cnt);
bool chk(vector<string>& arr, int x, int y, int k);
bool visited[82] = { false };
vector<pair<int, int>> blink;
bool ans = false;

int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    vector<string> arr(SIZE);


    for (auto& i : arr)
        cin >> i;
    for (int i = 0; i<SIZE ; i++)
        for (int j = 0; j <SIZE; j++)
            if (arr[i][j] == '0')
                blink.push_back({ i,j });

    dfs(arr, 0);

}
void dfs(vector<string>& arr, int cnt) {
    if (cnt == blink.size()) {
        for (auto i : arr)
            cout << i << '\n';
        ans = true;
        return;
    }

    if (visited[cnt])
        return;
    visited[cnt] = true;

    int x = blink[cnt].first;
    int y = blink[cnt].second;

    for (int i = 1; i < SIZE + 1; i++) {
        if (chk(arr, x, y, i)) {
            dfs(arr, cnt + 1);
            if (ans)
                return;
            arr[x][y] = '0';
        }
        else
            arr[x][y] = '0';
    }
    if (ans)
        return;
    visited[cnt] = false;
}
bool chk(vector<string>& arr, int x, int y, int k) {
    arr[x][y] = '0' + k;
    int nx = x / 3;
    int ny = y / 3;

    for (int i = 0; i < 3; i++) { // 사각형 확인
        for (int j = 0; j < 3; j++)
            if (arr[x][y] == arr[nx * 3 + i][ny * 3 + j])
                if (x != nx * 3 + i || y != ny * 3 + j)
                    return false;
    }
    for (int i = 0; i < SIZE; i++) {
        if (arr[x][y] == arr[x][i])
            if (y != i)
                return false;
    }
    for (int i = 0; i < SIZE; i++) {
        if (arr[i][y] == arr[x][y])
            if (x != i)
                return false;
    }
    return true;
}