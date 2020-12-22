#include <iostream>
#include <algorithm>
#define SIZE 1000000
using namespace std;

bool str[SIZE + 1] = { false };
void cantor(int start, int end);
void print_cantor(int start, int end);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int start = 1,end = 1;

	while (1)
	{	
		start = 1, end = 1;
		cin >> n;
		if (cin.eof())
			break;
		for (int j = 0; j < n; j++)
			end *= 3;
		cantor(1, end);
		print_cantor(1, end);
		for (int i = 1; i < end+1; i++)
			str[i] = false;
	}

	return 0;
}
void cantor(int start, int end)
{
	if (end - start + 1 <= 1)   // Base case
		return;
	int size = end - start + 1;
	int low = start + size / 3;
	int upp = low + size/3;
	for (int i = low; i < upp; i++)
		str[i] = true;
	// Recursion
	cantor(start, low-1);
	cantor(upp, end);
}
void print_cantor(int start, int end)
{
	for (int i = start; i < end+1; i++)
		if (str[i])
			cout << " ";
		else
			cout << "-";
	cout << "\n";
}