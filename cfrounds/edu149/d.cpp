#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        bool pos=0;
        bool neg=0;
        int sym=0;
        int ans=0;
        int last;
        string s; cin >> s;
        vector<int> a(n);

        for(int j=0; j<n; j++){
            if(s[j]=='('){
                sym+=1;
            }
            if(s[j]==')'){
                sym-=1;
            }
            if(sym<0){
                neg=1;
                a[j]=1;
                last=1;
            }
            if(sym>0){
                pos=1;
                a[j]=2;
                last=2;
            }
            if(sym==0){
                a[j]=last;
            }
        }

        if(pos) ans+=1;
        if(neg) ans+=1;

        if(sym==0){
            cout << ans << endl;
            if(ans==2){
                for(int j=0; j<n; j++){
                    cout << a[j] << ' ';
                }
                cout << endl;
            }
            if(ans==1){
                for(int j=0; j<n; j++){
                    cout << 1 << ' ';
                }
                cout << endl;
            }
        }
        else cout << -1 << endl;
    }
}