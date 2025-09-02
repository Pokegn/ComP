#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    int a=0, b=0;
    bool ans=true;
    int x;

    for(int i=0; i<n; i++){
        cin >> x;
        if(x==25) a++;
        if(x==50){
            if(a>0){
                a--;
                b++;
            }
            else ans=false;
        }
        if(x==100){
            if(b>0){
                if(a>0){
                    b--;
                    a--;
                }
                else ans=false;
            }
            else if(a>=3){
                a-=3;
            }
            else ans=false;
        }
    }

    if(ans) cout << "YES";
    else cout << "NO";

}