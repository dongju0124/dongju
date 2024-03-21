#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int sum = 0;
int usingApp[101];
int endCost[101];
int dp[10001];

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> usingApp[i];
	}	
	for (int i = 0; i < N; i++)
	{
		cin >> endCost[i];
		sum += endCost[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = sum; j >= endCost[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - endCost[i]] + usingApp[i]);
		}
	}


	for (int i = 0; i <= sum; i++)
	{
		if (dp[i] >= M)
		{
			cout << i << endl;
			break;
		}
	}

	
}