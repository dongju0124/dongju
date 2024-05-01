#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

bool visited[101];
vector<int> net[101];
int cnt;

void bfs(int first, int second) {
    queue<int> q;

    // 시작 노드 방문 및 큐에 삽입
    q.push(first);
    visited[first] = true;
    visited[second] = true;
  
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 현재 노드와 연결된 인접한 노드들을 방문하고 큐에 삽입
        for (int i = 0; i < net[current].size(); i++)
        {
            int next = net[current][i];

            if (!visited[next])
            {
                cnt++;
                q.push(next);
                visited[next] = true;
            }
               
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 123456789;

    for (auto w: wires)
    {
        net[w[0]].push_back(w[1]);
        net[w[1]].push_back(w[0]);
    }    
    
    for (auto w: wires)
    {
        fill(visited, visited + n + 1, false);
        cnt = 1;
        bfs(w[0], w[1]);
        answer = min(answer, abs(n - (2 * cnt)));
    }

    return answer;
}
