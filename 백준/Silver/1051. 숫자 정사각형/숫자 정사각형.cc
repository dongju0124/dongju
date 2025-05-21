#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int len;
int arr[50][50];
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp;
			cin >> temp;
			arr[i][j] = temp - '0';
		}
	}
	len = min(N, M);
	int a, b, c, d;
	int ans = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j <= N - i; j++)
		{
			for (int k = 0; k <= M - i; k++)
			{
				a = arr[j][k];
				b = arr[j + i - 1][k];
				c = arr[j][k + i - 1];
				d = arr[j + i - 1][k + i - 1];
				if (a == b && b == c && c == d)
					ans = i;
			}
		}
	}
	cout << ans * ans;
}