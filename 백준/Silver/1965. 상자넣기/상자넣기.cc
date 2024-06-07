#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> box;
int DP[1001];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		box.push_back(temp);
	}

	int big = 0;
	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (box[j] < box[i] && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		}
		big = max(big, DP[i]);
	}

	cout << big;
}