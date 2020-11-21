#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#define SIZE 1000
using namespace std;

int dp[SIZE + 1][SIZE + 1] = { 0 };
int Lcs(string& ori, string& dest);
void Print_Lcs(string& ori, string& dest);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string ori;
	string dest;
	cin >> ori >> dest;

	int result = Lcs(ori, dest);
	cout << result << "\n";

	Print_Lcs(ori, dest);

	return 0;
}
int Lcs(string& ori, string& dest) // LCS길이를 구하는 함수
{
	int osize = ori.size();
	int dsize = dest.size();

	for (int i = 1; i < osize + 1; i++)
		for (int j = 1; j < dsize + 1; j++)
			if (ori[i - 1] == dest[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);


	return dp[osize][dsize];
}
void Print_Lcs(string& ori, string& dest)
{
	int osize = ori.size();
	int dsize = dest.size();
	stack <char> s; // 출력할 원소를 저장하는 스택
	int cnt = dp[osize][dsize];
	
	for (int j = dsize,i = osize; j > 0 && i > 0; j--, i--)
		if (ori[i-1] == dest[j-1])
			s.push(ori[i-1]);
		else
			if (dp[i][j] == dp[i - 1][j])
				j++;
			else if (dp[i][j] == dp[i][j-1])
				i++;

	while(!s.empty())
		cout << s.top(),s.pop();
}