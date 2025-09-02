#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n, k; cin >> n >> k;
        int max = 2^(min(k, 30));

        cout << min(max, n+1);
    }
}