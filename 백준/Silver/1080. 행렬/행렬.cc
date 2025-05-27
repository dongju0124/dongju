#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> A, B;

void trans(int y, int x) {
    for (int i = y; i < y + 3; ++i) {
        for (int j = x; j < x + 3; ++j) {
            A[i][j] = 1 - A[i][j]; // 0 -> 1, 1 -> 0
        }
    }
}

int main() {
    cin >> N >> M;
    A.resize(N, vector<int>(M));
    B.resize(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j)
            A[i][j] = s[j] - '0';
    }

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j)
            B[i][j] = s[j] - '0';
    }

    int count = 0;
    for (int i = 0; i <= N - 3; ++i) {
        for (int j = 0; j <= M - 3; ++j) {
            if (A[i][j] != B[i][j]) {
                trans(i, j);
                ++count;
            }
        }
    }

    if (A == B) cout << count << endl;
    else cout << -1 << endl;

    return 0;
}
