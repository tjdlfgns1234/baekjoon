#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> vn;
vector<string> vm;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string buf;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> buf;
		vn.push_back(buf);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> buf;
		vm.push_back(buf);
	}
	sort(vn.begin(), vn.end());
	sort(vm.begin(), vm.end());
	vector<string>intersect(vn.size() + vm.size());
	auto iter = set_intersection(vn.begin(), vn.end(), vm.begin(), vm.end(), intersect.begin());
	intersect.erase(iter, intersect.end());

	cout << intersect.size() << "\n";
	for (int j = 0; j < intersect.size(); j++)
		cout << intersect[j] << "\n";


	return 0;
}