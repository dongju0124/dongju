#include<iostream>

using namespace std;

int N, cnt;

bool seperate(int n)
{
	if (n < 100)
		return true;




	int first, second, third;
	third = n % 10;
	second = (n / 10) % 10;
	first = (n / 100) % 10;

	if (first - second == second - third)
		return true;
	else
		return false;
}

int main()
{
	cin >> N;
	
	if (N == 1000)
		N--;
	
	for (int i = 1; i <= N; i++)
	{
		if (seperate(i))
			cnt++;
	}

	cout << cnt;
}