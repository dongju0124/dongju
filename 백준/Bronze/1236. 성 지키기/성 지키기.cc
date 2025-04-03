#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> castle(N);
    for (int i = 0; i < N; ++i) {
        cin >> castle[i];
    }

    vector<bool> rowHasGuard(N, false);
    vector<bool> colHasGuard(M, false);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (castle[i][j] == 'X') {
                rowHasGuard[i] = true;
                colHasGuard[j] = true;
            }
        }
    }

    int emptyRows = 0, emptyCols = 0;
    for (int i = 0; i < N; ++i) {
        if (!rowHasGuard[i]) emptyRows++;
    }
    for (int j = 0; j < M; ++j) {
        if (!colHasGuard[j]) emptyCols++;
    }

    cout << max(emptyRows, emptyCols) << endl;

    return 0;
}
