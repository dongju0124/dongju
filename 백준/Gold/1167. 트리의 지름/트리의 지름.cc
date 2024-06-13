#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100001;
vector<pair<int, int>> adj[MAX]; // 인접 리스트: (연결된 정점, 거리)
bool visited[MAX]; 
int dist[MAX];

// BFS 함수: 시작 정점으로부터 가장 먼 정점과 그 거리를 찾음
void bfs(int start, int& farthestNode, int& maxDistance) {
    memset(visited, false, sizeof(visited)); // 방문 여부 배열 초기화
    memset(dist, 0, sizeof(dist));

    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    maxDistance = 0; // 최대 거리 초기화
    farthestNode = start; // 가장 먼 정점 초기화

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto& edge : adj[node]) { // 현재 정점과 연결된 모든 정점에 대해
            int nextNode = edge.first;
            int weight = edge.second;

            if (!visited[nextNode]) {
                visited[nextNode] = true;
                dist[nextNode] = dist[node] + weight;
                q.push(nextNode);

                if (dist[nextNode] > maxDistance) {
                    maxDistance = dist[nextNode];
                    farthestNode = nextNode;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V;
    cin >> V;

    for (int i = 0; i < V; i++) {
        int u;
        cin >> u;
        while (true) {
            int v, w;
            cin >> v;
            if (v == -1) 
                break;
            cin >> w;
            adj[u].emplace_back(v, w);
        }
    }

    int farthestNode, maxDistance;

    // 단계 1: 임의의 정점(여기서는 1번 정점)에서 BFS를 시작하여 가장 먼 정점을 찾음
    bfs(1, farthestNode, maxDistance);

    // 단계 2: 첫 번째 BFS에서 찾은 가장 먼 정점에서 다시 BFS를 수행하여 트리의 지름을 계산
    bfs(farthestNode, farthestNode, maxDistance);

    cout << maxDistance << "\n"; // 트리의 지름 출력

    return 0;
}
