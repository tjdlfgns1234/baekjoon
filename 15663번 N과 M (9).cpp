#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()

// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.
// 우선순위 큐에 무엇을 넣을지도 잘 생각하자.
// 큐 쓰는 것도 좋았지만, 최적화는 잘해주자.
// 행렬을 배열로도 쓸 생각하자

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();
void dfs(vector<int> &arr,vector<int>  ans, int m);
int chk[8] = { 0 };
map<string, int> mp;

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

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    sort(all(arr));
    vector<int> ans;
    dfs(arr,ans, m);
}
void dfs(vector<int>& arr, vector<int>  ans, int m){
    if (ans.size() > m)
        return;
    else if (ans.size() != m) {
        for(int i = 0; i < arr.size(); i++)
            if (!chk[i]) {
                ans.push_back(arr[i]);
                chk[i] = 1;
                dfs(arr, ans, m);
                chk[i] = 0;
                ans.pop_back();
            }
    } 
    else if(ans.size() == m) {
        string s = "";
        for (auto i : ans)
            s += to_string(i) + " ";
        s+= '\n';
        if (mp.count(s) == 0)
            mp.insert({ s,1 }), cout << s;
        else
            return;
    }
}