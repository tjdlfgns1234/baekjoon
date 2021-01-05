#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> ori;
	vector<int> com;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		ori.push_back(tmp);
		com.push_back(tmp);
	}
	// 좌표 압축 과정
	sort(com.begin(), com.end());  // unique 함수 사용을 위한 정렬
	com.erase(unique(com.begin(), com.end()),com.end());  // 중복되지 않은 값들만 남김
	
	for (auto i : ori)
		cout << (upper_bound(com.begin(), com.end(), i) - com.begin()) - 1 << ' ';

	return 0;
}