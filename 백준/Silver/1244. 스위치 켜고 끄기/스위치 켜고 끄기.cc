#include<iostream>
using namespace std;

int arr[101];
int N;

void onoff(int i)
{
	if (arr[i] == 1)
		arr[i] = 0;
	else
	{
		arr[i] = 1;
	}
}

void boy(int cur)
{
	for (int i = 1; cur * i <= N; i++)
	{
		onoff(cur * i);
	}
}

void girl(int cur)
{
	onoff(cur);
	int front, end;

	for (int i = 1; i < N; i++)
	{
		front = cur - i;
		end = cur + i;
		if (front >= 1 && end <= N && arr[front] == arr[end])
		{
			onoff(front);
			onoff(end);
		}
		else
		{
			break;
		}
	}

}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	int T;
	cin >> T;
	while (T--)
	{
		int sex, num;

		cin >> sex >> num;

		if (sex == 1)
			boy(num);
		else
		{
			girl(num);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}