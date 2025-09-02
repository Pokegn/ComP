#include <bits/stdc++.h>
 
using namespace std;

long long int dif(long long int l, long long int r){
    return (ceil(double(l-r)/2));
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n;
        long long int ans=1000000000;
        vector<long long int> m(n);
        for(int j=0; j<n; j++){
            cin >> m[j];
        }

        sort(m.begin(), m.end());

        long long int a, b, c;
        long long int k;
        for(int i=0; i<n; i++){
            a = dif(m[0], m[i]);

            k = lower_bound(m[i+1], m.end(), ceil(double((l+r)/2)));
            b = dif(m[i+1], m[k-1]);
            c = dif(m[k], m[n-1]);
            if(ans>max(a, max(b, c))) ans=max(a, max(b, c));
        }

        cout << ans << endl;
        
    }
}