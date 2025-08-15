#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct State {
    vector<int> square;
    int moves;

    State(vector<int> s, int m) : square(s), moves(m) {}
};

// A 변환: 전체를 뒤집기
vector<int> transformA(vector<int> square) {
    reverse(square.begin(), square.end());
    return square;
}

// B 변환: 위 행은 오른쪽 회전, 아래 행은 왼쪽 회전
vector<int> transformB(vector<int> square) {
    vector<int> r = square;
    // 위: 0,1,2,3 -> 3,0,1,2
    r[0] = square[3];
    r[1] = square[0];
    r[2] = square[1];
    r[3] = square[2];
    // 아래: 4,5,6,7 -> 5,6,7,4
    r[4] = square[5];
    r[5] = square[6];
    r[6] = square[7];
    r[7] = square[4];
    return r;
}

// C 변환: 가운데 4칸(1,2,5,6)의 올바른 반시계 회전 매핑
vector<int> transformC(vector<int> square) {
    vector<int> r = square;
    r[0] = square[0];
    r[1] = square[2];
    r[2] = square[5];
    r[3] = square[3];
    r[4] = square[4];
    r[5] = square[6];
    r[6] = square[1];
    r[7] = square[7];
    return r;
}

// D 변환: 1번과 5번 위치 교환
vector<int> transformD(vector<int> square) {
    swap(square[0], square[4]);
    return square;
}

// 벡터를 문자열로 변환 (맵의 키로 사용)
string vectorToString(const vector<int>& v) {
    string result;
    for (int x : v) {
        result += to_string(x) + ",";
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 목표 상태 입력
    vector<int> target(8);
    for (int i = 0; i < 8; i++) {
        cin >> target[i];
    }

    // 초기 상태
    vector<int> initial = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // 목표 상태가 초기 상태와 같다면
    if (initial == target) {
        cout << 0 << endl;
        return 0;
    }

    // BFS
    queue<State> q;
    map<string, bool> visited;

    q.push(State(initial, 0));
    visited[vectorToString(initial)] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // 4가지 변환 시도
        vector<vector<int>> nextStates;
        nextStates.push_back(transformA(current.square));
        nextStates.push_back(transformB(current.square));
        nextStates.push_back(transformC(current.square));
        nextStates.push_back(transformD(current.square));

        for (const auto& nextSquare : nextStates) {
            // 목표 상태에 도달했는지 확인
            if (nextSquare == target) {
                cout << current.moves + 1 << endl;
                return 0;
            }

            string key = vectorToString(nextSquare);
            if (visited.find(key) == visited.end()) {
                visited[key] = true;
                q.push(State(nextSquare, current.moves + 1));
            }
        }
    }

    return 0;
}