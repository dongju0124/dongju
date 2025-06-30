#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int cmp[51];

int main()
{
    cin >> N;
    vector<pair<int, int>> human(N);

    for (int i = 0; i < N; i++)
    {
        cin >> human[i].first >> human[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        cmp[i] = 1;

        for (int j = 0; j < N; j++)
        {
            if (i != j) 
            {
                if (human[j].first > human[i].first && human[j].second > human[i].second)
                {
                    cmp[i]++; 
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << cmp[i];
        if (i < N - 1) cout << " ";
    }

    return 0;
}