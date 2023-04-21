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
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string buf;
        getline(cin,buf);
        map<string, int>mp;
        while (1) {
            string a, b, c;
            cin >> a >> b >> c;

            if (b == "does") {
                cin >> a >> c;
                if(c == "say?")
                    break;
            }
            if(b == "goes")
                mp.insert({ c, 1 });
        }

        string tmp;
        for (auto i : buf) {
            if (i == ' ')
                if (mp[tmp] != 1)
                    cout << tmp << " ", tmp = "";
                else
                    tmp = "";
            else 
                tmp += i;
        }
        if (mp.count(tmp) == 0)
            cout << tmp << " ";
        cin.ignore();
    }
}     
