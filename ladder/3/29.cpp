#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    int i;
    
    for(int r=1; r<2*n+1; r++){
        for(int i=2*abs(n-r); i>0; i--){
            cout << ' ';
        }
        if(r==1 || r==2*n) cout << 0 << endl;
        else{
            for(int i=0; i<n-abs(n-r)+1; i++){
                cout << i << ' ';
            }
            for(int i=n-abs(n-r)-1; i>=0; i--){
                cout << i;
                if(i!=0) cout << ' ';
            }
            cout << endl;
        }
    }
}