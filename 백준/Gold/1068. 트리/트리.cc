#include <iostream>
#include <vector>
using namespace std;

int N, deleteNode, root;
vector<int> tree[50];
bool removed[50];
int leafCount = 0;

void dfs(int node) {

    bool isLeaf = true;
    for (int child : tree[node]) {
        if (!removed[child]) {
            isLeaf = false;
            dfs(child);
        }
    }
    if (isLeaf) 
        leafCount++;
}

int main() {
    cin >> N;
    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        cin >> parent[i];
        if (parent[i] == -1) 
            root = i;
        else tree[parent[i]].push_back(i);
    }

    cin >> deleteNode;

    removed[deleteNode] = true;

    if (deleteNode == root) {
        cout << 0 << '\n';
    }
    else {
        dfs(root);
        cout << leafCount << '\n';
    }

    return 0;
}
