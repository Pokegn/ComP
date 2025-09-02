#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        string s; cin >> s;
        int dist=-1;
        char last;
        int first;
        vector<int> a;
        string ans;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='0'){
                ans+='0';
                if(dist==-1){
                    dist=0;
                    first=0;
                    a.push_back(0);
                }
                else{
                    if(s[j]!=last){
                        dist+=1;
                        a.push_back(0);
                    }
                }
                last='0';
            }
            if(s[j]=='1'){
                ans+='1';
                if(dist==-1){
                    dist=0;
                    first=0;
                    a.push_back(1);
                }
                else{
                    if(s[j]!=last){
                        dist+=1;
                        a.push_back(0);
                    }
                }
                last='1';
            }
            if(s[j]=='?'){
                if(dist==-1) ans+='0';
                else{
                    ans+=last;
                }
            }
        }

        cout << ans << endl;
    }
}