#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        long long int n, k, q; cin >> n >> k >> q;
        long long int len=0;
        long long int curr;
        int ans=0;

        for(int j=0; j<n; j++){
            cin >> curr;
            if(curr<=q) len+=1;
            else len=0;

            if(len>=k){
                ans+=len-q+1;
            }
        }

        cout << ans << endl;
    }
}