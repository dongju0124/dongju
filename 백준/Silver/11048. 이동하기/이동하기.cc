#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[1001][1001];
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	cout << arr[N][M] << "\n";
	return 0;
}