#include<iostream>
#include<string>
using namespace std;

char Num[101];

int main()
{
	int n;

	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> Num[i];
		int temp = Num[i] - '0';
		sum += temp;
	}

	cout << sum;
}