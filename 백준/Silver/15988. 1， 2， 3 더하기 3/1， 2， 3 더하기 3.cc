#include<iostream>
#include<algorithm>

using namespace std;

int T;
int N;
long long dp[1000001];

int main()
{
	cin >> T;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;


	while (T--)
	{
		cin >> N;

		for (int i = 4; i <= N; i++)
		{
			dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
		}

		cout << dp[N] << "\n";
	}
}