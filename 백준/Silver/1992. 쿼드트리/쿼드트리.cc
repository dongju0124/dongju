#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> image;

bool isSame(int x, int y, int size) {
    char first = image[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (image[i][j] != first) return false;
        }
    }
    return true;
}

void QuadTree(int x, int y, int size) {
    if (isSame(x, y, size)) {
        cout << image[x][y];
        return;
    }

    cout << '(';
    int half = size / 2;
    QuadTree(x, y, half);                 // 1 
    QuadTree(x, y + half, half);          // 2
    QuadTree(x + half, y, half);          // 3
    QuadTree(x + half, y + half, half);   // 4
    cout << ')';
}
/* 1 2
   4 3  */
int main() {
    int N;
    cin >> N;
    image.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> image[i];
    }

    QuadTree(0, 0, N);
    cout << endl;

    return 0;
}
