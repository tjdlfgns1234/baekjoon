#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define SIZE 100000
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


int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n;
    cin >> n;

    vector<string> arr(n);

    for (auto& i : arr)
        cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> tmp(50);
        int con = 0;
        tmp[i] = 2;
        for (int j = 0; j < n; j++) { // A-B 관계인 집합
            if (arr[i][j] == 'Y') {
                if (tmp[j] == 0) {
                    con++;
                    tmp[j] = 1;
                }
            }
        }
        for (int j = 0; j < n; j++) { // A의 친구 중에서 직접적인 관계가 있는 사람.
            if (tmp[j] == 1)
                for (int k = 0; k < n; k++) {
                    if (arr[j][k] == 'Y') {
                        if (tmp[k] == 0)
                        {
                            con++;
                            tmp[k] = 2;
                        }
                    }
                }
        }

        ans = max(con, ans);
    }


    // A-B, 자기자신과 친구 X
    // A-C, B-C가 존재해면 2-친구
    // 경로가 2인 수
    cout << ans;

}