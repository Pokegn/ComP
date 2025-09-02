#include <bits/stdc++.h>
 
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        long long int a, b;
        cin >> a >> b;
        if (__gcd(a,b)==1){
            cout << 1 << endl << a << ' ' << b << endl;
        }
        else{
            cout << 2 << endl;
            if(a>b){
                if (b>2) cout << b-2 <<' '<< b-1 << endl;
                else cout << 1 <<' '<< 1 << endl;
            }
            else{
                if (a>2) cout << a-1 <<' '<< a-2 << endl;
                else cout << 1 <<' '<< 1 << endl;
            }
            cout << a <<' '<< b << endl;
        }
    }
}