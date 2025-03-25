#include<iostream>
using namespace std;



int main()
{
	int alp[27];
	for (int i = 0; i < 27; i++)
	{
		alp[i] = 0;
	}
	string word;

	cin >> word;

	for (int i = 0; i < word.size(); i++){
		if ('A' <= word[i] && word[i] <= 'Z'){
			alp[word[i] - 'A']++;
			
		}
		else{
			alp[word[i] - 'a']++;
		}
	}

    int maxCount = 0;
    int maxIndex = -1;
    bool isDuplicated = false;

    for (int i = 0; i < 26; i++) {
        if (alp[i] > maxCount) {
            maxCount = alp[i];
            maxIndex = i;
            isDuplicated = false;
        }
        else if (alp[i] == maxCount && maxCount != 0) {
            isDuplicated = true;
        }
    }

    if (isDuplicated) {
        cout << "?" << endl;
    }
    else {
        cout << (char)(maxIndex + 'A') << endl;
    }

    return 0;
}