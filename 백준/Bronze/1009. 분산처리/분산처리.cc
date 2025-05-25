#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int TC;
int main()
{
	cin >> TC;

	long long a, b;

	while (TC--)
	{
		cin >> a >> b;

		a %= 10;

		if (a == 0) {
			cout << 10 << '\n';
			continue;
		}

		vector<int> cycle;
		int current = a;

		while (true) {
			if (find(cycle.begin(), cycle.end(), current) != cycle.end()) 
				break;
			cycle.push_back(current);
			current = (current * a) % 10;
		}

		int index = (b - 1) % cycle.size();
		cout << cycle[index] << '\n';
	}
}