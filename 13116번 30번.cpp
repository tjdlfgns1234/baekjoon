#include <iostream>
#include <algorithm>

using namespace std;

int lca(int a, int b);
int depth(int a);


int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << lca(a, b)*10 << '\n';
	}


	return 0;
}
int lca(int a, int b)
{
	int dep_a = depth(a), dep_b = depth(b);
	while (1)
	{
		if (dep_a > dep_b)
		{
			dep_a--;
			a = (a / 2);
		}
		else if (dep_a < dep_b)
		{
			dep_b--;
			b = (b / 2);
		}
		else
		{
			if (a == b)
				return a;
			else
			{
				dep_b--;
				b = (b / 2);
				dep_a--;
				a = (a / 2);
			}
		}
	}
}
int depth(int a)
{
	int dep_a=0;
	while (1)
	{
		a /= 2;
		if (a == 0)
			break;
		dep_a++;
	}
	return dep_a;
}