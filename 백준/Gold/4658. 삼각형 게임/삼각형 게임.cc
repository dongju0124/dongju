#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void swap(vector<vector<int>>& tri, int n) {
    int temp = tri[n][0];
    tri[n][0] = tri[n][1];
    tri[n][1] = tri[n][2];
    tri[n][2] = temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        vector<vector<int>> tri(6, vector<int>(3));
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> tri[i][j];
            }
        }
        int ans = -1;
        vector<int> order = { 0, 1, 2, 3, 4, 5 };
        do {
            for (int _ = 0; _ < 3; ++_) {
                swap(tri, 0);
                for (int _ = 0; _ < 3; ++_) {
                    swap(tri, 1);
                    for (int _ = 0; _ < 3; ++_) {
                        swap(tri, 2);
                        for (int _ = 0; _ < 3; ++_) {
                            swap(tri, 3);
                            for (int _ = 0; _ < 3; ++_) {
                                swap(tri, 4);
                                for (int _ = 0; _ < 3; ++_) {
                                    swap(tri, 5);
                                    int res = 0;
                                    bool possible = true;
                                    for (int j = 0; j < 6; ++j) {
                                        if (tri[order[j]][1] == tri[order[(j + 1) % 6]][0]) {
                                            res += tri[order[j]][2];
                                        }
                                        else {
                                            possible = false;
                                            break;
                                        }
                                    }
                                    if (possible) 
                                        ans = max(ans, res);
                                }
                            }
                        }
                    }
                }
            }
        } while (next_permutation(order.begin(), order.end()));

        if (ans != -1) {
            cout << ans << endl;
        }
        else {
            cout << "none" << endl;
        }

        char a;
        cin >> a;
        if (a == '$') break;
    }

    return 0;
}
