#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define all(a) a.begin(),a.end()

// beware of min & max value;
// 실수 연산은 정수연산보다 한참 느리다는 것을 기억하자
// 왠만하면 자료형은 적재적소에 맞추는게 기본!

using namespace std;
void solve();

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

    while (t--) {
        string op;
        cin >> op;

        int n;
        cin >> n;
        deque <int> arr;

        // R은 배열 뒤집기, D는 첫 번째 수를 버리는 함수
        // 요구되는 시간 복잡도는 두 연산 모두 O(1)


        int cnt = 0;
        string raw;
        cin >> raw;

        string tmp = "";
        for (int i = 0; i < raw.size(); i++) { // 파싱
            if (raw[i] == '[')
                continue;
            else if (raw[i] == ']')
                if (n == 0) 
                    continue;
                else
                    arr.push_back(stoi(tmp));
            else if (raw[i] == ',')
                arr.push_back(stoi(tmp)),tmp = "";
            else
                tmp += raw[i];
        }

        bool reflag = false;
        bool errorflag = false;
        for (auto i : op) {
            if (i == 'R') {
                reflag = (!reflag);
            }
            else if (i == 'D') {
                if (arr.empty() == true) {
                    cout << "error\n";
                    errorflag = true;
                    break;
                }
                else {
                    if (reflag)
                        arr.pop_back();
                    else
                        arr.pop_front();
                }
            }
        }

        if (errorflag)
            continue;
        else {
            cout << "[";
            while (!arr.empty()) {
                if (arr.size() == 1) {
                    if (reflag) {
                        cout << arr.back();
                        arr.pop_back();
                    }
                    else {
                        cout << arr.front();
                        arr.pop_front();
                    }
                }
                else if (reflag) {
                    cout << arr.back() << ",";
                    arr.pop_back();
                }
                else {
                    cout << arr.front() << ",";
                    arr.pop_front();
                }
            }
            cout << "]\n";
        }
    }
}