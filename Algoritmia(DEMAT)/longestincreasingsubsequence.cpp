#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int main(){
    int ans=0;
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> sz(n);
    int mx=1;
    sz[n-1] = 1;

    for(int i=n-2; i>=0; i--){
        mx = 1;
        for(int j=i; i<n; i++){
            if(a[i]<a[j]){
                mx = max(mx,sz[j]);
            }
        }
        sz[i] = mx;
        if(ans<sz[i]) ans = sz[i];
    }

    cout << ans << endl;
}