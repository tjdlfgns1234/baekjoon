#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int n;
	cin >> n;
	double mean = 0;
	int* arr = new int[n];
	int m = -1;

	for (int i = 0; i < n; i++)
		cin >> arr[i],m=max(m,arr[i]);
	for (int i = 0; i < n; i++)
		mean += arr[i] /(double) m * 100;

	cout << mean/n;
	
	return 0;
}