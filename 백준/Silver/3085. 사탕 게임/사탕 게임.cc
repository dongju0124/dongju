#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N;
char candy[51][51];
int ans = 0;

void eat_row() {
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int j = 0; j < N - 1; j++) {
            if (candy[i][j] == candy[i][j + 1]) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 1;
            }
        }
    }
}

void eat_col() {
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int j = 0; j < N - 1; j++) {
            if (candy[j][i] == candy[j + 1][i]) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 1;
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> candy[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            swap(candy[i][j], candy[i][j + 1]);
            eat_col();
            eat_row();
            swap(candy[i][j], candy[i][j + 1]);

            swap(candy[j][i], candy[j + 1][i]);
            eat_col();
            eat_row();
            swap(candy[j][i], candy[j + 1][i]);
        }
    }

    cout << ans;
    return 0;
}
