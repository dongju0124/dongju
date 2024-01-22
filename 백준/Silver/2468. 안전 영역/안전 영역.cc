#include <iostream>
#include<vector>
#include <cstring>
using namespace std;

int N;
int map[101][101];
int visited[101][101];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
int ans;

void dfs(int y, int x, int rain) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx<0 || nx >=N || ny < 0 || ny >= N)
		{
			continue;
		}

		if (!visited[ny][nx] && map[ny][nx] > rain)
		{
			dfs(ny, nx, rain);
		}
	}

}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}


	for (int k = 0; k < 100; k++)
	{
		int cnt = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0 ; j < N; j++)
			{
				if (map[i][j] > k && !visited[i][j])
				{
					cnt++;
					dfs(i, j, k);
				}
			}
		}
		if (cnt > ans)
		{
			ans = cnt;
		}
	}

	cout << ans;

}