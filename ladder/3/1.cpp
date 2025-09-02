#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k; cin >> n>>k;
    int y;
    int c=0;
    for(int i=0; i<n; i++){
        cin >> y;
        if(y>=5-k) c+=1;
    }
    cout << int(c/3);
}