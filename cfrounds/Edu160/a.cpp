#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    string s; cin >> s;
    int sz = s.size();
    int indice=-1;
    for(int i=1; i<sz; i++){
        if(s[i] > '0'){
            indice = i;
            break;
        }
    }
    if(indice == -1){
        cout << -1 << '\n';
        return;
    }

    int a = (int) s[0]-'0';
    for(int i=0; i<indice-1; i++) a*=10;

    int xd = 0;
    int b = (int) s[indice]-'0';
    for(int i=indice+1; i<sz; i++){
        b*=10;
        b+=(int) s[i]-'0';
    }

    if(a<b) cout << a << ' ' << b << '\n';
    else cout << -1 << '\n';

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}