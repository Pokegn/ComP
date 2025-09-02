#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int i; for (i=0; i<t; i++){
        int a,b,c,d; cin >> a  >> b >> c;
        if (c<a){
            d=c; c=a; a=d;
        }
        if (c<b){
            d=c; c=b; b=d;
        }
        if (c==a+b) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}