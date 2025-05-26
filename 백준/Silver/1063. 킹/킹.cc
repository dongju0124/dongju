#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 방향 벡터 설정
unordered_map<string, pair<int, int>> directions = {
    {"R",  {1, 0}},
    {"L",  {-1, 0}},
    {"B",  {0, -1}},
    {"T",  {0, 1}},
    {"RT", {1, 1}},
    {"LT", {-1, 1}},
    {"RB", {1, -1}},
    {"LB", {-1, -1}}
};

bool isInside(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    string kingPos, stonePos;
    int N;
    cin >> kingPos >> stonePos >> N;

    int kingX = kingPos[0] - 'A';
    int kingY = kingPos[1] - '1';

    int stoneX = stonePos[0] - 'A';
    int stoneY = stonePos[1] - '1';

    for (int i = 0; i < N; i++) {
        string move;
        cin >> move;

        int dx = directions[move].first;
        int dy = directions[move].second;

        int newKingX = kingX + dx;
        int newKingY = kingY + dy;

        if (!isInside(newKingX, newKingY)) 
            continue;

        if (newKingX == stoneX && newKingY == stoneY) 
        {
            int newStoneX = stoneX + dx;
            int newStoneY = stoneY + dy;

            if (!isInside(newStoneX, newStoneY)) 
                continue;

            stoneX = newStoneX;
            stoneY = newStoneY;
        }

        kingX = newKingX;
        kingY = newKingY;
    }

    cout << (char)(kingX + 'A') << kingY + 1 << "\n";
    cout << (char)(stoneX + 'A') << stoneY + 1 << "\n";

    return 0;
}
