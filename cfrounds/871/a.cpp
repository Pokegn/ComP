#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    string s;
    int ans=0;
    for(int i=0; i<t; i++){
        cin >> s;
        if(s[0]!='c') ans+=1;
        if(s[1]!='o') ans+=1;
        if(s[2]!='d') ans+=1;
        if(s[3]!='e') ans+=1;
        if(s[4]!='f') ans+=1;
        if(s[5]!='o') ans+=1;
        if(s[6]!='r') ans+=1;
        if(s[7]!='c') ans+=1;
        if(s[8]!='e') ans+=1;
        if(s[9]!='s') ans+=1;
        cout << ans << endl;
        ans=0;
    }
    
}