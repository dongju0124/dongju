#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main()
{
	arr.resize(9);
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	

	max_element(arr.begin(), arr.end());
	int a = find(arr.begin(), arr.end(), *max_element(arr.begin(), arr.end())) - arr.begin();

	cout << *max_element(arr.begin(), arr.end()) << "\n";
	cout << a + 1;
}