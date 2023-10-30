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
    getline(cin, s, '\n');

    int ph = 0, pg = 0;

    for (auto i : s)
        if (i == 'S')
            pg++;
        else if (i == 'D')
            pg++;
        else if (i == 'H')
            ph++;
        else if (i == 'P')
            ph++;
        else if (i == 'Y')
            ph++;
        else if (i == 'A')
            ph++, pg++;

    cout << fixed;
    cout.precision(2);

    if (ph == 0 && pg == 0)
        cout << 50.00;
    else
        cout << ((double)ph / ((double)ph + (double)pg)) * 100 + e;
}