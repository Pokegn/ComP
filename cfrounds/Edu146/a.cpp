#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        long long int k,n; cin >> n >> k;

        if(n%2 == 0){
           cout << "YES" << endl; 
        } 
        else{
            if(k%2==1 and n>=k) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}