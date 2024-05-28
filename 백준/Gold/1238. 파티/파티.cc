#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 987654321

int N, M, X;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> reverse_graph[1001];

vector<int> dijkstra(int start, vector<pair<int, int>> g[]) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > dist[current]) continue;

        for (const auto& edge : g[current]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[current] + weight < dist[next]) {
                dist[next] = dist[current] + weight;
                pq.push({ dist[next], next });
            }
        }
    }

    return dist;
}

int main() {
    cin >> N >> M >> X;
    int start, end, dist;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> dist;
        graph[start].push_back({ end, dist });
        reverse_graph[end].push_back({ start, dist });
    }

    // 다익스트라 알고리즘을 사용하여 각각의 마을에서 X까지의 최단 거리를 계산
    vector<int> to_X = dijkstra(X, reverse_graph);
    // 다익스트라 알고리즘을 사용하여 X에서 각각의 마을까지의 최단 거리를 계산
    vector<int> from_X = dijkstra(X, graph);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int total_time = to_X[i] + from_X[i];
        if (total_time > ans) {
            ans = total_time;
        }
    }

    cout << ans;
}
