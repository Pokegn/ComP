#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int k=10e5+1;

    for(int i=0; i<n; i++){
        cout << k+i << ' ';
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}