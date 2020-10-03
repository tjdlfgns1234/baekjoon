#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
map<int, int> mp;

/*  좌표를 정렬한다음 그와 대응하는 번호를 매긴다음 출력  */

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int count = 0;
	cin >> n;
	int* origin = new int[n];
	int* copy = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> origin[i];
		copy[i] = origin[i];
	}

	sort(copy, copy + n);
	mp.insert(make_pair(copy[0], count));

	for (int i = 1; i < n; i++)
	{
		if (copy[i] != copy[i - 1])
		{
			count++;
			mp.insert(make_pair(copy[i], count));
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << mp[origin[i]] << " ";
	}

	return 0;
}