#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,t; cin >> n >> t;
    vector<char> f(n);
    char x;
    bool skip=false;

    for(int i=0; i<n; i++){
        cin >> f[i];
    }

    for(int i=0; i<t;i++){
        for(int j=n-1; j>=1; j--){
            
                if(f[j]=='G' and f[j-1]=='B' and skip==false){
                    x=f[j];
                    f[j]=f[j-1];
                    f[j-1]=x;
                    skip =true;
                }
                else skip = false;
            
        }
    }

    for(int i=0; i<n; i++){
        cout << f[i];
    }

}