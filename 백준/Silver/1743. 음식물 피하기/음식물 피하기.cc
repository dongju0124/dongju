#include<iostream>

using namespace std;

int map[101][101];
int N, M, K;
int ans = 0;
bool visited[101][101];
int big;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int x, int y)
{
	visited[x][y] = true;
	big++;
	int nx, ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx > 0 && nx <= N && ny > 0 && ny <= M)
		{
			if (map[nx][ny] && !visited[nx][ny])
			{
				dfs(nx, ny);
			}
		}
	}
	return big;
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) 
		{
			if (!visited[i][j] && map[i][j])
			{
				big = 0;
				int temp = dfs(i,j);

				ans = max(temp, ans);
			}
		}
	}

	cout << ans;
}