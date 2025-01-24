#include<iostream>
#include<algorithm>
using namespace std;

long long N, K;
long long Low, High, Mid;
long long Lan[10001];
long long num = 0;

void binary()
{
	Low = 1;
	High = Lan[K - 1];

	while (Low <= High)
	{
		Mid = (Low + High) / 2;
		long long cnt = 0;
		for (int i = 0; i < K; i++)
		{
			cnt = cnt + Lan[i] / Mid;
		}

		if (cnt >= N)
		{
			Low = Mid + 1; //자른 개수가 많으므로 자르는 단위를 키움

			if (num < Mid)
				num = Mid;
		}
		else
		{
			High = Mid - 1; // 자른 개수가 적으므로 자르는 단위를 줄임
		}

	}
	cout << num;
}

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> Lan[i];
	}

	sort(Lan, Lan + K);


	binary();
}