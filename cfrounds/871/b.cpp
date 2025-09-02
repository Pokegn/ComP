#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int n;
    int ans;
    int c;
    bool x;
    for(int i=0; i<t; i++){
        ans=0;
        c=0;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> x;
            if(x==0){
                c+=1;
            }
            if(c>ans) ans=c;
            if(x==1) c=0;

        }
        cout << ans << endl;
    }
}