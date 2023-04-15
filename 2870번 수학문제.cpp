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

    vector<string> arr(n);
    vector<string> ans;
    for (auto& i : arr)cin >> i;

    
    string tmp = "";
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] >= '1' && arr[i][j] <= '9') {
                if (tmp.size() == 1)
                    if (tmp[0] == '0')
                        tmp.clear();
                tmp += arr[i][j];
            }
            else if (arr[i][j] == '0') {
                if (tmp.size() == 1) {
                    if (tmp[0] != '0')
                        tmp += arr[i][j];
                }
                else
                    tmp += arr[i][j];
            }
            else {
                if (tmp.size() != 0)
                    ans.push_back(tmp), tmp.clear();
            }
        }
        if (tmp.size() != 0)
            ans.push_back(tmp), tmp.clear();
    }

    for (int i = 0; i < ans.size(); i++)
        for (int j = i+1; j < ans.size(); j++)
            if (ans[i].size() == ans[j].size()) {
                if (ans[i] > ans[j])
                    swap(ans[i], ans[j]);
            }
            else  if (ans[i].size() > ans[j].size()) 
                swap(ans[i], ans[j]);
            


    for (auto i : ans)
        cout << i << '\n';
}