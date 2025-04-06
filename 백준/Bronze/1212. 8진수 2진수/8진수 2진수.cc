#include <iostream>
#include <string>
using namespace std;

string octalDigitToBinary(char c, bool isFirst) {
    int val = c - '0';
    string bin;

    for (int i = 2; i >= 0; --i) {
        bin += (val & (1 << i)) ? '1' : '0';
    }

    if (isFirst) {
        size_t firstOne = bin.find('1');
        if (firstOne != string::npos)
            return bin.substr(firstOne);
        else
            return "0";
    }

    return bin;
}

int main() {
    string octal;
    cin >> octal;

    string binary;

    for (size_t i = 0; i < octal.size(); ++i) {
        binary += octalDigitToBinary(octal[i], i == 0);
    }

    cout << binary << endl;
    return 0;
}
