#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        int ans=n;
        vector<long long int> a(n);
        for(int j=0; j<n; j++){
            cin >> a[j];
        }

        if(n==1) cout << 1 << endl;
        else{
            int wasB;
            if(a[0]>a[1]) wasB=1;
            else if(a[0]==a[1]){
                ans-=1;
                wasB=0;
            }
            else wasB=-1;

            for(int j=1; j<n-1; j++){
                if(a[j]>a[j+1]){
                    if(wasB==1) ans-=1;
                    wasB=1;
                }
                if(a[j]<a[j+1]){
                    if(wasB==-1) ans-=1;
                    wasB=-1;
                }
                if(a[j]==a[j+1]){
                    ans-=1;
                }
            }

            cout << ans << endl;
        }
    }
}