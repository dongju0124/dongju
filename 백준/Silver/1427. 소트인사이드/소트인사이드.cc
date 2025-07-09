#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<char> arr;
string num;

int main()
{
	cin >> num;

	for (int i = 0; i < num.size(); i++)
	{
		arr.push_back(num[i]);
	}
	
	sort(arr.begin(), arr.end(), greater<>());

	string result = "";
	for (int i = 0; i < num.size(); i++)
	{
		result = result + arr[i];
	}

	cout << result;
}