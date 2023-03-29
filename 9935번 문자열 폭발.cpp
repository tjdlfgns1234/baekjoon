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
// 행렬을 배열로도 쓸 생각하자

using namespace std;
void solve();

int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    string a, b;
    cin >> a >> b;

    string buf;
    for (int i = 0; i < a.length(); i++) {
        buf += a[i];

        if (buf.length() >= b.length()) {
            bool f = true;
            for (int j = 0; j < b.length(); j++)
                if (buf[buf.length() - b.length() + j] != b[j]) {
                    f = false;
                    break;
                }

            if (f) {
                buf.erase(buf.end() - b.length(), buf.end());
            }
        }
    }
    if (!buf.empty())
        cout << buf;
    else
        cout << "FRULA";
}
