#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s; cin >> s;
    int sz= s.size();

    for(int i=0; i<sz; i++){
        if(s[i]<'a') s[i]+=32;
    }
    
    int j=0;
    for(int i=0; i<sz; i++){
        if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='y') s.erase(s.begin() + j);
        else j++;
    }

    for(int i=0; i<s.size(); i++){
        cout << '.' << s[i];
    }
}