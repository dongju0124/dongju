#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int island[101];



int getParent(int node)
{
    if (island[node]== node) return node;
    return island[node] = getParent(island[node]);
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;


    for (int i = 0; i < n; i++)
    {
        island[i] = i;
    }

    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < costs.size(); i++)
    {
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];

        if (start != end)
        {
            answer += cost;
            island[end] = start;
        }

    }

    return answer;
}