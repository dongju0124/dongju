#include<iostream>
#include<vector>
using namespace std;

bool isGold(int N)
{
	while (N != 0)
	{
		int digit = N % 10;

		if (digit != 4 && digit != 7)
		{
			return false;
		}

		N /= 10;
	}
	return true;
}

int main()
{
	int N;
	int ans;
	cin >> N;

	while (N >= 4)
	{
		if (isGold(N)) {
			cout << N;
			return 0;
		}
		N--;
	}

	
}