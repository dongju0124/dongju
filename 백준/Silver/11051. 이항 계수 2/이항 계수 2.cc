#include<iostream>
using namespace std;

long long dp[1001];
int N, K;

long long power(long long base, long long exp)
{
	long long result = 1;
	while (exp > 0) {
		if (exp % 2 == 1)
			result = (result * base) % 10007;
		base = (base * base) % 10007;
		exp /= 2;
	}
	return result;
}

int main()
{
	cin >> N >> K;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] * i)%10007;
	}


	long long k = (dp[K] * dp[N - K]) % 10007;

	cout << (dp[N] * power((dp[K] * dp[N - K]), 10005)) % 10007;
}