#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        string s; cin >> s;
        string ans;
        bool next=true;
        char x;
        for(int j=0; j<s.size(); j++){
            if(next==true){
                ans+=s[j];
                x=s[j];
            }
            else{
                if(s[j]==x) next=true;
            }

            cout << ans << endl;
        }
    }
}