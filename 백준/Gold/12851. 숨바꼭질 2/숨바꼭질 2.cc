#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, K;

vector<int> visited(100001, -1);
vector<int> num(100001, 0);
queue<int> q;

int fastT, ways;

void move()
{
	q.push(N);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		vector<int> nextWay = { cur - 1,cur + 1, cur * 2 };

		for (int next : nextWay)
		{
			if (next < 0 || next > 100000)
				continue;

			if (visited[next] == -1)
			{
				visited[next] = visited[cur] + 1;
				num[next] = num[cur];
				q.push(next);
			}
			else if (visited[next] == visited[cur] + 1)
				num[next] += num[cur + 1];
		}
	}
	fastT = visited[K];
	ways = num[K];
	
}


int main()
{
	cin >> N >> K;

	visited[N] = 0;
	num[N] = 1;

	move();

	cout << fastT << endl;
	cout << ways;
}