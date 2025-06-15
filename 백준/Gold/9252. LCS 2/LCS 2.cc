#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str1, str2;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> path;

string findLCS(int i, int j) {
    string result = "";
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result = str1[i - 1] + result;
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    dp.resize(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[len1][len2] << "\n";

    if (dp[len1][len2] > 0) {
        cout << findLCS(len1, len2) << "\n";
    }

    return 0;
}