#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    //int t; cin >> t;
 
    //for (int i=0; i<t; i++){
        int n; cin >> n;
        int x,y,z; 
        int k;

        x=0;
        y=0;
        z=0;
        for(int j=0; j<n; j++){
            cin >> k;
            x+=k;
            cin >> k;
            y+=k;
            cin >> k;
            z+=k;
        }
        if(x==0 and y==0 and z==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    //}
}