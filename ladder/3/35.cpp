#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s; cin >> s;
    sz=s.size();
    bool h=false, e=false, l1=false, l2=false, o=false;

    for(int i=0; i<sz; i++){
        if(!h) if(s[i]=='h') h=true;
        else if(!e) if(s[i]=='e') e=true;
        else if(!l1) if(s[i]=='l') l1=true;
        else if(!l2) if(s[i]=='l') l2=true;
        else if(!o) if(s[i]=='o') o=true;
    }

    if(o) cout << "YES";
    else cout << "NO";
}