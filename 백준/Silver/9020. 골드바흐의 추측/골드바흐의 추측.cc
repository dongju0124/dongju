#include<iostream>

using namespace std;

int arr[10001];

int main()
{
	int N, T;
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 2; i * i <= N; i++)
		{
			{
				for (int j = 2; j * i <= N; j++)
				{
					arr[i * j] = 1;
				}
			}
		}

		for (int i = N/2; i >= 2; i--)
		{
			if (arr[i] == 0 && arr[N - i] == 0)
			{
				cout << i << " " << N - i << '\n';
				break;
			}
		}
	}

}