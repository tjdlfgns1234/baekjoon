#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    string buf, op;
    map <string, int> mp;
    stack <string> s;
    for (int i = 0; i < n; i++)
    {
        cin >> buf >> op;
        if (op == "enter")
            mp.insert({ buf,1 });
        else
            mp.erase(mp.find(buf));
    }

    map <string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        s.push(it->first);
    while (!s.empty())
        cout << s.top() << "\n", s.pop();

    return 0;
}