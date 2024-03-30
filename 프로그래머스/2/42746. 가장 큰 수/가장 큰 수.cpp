#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str_numbers;

    for (int num : numbers) {
        str_numbers.push_back(to_string(num));
    }
    
    sort(str_numbers.begin(), str_numbers.end(), compare);

    for (string str : str_numbers) {
        answer += str;
    }
    
    if (answer[0] == '0') {
        return "0";
    }
    
    return answer;
}