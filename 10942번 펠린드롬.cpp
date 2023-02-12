#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define INF 100000007
#define all(a) a.begin(),a.end()

// beware of min & max value;
/*
    Base case
      크기가 1일때는 무조건 회문
      크기가 2일때 둘이 같으면 회문
    Inductive Step
      만약 arr[i] == arr[j]이면
         i부터 j까지 회문일려면, i+1, j-1까지도 회문이여야 한다.

    Proof) 귀류법 i+1, j-1 회문이 아니고, i,j가 회문이라 하자.
          회문의 정의에 의해서, i+1, j-1이 회문이 아니면 i,j도
          회문일 수 없다. 따라서 위 가정은 모순이다.
*/

using namespace std;
void solve();
bool dp[2001][2001] = { false };


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

    vector<int> arr(n+1);
    arr[0] = 0;
    for (int i = 1; i < n+1; i++) {
        cin >> arr[i];
        dp[i][i] = true; // 한자리는 회문!

        if (i != 1)
           if (arr[i] == arr[i - 1])
                dp[i - 1][i] = true; // 두 자리 수도 회문일 경우
    }

    for (int i = 2; i < n; i++) {
        for (int j = 1; i + j < n + 1; j++)
            if (arr[j] == arr[i + j])
                if (dp[j + 1][i + j - 1])
                    dp[j][i + j] = true;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        cout << dp[s][e] << '\n';
    }
}