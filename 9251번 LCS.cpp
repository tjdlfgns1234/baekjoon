#include <iostream>
#include <algorithm>
#include <string>
#define SIZE 1000
using namespace std;

int dp[SIZE+1][SIZE+1] = { 0 };

int Lcs(string& ori, string& dest);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string ori;
	string dest;
	cin >> ori >> dest;
			
	cout << Lcs(ori, dest);

	return 0;
}
int Lcs(string& ori, string& dest)
{
	int osize = ori.size();
	int dsize = dest.size();
	
	for (int i = 1; i < osize+1; i++)
		for (int j = 1; j < dsize+1; j++)
			if (ori[i-1] == dest[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[osize][dsize];
}