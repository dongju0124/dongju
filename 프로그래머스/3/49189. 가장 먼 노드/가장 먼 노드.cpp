#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1); // 그래프 생성
    vector<int> distances(n + 1, -1); // 각 노드로부터의 거리를 저장할 배열

    // 그래프 생성
    for (auto& e : edge) {
        int a = e[0];
        int b = e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1); // 시작 노드는 1번
    distances[1] = 0;

    int max_distance = 0;
    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);

                // 가장 멀리 떨어진 노드의 거리 업데이트
                if (distances[neighbor] > max_distance) {
                    max_distance = distances[neighbor];
                    count = 1;
                } else if (distances[neighbor] == max_distance) {
                    count++;
                }
            }
        }
    }

    return count;
}