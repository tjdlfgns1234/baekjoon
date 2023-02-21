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
    int n, k;
    cin >> n >> k;

    ll ans = 0ll;

    vector<pair<int,int>> arr(n); // f : 무게, s : 가치
    vector <int> bag(k);

    for (auto& i : arr)
        cin >> i.first >> i.second;
    for (auto& i : bag)
        cin >> i;

    sort(all(bag));  // 작은거 부터 채워나감
    sort(all(arr));  // 무게기준 작은거 부터

    
    priority_queue<int> pq; // max-heap

    int jewel_idx = 0; // 보석의 index 

    for (int i = 0; i < k; i++) {
        while (1) {
            if (jewel_idx >= n)
                break;
            if (arr[jewel_idx].first <= bag[i]) {
                pq.push(arr[jewel_idx].second); // 최고값 넣기
            }
            else
                break;
            jewel_idx++;
        }
        if (!pq.empty())
            ans += pq.top(), pq.pop();
    }
    cout << ans;
}