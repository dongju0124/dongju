#include <iostream>
using namespace std;

bool sosu[100001];
int num[100001];

int main()
{
	int A, B;
	cin >> A >> B;

	fill_n(sosu, 100001, true);

	sosu[0] = false;
	sosu[1] = false;

	for (int i = 2; i <= 100000; i++)
	{
		if (sosu[i])
		{
			for (int j = i*2; j <= B; j=j+i)
			{
				sosu[j] = false;
				int temp = j;
				while (temp%i==0)
				{
					temp /= i;
					num[j]++;
				}
			}
		}
	}

	int ans = 0;
	for (int i = A; i <= B; i++)
	{
		if (sosu[num[i]])
			ans++;
	}

	cout << ans;
}