#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
 
        int n;
        cin >> n;
        char d; cin >> d;
        string a;
        cin >> a;
 
        bool seacabo=0;
 
        for (int j=0; j<n; j++){
            if (d > a[j]){
                a.insert (j, 1, d);
                seacabo=1;
                break;
            }
        }
        if (seacabo == 0) {
            a.insert(n,1,d);
        }
 
        for (int j=0; j<n+1; j++) cout << a[j];
        cout << endl;
 
    }
        
}