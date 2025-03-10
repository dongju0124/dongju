#include<iostream>
#include<vector>
using namespace std;

int N, S, E, Q;
vector<int> arr;
int dp[2001][2001];

void findPal()
{
	// 길이가 1인 문자열은 항상 팰린드롬
	for (int i = 0; i < N; i++) {
		dp[i][i] = 1;
	}

	// 길이가 2인 경우 체크
	for (int i = 0; i < N - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	// 길이가 3 이상인 경우 체크
	for (int len = 3; len <= N; len++) {
		for (int i = 0; i <= N - len; i++) {
			int j = i + len - 1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
				dp[i][j] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	findPal();

	cin >> Q;

	while (Q--)
	{
		cin >> S >> E;
		cout << dp[S - 1][E - 1] << "\n";
	}
}