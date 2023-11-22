#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int main() {
    int N;
    cin >> N;

    // 그래프 초기화
    vector<vector<char>> graph(N, vector<char>(N));
    vector<vector<int>> dist(N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];

            // 자기 자신과의 거리는 0으로 초기화
            if (i == j) dist[i][j] = 0;
            // 친구인 경우 거리를 1로 초기화
            else if (graph[i][j] == 'Y') dist[i][j] = 1;
        }
    }

    // 플로이드-와샬 알고리즘
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int maxTwoFriends = 0;

    // 2-친구의 수 계산
    for (int i = 0; i < N; ++i) {
        int twoFriends = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j && dist[i][j] <= 2) {
                twoFriends++;
            }
        }
        maxTwoFriends = max(maxTwoFriends, twoFriends);
    }

    cout << maxTwoFriends << endl;

    return 0;
}
