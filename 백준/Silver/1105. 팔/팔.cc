#include<iostream>
using namespace std;

int main()
{
	string L, R;

	cin >> L >> R;

	int ans = 0;

	if (L.size() != R.size())
	{
		ans = 0;
	}
	else
	{
		for (int i = 0; i < L.size(); i++)
		{
			if (L[i] != R[i])
				break;

			if (L[i] == R[i] && L[i] == '8')
				ans++;
		}
	}

	cout << ans;
}