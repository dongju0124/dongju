#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
int N, M, R;
int times[100001];
bool visited[100001];
int cnt = 1;
void bfs(int start)
{	
	queue<int>q;
	visited[start] = true;
	q.push(start);
	times[start] = cnt;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto nx : graph[x])
		{
			if (!visited[nx])
			{
				visited[nx] = true;
				q.push(nx);
				times[nx] = ++cnt;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	bfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << times[i] << "\n";
	}
}