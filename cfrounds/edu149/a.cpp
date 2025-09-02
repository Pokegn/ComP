#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int x, k; cin >> x >> k;

        if(x%k!=0){
            cout << 1 << endl << x << endl;
        }
        else cout << 2 << endl << -1 << ' ' << x+1 << endl;
    }
}