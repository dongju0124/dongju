#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	int Fruit[10];
	int Kind = 0;
	int now = 0;
	for (int i = 0; i < 10; i++)
	{
		Fruit[i] = 0;
	}
	cin >> N;
	queue<int> tang;
	int cnt = N;

	while (N--)
	{
		int fruit;

		cin >> fruit;

		//꼬치에 꽂음
		tang.push(fruit);
		if (Fruit[fruit] == 0)
		{
			Kind++;
		}
		Fruit[fruit]++;

		//꼬치에서 뽑아야 하는 경우
		while (Kind > 2)
		{
			fruit = tang.front();
			tang.pop();

			Fruit[fruit]--;
			if (Fruit[fruit] == 0)
				Kind--;
		}
		// 종류가 2개 이하일 때 과일 개수 체크
		int n = tang.size();
		now = max(now, n);
	}

	cout << now;
}