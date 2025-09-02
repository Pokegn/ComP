#include <bits/stdc++.h>
 
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t=1;
 
    for (int ti=0; ti<t; ti++){
        int n; long long int d;
        cin >> n >> d;
        vector<long long int> a(n);

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        int r=1;
        long long int ans=0;
        for(int l=0; l<n-2; l++){
            r++;
            while(r<n && a[r]-a[l]<=d){
                r++;
            }
            ans+=(long long int)(r-l-1)*(long long int)(r-l-2)/2;
            r--;
        }

        cout << ans;

    }
}