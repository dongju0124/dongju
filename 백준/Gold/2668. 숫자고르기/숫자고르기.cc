#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[101];
int visited[101];
vector<int> result;

void dfs(int x, int cur)
{
	if (visited[cur])
	{
		if (x == cur)
		{
			result.push_back(x);
		}
		return;
	}

	visited[cur] = 1;
	dfs(x, arr[cur]);
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		fill(visited, visited + N + 1, 0);
		dfs(i, i);
	}

	sort(result.begin(), result.end()); 

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
		
}