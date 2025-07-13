#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<long long> num;
stack<int> s;
stack<long long> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	num.resize(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	for (int i = N; i >= 1; i--)
	{
		while (!s.empty() && num[s.top()] <= num[i])
		{
			s.pop();
		}

		if (!s.empty())
		{
			result.push(num[s.top()]);
		}
		else
		{
			result.push(-1);
		}

		s.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << result.top() << " ";
		result.pop();
	}
}