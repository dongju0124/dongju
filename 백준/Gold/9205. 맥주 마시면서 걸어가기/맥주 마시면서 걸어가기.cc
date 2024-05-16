#include <iostream>
#include <queue>
#include<algorithm>
#include<cstring>
using namespace std;

vector<pair<int, int>> store;
pair<int, int> festival;
pair<int, int> home;
bool visited[100];
bool BFS(int n) {
    queue<pair<int, int>> q;
    q.push({ home.first, home.second });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(festival.first - x) + abs(festival.second - y) <= 1000)
            return true;

        for (int i = 0; i < n; i++) {

            if (visited[i] == true) {
                continue;
            }

            if (abs(store[i].first - x) + abs(store[i].second - y) <= 1000) 
            {
                visited[i] = 1;
                q.push({ store[i].first, store[i].second }); 
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int T;
    cin >> T;

    while (T--) {

        
        int n;
        cin >> n;
        store.resize(n);

        cin >> home.first >> home.second;                
        for (int i = 0; i < n; i++) 
        {
            cin >> store[i].first >> store[i].second;    
        }

        cin >> festival.first >> festival.second;        

        if (BFS(n))
            cout << "happy\n";
        else 
            cout << "sad\n";
        store.clear();
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}