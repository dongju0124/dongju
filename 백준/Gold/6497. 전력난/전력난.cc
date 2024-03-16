#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


struct house
{
	long long a, b, c;
};

vector<house> city;

long long dist[200001];

long long  findParent(long long  node)
{
	if (dist[node] == node)
		return node;
	else
		return dist[node] = findParent(dist[node]);
}

void unionParent(long long  a, long long  b)
{
	a = findParent(a);
	b = findParent(b);

	if (a != b)
		dist[b] = a;
}

bool compare( house a, house b)
{
	return a.c < b.c;
}

int main() 
{
	while (1)
	{
		long long  n, m;

		cin >> n >> m;
		if (m == 0 && n ==  0)
		{
			break;
		}

		for (int i = 0; i < m; i++)
		{
			int x, y, z;

			cin >> x >> y >> z;

			city.push_back({ x,y,z });
		}

		for (int i = 0; i < n; i++)
		{
			dist[i] = i;
		}

		sort(city.begin(), city.end(), compare);
		long long  ans = 0;

		for (auto& root : city)
		{
			long long  start, end, cost;
			start = root.a;
			end = root.b;
			cost = root.c;

			if (findParent(start) == findParent(end))
			{
				ans += cost;
				continue;
			}

			unionParent(start, end);
		}

		cout << ans <<"\n";

		city.clear();
	}
	

}