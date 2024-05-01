#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer;
int cnt;
bool visited[9];

void dfs(vector<vector<int>>& dungeons, int k, int cnt) {

    if (cnt > answer)
        answer = cnt;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(dungeons, k - dungeons[i][1], cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    cnt = 0;
    dfs(dungeons, k, 0);
    return answer;
}