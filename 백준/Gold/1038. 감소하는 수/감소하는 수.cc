#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> decreasingNumbers;

void solve(long long num, int lastDigit) {
		decreasingNumbers.push_back(num);
	for (int i = 0; i < lastDigit; i++) {
		solve(num * 10 + i, i);
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		solve(i, i);
	}

	sort(decreasingNumbers.begin(), decreasingNumbers.end());

	if (N >= decreasingNumbers.size()) 
		cout << -1;
	else cout << decreasingNumbers[N];

	return 0;
}