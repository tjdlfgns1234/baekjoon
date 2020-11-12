#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int* arr = new int[n];
    vector <int> list;
    for (int i = 0; i < n; i++) cin >> arr[i];

    list.push_back(arr[0]);
    for (int i = 1; i < n; i++)
        if (arr[i] < list[0]) list[0] = arr[i];
        else if (arr[i] > list.back())list.push_back(arr[i]);
        else {
            vector<int>::iterator it = upper_bound(list.begin(), list.end(), arr[i] - 1);
            *it = arr[i];
        }
    cout << list.size();

}