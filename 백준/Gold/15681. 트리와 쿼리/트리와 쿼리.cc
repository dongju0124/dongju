#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, R, Q;

vector<int> Tree[100005];
int subTree[100005];
bool visited[100005];


int makeSub(int node)
{
	visited[node] = true;
	subTree[node] = 1;
	for (int neighbor : Tree[node]) {
		if (!visited[neighbor]) {
			subTree[node] += makeSub(neighbor);// 자식 노드의 수를 부모 노드에 더함
		}
	}
	return subTree[node];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> R >> Q;

	for (int i = 0; i < N-1; i++)
	{
		int U, V;
		cin >> U >> V;
		Tree[U].push_back(V);
		Tree[V].push_back(U);
	}
	
	makeSub(R);

	while (Q--)
	{
		int U;
		cin >> U;
		cout << subTree[U] << "\n";
	}
}