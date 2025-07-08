#include <iostream>
#include <string>
using namespace std;

const int MAX = 51;
string grid[MAX];
string result[MAX];
bool covered[MAX][MAX];
int R, C;

bool canPlaceTile(int r, int c) {
    if (r + 1 >= R || c + 1 >= C) return false;
    for (int dr = 0; dr < 2; dr++)
        for (int dc = 0; dc < 2; dc++)
            if (grid[r + dr][c + dc] != '#' || covered[r + dr][c + dc])
                return false;
    return true;
}

void placeTile(int r, int c) {
    result[r][c] = '/';
    result[r][c + 1] = '\\';
    result[r + 1][c] = '\\';
    result[r + 1][c + 1] = '/';
    for (int dr = 0; dr < 2; dr++)
        for (int dc = 0; dc < 2; dc++)
            covered[r + dr][c + dc] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            cin >> grid[i];

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                covered[i][j] = false;

        for (int i = 0; i < R; i++) {
            result[i] = grid[i];
            for (int j = 0; j < C; j++)
                if (grid[i][j] == '#') 
                    result[i][j] = '.';
        }

        bool possible = true;

        for (int i = 0; i < R && possible; i++) {
            for (int j = 0; j < C && possible; j++) {
                if (grid[i][j] == '#' && !covered[i][j]) {
                    if (!canPlaceTile(i, j)) {
                        possible = false;
                        break;
                    }
                    placeTile(i, j);
                }
            }
        }

        if (possible) {
            for (int i = 0; i < R && possible; i++)
                for (int j = 0; j < C && possible; j++)
                    if (grid[i][j] == '#' && !covered[i][j])
                        possible = false;
        }

        cout << "Case #" << t << ":\n";
        if (possible) {
            for (int i = 0; i < R; i++)
                cout << result[i] << "\n";
        }
        else {
            cout << "Impossible\n";
        }
    }
    return 0;
}