#include <iostream>
#include <algorithm>

using namespace std;

bool rockgame(long long n);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	if (rockgame(n))	// 선공 승
		cout << "SK";
	else
		cout << "CY";

	return 0;
}
bool rockgame(long long n)
{
	long long re = n % 5;
	bool result = true;
	if (re == 2 || re == 0)
		result = false;

	return result;
}