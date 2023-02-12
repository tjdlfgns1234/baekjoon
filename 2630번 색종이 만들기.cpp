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

void paper(vector<vector<int>>& arr, int x, int y, int size);
int ans = 0;
int ans2 = 0;

int main()
{
    ios::sync_with_stdio(NULL);
    cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    paper(arr, 0, 0, n);

    cout << ans << '\n' << ans2;



}
void paper(vector<vector<int>>& arr, int x, int y, int size) {
    int flag = arr[x][y]; //  현재 색깔 확인

    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++) {
            if (flag != arr[i][j]) { // 종이를 나누어야 하면
                flag = 2;
            }

            if (flag == 2) // 재귀가 필요하면
            {
                paper(arr, x, y, size / 2);
                paper(arr, x, y + size / 2, size / 2);
                paper(arr, x + size / 2, y, size / 2);
                paper(arr, x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    if (flag == 0)
        ans++;
    else
        ans2++;
}
