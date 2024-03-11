#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
int goal;
int cnt;
int current;
deque<int> dq;


void pop_first()
{
	dq.pop_front();
}

void move_left() 
{
	dq.push_back(dq.front());
	dq.pop_front();
}

void move_right() 
{
	dq.push_front(dq.back());
	dq.pop_back();
}



int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> goal;
		

		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == goal) {
				current = i;
				break;
			}
		}

		if (current < dq.size() - current) {
			while (1)
			{
				if (dq.front() == goal) {
					pop_first();
					break;
				}
				++cnt;
				move_left();
			}
		}
		else
		{
			while (1)
			{
				if (dq.front() == goal) {
					pop_first();
					break;
				}
				++cnt;
				move_right();
			}
		}
	}

	cout << cnt;

}