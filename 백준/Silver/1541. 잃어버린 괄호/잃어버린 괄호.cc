#include<iostream>
#include<string>
using namespace std;

string set;

int main() {

	cin >> set;
	int result = 0;
	string num;
	bool minus_check = false;

	for (int i = 0; i <= set.size(); i++)
	{
		if (set[i] == '-' || set[i] == '+' || i == set.size())
		{
			if (minus_check)
			{
				result = result - stoi(num);
				num = "";
			}
			else
			{
				result = result + stoi(num);
				num = "";
			}
		}
		else
		{
			num = num + set[i];
		}

		if (set[i] == '-')
			minus_check = true;
	}

	cout << result;
}
