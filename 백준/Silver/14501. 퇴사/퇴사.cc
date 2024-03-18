#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<pair<int,int>> council;

int main() {

	cin >> n;

	vector<int>maxPay(n+1, 0);

	for (int i = 0; i < n; i++)
	{
		int days, pay;

		cin >> days >> pay;

		council.push_back({ days, pay });
	}

	for (int i = n-1; i >=0 ; i--)
	{
		int poss = i + council[i].first;

		if (poss <= n)
		{
			maxPay[i] = max(maxPay[poss] + council[i].second, maxPay[i + 1]);
		}
		else
		{
			maxPay[i] = maxPay[i + 1];
		}
	}

	cout << maxPay[0];
}