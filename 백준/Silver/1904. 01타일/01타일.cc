#include<iostream>
using namespace std;

int tile[1000001];
int N;

int main()
{
	cin >> N;

	tile[1] = 1;
	tile[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		tile[i] = (tile[i - 2] + tile[i - 1]) % 15746;
	}

	cout << tile[N];
}