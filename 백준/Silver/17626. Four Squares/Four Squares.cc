#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> DP(N + 1, 50001);
	DP[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j*j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}

	cout << DP[N];
}