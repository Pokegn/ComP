#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int n, m;
    int x;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        vector<int> c(n,0);
        for(int j=0; j<m; j++){
            cin >> x; c[x-1]+=1;
            cin >> x; c[x-1]+=1;
        }

        int a=-1, b=-1;
        int i1=0;
        int i2=0;

        for(int j=0; j<n; j++){
            if(c[j]>1){
                if(a==-1){
                    a=c[j];
                    i1+=1;
                }
                else{
                    if(c[j]!=a){
                        if(b==-1) b=c[j];
                        i2+=1;
                    }
                    else{
                        i1+=1;
                    }
                }
            }
        }

        if(b==-1) cout << a << ' ' << a-1 << endl;
        else{
            if(i1==1) cout << a << ' ' << b-1 << endl;
            else cout << b << ' ' << a-1 << endl;
        }

    }
}