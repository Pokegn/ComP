#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s; cin >> s;
    int sz= s.size();
    int samecount=0;
    bool ans=0;

    for(int i=1; i<sz; i++){
        if(s[i]==s[i-1]){
            samecount+=1;
            if(samecount==6) ans=1;
        }
        else samecount=0;
    }

    if(ans==1) cout << "YES";
    else cout << "NO";
}