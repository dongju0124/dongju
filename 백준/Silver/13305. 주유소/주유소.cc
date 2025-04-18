#include <iostream>
using namespace std;

typedef long long ll;

ll oil[123456];
ll path[123456];
ll City, Min, Total;

int main()
{
    cin >> City;

	for (int i = 0; i < City - 1; i++)
	{
		cin >> path[i];
	}
	
	for (int i = 0; i < City; i++)
	{
		cin >> oil[i];
	}
	
	Min = oil[0];

	Total = Min * path[0];

	for (int i = 0; i < City; i++)
	{
		if (Min >= oil[i + 1])
			Min = oil[i + 1];
		Total += Min * path[i + 1];
	}

	cout << Total;

    return 0;
}
