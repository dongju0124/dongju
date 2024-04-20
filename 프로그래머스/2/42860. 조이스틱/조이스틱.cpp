#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minMoves(string name) {
    int moves = 0;
    int length = name.length();
    
    // 1. 각 문자에 대한 상하 이동 횟수 계산
    for (int i = 0; i < length; ++i) {
        // 알파벳을 오름차순, 내림차순으로 이동하는 경우 중 더 적은 횟수 선택
        moves += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    int min_cursor_moves = length - 1;
    for (int i = 0; i < length; ++i) {
        // 2. 커서 이동 횟수 계산
        int next = i + 1;
        while (next < length && name[next] == 'A') {
            ++next;
        }
        // 다음 위치로 가는데 필요한 이동 횟수 (왼쪽으로 갈지, 오른쪽으로 갈지 중 작은 것 선택)
        int cursor_moves = i + length - next + min(i, length - next);
        min_cursor_moves = min(min_cursor_moves, cursor_moves);
    }
    
    // 상하 이동 횟수와 커서 이동 횟수의 합이 최소 이동 횟수
    return moves + min_cursor_moves;
}

int solution(string name) {
    return minMoves(name);
}
