#include<iostream>
#include<queue>

using namespace std;

int N, K;
bool visited[100001];

int main()
{
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty())
	{
		int now = q.front().first;
		int count = q.front().second;
		q.pop();

		if (now == K)
		{
			cout << count;
			break;
		}

		if (now * 2 <= 100000 && !visited[now * 2]) {
			q.push(make_pair(now * 2, count));
			visited[now * 2] = true;
		}

		if (now - 1 >= 0 && !visited[now - 1])
		{
			q.push(make_pair(now - 1, count + 1));
			visited[now - 1] = true;
		}

		if (now + 1 <= 100000 && !visited[now + 1])
		{
			q.push(make_pair(now + 1, count + 1));
			visited[now + 1] = true;
		}




	}

}