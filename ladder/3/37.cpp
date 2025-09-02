#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long int n; cin >> n;
    int a, b;

    if(n<0){
        n*=-1;
        a=n%10;
        b=(n%100)/10;

        if(a>=b) cout << (n/10)*(-1);
        else cout << ((n/100)*10+a)*(-1);
    }
    else{
        cout << n;
    }
}