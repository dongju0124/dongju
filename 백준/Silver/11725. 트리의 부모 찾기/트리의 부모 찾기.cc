#include<iostream>
#include<vector>

using namespace std;

vector<int> graph[100001];
int parent[100001];
int N;

void dfs(int node, int par) {
	parent[node] = par;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (next != par) {
			dfs(next, node);
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}
}