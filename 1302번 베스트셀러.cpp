#include <algorithm>
#include <iostream>
#include <map>


using namespace std;
map<string, int> arr;
map<int, string> arr2;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string tmp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (arr.find(tmp) == arr.end())
		{
			arr.insert(make_pair(tmp, 1));
		}
		else
		{
			arr.find(tmp)->second += 1;
		}
	}

	map<string, int>::iterator it;
	map<int, string>::iterator it2;
	for (it = arr.begin(); it != arr.end(); it++)
	{
		arr2.insert(make_pair(it->second,it->first));
	}
	it2 = arr2.end();
	it2--;
	cout <<it2->second;

	return 0;
}