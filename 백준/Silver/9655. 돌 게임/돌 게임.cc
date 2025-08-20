#include<iostream>
using namespace std;

int stone[1001];

int main()
{
	int N;

	cin >> N;

	if (N % 2 == 1)
		cout << "SK";
	else
		cout << "CY";
}