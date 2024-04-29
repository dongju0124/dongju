#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<string>>& tickets, string start, vector<string>& path, vector<string>& answer, vector<bool>& visited, int depth) {
    path.push_back(start); // 현재 공항 추가
    if (depth == tickets.size()) { // 모든 티켓을 사용한 경우
        answer = path; // 현재 경로를 정답으로 저장
        return true;
    }
    
    for (int i = 0; i < tickets.size(); ++i) {
        if (tickets[i][0] == start && !visited[i]) { // 출발지가 현재 공항이고, 해당 티켓을 사용하지 않은 경우
            visited[i] = true; // 티켓 사용 처리
            if (dfs(tickets, tickets[i][1], path, answer, visited, depth + 1)) // 다음 공항으로 이동
                return true;
            visited[i] = false; // 백트래킹: 티켓 사용 해제
        }
    }
    path.pop_back(); // 현재 공항을 경로에서 제거 (백트래킹)
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false); // 티켓 사용 여부를 저장하는 배열
    vector<string> path; // 경로를 저장하는 배열

    // 알파벳 순서로 경로를 만들기 위해 티켓을 정렬
    sort(tickets.begin(), tickets.end());

    dfs(tickets, "ICN", path, answer, visited, 0); // DFS 호출

    return answer;
}
