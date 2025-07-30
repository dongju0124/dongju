#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, wifi;
vector<int> house;

int main()
{
	cin >> N >> C;

	house.resize(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}

	sort(house.begin(), house.end());

	int start = 1;
	int end = house[N - 1] - house[0];
	int mid, prev;
	int dis = -1;
	while (start <= end)
	{
		wifi = 1;
		mid = (start + end) / 2;
		prev = house[0];

		for (int i = 1; i < N; i++)
		{
			if (house[i] - prev >= mid) {
				wifi++;
				prev = house[i];
			}
		}

		if (wifi >= C)
		{
			dis = max(dis, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << dis;
	
}