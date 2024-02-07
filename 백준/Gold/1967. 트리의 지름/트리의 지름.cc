#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;

// 각 노드에서 연결된 노드와 가중치를 저장할 벡터
vector<pair<int, int>> tree[MAX];

// 각 노드의 방문 여부를 저장할 배열
bool visited[MAX];

// 최대 거리와 해당 거리에서의 가장 먼 노드
int maxDistance = 0;
int farthestNode = 0;

// DFS를 사용하여 가장 먼 노드를 찾는 함수
void dfs(int node, int currentDistance) {
    visited[node] = true;

    // 현재 거리가 최대 거리보다 크면 업데이트
    if (currentDistance > maxDistance) {
        maxDistance = currentDistance;
        farthestNode = node;
    }

    // 현재 노드와 연결된 모든 이웃 노드에 대해 DFS 호출
    for (const auto& neighbor : tree[node]) {
        int nextNode = neighbor.first;
        int weight = neighbor.second;
        if (!visited[nextNode]) {
            dfs(nextNode, currentDistance + weight);
        }
    }
}

// 트리의 지름을 찾는 함수
int treeDiameter(int n) {
    maxDistance = 0;
    farthestNode = 0;

    // 방문 여부 배열 초기화
    fill(visited, visited + n + 1, false);

    // DFS를 사용하여 루트(노드 1)에서 가장 먼 노드 찾기
    dfs(1, 0);

    // 두 번째 DFS를 위해 방문 여부 배열 재설정
    fill(visited, visited + n + 1, false);

    maxDistance = 0;

    // 가장 먼 노드에서 다시 DFS를 사용하여 트리의 지름 찾기
    dfs(farthestNode, 0);

    return maxDistance;
}

int main() {
    int n;
    cin >> n;

    // 간선 정보 입력 및 트리에 저장
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    // 트리의 지름 계산
    int result = treeDiameter(n);

    // 결과 출력
    cout << result << endl;

    return 0;
}
