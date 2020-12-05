#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int arr[9] = { 0 };
    int arr2[9] = { 0 };
    int sum = 0, sum2 = 0;
    bool ans = false;
    bool flag = false;
    for (int i = 0; i < 9; i++)
        cin >> arr[i];

    for (int i = 0; i < 9; i++)
        cin >> arr2[i];

    for (int i = 0; i < 9; i++)
    {
        sum += arr[i];
        if (sum > sum2)
        {
            flag = true;
        }
        sum2 += arr2[i];
    }

    if (sum < sum2 && flag)
        ans = true;


    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}