#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#define SIZE 50

using namespace std;

list <int> mem[SIZE + 1];	// x가 참가한 파티
list <int> par[SIZE + 1];	// 파티 x에 참가한 사람들
bool visit[SIZE + 1] = { false };
bool result[SIZE + 1] = { false };
void dfs();

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int n, p;
	int t;
	int ans = 0;
	cin >> n >> p;
	cin >> t;
	int x;
	for (int i = 0; i < t; i++) // 진실을 아는 사람
		cin >> x, mem[0].push_front(x);

	int person;
	for (int j = 1; j < p+1; j++)
	{
		cin >> person;
		for (int i = 0; i < person; i++) // x가 참가한 파티
			cin >> x, mem[x].push_front(j),par[j].push_front(x);
	}
	dfs();

	for (int i = 1; i < p + 1; i++)
		if (!result[i])
			ans++;
	cout << ans;

	return 0;
}
void dfs()
{
	stack <int> person;
	person.push(0);
	list<int>::iterator it,it2;
	int now;

	now = person.top(); // 진실을 알고 있는 사람
	person.pop();
	for (it = mem[now].begin(); it != mem[now].end(); it++)
		person.push(*it);

	while (!person.empty())
	{
		now = person.top(); // 진실을 알고 있는 사람
		person.pop();
		visit[now] = true;	// 이미 조사한 사람
		for (it = mem[now].begin(); it != mem[now].end(); it++)
			for (it2 = par[*it].begin(); it2 != par[*it].end(); it2++)
			{
				result[*it] = true; // 진실을 알고 있는 사람이 파티 참가
				if (!visit[*it2])
					person.push(*it2);	// 그사람을 통해 진실을 안사람
			}
	}
}