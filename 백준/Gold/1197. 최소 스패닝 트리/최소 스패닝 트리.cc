#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int N, M;
int sum;
vector<tuple<int, int, int>> edge;
vector<int>v;
int val[100001];

int find(int k) {
    if (val[k] == k)
        return k;
    else
        return val[k] = find(val[k]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if (a < b)
    {
        val[b] = a;
    }
    else
    {
        val[a] = b;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i <= N; i++) val[i] = i;
    cin >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge.push_back({ c,a,b });
    }
    sort(edge.begin(), edge.end());

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        val[i] = i;
    }
    for (auto e : edge)
    {
        int a, b, c;
        tie(a, b, c) = e;
        if (find(b) != find(c))
        {
            join(b, c);
            v.push_back(a);
            ans = ans + a;
        }
    }

    cout << ans;
}
