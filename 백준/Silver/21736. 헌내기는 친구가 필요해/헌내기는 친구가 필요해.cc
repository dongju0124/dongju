#include<iostream>

using namespace std;

char map[601][601];
bool visited[601][601];
int N, M;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int cnt = 0;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (!visited[nx][ny] && map[nx][ny] != 'X')
			{
				visited[nx][ny] = true;
				if (map[nx][ny] == 'P')
					cnt++;
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	int startX, startY;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'I')
			{
				visited[i][j] = true;
				startX = i;
				startY = j;
			}
		}
	}

	dfs(startX, startY);

	if (cnt == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << cnt;
	}

}