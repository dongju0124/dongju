//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
//    queue<pair<int, int>> q;
//    q.push({ start, 0 });
//    visited[start] = true;
//    int kevin_bacon = 0;
//
//    while (!q.empty()) {
//        int current = q.front().first;
//        int distance = q.front().second;
//        q.pop();
//
//        kevin_bacon += distance;
//
//        for (int neighbor : graph[current]) {
//            if (!visited[neighbor]) {
//                q.push({ neighbor, distance + 1 });
//                visited[neighbor] = true;
//            }
//        }
//    }
//
//    return kevin_bacon;
//}
//
//int main() {
//    int N, M;
//    cin >> N >> M;
//
//    vector<vector<int>> graph(N + 1);
//    for (int i = 0; i < M; ++i) {
//        int a, b;
//        cin >> a >> b;
//        graph[a].push_back(b);
//        graph[b].push_back(a);
//    }
//
//    int min_kevin_bacon = 999999999999999;
//    int min_person = 0;
//
//    for (int i = 1; i <= N; ++i) {
//        vector<bool> visited(101, false);
//        int kevin_bacon = bfs(i, graph, visited);
//
//        if (kevin_bacon < min_kevin_bacon) {
//            min_kevin_bacon = kevin_bacon;
//            min_person = i;
//        }
//    }
//
//    cout << min_person << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    const int INF = 99999999999999;
    vector<vector<int>> graph(101, vector<int>(101, INF));

    // 자기 자신으로 가는 비용은 0으로 초기화
    for (int i = 1; i <= N; ++i)
        graph[i][i] = 0;

    // 친구 관계 입력
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    // 플로이드-와샬 알고리즘
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // 케빈 베이컨의 수 계산
    int min_kevin_bacon = INF;
    int min_person = 0;

    for (int i = 1; i <= N; ++i) {
        int kevin_bacon = 0;
        for (int j = 1; j <= N; ++j) {
            if (graph[i][j] != INF) {
                kevin_bacon += graph[i][j];
            }
        }

        if (kevin_bacon < min_kevin_bacon) {
            min_kevin_bacon = kevin_bacon;
            min_person = i;
        }
    }

    cout << min_person << endl;

    return 0;
}
