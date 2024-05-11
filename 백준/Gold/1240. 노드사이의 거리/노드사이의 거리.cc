#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> tree[1001]; // 각 노드의 연결 정보와 거리를 저장하는 벡터

// 두 노드 사이의 최단 거리를 구하는 함수
int shortestDistance(int start, int end, int n) {
    vector<int> dist(n + 1, 123456789); // 각 노드까지의 거리를 저장할 배열
    dist[start] = 0; // 시작 노드의 거리는 0으로 초기화
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next : tree[cur]) {
            int nextNode = next.first;
            int nextDist = next.second;
            if (dist[nextNode] > dist[cur] + nextDist) {
                dist[nextNode] = dist[cur] + nextDist;
                q.push(nextNode);
            }
        }
    }
    return dist[end];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        tree[u].push_back({ v, d });
        tree[v].push_back({ u, d });
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << shortestDistance(u, v, n) << endl;
    }

    return 0;
}
