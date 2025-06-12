#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> books;

    for (int i = 0; i < N; i++) {
        string title;
        cin >> title;
        books[title]++;
    }

    string bestSeller;
    int maxSold = 0;

    for (const auto& book : books) {
        if (book.second > maxSold) {
            maxSold = book.second;
            bestSeller = book.first;
        }
        else if (book.second == maxSold && book.first < bestSeller) {
            bestSeller = book.first;
        }
    }

    cout << bestSeller << endl;
    return 0;
}