#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int x;
        int n, m; cin >> n >> m;
        vector<int> a(n*m);

        for(int j=0; j<n*m; j++){
            cin >> a[j];
        }

        sort(a.begin(), a.end());

        int d=max(a[n*m-1]-a[1], a[n*m-2]-a[0]);

        if(n>m){
            x=n;
            n=m;
            m=x;
        }

        cout << (n-1)*d + n*(m-1)*(a[n*m-1]-a[0]) << endl;
    }
}