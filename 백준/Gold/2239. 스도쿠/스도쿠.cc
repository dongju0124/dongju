#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[9][9];
bool solved = false;

bool check(int row, int col, int num) {
    // 행, 열 확인
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) 
            return false;
        if (board[i][col] == num) 
            return false;
    }

    // 3x3 블록 확인
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num) 
                return false;
        }
    }

    return true;
}

void dfs(int row, int col) {
    if (row == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        solved = true;
        return;
    }

    if (board[row][col] != 0) {
        if (col == 8) 
            dfs(row + 1, 0);
        else
            dfs(row, col + 1);
    }
    else {
        for (int num = 1; num <= 9; num++) {
            if (check(row, col, num)) {
                board[row][col] = num;
                if (col == 8) 
                    dfs(row + 1, 0);
                else 
                    dfs(row, col + 1);
                if (solved) //사전순 출력을 위해 이미 완성시 끝
                    return;
                board[row][col] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 9; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    dfs(0, 0);
    return 0;
}
