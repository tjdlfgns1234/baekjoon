﻿#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define mod 1000000007

// beware of min & max value;
// 빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
// /와 %연산은 배열을 나타낼때 유용하게 쓰인다.
// 배운거 내에서만 쓸 생각을 하자. 
// 평소 연습했던 대로!
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
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    string a, b;
    cin >> a >> b;

    int ans = 51;
    if (a.length() <= b.length()) {
        for (int i = 0; i < b.length() - a.length()+1; i++) {
            int diff = 0;
            for (int j = 0; j < a.length(); j++) {
                if (a[j] != b[i + j])
                    diff++;
            }
            ans = min(diff, ans);
        }
    }
    else {
        for (int i = 0; i < a.length() - b.length()+1; i++) {
            int diff = 0;
            for (int j = 0; j < b.length(); j++) {
                if (b[j] != a[i + j])
                    diff++;
            }
            ans = min(diff, ans);
        }
    }
    cout << ans;
}