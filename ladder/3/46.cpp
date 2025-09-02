#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    long long int l, r;
    long long int x;
    long long int ls=0, rs=0;

    for(int i=1; i<=n; i++){
        cin >> x;

        if(i==1 or x<l){
            ls=1;
            l=x;
        }
        else if(x==l){
            ls+=1;
        }

        if(i==1 or x>r){
            rs=1;
            r=x;
        }
        else if(x==r){
            rs+=1;
        }
    }

    int ans=r-l;
    cout << ans << ' ';
    if(ans==0) cout << ls*(ls-1)/2;
    else cout << ls*rs;
}