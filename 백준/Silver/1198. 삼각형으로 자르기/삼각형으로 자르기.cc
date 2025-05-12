#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct node
{
	double x;
	double y;
};

vector<node> arr;

double Tri(node a, node b, node c)
{
	return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2;
}

int main()
{
	int N;
	double ans = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;
		arr.push_back({x,y});
	}

	for (int i = 0; i < N-2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				ans = max(ans, Tri(arr[i], arr[j], arr[k]));
			}
		}
	}
	cout << fixed << setprecision(1) << ans;
}