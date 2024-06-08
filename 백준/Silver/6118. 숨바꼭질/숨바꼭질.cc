#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 20000;
const int MAX_M = 50000;

int N, M;
vector<vector<int>> adj(MAX_N + 1);
vector<int> dist(MAX_N + 1, INT_MAX);

void bfs(int start) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (dist[neighbor] == INT_MAX) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    bfs(1);

    int max_dist = 0;
    int barn = -1;
    int count = 0;

    for (int i = 1; i <= N; ++i) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            barn = i;
            count = 1;
        }
        else if (dist[i] == max_dist) {
            count++;
        }
    }

    cout << barn << " " << max_dist << " " << count << endl;

    return 0;
}
