#include<iostream>
using namespace std;

int N, K, cnt;

int main()
{
	cin >> N >> K;



	for (int i = 0;; i++)
	{
		cnt = 0;
		int temp = N;
		while (temp > 0)
		{
			if (temp % 2 == 1)
				cnt++;
			temp = temp / 2;
		}

		if (cnt <= K)
		{
			cout << i;
			return 0;
		}
			N++;
	}
}