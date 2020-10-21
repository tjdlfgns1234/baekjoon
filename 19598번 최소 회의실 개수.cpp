#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Time {
	int start;
	int end;
};

vector <struct Time> time;
typedef struct Time T;
bool compare(const T& a, const T& b)
{
	if (a.start < b.start)
		return true;
	else if (a.start == b.start)
		return a.end < b.end;
	else
		return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector <int>, greater<int>> q;	// 오름차순 큐
	T tmp;
	int n;
	int findmin = 987654321;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp.start >> tmp.end;
		time.push_back(tmp);
	}
	sort(time.begin(), time.end(), compare);
	vector <struct Time> ::iterator it = time.begin();
	q.push(it->end);
	it++;
	for (; it != time.end(); it++)
	{
		if (q.top() > it->start)
			q.push(it->end);
		else
			q.pop(), q.push(it->end);
	}

	cout << q.size();

	return 0;
}