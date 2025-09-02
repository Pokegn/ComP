#include<bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int c=0;
    bool x=1;
    for(int i=0; i<s.size(); i++){
        if((s[i]=='4' or s[i]=='7')) c+=1;
    }

    string r=to_string(c);

    for(int i=0; i<r.size(); i++){
        if(not(r[i]=='4' or r[i]=='7')) x=0;
    }
    if(x==0) cout << "NO";
    else cout << "YES";
}