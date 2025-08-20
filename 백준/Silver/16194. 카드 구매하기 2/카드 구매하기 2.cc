#include<iostream>
#include<algorithm>

using namespace std;

int N;
int P[10001];
long long dp[1000001];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
		dp[i] = 123456789;
	}

	

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			dp[j] = min(dp[j], dp[j-i] + P[i]);
		}
	}

	cout << dp[N];
}