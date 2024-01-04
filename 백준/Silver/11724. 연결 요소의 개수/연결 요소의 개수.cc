#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1001] = { false };
int N, M;
vector<int>edges[1001];

void dfs(int n)
{
    visited[n] = true;
    for (int i = 0; i < edges[n].size(); i++)
    {
        int next = edges[n][i];
        if (!visited[next])
        {
            dfs(next);
        }
    }
}


int main() {

    cin >> N >> M;
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }

    }

    cout << cnt;

    return 0;
}