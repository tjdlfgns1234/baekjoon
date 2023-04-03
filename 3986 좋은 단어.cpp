﻿#include <bits/stdc++.h>
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

    int ans = t;
    while (t--) { 
        stack <char> stack;
        string s;
        cin >> s;

        if (s.size() & 1) 
            ans--;
        else {
            for (int i = 0; i < s.size(); i++) {
                // 현재 위치의 것을 제거해줘야함. 이럴땐 스택 구조를 생각하자.
                if (stack.empty())
                    stack.push(s[i]);
                else
                    if (stack.top() == s[i])
                        stack.pop();
                    else
                        stack.push(s[i]);
            }
            if (!stack.empty())
                ans--;
        }
    }
    cout << ans;
}
