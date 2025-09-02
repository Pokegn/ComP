#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s; cin >> s;
    bool ans=true;
    string cw;
    char cn;
 
    int sz=s.size();
    for(int i=0; i<sz; i++){
        cn=s[i];
        if(i==0){
            cw+=cn;
            if(cn!='1') ans=false;
        }
        else if(cn=='1'){

            if(cw!="1" && cw!="14" && cw!="144"){
                ans=false;
 
            }
                cw.clear();
                cw+=cn;
        }
        else cw+=cn;
        
        if(i==sz-1){
            if(cw!="1" && cw!="14" && cw!="144"){
                ans=false;
            }
        }
        
    }
 
    if(ans==true) cout << "YES";
    else cout << "NO";
}