#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[328001];
vector<int> support_dist;

void dfs(int curr, int parent, int depth, int S) {
    if (curr <= S) {
        support_dist.push_back(depth); // 지지대 도달 시 거리 저장
    }

    for (int next : graph[curr]) {
        if (next != parent) {
            dfs(next, curr, depth + 1, S);
        }
    }
}

int main() {
    int N, S, P;
    cin >> N >> S >> P;

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(P, -1, 0, S);

    sort(support_dist.begin(), support_dist.end()); //거리 정렬

    int notBreak = 0;
    // 결과 출력
    for (int i = 0; i < 2; ++i) {
        notBreak = notBreak + support_dist[i];
    }
    cout << N - (notBreak + 1);//+1은 펭귄 위치

    return 0;
}
