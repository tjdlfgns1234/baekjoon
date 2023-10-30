#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define SIZE 30000
#define mod 1000000007
#define e 0.0000000001


// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.
// 배운거 내에서만 쓸 생각을 하자. 
// for문을 쓰는 것보다 전체를 한번에 초기화 할 생각을 하자. => 상수 시간 최적화
// 함수 호출은 스택 메모리를 사용한다는 것에 유의하자.
// 행렬을 배열로도 쓸 생각하자
// 급하기 풀지 말자


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve() {

    string s;
    cin >> s;
    ll ori = stoll(s);
    if (s.size() == 1)
        cout << ori;
    else {
        int ans = 9;
        string a, b, c;
        for (int i = 1; i <= 100000; i++) {
            a = to_string(i), b = to_string(i);
            reverse(all(b));

            c = a + b;
            if (stoll(c) <= ori)
                ans++;
            for (int j = 0; j < 10; j++) {
                c = a + to_string(j) + b;
                if (stoll(c) <= ori)
                    ans++;
            }

        }
        cout << ans;
    }
}