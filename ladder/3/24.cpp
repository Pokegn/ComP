#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t=1;
 
    for (int i=0; i<t; i++){

        bool ans=1;

        for(int j=0; j<8; j++){
            char c; cin >> c;
            char d; d=c;

            for(int k=1; k<8; k++){
                    cin >> c;
                    if(c==d) ans=0;
                    d=c;
            }
            
        }

        if(ans) cout << "YES";
        else cout << "NO";
    }
}