#include <iostream>
#include <vector>

using namespace std;

int graph[101][101]; // 관계를 나타내는 그래프
int visited[101];           // 방문 여부를 나타내는 배열
int result = -1;                  // 최종 결과

void dfs(int current, int end, int depth) {
    if (current == end) {
        result = depth; // 목표 노드에 도달한 경우 촌수 업데이트
        return;
    }

    for (int i = 1; i <= 101; ++i) {
        if (graph[current][i] && !visited[i]) {
            visited[i] = 1; // 방문 표시
            dfs(i, end, depth + 1);
            visited[i] = 0; // 백트래킹
        }
    }
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

    visited[target1] = 1; // 시작 노드 방문 표시
    dfs(target1, target2, 0);

    cout << result << endl;

    return 0;
}
