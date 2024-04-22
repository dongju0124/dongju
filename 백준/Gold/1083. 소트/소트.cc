#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, S;
	vector<int> arr(51);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cin >> S;

	int temp = 0;
	while (temp < N && S>0)
	{
		int idx = temp;

		for (int i = temp; i <= min(N-1, temp+S); i++)
		{
			if (arr[idx] < arr[i])
				idx = i;
		}
		for (int i = idx; i > temp; i--)
		{
			int tmp;
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
			S--;
		}

		temp++;
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}