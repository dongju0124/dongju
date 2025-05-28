#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, len;
vector<int> arr;
vector<int> temp;

void solve(int digit, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << temp[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = digit; i < len; i++)
	{
		temp.push_back(arr[i]);
		solve(i, cnt + 1);
		temp.pop_back();
	}
}

int main()
{
	cin >> N >> M;

	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()),arr.end());

	len = arr.size();

	solve(0, 0);
}