#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, N;
vector<string> board;
vector<string> state3, state1;
int dx[] = { -1, 1, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0 };

vector<string> explodeBombs(const vector<string>& board) {
    vector<string> result(R, string(C, 'O'));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'O') {
                for (int k = 0; k < 5; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                        result[nx][ny] = '.';
                    }
                }
            }
        }
    }

    return result;
}

void printBoard(const vector<string>& board) {
    for (int i = 0; i < R; i++) {
        cout << board[i] << '\n';
    }
}


int main() {
    cin >> R >> C >> N;

    board.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    if (N == 1) {
        printBoard(board);
        return 0;
    }

    if (N % 2 == 0) {

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << 'O';
            }
            cout << '\n';
        }
        return 0;
    }


    state3 = explodeBombs(board);

    state1 = explodeBombs(state3);

    if (N % 4 == 3) {
        printBoard(state3);
    }
    else { 
        printBoard(state1);
    }

    return 0;
}