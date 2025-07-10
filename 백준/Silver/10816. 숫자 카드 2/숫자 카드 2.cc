#include<iostream>
#include<vector>
using namespace std;

int N, M;

long long sc[20000001];
bool card[20000001];

long long checkMinus(long long num)
{
	if (num < 0)
	{
		return 10000000 - num;
	}

	return num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		num = checkMinus(num);
		sc[num]++;
		card[num] = true;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		num = checkMinus(num);
		if (card[num])
		{
			cout << sc[num] << " ";
		}

		if (!card[num])
		{
			cout << 0 << " ";
		}
	}
}