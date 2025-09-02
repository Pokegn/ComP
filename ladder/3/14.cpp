#include <bits/stdc++.h>

using namespace std;

int main(){
    int c,r; cin >> r >> c;
    vector<int> a(c,0);
    int ac=0, bc=0;
    vector<int> b(r,0);
    char x;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> x;
            if(x!='.'){
                if(a[j]==0){
                    a[j]=1;
                    ac+=1;
                }
                if(b[i]==0){
                    b[i]=1;
                    bc+=1;
                }
            }
        }
    }

    cout << (c-ac)*r + (r-bc)*(ac);
}