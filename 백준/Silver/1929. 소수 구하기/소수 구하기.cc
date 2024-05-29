#include<iostream>

using namespace std;

int M, N;

int arr[1000001];

int main()
{
	cin >> M >> N;
    arr[1] = 1;
    //에라토스테네스의 체
    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i] == 0)
            for (int j = i * i; j <= N; j += i)
            {
                arr[j] = 1;
            }
    }

    for (int i = M; i <= N; i++)
    {
        if (!arr[i])
            cout << i << "\n";
    }
}