#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define mod 1000000007

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
int gcd(int a, int b);
int lcm(int a, int b);


int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    string s, t;
    cin >> s >> t;

    int LCM = lcm(s.size(), t.size());

    int x = LCM / s.size();
    int y = LCM / t.size();

    string s1, s2;
    for (int i = 0; i < x; i++)
        s1 = s1 + s;
    for (int i = 0; i < y; i++)
        s2 = s2 + t;

    cout << (s1 == s2);
}     
int gcd(int a, int b)
{
    int tmp = a, tmp2 = b;
    while (tmp2 != 0)
    {
        int r = tmp % tmp2;
        tmp = tmp2;
        tmp2 = r;
    }
    return tmp;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}