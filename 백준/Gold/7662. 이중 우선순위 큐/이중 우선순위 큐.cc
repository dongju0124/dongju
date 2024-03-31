#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int T,k,n;
char c;

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>T;

    while(T--){

        map<int, int> m;

        cin>>k;
        while(k--){

            cin>>c>>n;

            if(c=='D'){
                if(m.empty()) continue;

                if(n==1) {
                    if(--m[m.rbegin()->first]==0) m.erase(m.rbegin()->first);
                }
                else if(n==-1) {
                    if(--m[m.begin()->first]==0) m.erase(m.begin()->first);
                }
            }
            else { // c=='I'
                m[n]++;
            }

        }

        if(m.empty()) cout<<"EMPTY\n";
        else cout<<m.rbegin()->first<<" "<<m.begin()->first<<'\n';
    }
}