#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector <int> arr;
vector <int> ans;
int cycle;


int main() {

	cin >> N;
	int cycle = N;

	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		arr.push_back(k);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		ans.push_back(arr[i] * cycle);
		cycle--;
	}
	int max;
	max = *max_element(ans.begin(), ans.end());

	cout << max;

	return 0;
}