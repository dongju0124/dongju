#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int N, M;
int sum;
vector<tuple<int, int, int>> edge;
int val[1001];


int find(int k) {
    if (val[k] == k) 
        return k;
    else 
        return val[k] = find(val[k]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a > b)
    {
        val[a] = b;
    }
    else
    {
        val[b] = a;
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
    for (auto e : edge) {
        int a, b, c;
        tie(a, b, c) = e;
        if (find(b) == find(c)) 
            continue;
        join(b, c);
        ans += a;
    }

    cout << ans;
}
