#include <string>
#include <vector>
using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[n - 1][i]);
    return ans;
}
