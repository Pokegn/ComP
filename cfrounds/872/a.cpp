#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        string s; cin >> s;
        int ans=-1;

        for(int j=1; j<s.size(); j++){
            if(s[j]!=s[0]) ans=s.size()-1;
        }

        cout << ans << endl;
    }
}