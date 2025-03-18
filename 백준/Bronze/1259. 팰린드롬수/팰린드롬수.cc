#include<iostream>
#include<string>
using namespace std;

int main()
{
	string num;

	while (1)
	{
		cin >> num;
		if (num == "0")
			break;

		string reverseNum = string(num.rbegin(), num.rend());

		if (num == reverseNum)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;

}