#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        string s; cin >> s;
        int sz=s.size();
        bool ans=false;

        for(int i=1; i<=sz/2-1; i++){
            if(s[i]!=s[i-1]) ans=true;
        }

        if(ans==true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}