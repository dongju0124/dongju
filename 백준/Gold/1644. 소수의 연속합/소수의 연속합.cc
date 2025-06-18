#include<iostream>
#include<vector>
using namespace std;

int N;
bool arr[4000001];
int cnt = 0;
vector<int> Prime;

void solve()
{
    int start = 0, end = 0, sum = 0;

    while (true)
    {
        if (sum >= N)
        {
            if (sum == N)
                cnt++;

            sum -= Prime[start++];
        }
        else
        {
            if (end == Prime.size())
                break;

            sum += Prime[end++];
        }
    }
}

int main()
{
    cin >> N;

    arr[0] = true;
    arr[1] = true;

    for (int i = 2; i * i <= N; i++)
    {
        if (!arr[i])
        {
            for (int j = i * i; j <= N; j = j + i)
            {
                arr[j] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (!arr[i])
            Prime.push_back(i);
    }

    solve();

    cout << cnt << endl;
}
