#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char board[8][8];
    int cnt = 0;
    
    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 8; j++) {
            board[i][j] = row[j];
        }
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                if (board[i][j] == 'F') 
                {
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt;
    return 0;
}