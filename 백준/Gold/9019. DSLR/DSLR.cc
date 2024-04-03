#include<iostream>
#include<cstring>
#include<string>
#include<queue>


using namespace std;

int Start, End;
bool Visit[10001];

string BFS(int a) {
    queue<pair<int, string>> Q;
    Q.push(make_pair(a, ""));
    Visit[a] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        string s = Q.front().second;
        Q.pop();

        if (x == End) return s;

        int nx = x * 2;
        if (nx > 9999) nx = nx % 10000;
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push({ nx, s + "D" });
        }

        nx = x - 1;
        if (nx < 0) nx = 9999;
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push({ nx, s + "S" });
        }

        nx = (x % 1000) * 10 + (x / 1000);
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push({ nx, s + "L" });
        }

        nx = (x % 10) * 1000 + (x / 10);
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push({ nx, s + "R" });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Tc;
    cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        memset(Visit, false, sizeof(Visit));
        cin >> Start >> End;
        string R = BFS(Start);
        cout << R << "\n";
    }

    return 0;
}
