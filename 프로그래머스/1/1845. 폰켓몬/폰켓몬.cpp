#include <vector>
#include <set>
using namespace std;

set<int> p;

int solution(vector<int> nums)
{
    int answer = 0;
    for(int i=0; i<nums.size(); i++)
    {
        p.insert(nums[i]);
    }
    
    int s = nums.size()/2;
    
    if(s>=p.size())
    {
        answer = p.size();
    }
    else
    {
        answer = s;
    }
    
   
    return answer;
}