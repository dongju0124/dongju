#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int copyLab[8][8];
int lab[8][8];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> Empty, Virus;
int maxSafe = 0;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < M && copyLab[nx][ny] == 0) {
            copyLab[nx][ny] = 2;
            dfs(nx, ny);
        }

    }
}

void spread()
{
    memcpy(copyLab, lab, sizeof(lab));

    for (auto v : Virus)
    {
        dfs(v.first, v.second);
    }
    int safe = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copyLab[i][j] == 0)
                safe++;
        }
    }

    maxSafe = max(maxSafe, safe);
}

void setWall(int cnt, int start)
{
    if (cnt == 3)
    {
        spread();
        return;
    }

    for (int i = start; i < Empty.size(); i++)
    {
        int x = Empty[i].first;
        int y = Empty[i].second;

        lab[x][y] = 1;
        setWall(cnt + 1, i + 1);
        lab[x][y] = 0;
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) Empty.push_back({ i, j });
            if (lab[i][j] == 2) Virus.push_back({ i, j });
        }

    setWall(0, 0);
    cout << maxSafe << '\n';
}