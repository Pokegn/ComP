#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int n; cin >> n;
    int l=0, r=0;
    int li, ri;
    bool cond=0;
    for(int i=0; i<n; i++){
        cin >> li >> ri;
        if((li-ri)%2!=0) cond = 1;
        l+=li; r+=ri;
    }

    if(l%2==0 && r%2==0){
        cout << 0 << "\n";
        return;
    }

    if(cond && l%2==r%2) cout << 1 << "\n";
    else cout << -1 << "\n";
    return;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}