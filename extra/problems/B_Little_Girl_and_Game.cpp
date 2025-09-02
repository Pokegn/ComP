#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t=1;
 
    for (int ti=0; ti<t; ti++){
        vector<int> a(26);
        string s; cin >> s;
        int sz = s.size();
        for(int i=0; i<sz; i++){
            a[s[i]-'a']+=1;
        }
        int impar=0;
        for(int i=0; i<26; i++){
            if(a[i]%2==1) impar++;
        }
        if(impar==0) cout << "First";
        else{
            if(impar%2==0) cout << "Second";
            else cout << "First";
        }
    }
}