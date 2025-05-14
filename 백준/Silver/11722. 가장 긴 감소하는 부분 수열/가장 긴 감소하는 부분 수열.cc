#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000];
int dp[1000];
int main()
{
	int N;
	cin >> N;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
}