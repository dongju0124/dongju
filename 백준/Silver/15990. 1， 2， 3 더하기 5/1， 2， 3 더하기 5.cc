#include<iostream>
#include<algorithm>

using namespace std;

int T, N;
long long dp[100001][4];

int main()
{
	cin >> T;

	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int n = 4; n <= 100001; n++) {
		if (n - 1 >= 0)
			dp[n][1] = (dp[n - 1][2] + dp[n - 1][3]) % 1000000009;
		
		if (n - 2 >= 0) 
			dp[n][2] = (dp[n - 2][1] + dp[n - 2][3]) % 1000000009;
	
		if (n - 3 >= 0)
			dp[n][3] = (dp[n - 3][1] + dp[n - 3][2]) % 1000000009;
		
	}


	while (T--)
	{
		cin >> N;
		long long result = (dp[N][1] + dp[N][2] + dp[N][3]) % 1000000009;
		cout << result << "\n";
	}

	


}