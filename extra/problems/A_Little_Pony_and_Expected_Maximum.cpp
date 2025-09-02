#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t=1;
 
    for (int ti=0; ti<t; ti++){
        int m, n; cin >> m >> n;
        double k = m*pow(10, double(-9)/n);
        //cout << k;
        double ans = m;
        for(int i=m-1; i>k; i--){
            ans-=pow(double(i)/m, n);
        }

        cout << ans;
    }
}