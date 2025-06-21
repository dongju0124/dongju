#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int T, n;
vector<int> student;
bool visited[100001];
bool done[100001];
int result;

void dfs(int curr) {
    visited[curr] = true;
    int next = student[curr];

    if (!visited[next]) {
        dfs(next);
    }
    else if (!done[next]) {
        for (int i = next; i != curr; i = student[i]) 
        {
            result++;
        }
        result++;
    }

    done[curr] = true;
}

int main() {
    cin >> T;

    while (T--) {
        cin >> n;
        student.resize(n + 1);
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        result = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> student[i];
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << n - result << '\n';
    }

    return 0;
}
