#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int s=0;
    int x;
    int ans=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> x;
            s+=x;
        }
        if(s>=2) ans+=1;
        s=0;
    }

    cout << ans;
}