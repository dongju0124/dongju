#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int rec[1001];

	rec[0] = 1;
	rec[1] = 1;

	if (n >= 2)
	{

		for (int i = 2; i <= n; i++)
		{
			rec[i] = (rec[i - 1] + rec[i - 2])%10007;
		}

	}

	cout << rec[n];

}