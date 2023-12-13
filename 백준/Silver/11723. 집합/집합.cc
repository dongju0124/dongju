#include <iostream>
#include <cstring>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    int arr[21];
    memset(arr, 0, sizeof(arr));

    while (M--) {
        string operation;
        int x;
        cin >> operation;

        if (operation == "add") {
            cin >> x;
            arr[x] = 1;
        }
        else if (operation == "remove") {
            cin >> x;
            arr[x] = 0;
        }
        else if (operation == "check") {
            cin >> x;
            cout << arr[x] << '\n';
        }
        else if (operation == "toggle") {
            cin >> x;
            arr[x] = (arr[x] == 1) ? 0 : 1;
        }
        else if (operation == "all") {
            for (int k = 1; k <= 20; k++) 
            { arr[k] = 1; }
        }
        else if (operation == "empty") {
            memset(arr, 0, sizeof(arr));
        }
    }

    return 0;
}
