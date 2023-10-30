#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define SIZE 30000
#define mod 1000000007


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
short gcd(short a, short b);
pair<short, short> arr[7600460];
bool cmp(const pii& a, const pii& b) {
    return (((float)a.first / (float)a.second < (float)b.first / (float)b.second));
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;


    // 7400만 정도 돌아감.
    // 5000 7600459

    for (int i = 2; i <= n; i++)
        if (i & 1) {
            for (int j = 1; j <= i/2; j++) {
                if (gcd(i, j) == 1)
                    arr[cnt++] = { j,i }, arr[cnt++] = { i - j,i };
            }
        }
        else {
            if (i == 2) {
                arr[cnt++] = { 1,i };
                continue;
            }

            for (int j = 1; j < i/2; j += 2) {
                if (gcd(i, j) == 1)
                    arr[cnt++] = { j,i }, arr[cnt++] = { i - j,i };
            }
        }

    arr[cnt++] = { 0,1 };
    arr[cnt++] = { 1,1 };
    nth_element(arr, arr + k-1, arr + cnt, cmp);
   // sort(arr + 1, arr + cnt, cmp);
   //cout << cnt << '\n';
    //if (k == cnt)
    //    cout << 1 << " " << 1;
    //else
        cout << arr[k - 1].first << " " << arr[k - 1].second;

}
short gcd(short a, short b) {
    short n;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;

}