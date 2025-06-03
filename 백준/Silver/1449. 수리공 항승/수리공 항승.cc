#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int arr[1001];

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int count = 1;          
    double covered = arr[0] - 0.5 + L; 

    for (int i = 1; i < N; i++) 
    {
        if (arr[i] + 0.5 > covered) 
        {  
            count++;                    
            covered = arr[i] - 0.5 + L;
        }
    }

    cout << count << endl;
    return 0;
}