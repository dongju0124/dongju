#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int N;
long long cnt;
int x, y;
long long dp[101][101];


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{ 
		for (int j = 0; j < N; j++) 
		{
			cin >> map[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == N - 1 && j == N - 1)
				continue;

			if (dp[i][j] != 0)
			{
				int down = j + map[i][j];
				int right = i + map[i][j];

				if (down < N)
					dp[i][down] = dp[i][down] + dp[i][j];
				if (right < N)
					dp[right][j] = dp[right][j] + dp[i][j];
			}

		}
	}
	
	cout << dp[N - 1][N - 1];
}