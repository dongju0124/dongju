#include<iostream>
using namespace std;

long long DP[101][10];

int N;

int main()
{
	cin >> N;

	for (int i = 0; i < 9; i++)
	{
		DP[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				DP[i][j] = DP[i - 1][1] % 1000000000;
			else if (j == 9)
				DP[i][j] = DP[i - 1][8] % 1000000000;
			else
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
		}
	}

	long long cnt = 0;

	for (int i = 0; i < 10; i++)
	{
		cnt = cnt + DP[N][i];
	}

	cout << cnt % 1000000000;
}