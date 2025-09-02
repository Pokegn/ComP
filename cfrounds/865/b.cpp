#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;


        if(n%2 ==1){
            cout << 2*n << ' ';
            for(int j=0; j<(int (n/2)); j++){
                cout << n+1-(2+2*j) << ' ' << (2*n)-2-2*j << ' ';
            }
            cout << endl;
            for(int j=0; j<(int (n/2)); j++){
            cout << n+1-(1+2*j) << ' ' << (2*n)-1-2*j << ' ';
            }
            cout << 1 << endl;

        }

        else{
            for(int j=0; j<(n/2); j++){
                cout << (2*n)-1-2*j << ' ' << 1+2*j << ' ';
            }
            cout << endl;
            for(int j=0; j<(n/2)-1; j++){
                cout << 2+2*j << ' ' << (2*n)-2-2*j << ' ';
            }
            cout << n << ' ' << 2*n << endl;
        }
        



    }
}