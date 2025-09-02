#include<bits/stdc++.h>

using namespace std;

int main(){
    string a; cin >> a;
    int i=0;
    bool x=true;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='H' or a[i]=='Q' or a[i]=='9' or a[i]=='+'){
            x=false;
        }
    }

    if(x) cout << "NO";
    else cout << "YES";
        
}