#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int graph[101][101]; // 관계를 나타내는 그래프
int visited[101];           // 방문 여부를 나타내는 배열

int bfs(int start, int end, int n) {
    queue<pair<int, int>> q; // 현재 노드와 촌수를 저장하는 큐
    q.push({ start, 0 });      // 시작 노드와 촌수 0을 큐에 삽입
    visited[start] = 1;      // 시작 노드 방문 표시

    while (!q.empty()) {
        int current = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (current == end) {
            return cnt; // 목표 노드에 도달한 경우 촌수 반환
        }

        for (int i = 1; i <= n; ++i) {
            if (graph[current][i] && !visited[i]) {
                q.push({ i, cnt + 1 });
                visited[i] = 1; // 방문 표시
            }
        }
    }

    return -1; // 목표 노드에 도달하지 못한 경우 -1 반환
}

int main() {
    int n, target1, target2, m;
    cin >> n >> target1 >> target2 >> m;

    for (int i = 0; i < m; ++i) {
        int parent, child;
        cin >> parent >> child;
        graph[parent][child] = 1;
        graph[child][parent] = 1; // 양방향 그래프로 표현
    }

    int result = bfs(target1, target2, n);

    cout << result << endl;

    return 0;
}
