#include<iostream>

using namespace std;

int main()
{
	int N, X;

	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		int temp;
		
		cin >> temp;

		if (temp < X)
			cout << temp << " ";

	}
}