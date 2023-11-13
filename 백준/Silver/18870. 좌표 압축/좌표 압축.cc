#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr1;
vector<int> arr2;

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		arr1.push_back(k);
	}

	arr2 = arr1;

	sort(arr1.begin(), arr1.end());
	arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());


	for (int i = 0; i < N; i++) {

		auto it = lower_bound(arr1.begin(), arr1.end(), arr2[i]);
		cout << it - arr1.begin() <<" ";
	}
}