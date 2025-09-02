#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    int f, t;
    int ans=-2000000000;

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> f >> t;
        if(t>k) f=f-t+k;
        if(f>ans) ans=f;
    }
    
    cout << ans;
}