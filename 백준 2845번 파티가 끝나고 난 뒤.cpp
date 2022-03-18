#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int l, p;
	cin >> l >> p;
	int people = l * p;
	int arr[5] = { 0 };
	

	for (auto& i:arr)
		cin >> i;

	for (auto i : arr)
		cout << (i-people) << " ";


	return 0;
}