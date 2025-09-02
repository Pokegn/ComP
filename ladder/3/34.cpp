#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s; cin >> s;
    string t; cin >> t;
    bool ans=true;

    reverse(s.begin(), s.end());

    if(s.size()==t.size()){
        for(int i=0; i<s.size(); i++){
            if(s[i]!=t[i]) ans=false;
        }
    }
    else ans=false;

    if(ans) cout << "YES";
    else cout << "NO";
}