#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;

	vector<int> arr;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}
}