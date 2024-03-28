#include<iostream>
#include<algorithm>
using namespace std;

char grid[101][101];
bool visited[101][101];
int N;
int normalCnt = 0;
int rgCnt = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (!visited[nx][ny] && grid[x][y] == grid[nx][ny])
			{
				visited[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];

		}
	}	


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j];
				dfs(i, j);
				normalCnt++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == 'G')
			{
				grid[i][j] = 'R';
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j];
				dfs(i, j);
				rgCnt++;
			}
		}
	}

	cout << normalCnt << " " << rgCnt;



}