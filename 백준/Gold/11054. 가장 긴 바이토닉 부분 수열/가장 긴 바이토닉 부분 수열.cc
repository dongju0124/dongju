#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1001];
int reverseDp[1001];
int arr[1001];
int N;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = N-1; i >= 0; i--)
	{
		reverseDp[i] = 1;
		for (int j = N-1; j >= i; j--)
		{
			if (arr[j] < arr[i] && reverseDp[i] < reverseDp[j] + 1)
				reverseDp[i] = reverseDp[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) 
	{ if (ans < dp[i] + reverseDp[i] - 1)
		ans  = dp[i] + reverseDp[i] - 1; 
	}

	cout << ans;
}