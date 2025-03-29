#include<iostream>
#include<algorithm>
using namespace std;

/*
int main()
{
	int M;
	int list[4]; // list[0]: 주문 시각(t), list[1]: 수익(v), list[2]: z1, list[3]: z2
	int delivery1[2]; // delivery1[0]: 현재 작업 종료 시각, delivery1[1]: 총 수익
	int delivery2[2]; // delivery2[0]: 현재 작업 종료 시각, delivery2[1]: 총 수익

	for (int i = 0; i < 2; i++)
	{
		delivery1[i] = 0;
		delivery2[i] = 0;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> list[j];
		}

		// 문제 1: 아래 조건은 "해당 시점에 완전히 비어있는 경우"만 고려하고 있음
		// 하지만 실제로는 delivery1[0]이 list[0]보다 작거나 같은지(= 지금 이 주문을 맡을 수 있는지)를 봐야 함
		if (delivery1[0] < list[0] && delivery2[0] < list[0])
		{
			// 문제 2: 작업 종료 시각을 잘못 업데이트함
			// delivery1[0] += list[0] 은 말이 안 됨!
			// 현재 시간이 아니라, max(delivery1[0], list[0]) + list[2] 가 되어야 함
			if (list[2] < list[3])
			{
				delivery1[0] += list[0];  // X잘못된 시간 갱신 방식
				delivery1[1] += list[1];
			}
			else
			{
				delivery2[0] += list[0];  // X 마찬가지로 잘못된 시간 갱신
				delivery2[1] += list[1];
			}
		}

		else if (delivery1[0] < list[0] && delivery2[0] > list[0])
		{
			delivery1[0] += list[0];  // X 위와 마찬가지로 시간 갱신 방식이 잘못됨
			delivery1[1] += list[1];
		}
		else if (delivery1[0] > list[0] && delivery2[0] < list[0])
		{
			delivery2[0] += list[0];  // X
			delivery2[1] += list[1];
		}
		else
		{
			continue;
		}
	}
	cout << delivery1[1] << " " << delivery2[1];
}
*/

int main()
{
	int M;
	int list[4];
	int delivery1[2]; // delivery1[0]: 작업 종료 시각, delivery1[1]: 총 수익
	int delivery2[2];

	for (int i = 0; i < 2; i++)
	{
		delivery1[i] = 0;
		delivery2[i] = 0;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> list[j]; // list[0]: 시간 t, list[1]: 수익 v, list[2]: z1, list[3]: z2
		}

		// 둘 다 가능한 경우
		if (delivery1[0] <= list[0] && delivery2[0] <= list[0])
		{
			if (list[2] < list[3])
			{
				delivery1[0] = max(delivery1[0], list[0]) + list[2];
				delivery1[1] += list[1];
			}
			else
			{
				delivery2[0] = max(delivery2[0], list[0]) + list[3];
				delivery2[1] += list[1];
			}
		}
		// delivery1만 가능한 경우
		else if (delivery1[0] <= list[0] && delivery2[0] > list[0])
		{
			delivery1[0] = max(delivery1[0], list[0]) + list[2];
			delivery1[1] += list[1];
		}
		// delivery2만 가능한 경우
		else if (delivery1[0] > list[0] && delivery2[0] <= list[0])
		{
			delivery2[0] = max(delivery2[0], list[0]) + list[3];
			delivery2[1] += list[1];
		}
		// 둘 다 불가능한 경우: 주문은 사라짐
		else
		{
			continue;
		}
	}

	cout << delivery1[1] << " " << delivery2[1];
}
