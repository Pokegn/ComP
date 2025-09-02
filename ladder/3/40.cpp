#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int k; cin >> k;
    string s; cin >> s;
    string ans;
    int sz=s.size();
    vector<int> a(26, 0);
    bool x=true;

    for(int i=0; i<sz; i++){
        int j=s[i];
        a[s[i]-'a']+=1;
    }

    for(int i=0; i<26; i++){
        if(a[i]%k==0){
            a[i]/=k;
        }
        else x=false;
    }

    if(x){
        for(int j=0; j<26; j++){
            for(int l=0; l<a[j]; l++){
                ans+=(j+'a');
            }
        }

        for(int i=0; i<k; i++) cout << ans;
    }
    else cout << -1;
}