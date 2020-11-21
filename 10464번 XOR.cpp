#include <iostream>
#include <algorithm>
using namespace std;

int XOR(int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	int t;
	int s, f;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s >> f;
		cout << XOR(s, f) << "\n";
	}

	return 0;
}
int XOR(int x, int y)
{
	int* bits;

	if (x % 2 == 0)
		bits = new int[4] {y, 1, y ^ 1, 0};
	else
		bits = new int[4] {x, x^y, x -1, (x-1)^y};

	return bits[(y - x) % 4];
}