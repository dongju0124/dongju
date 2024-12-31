#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to draw the star pattern recursively
void drawStar(vector<string>& pattern, int size, int x, int y) {
    if (size == 3) {
        // Base case: Draw the smallest star pattern
        pattern[y][x] = '*';
        pattern[y + 1][x - 1] = '*';
        pattern[y + 1][x + 1] = '*';
        pattern[y + 2][x - 2] = '*';
        pattern[y + 2][x - 1] = '*';
        pattern[y + 2][x] = '*';
        pattern[y + 2][x + 1] = '*';
        pattern[y + 2][x + 2] = '*';
        return;
    }

    int newSize = size / 2; // Halve the size for the recursive calls
    drawStar(pattern, newSize, x, y); // Top triangle
    drawStar(pattern, newSize, x - newSize, y + newSize); // Bottom-left triangle
    drawStar(pattern, newSize, x + newSize, y + newSize); // Bottom-right triangle
}

int main() {
    int N;
    cin >> N;

    // Initialize the pattern with spaces
    vector<string> pattern(N, string(2 * N - 1, ' '));

    // Draw the star pattern
    drawStar(pattern, N, N - 1, 0);

    // Print the pattern
    for (const string& line : pattern) {
        cout << line << "\n";
    }

    return 0;
}
