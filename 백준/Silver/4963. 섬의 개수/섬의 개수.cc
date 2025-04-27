#include<iostream>
#include<string.h>
using namespace std;

int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int map[50][50];
bool visited[50][50];
int w, h, x, y;

void dfs(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= w || ny < 0 || ny >= h)
			continue;
		if (!visited[ny][nx] && map[ny][nx])
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	while (1)
	{
		int cnt = 0;

		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}		
		
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visited[i][j] && map[i][j])
				{		
					dfs(i, j);
					cnt++;
				}
					
			}
		}

		cout << cnt << "\n";
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
	}
}
