#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;


int solution(vector<string> friends, vector<string> gifts) {

    int answer = 0;
    
    unordered_map<string, unordered_map<string, int>> giftCheck;
    unordered_map<string, int> giftState; // 각 친구가 준 선물의 수
    unordered_map<string, int> nextGift; // 각 친구가 받은 선물의 수

    for (auto const& name : friends)
    {
        giftState[name] = 0;
        nextGift[name] = 0;
        for (auto const& recive : friends)
        {
            giftCheck[name][recive] = 0;
        }
    }

    // 각 친구별로 선물 수를 계산
    for (string gift : gifts) {
        stringstream ss(gift);
        string giver, receiver;
        ss >> giver >> receiver;
        giftCheck[giver][receiver]++;
        giftState[giver]++;
        giftState[receiver]--;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        string giver = friends[i];
        for (int j = i+1; j < friends.size(); j++)
        {
            string receiver = friends[j];
            if (giver != receiver)
            {
                int rate1 = giftCheck[giver][receiver];
                int rate2 = giftCheck[receiver][giver];

                if (rate1 > rate2)
                    nextGift[giver]++;
                else if (rate1 < rate2)
                    nextGift[receiver]++;
                else
                {
                    if (giftState[giver] > giftState[receiver])
                        nextGift[giver]++;
                    if (giftState[giver] < giftState[receiver])
                        nextGift[receiver]++;

                }
            }
        }
    }

    for (auto Max : nextGift)
        answer = max(answer, Max.second);

    return answer;
}