#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {

    map<string, int> m;
    
    for(int i=0; i<phone_book.size(); i++)
    {
          m.insert({phone_book[i], 1});
    }
    
    for(int i=0;i<phone_book.size();i++)
        for(int j=0;j<phone_book[i].size()-1;j++)
            if(m[phone_book[i].substr(0,j+1)]) 
                return false;
    
    return true;
}