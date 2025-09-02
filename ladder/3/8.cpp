#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int ans;
    ans = min({k*l/(n*nl), p/(np*n), c*d/n});

    cout << ans;
}

