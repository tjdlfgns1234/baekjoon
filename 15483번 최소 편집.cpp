#include <iostream>
#include <algorithm>
#include <string>
#define SIZE 1000
using namespace std;

int dp[SIZE+1][SIZE+1] = { 0 };

int EditDistance(string& str1, string& str2);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str1;
	string str2;
	cin >> str1 >> str2;
			
	cout << EditDistance(str1, str2);

	return 0;
}
int EditDistance(string& str1, string& str2)
{
	int size1 = str1.size();
	int size2 = str2.size();

	// 초기화
	for (int i = 0; i < size1+1; i++) dp[i][0] = i;
	for (int i = 0; i < size2+1; i++) dp[0][i] = i;
		
	for (int i = 1; i < size1 + 1; i++)
		for (int j = 1; j < size2 + 1; j++)
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i-1][j - 1];
			else
				dp[i][j] = min(min(dp[i-1][j-1]+1,dp[i][j-1]+1),dp[i-1][j]+1);

	return dp[size1][size2];
}