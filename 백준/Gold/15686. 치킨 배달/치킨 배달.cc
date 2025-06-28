#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> houses;    
vector<pair<int, int>> chickens;  
vector<bool> selected;            
int answer = 2147483647;         

int getDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int calculateCityDistance() {
    int total = 0;
    for (auto& house : houses) {
        int minDist = 2147483647;
        for (int i = 0; i < chickens.size(); i++) {
            if (selected[i]) {
                minDist = min(minDist, getDistance(house, chickens[i]));
            }
        }
        total += minDist;
    }
    return total;
}

void selectChickens(int index, int count) {
    if (count == M) {
        answer = min(answer, calculateCityDistance());
        return;
    }

    for (int i = index; i < chickens.size(); i++) {
        if (!selected[i]) {
            selected[i] = true;
            selectChickens(i + 1, count + 1);
            selected[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            if (val == 1) {
                houses.push_back({ i, j });
            }
            else if (val == 2) {
                chickens.push_back({ i, j });
            }
        }
    }

    selected.resize(chickens.size(), false);
    selectChickens(0, 0);

    cout << answer << '\n';

    return 0;
}