#include<iostream>
using namespace std;

int dp[31][31];

int comb(int n, int m)
{
	if (dp[n][m])
		return dp[n][m];
	else
	{
		dp[n][m] = comb(n - 1, m - 1) + comb(n - 1, m);
		return dp[n][m];
	}
}

int main()
{
	int TC;
	cin >> TC;

	for (int i = 0; i < 31; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	while (TC--)
	{
		int N, M;
		cin >> N >> M;
		cout << comb(M, N) << "\n";
	}
}
