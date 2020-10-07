#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map <int,int> set;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	int tmp;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		set.insert(make_pair(tmp,1));
	}


	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (set.find(tmp) != set.end())
			set.erase(tmp);
			
	}

	map<int, int>::iterator it;

	cout << set.size() << "\n";

	for (it = set.begin(); it!=set.end(); it++)
	{
		cout << (*it).first << " ";
	}



	return 0;
}