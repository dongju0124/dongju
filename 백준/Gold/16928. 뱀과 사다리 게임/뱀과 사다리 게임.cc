#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int sn[101];
int cnt[101];
int N, M;
int x, y;
int u, v;

void makeMap()
{
	for (int i = 0; i <= 100; i++)
	{
		sn[i] = i;
		cnt[i] = -1;
	}
}

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	cnt[x] = 0;
	while (!q.empty())
	{
		int nx = q.front();
		q.pop();

		for (int i = 1; i <= 6 ; i++) 
		{
			int ny = nx + i;

			if (ny > 100) 
				continue;
			
			if (cnt[sn[ny]] == -1)
			{
				cnt[sn[ny]] = cnt[nx] + 1;
				q.push(sn[ny]);
			}
		}
	}
}

int main()
{
	makeMap();

	cin >> N >> M;
	for (int i = 0; i < N+M; i++)
	{
		cin >> x >> y;
		sn[x] = y;
	}

	bfs(1);

	cout << cnt[100];
}
