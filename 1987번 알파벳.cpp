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
// 상수 시간 복잡도도 생각하자

using namespace std;
void solve();
void move(vector<string>& arr,int cost, int x, int y);
bool chk[26] = { false };
int ans = 0, r,c;
int nx[4] = { 1, -1, 0, 0 };
int ny[4] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(NULL);
    cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> r >> c;

    vector <string> arr(r);

    for (int i = 0; i < r; i++)
        cin >> arr[i];

    move(arr ,0,  0, 0);
    cout << ans;
}
void move(vector<string>& arr,int cost, int x, int y) {
    cost++;
    if (!chk[arr[x][y] - 'A'])
        chk[arr[x][y] - 'A'] = true;
    if (ans < cost)
        ans = cost;
   
    for (int i = 0; i < 4; i++) {
        int px = x + nx[i];
        int py = y + ny[i];

        if(px>=0 && px <r)
            if(py >=0 && py < c)
                if (!chk[arr[px][py]-'A']) {
                    move(arr, cost, px, py);
                    chk[arr[px][py] - 'A'] = false;
                 }
    }
}