#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
  
    priority_queue <int,vector<int>,greater<int>>pq;
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x != 0)
            pq.push(x);
        else
            if (!pq.empty())
                cout << pq.top() << "\n", pq.pop();
            else
                cout << 0 << "\n";
    }

}