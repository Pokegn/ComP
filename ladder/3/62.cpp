#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    string s; cin >> s;
    int sz = s.size();
    vector<bool> eqnext(sz, 0);
    for(int i=0; i<sz-1; i++){
        if(s[i] == s[i+1]) eqnext[i] = 1;
    }

    vector<int> cans(sz,0);
    cans[0] = 0;
    for(int i=1; i<sz; i++){
        cans[i] = cans[i-1] + eqnext[i-1];
    }
    //cout << s[0] << s[1] << (s[0]==s[1] ? 1 : 0);
    int m; cin >> m;
    int l,r;
    for(int i=0; i<m; i++){
        cin >> l >> r;
        if(l==1) cout << cans[r-1] << "\n";
        else{
            cout << cans[r-1] - cans[l-1] << "\n";
        }
    }
}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}