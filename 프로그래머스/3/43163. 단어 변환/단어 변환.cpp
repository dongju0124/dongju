#include <string>
#include <vector>

using namespace std;
int answer=100;

void dfs(string begin, string target, vector<string> words,vector<bool>& visited, int cnt = 0)
{   for (int i = 0; i < words.size(); i++) {
        int count = 0;
        for (int j = 0; j < words[i].length(); j++)
            if (!visited[i] && begin[j] != words[i][j])  count++;
        if (count == 1) {
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }
            visited[i] = true;
            dfs(words[i], target, words, visited, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(), false);
    dfs(begin, target, words, visited);
    if (answer == 100)   return 0;
    return answer;
}