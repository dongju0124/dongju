#include <iostream>
#include <string>
#include <vector>  
using namespace std;

int graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (auto& e : results) {
        int a = e[0];
        int b = e[1];

        graph[a][b] = 1;
        graph[b][a] = -1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
            }
        }
    }

    //자기 자신과의 경기만 0으로 1개 나올 것

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 0)
            {
                cnt++;
            }
        }
        if (cnt == 1)
            answer++;
    }


    return answer;
}

int main() {
    vector<vector<int>> edges = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
    int n = 5;
    int result = solution(n, edges);
    cout << result << endl; // 출력: 2
    return 0;
}