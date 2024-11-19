#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int R, C;
bool visited[27];
vector<vector<char>> arr;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int result = 0;
int cnt = 0;

void dfs(int x, int y, int cnt)
{
	result = max(result, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[arr[nx][ny] - 'A'])
		{
			visited[arr[nx][ny] - 'A'] = 1;
			dfs(nx, ny, cnt+1);
			visited[arr[nx][ny] - 'A'] = 0;
		}
	}
}

int main()
{
	cin >> R >> C;
	arr.resize(R, vector<char>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
		}
	}

	visited[arr[0][0] - 'A'] = 1;

	dfs(0, 0, 1);

	cout << result;
}