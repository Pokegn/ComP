#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        int mayor=0;
        int cuenta=0;
        string a; cin >> a;
    
        for(int j=0; j<n; j++){
            if(j==0) cuenta=1;
            else{
                if(a[j]==a[j-1]) cuenta++;
                else{
                    cuenta=1;
                }
            }
            if(cuenta>mayor) mayor=cuenta;
        }

        cout << mayor+1 << endl;
    }
}