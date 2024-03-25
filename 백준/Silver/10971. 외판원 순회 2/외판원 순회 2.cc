#include<iostream>
#include<vector>

using namespace std;

int N;
int m = 987654321;
vector<vector<int>> w;
bool visited[10];

void dfs(int cc, int cnt, int cost)
{
	if (cnt == N - 1)
		if (w[cc][0] != 0) {
			m = min(m, cost + w[cc][0]);
			return;
		}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && w[cc][i] != 0)
		{
			visited[cc] = true;
			dfs(i, cnt+1, cost + w[cc][i]);
			visited[cc] = false;
		}
	}
}

void mincost()
{
	visited[0] = true;
	dfs(0, 0, 0);
}

int main()
{
	cin >> N;

	w.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> w[i][j];
		}
	}

	mincost();

	cout << m;
}