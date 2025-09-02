#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t=1;
 
    for (int i=0; i<t; i++){
        string s; cin >> s;
        string ans;
        bool f=false;

        auto ti=s.size();
        for(int j=0; j<ti; j++){

                if(ti-j>=2 && s[j]=='W' && s[j+1]=='U' && s[j+2]=='B'){
                    if(f==true){
                        ans+=' ';
                    }
                    j+=2;
                }
                else{
                    ans+=s[j];
                    f=true;
                }
        }

        for(int j=0; j<ans.size(); j++){
            if(ans[j]==' ' && ans[j+1]==' ') ans.erase(ans.begin()+j+1);
        }

        if(ans[ans.size()-1]==' ') ans.erase(ans.begin()+ans.size()-1);

        for(int j=0; j<ans.size(); j++){
            cout << ans[j];
        }
    }
}