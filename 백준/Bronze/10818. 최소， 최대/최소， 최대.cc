#include<iostream>
using namespace std;

long long N;
long long num;
long long Max = 1000000;
long long Min = -1000000;
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num < Max)
			Max = num;

		if (num > Min)
			Min = num;
	}

	cout << Max << " " << Min;
}