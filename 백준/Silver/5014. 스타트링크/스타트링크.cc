#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int F, S, G, U, D;
int mv[2];
int cnt[1000001];
bool visited[1000001] = { false };
void BFS(int s)
{
	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty())
	{
		s = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int ns = s + mv[i];

			if (ns > 0 && ns <= F)
			{
				if (!visited[ns])
				{
					visited[ns] = true;
					q.push(ns);
					cnt[ns] = cnt[s] + 1;
				}
			}
		}
	}

}

int main()
{
	cin >> F >> S >> G >> U >> D;
	mv[0] = U;
	mv[1] = -D;
	BFS(S);

	if (visited[G])
		 cout << cnt[G];
	else
		cout << "use the stairs";
}