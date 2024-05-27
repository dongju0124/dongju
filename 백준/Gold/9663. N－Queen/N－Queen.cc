#include<iostream>
#include<cmath>
using namespace std;

int N;
int cnt = 0;
int col[16];
bool check(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (col[i] == col[x] || abs(col[x] - col[i]) == x - i)//abs(col[x] - col[i] == x - i :대각선
		{
			return false;
		}
	}
	return true;
}
void Queen(int x)
{
	if (x == N)
		cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[x] = i;
			if (check(x))
				Queen(x + 1);
		}
	}
}

int main()
{
	cin >> N;
	Queen(0);
	cout << cnt;
}