#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> cust(24*60);

    int x,h,m;
    int ans=0;
    for(int i=0; i<n; i++){
        cin >> h >> m;
        x = 60*h+m;
        cust[x]++;
        if(cust[x] > ans) ans=cust[x];
    }

    cout << ans;
}