#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited[start] = true;
    int kevin_bacon = 0;

    while (!q.empty()) {
        int current = q.front().first;
        int distance = q.front().second;
        q.pop();

        kevin_bacon += distance;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push({ neighbor, distance + 1 });
                visited[neighbor] = true;
            }
        }
    }

    return kevin_bacon;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min_kevin_bacon = 99999999999999999999;
    int min_person = 0;

    for (int i = 1; i <= N; ++i) {
        vector<bool> visited(101, false);
        int kevin_bacon = bfs(i, graph, visited);

        if (kevin_bacon < min_kevin_bacon) {
            min_kevin_bacon = kevin_bacon;
            min_person = i;
        }
    }

    cout << min_person << endl;

    return 0;
}
