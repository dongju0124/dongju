#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define inf 123456789

int TC;
int N, M, W;


struct Edge
{
	int start;
	int end;
	int weight;
};

void bellmanFord(int N, vector<Edge>& edges) {
    vector<int> dist(N+1, inf);

    // 모든 간선 체크
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int u = edges[j].start;
            int v = edges[j].end;
            int weight = edges[j].weight;

            if (dist[u]+weight<dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // 음의 사이클 체크
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].start;
        int v = edges[i].end;
        int weight = edges[i].weight;
        if (dist[u]+weight<dist[v])
        {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << endl;

}

int main()
{
	cin >> TC;

	while (TC--)
	{
		vector<Edge> edges;
		cin >> N >> M >> W;

		int S, E, T;
		for (int i = 0; i < M; i++)
		{
			cin >> S >> E >> T;
			edges.push_back({ S, E, T });
            edges.push_back({ E, S, T }); 
		}
		for (int i = 0; i < W; i++)
		{
            cin >> S >> E >> T;
			edges.push_back({ S,E,-T });
		}
        bellmanFord(N, edges);
	}


}