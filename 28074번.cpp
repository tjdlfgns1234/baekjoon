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
    string s;
    cin >> s;

    int arr[5] = { 0 };

    for (auto i : s) {
        if (i == 'M')
            arr[0] = 1;
        else if (i == 'O')
            arr[1] = 1;
        else if (i == 'B')
            arr[2] = 1;
        else if (i == 'I')
            arr[3] = 1;
        else if (i == 'S')
            arr[4] = 1;
    }
    

    int cnt = 0;

    for (int i = 0; i < 5; i++)
        if (arr[i] == 1)
            cnt++;
    if (cnt == 5)
        cout << "YES";
    else
        cout << "NO";



}