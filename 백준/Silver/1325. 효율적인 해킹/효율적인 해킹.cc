#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> com[10001];
bool visited[10001];
int cnt = 0;
int ans[10001];
int max_hack = 0;

void dfs(int n)
{
	cnt++;
	visited[n] = true;
	for (int k : com[n]) {
		if (!visited[k])
		{
			dfs(k);		
		}
	}
}

int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		com[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		
		cnt = 0;
		dfs(i);
		
		ans[i] = cnt;
		max_hack = max(ans[i], max_hack);
	}

	for (int i = 1; i <= N; i++)
		if (max_hack == ans[i])
			cout << i << " ";

	
}