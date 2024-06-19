#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 나이트의 이동 가능한 8가지 방향
const vector<pair<int, int>> directions = {
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
};

// BFS를 사용하여 최소 이동 횟수를 계산하는 함수
int knight_moves(int l, pair<int, int> start, pair<int, int> end) {
    vector<vector<bool>> visited(l, vector<bool>(l, false));
    queue<tuple<int, int, int>> q; // (x, y, 이동 횟수)

    q.push(make_tuple(start.first, start.second, 0));
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        int x, y, moves;
        tie(x, y, moves) = q.front();
        q.pop();

        if (x == end.first && y == end.second) {
            return moves;
        }

        for (size_t i = 0; i < directions.size(); ++i) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_tuple(nx, ny, moves + 1));
            }
        }
    }

    return -1; // 목표에 도달할 수 없는 경우
}

int main() {
    int t;
    cin >> t;
    vector<int> results;

    for (int i = 0; i < t; ++i) {
        int l;
        cin >> l;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        pair<int, int> start = make_pair(sx, sy);
        pair<int, int> end = make_pair(ex, ey);

        if (start == end) {
            results.push_back(0);
        }
        else {
            results.push_back(knight_moves(l, start, end));
        }
    }

    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
