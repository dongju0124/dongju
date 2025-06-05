#include<iostream>

using namespace std;

int R, C, K;
char arr[5][5];
bool visited[5][5];
int cnt = 0;

int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1, -1 ,0,0 };

void dfs(int x, int y, int depth)
{

	if (x == 0 && y == C - 1)  // 도착지
	{
		if (depth == K) cnt++;
		return;
	}


	for (int i = 0; i < 4; i++)
	{
		int nx, ny;

		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && R > nx && ny >= 0 && C > ny)
		{
			if (!visited[nx][ny] && arr[nx][ny] != 'T')
			{
				visited[nx][ny] = true;
				dfs(nx, ny, depth + 1);
				visited[nx][ny] = false;
			}
		}
	}
}

int main()
{
	cin >> R >> C >> K; 


	//(0,C-1) == 도착지, (R-1,0) == 출발지
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
		}
	}

	visited[R - 1][0] = true;
	dfs(R-1, 0, 1);

	cout << cnt;
}