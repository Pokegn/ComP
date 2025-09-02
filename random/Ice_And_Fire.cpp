//https://codeforces.com/contest/1774/problem/C
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t, ti, n, i, c, d;
    char s[200000];
    cin >> t;
    for(ti=0; ti<t; ti++){
        cin >> n;
        c=0;
        d=0;
        
        cin >> s[0];
        cout << 1 << ' ';
        
        for(i=1; i<n-1; i++){
            cin >> s[i];
 
            if (s[i-1]!=s[i]){
                cout << i+1 << ' ';
                i++;
                break;
            }
            cout << 1 << ' ';
        }
 
        for(i=i; i<n-1; i++){
            cin >> s[i];
 
            if (s[i-1]!=s[i]){
                d=0;
            }
            else d+=1;
 
            cout << i+1-d << ' ';
 
        }
        
        cout << endl;
    }
}