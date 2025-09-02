#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int m; int n;
    int v2m, v2n, v3m, v3n;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        v2m=0; v2n=0; v3m=0; v3n=0;

        while(n%3==0){
            v3n+=1;
            n/=3;
        }
        while(n%2==0){
            v2n+=1;
            n/=2;
        }
        while(m%3==0){
            v3m+=1;
            m/=3;
        }
        while(m%2==0){
            v2m+=1;
            m/=2;
        }

        if(m!=n) cout << "NO" << endl;
        else{
            if((v3n-v3m)>=(v2m-v2n) and (v2m-v2n)>=0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}