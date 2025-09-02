#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t; cin >> t;
    int i; for (i=0; i<t; i++){
        char a[8];
        char x='B';
        int k;
 
 
        for(k=0; k<8; k++){
            int b=0;
            int j; for (j=0; j<8; j++){
                cin >> a[j];
 
                if (x=='B'){
                    if (j>0){
                        if (a[j]==a[j-1]) b+=1;
                        if (b==7 and a[j]=='R') x='R';
                    }      
 
                }
 
            }
 
        }
        
        cout << x << endl;
    }
}