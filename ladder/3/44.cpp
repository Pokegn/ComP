#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int y, k, n; cin >> y >> k >> n;
    int x=(-y%k+k)%k;
    bool c=false;

    while(x<n-y+1){
        if(x>0){
            cout << x << ' ';
            c=true;
        }
        x+=k;
    }
    if(!c) cout << -1;
}