#include <iostream>
using namespace std;

int sudoku[9][9];
bool solved = false;

bool check(int y, int x, int n) {
    for (int i = 0; i < 9; i++)
        if (sudoku[i][x] == n || sudoku[y][i] == n) return false;

    int sy = (y / 3) * 3, sx = (x / 3) * 3;
    for (int i = sy; i < sy + 3; i++)
        for (int j = sx; j < sx + 3; j++)
            if (sudoku[i][j] == n) return false;

    return true;
}

void run(int y, int x) {
    if (y == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j] << " ";
            cout << "\n";
        }
        solved = true;
        return;
    }

    if (x == 9) {
        run(y + 1, 0);
        return;
    }

    if (sudoku[y][x] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (check(y, x, i)) {
                sudoku[y][x] = i;
                run(y, x + 1);
                if (solved) 
                    return; 
                sudoku[y][x] = 0;
            }
        }
    }
    else {
        run(y, x + 1);
    }
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> sudoku[i][j];

    run(0, 0);
}
