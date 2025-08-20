#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, K;
vector<int> coins;
int result = 0;
int dp[10001];

int main()
{
	cin >> N >> K;

	coins.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> coins[i];
	}

	sort(coins.begin(), coins.end());
	for (int i = 1; i <= K; i++)
	{
		dp[i] = 10001;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = coins[i]; j <= K; j++)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);

		}
	}

	if (dp[K] == 10001)
		cout << -1;
	else
		cout << dp[K];

}