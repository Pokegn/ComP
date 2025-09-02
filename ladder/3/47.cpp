#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<long long int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    long long int ans=0;
    for(int i=0; i<n; i++){
        ans+=abs((i+1)-a[i]);
    }

    cout << ans;
}