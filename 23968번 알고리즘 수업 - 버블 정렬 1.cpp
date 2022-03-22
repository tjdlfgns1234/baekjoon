#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

void bubble_sort(vector<int>& arr, int k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (auto& i:arr)
        cin >> i;

    bubble_sort(arr, k);

    return 0;
}
void bubble_sort(vector<int>& arr, int k)
{
    int cnt = 0;
    for (int i = arr.size(); i > 1; i--)
        for (int j = 0; j < arr.size()-1; j++)
            if (arr[j] > arr[j + 1]) {
                cnt++;
                if (cnt == k) {
                    cout << arr[j + 1] << " " << arr[j];
                    return;
                }
                else
                    swap(arr[j], arr[j + 1]);
            }
    if (cnt < k)
        cout << -1;
}