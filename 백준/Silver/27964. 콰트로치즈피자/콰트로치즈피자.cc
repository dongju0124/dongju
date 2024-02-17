#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int n;
	string cheese[101];
	vector<string> realCheese;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cheese[i];
	}
	int cnt;

	for (int i = 0; i < n; i++)
	{
		int chz = cheese[i].find("Cheese", cheese[i].size() - 6);
		if (chz != string::npos)
		{
			realCheese.push_back(cheese[i]);
		}
	}

	sort(realCheese.begin(), realCheese.end()); realCheese.erase(unique(realCheese.begin(), realCheese.end()), realCheese.end());

	if (realCheese.size()>=4)
	{
		cout << "yummy";
	}
	else
	{
		cout << "sad";
	}

}