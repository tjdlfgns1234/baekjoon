#include <bits/stdc++.h>
#include <unordered_map>
#define all(a) a.begin(),a.end()
#define SIZE 2000
#define mod 1000000007
#define e 0.00000001
#define k 347

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
ll init(vector<ll>& segtree, size_t node, size_t start, size_t end);
void update(vector<ll>& segtree, size_t node, size_t start, size_t end, size_t idx, ll x);
ll query(vector<ll>& segtree, size_t node, size_t l, size_t r, size_t start, size_t end);


ll arr[1000001];
int n;

int main()
{
    ios::sync_with_stdio(NULL);
    std::cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int u ,q;
    cin >> n >> u >> q;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int depth = ceil(log2(n));
    int size = 1 << (depth + 1);
    vector<ll> segtree(size);

    init(segtree, 1,0,n-1);
    int t = u + q;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) { // update
            update(segtree, 1, 0, n - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else if (a == 2) // query
            cout << query(segtree,1,b-1,c-1,0,n-1) << '\n';
    }

}
ll init(vector<ll>& segtree, size_t node, size_t start, size_t end) {
    if (start == end)
        return segtree[node] = arr[start];
    size_t mid = start + (end - start) / 2;
    
    return  segtree[node] = init(segtree, node * 2, start, mid) + init(segtree, node * 2 + 1, mid + 1, end);

}
void update(vector<ll>& segtree, size_t node, size_t start, size_t end, size_t idx, ll x) {
    if (idx<start || idx > end)
        return;

    segtree[node] += x;

    if (start != end) {
        size_t mid = start + (end - start) / 2;
        update(segtree, node * 2, start, mid, idx, x);
        update(segtree, node * 2 +1, mid+1, end, idx, x);
    }
   
}
ll query(vector<ll>& segtree, size_t node, size_t l, size_t r, size_t start, size_t end) {
    if (l > end || r < start) return 0;
    if (l <= start && r >= end) return segtree[node];

    size_t mid = start + (end - start) / 2;
    
    return query(segtree, node * 2, l, r, start, mid) + query(segtree, node * 2 + 1, l, r, mid + 1, end);
}