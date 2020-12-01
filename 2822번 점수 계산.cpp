#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    map<short, short> mp;
    short sum = 0;
    short tmp;
    short ans[5] = { 0 };

    for (int i = 0; i < 8; i++)
        cin >> tmp, mp.insert({tmp,i+1});

    short i=0;
    map<short, short>:: iterator it;
    for (it = mp.begin(); it != mp.end(); it++,i++)
    {
        if (i < 3)
            continue;
        else
            sum += it->first, ans[i-3] = it->second;
    }

    sort(ans, ans + 5);

    cout << sum << "\n";
    for (short i = 0; i < 5; i++)
        cout << ans[i] << " ";

    return 0;
}