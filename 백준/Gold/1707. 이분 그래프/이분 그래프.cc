#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int K, V, E;
vector<int> graph[20001];
int visited[20001];// 0: 미방문, 1: 빨강, -1: 파랑

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();

        for (int v : graph[u]) {
            if (visited[v] == 0) {
                visited[v] = -visited[u];
                q.push(v);
            }
            else if (visited[v] == visited[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    while (K--) {
        cin >> V >> E;

        for (int i = 1; i <= V; i++) {
            graph[i].clear();
            visited[i] = 0;
        }

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool bip = true;
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                if (!bfs(i)) {
                    bip = false;
                    break;
                }
            }
        }

        if (bip)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}
