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

void dfs(const  vector<char>& s, string ans , int num,const int n);
map<string, int> mp;


int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n;
    cin >> n;

    vector<char> s(n);


    for (auto& i : s)cin >> i;

    for(int i = 0; i < 10;i++)
        dfs(s, to_string(i), 0, n);

    map<string, int>::iterator it;

    it = mp.end();

    cout << (--it)->first << '\n';
    it = mp.begin();
    cout << it->first;

}
void dfs(const vector<char>& s, string  ans, int num,const int n) {
    if (ans.size() == n + 1) {
        if (mp.count(ans) == 0) {
            mp.insert({ ans,1 });
            return;
        }
    }
    else if (ans.size() > n + 1)
        return;
    

    for (int i = 0; i < 10; i++) {
        bool f = false;
        for (int j = 0; j < ans.size(); j++) {
            if (ans[j] - '0' == i)
                f = true;
        }
        if (f)
            continue;

        if (s[num] == '<') {
            if (ans[ans.size()-1] - '0' < i) {
                dfs(s, ans+to_string(i), num+1, n);
            }
        }
        else if (s[num] == '>') {
            if (ans[ans.size() - 1] - '0' > i) {
                dfs(s, ans + to_string(i), num + 1, n);
            }
        }
        }
    }



