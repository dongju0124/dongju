#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> S;
vector<bool> visited;
int min_diff = 999999999;

// 팀의 능력치 차이를 계산하는 함수
void calculateDifference(const vector<bool>& team) {
    int start_sum = 0, link_sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (team[i] && team[j]) // 두 선수가 스타트 팀에 속한 경우
                start_sum += S[i][j];
            else if (!team[i] && !team[j]) // 두 선수가 링크 팀에 속한 경우
                link_sum += S[i][j];
        }
    }
    int diff = abs(start_sum - link_sum);
    min_diff = min(min_diff, diff);
}

// 백트래킹을 이용하여 가능한 모든 팀 조합을 탐색하는 함수
void dfs(int idx, int count) {
    if (count == N / 2) { // 팀이 정확히 N/2명이 되면 능력치 차이 계산
        vector<bool> team(N, false);
        for (int i = 0; i < N; ++i) {
            if (visited[i])
                team[i] = true; // 방문한 인덱스는 스타트 팀
        }
        calculateDifference(team);
        return;
    }

    for (int i = idx; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i + 1, count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N;

    S.resize(N, vector<int>(N));
    visited.resize(N, false);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> S[i][j];
        }
    }

    dfs(0, 0);

    cout << min_diff << endl;

    return 0;
}
