#include <iostream>
#include <vector>
#include <string>
using namespace std;

string arr1;
string arr2;
int dp[1001][1001];

int main() {

	cin >> arr1;
	cin >> arr2;

	for (int i = 1; i <= arr1.size(); i++)
	{
		for (int j = 1; j <= arr2.size(); j++)
		{
			if (arr1[i-1]==arr2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[arr1.size()][arr2.size()];

}