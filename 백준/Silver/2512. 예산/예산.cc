#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> budget;
int totalBudget;
int maxRequest;

void binarySearch()
{
	int low = 1;
	int high = maxRequest;
	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		long long total = 0;

		for (int i : budget)
		{
			total += min(i, mid);
		}
		if (total <= totalBudget) {
			result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << result;
}

int main()
{
	int N;
	cin >> N;
	budget.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> budget[i];
		maxRequest = max(maxRequest, budget[i]);
	}
	cin >> totalBudget;
	sort(budget.begin(), budget.end());

	binarySearch();
}