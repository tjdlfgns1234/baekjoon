#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define maxVal 100000
using namespace std;

// 트리로만 생각하지 말고 그래프로 생각하기!!

int main(void)
{
	ios::sync_with_stdio(NULL);
	::cout.tie(NULL), cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	int ans = 0;
	vector<int> cost(maxVal * 2 + 1);
	vector<int> back(maxVal * 2 + 1);
	queue<int>q;

	for (auto& i : cost)
		i = 2 * maxVal + 1;

	for (auto& i : back)
		i = 2 * maxVal + 1;

	cost[n] = 0;

	q.push(n); // 시작점 생성

	if (n == k) {
		cout << 0 << "\n" << n;
		return 0;
	}
	else {


		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (cur == k) {
				continue;
			}

			// 3개의 연산
			int m1 = cur - 1;
			int m2 = cur + 1;
			int m3 = cur * 2;

			if (0 <= m1) {  // m1 연산이 가능할 경우
				if (cost[cur] + 1 <= cost[m1]) {
					q.push(m1), cost[m1] = cost[cur] + 1;
					back[m1] = cur;
				}
			}

			if (k >= m2) {  // m2 연산이 의미가 있을 경우
				if (cost[cur] + 1 <= cost[m2]) {
					q.push(m2), cost[m2] = cost[cur] + 1;
					back[m2] = cur;
				}
			}

			if (k + 1 >= m3) {  // m3 연산이 의미가 있을 경우
				if (cost[cur] + 1 <= cost[m3]) {
					q.push(m3), cost[m3] = cost[cur] + 1;
					back[m3] = cur;
				}
			}
		}

		ans = cost[k];

		int start = k;

		stack<int> ans2;
		ans2.push(start);

		while (1) {
			if (back[start] != n)
				start = back[start], ans2.push(start);
			else {
				ans2.push(n);
				break;
			}
		}

		cout << ans << "\n";
		while (!ans2.empty()) {
			::cout << ans2.top() << " ";
			ans2.pop();
		}
	}
	return 0;
}