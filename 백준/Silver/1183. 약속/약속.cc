#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N;
	int A, B;
	vector<int> arr;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		arr.push_back(A - B);
	}
	sort(arr.begin(), arr.end());

	if (N % 2 == 1)
		cout << 1;
	else
		cout << arr[N / 2] - arr[N / 2 - 1] + 1;
}