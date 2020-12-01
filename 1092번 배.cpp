#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

vector<int> crane;
vector<int> box;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    int tmp;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> tmp, crane.push_back(tmp);

    int m;
    cin >> m;;
    for (int i = 0; i < m; i++)
        cin >> tmp, box.push_back(tmp);


    sort(box.begin(), box.end(), greater<int>());
    sort(crane.begin(), crane.end(), greater<int>());


    if (box[0] > crane[0])
    {
        cout << -1;
        return 0;
    }

    int ans = 0;
    while (!box.empty())
    {
        int cidx = 0;
        for (int i = 0; i < box.size(); i++)
        {
            if (cidx == crane.size())
                break;
            if (crane[cidx] >= box[i])
            {
                cidx++;
                box.erase(box.begin() + i);
                i--;
            }
        }
        ans++;
    }
    cout << ans;

    return 0;
}