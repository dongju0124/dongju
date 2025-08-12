#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> friends[501];
bool visited[501];
int result = 0;

int N, M;

void bfs(int start)
{
	queue<pair<int,int>> q;
	q.push({ start,0 });

	while (!q.empty())
	{
		int current = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (depth >= 2) 
			continue;

		for (auto next : friends[current])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push({ next, depth + 1 });
				result++;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	visited[1] = true;

	bfs(1);

	cout << result << endl;
}