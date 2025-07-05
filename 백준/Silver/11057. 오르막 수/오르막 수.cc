#include <iostream>
using namespace std;

const int MOD = 10007;
int dp[1001][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }


    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {

            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) 
    {
        result = (result + dp[N][i]) % MOD;
    }

    cout << result << "\n";

    return 0;
}