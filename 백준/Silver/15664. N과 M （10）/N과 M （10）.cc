#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr, temp;
set<vector<int>> result;

void solve(int digit, int cnt) {
	if (cnt == M) {
		result.insert(temp);
		return;
	}

	for (int i = digit; i < arr.size(); i++) {
		temp.push_back(arr[i]);
		solve(i + 1, cnt + 1);
		temp.pop_back();
	}
}

int main() {
	cin >> N >> M;
	arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	solve(0, 0);

	for (const auto& seq : result) {
		for (int num : seq) {
			cout << num << ' ';
		}
		cout << '\n';
	}

	return 0;
}
