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
	cout.tie(NULL), cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	int ans = 0;
	queue<pair<int, int>>q;
	bool* visit = new bool[maxVal + 1];
	for (int i = 0; i < maxVal +1;i++)
		visit[i] = false;

	q.push({ n,0 }); // 시작점 생성

	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == k) { // 현위치가 k 라면 바로 정답.
			ans = cost;
			break;
		}

		// 3개의 연산
		int m1 = cur - 1;
		int m2 = cur + 1;
		int m3 = cur * 2;

		if (0 <= m1) {  // m1 연산이 가능할 경우
			if (!visit[m1])
				q.push({ m1, cost + 1 }), visit[m1] = true;
		}
		
		if (k >= m2) {  // m2 연산이 의미가 있을 경우
				if(!visit[m2])
					q.push({ m2, cost + 1 }), visit[m2] = true;
		}
		
		if (k+1 >= m3) {  // m3 연산이 의미가 있을 경우
			if (!visit[m3])
				q.push({ m3, cost + 1 }), visit[m3] = true;
		}
	}

	cout << ans;

	return 0;
}