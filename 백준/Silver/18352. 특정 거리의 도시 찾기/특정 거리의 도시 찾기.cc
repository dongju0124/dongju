#include <iostream>
#include <queue>
using namespace std;

int n, m, k, x;
int MAP[300001];
vector<int> r[300001];

void dist(int s) {
	MAP[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < r[cur].size(); i++) {
			int next = r[cur][i];
			if (MAP[next] > MAP[cur] + 1) {
				MAP[next] = MAP[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> x;
	for (int i = 1; i <= n; i++) {
		MAP[i] = 100000001;
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		r[s].push_back(e);
	}
	dist(x);
	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (MAP[i] == k) {
			check = true;
			cout << i << endl;
		}
	}
	if (!check)
		cout << "-1";
}