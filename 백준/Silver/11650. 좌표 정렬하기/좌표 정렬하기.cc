#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> arr;
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;

		cin >> x >> y;
		arr.push_back({ x,y });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}