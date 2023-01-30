#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define all(a) a.begin(),a.end()

// beware of min & max value;

using namespace std;

void solve();
int pow2(int a, int b) {
    int c = 1;
    while (b--)c *= a;
    return c;
};

int main()
{
    ios::sync_with_stdio(NULL);
    cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int t;
    cin >> t;
    int ans = 1;

    while (t--) {
        string n;
        cin >> n;
        ans = 1;
        vector<int>arr(n.size());
        vector<string> raw_sum;
        unordered_map<int, int> sum;

        string sub = "";

        int one = 0, zero = 0;

        for (int i = 0; i < n.size(); i++) {
            sub = n[i];
            arr[i] = std::stoi(sub);
            if (arr[i] == 0)
                one++;
            else if (arr[i] == 1)
                zero++;
        }

        if (one + zero == n.size()) {
            cout << "Hello, BOJ 2023!" << '\n';
            continue;
        }

        sub = n[0];

        queue<pair<int, string>>q;
        q.push({ 0,sub });
        
        pair<int, string> s;
        while (!q.empty()) {
            s = q.front();
            q.pop();
            if (s.first + 1 >= n.size()) {
                raw_sum.push_back(s.second);
                continue;
            }

            if (s.first + 1 != n.size()) {
                if (s.second[s.second.size() - 1] != '+')
                    q.push({ s.first, s.second + '+' });
                s.second += n[s.first + 1];
                if (n[s.first + 1] == '0') {
                    if (s.second[s.second.size() - 1] == '+')
                        continue;
                    else
                        q.push({ s.first + 1, s.second});
                 }
                else {
                    q.push({ s.first + 1, s.second});
                }       
            }
        }
        string tmp = "";
        for (int k = 0; k < raw_sum.size(); k++) {
            int tmp_sum = 0;
            for (int i = 0; i < raw_sum[k].size(); i++) {
                if (raw_sum[k][i] == '+') {
                        tmp_sum += std::stoi(tmp);
                        tmp = "";
                }
                else
                    tmp += raw_sum[k][i];
            }
            if (tmp != "") {
                tmp_sum += std::stoi(tmp);
                tmp = "";
            }
            sum.insert({ tmp_sum,1 });
        }

        int m = 2, tmp_sum = 0, ni = std::stoi(n);
        while (1) {
            tmp_sum = 0;
            for (int i = 0; i < arr.size(); i++) {
                tmp_sum += pow2(arr[i], m);
            }
            if (sum.count(tmp_sum)!= 0)
                ans++;
            m++;
            if (tmp_sum >= ni)
                break;
        }
        cout << ans << '\n';
    }
}