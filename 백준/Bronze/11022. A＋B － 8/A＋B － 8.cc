#include<iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int A, B;
		cin >> A >> B;

		cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << "\n";
	}
}