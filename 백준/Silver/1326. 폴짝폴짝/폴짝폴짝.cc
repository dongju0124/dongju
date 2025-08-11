#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int bridge[10001];
bool visited[10001];

int N;
int a, b;
int cnt = 123456789;
int jump = -1;


void bfs(int x)
{
	visited[x] = true;
	queue<pair<int, int>> q;
	q.push({ x,0 });

	while (!q.empty())
	{
		int nx = q.front().first;
		int nj = q.front().second;
		q.pop();
		
		if (nx == b)
		{
			jump = nj;
			return;
		}

		for (int i = nx + bridge[nx]; i <= N; i = i + bridge[nx])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push({ i,nj + 1 });
			}
		}		
		for (int i = nx - bridge[nx]; i >= 1; i = i - bridge[nx])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push({ i,nj + 1 });
			}
		}
	}

}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> bridge[i];
	}

	cin >> a >> b;

	bfs(a);

	cout << jump;
}