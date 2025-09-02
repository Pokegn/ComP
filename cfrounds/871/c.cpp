#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int n;
    int b10, b01, b11;
    int x;
    string s;
    for(int i=0; i<t; i++){
        cin >> n;
        b10=-1, b01=-1, b11=-1;

        for(int j=0; j<n; j++){
            cin >> x;
            string s;
            cin >> s;

            if(s=="01"){
                if(b01>x or b01==-1) b01=x;
            }
            if(s=="10"){
                if(b10>x or b10==-1) b10=x;
            }
            if(s=="11"){
                if(b11>x or b11==-1) b11=x;
            }

        }
        
            if((b01>0 and b10>0) or b11>0){
                if(b01<0 or b10<0) cout << b11 << endl;
                else if (b11<0) cout << b01 + b10 << endl;
                else cout << min(b10+b01, b11) << endl;
            }
            else cout << -1 << endl;
        
    }
}