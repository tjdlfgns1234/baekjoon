#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	
	while (1)
	{
		int n;
		cin >> n;
		if (n==0)
			break;
		vector <int> arr(n);
		for (auto& i : arr)
			cin >> i;
		arr.erase(unique(arr.begin(), arr.end()),arr.end());
		
		for (auto i : arr)
			cout << i << ' ';
		cout << "$\n";
	}
	return 0;
}