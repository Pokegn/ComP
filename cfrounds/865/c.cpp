#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        long long int x;
        long long int s=0;

        if(n%2==1){
            cout << "YES" << endl;
            for(int j=0; j<n; j++) cin >> x;
        } 
        else{
            int k=n/2;
            for(int j=0; j<k; j++){
                cin >> x;
                s+=x;
                cin >> x;
                s-=x;
            }
            if(s<=0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
       
    }
}