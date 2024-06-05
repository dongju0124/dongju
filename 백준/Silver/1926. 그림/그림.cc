#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> paper;
vector<vector<bool>> visited;

int dx[] = { 1, -1, 0, 0 }; // 오른쪽, 왼쪽, 위, 아래
int dy[] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
    visited[x][y] = true;
    int area = 1; // 현재 칸도 포함

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && paper[nx][ny] == 1 && !visited[nx][ny]) {
            area += dfs(nx, ny);
        }
    }

    return area;
}

int main() {
    cin >> n >> m;
    paper.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int numberOfPictures = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == 1 && !visited[i][j]) {
                numberOfPictures++;
                maxArea = max(maxArea, dfs(i, j));
            }
        }
    }

    cout << numberOfPictures << endl;
    cout << maxArea << endl;

    return 0;
}
