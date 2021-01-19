#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	char s[106];
	while (1)
	{
		fgets(s, 105, stdin);
		if (s[0] == '.')
			break;
		bool chk = false;
		
		stack <char> stack;
		int n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(')
				stack.push('(');
			else if (s[i] == ')')
			{
				if (!stack.empty())
				{
					if (stack.top() != '(')
						chk = true, stack.pop();
					else if (stack.top() == '(')
						stack.pop();
				}
				else
					chk = true;
			}
			else if (s[i] == '[')
				stack.push('[');
			else if (s[i] == ']')
			{
				if (!stack.empty())
				{
					if (stack.top() != '[')
						chk = true, stack.pop();
					else if (stack.top() == '[')
						stack.pop();
				}
				else
					chk = true;
			}
		}
		if (!stack.empty())
			chk = true;
		if (chk)
			cout << "no" << '\n';
		else
			cout << "yes" << '\n';
	}

	return 0;
}
