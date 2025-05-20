#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int M, N, K;
int arr[100][100];
bool visited[100][100];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<int> area;
int dfs(int y, int x)
{	
	visited[y][x] = true;
	int cnt = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[ny][nx] && arr[ny][nx] == 0)
		{
			cnt += dfs(ny, nx);
		}
	}

	return cnt;
}
int main()
{
	cin >> M >> N >> K;

	while (K--)
	{
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;

		for (int i = ly; i < ry; i++)
		{
			for (int j = lx; j < rx; j++)
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0 && !visited[i][j])
			{
				visited[i][j] = true;
				area.push_back(dfs(i, j));
			}
		}
	}

	sort(area.begin(), area.end());

	cout << area.size() << "\n";
	for (int i = 0; i < area.size(); i++)
	{
		cout << area[i] << " ";
	}
}