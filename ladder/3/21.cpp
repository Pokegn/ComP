#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    int a, b, ans=0; cin >> a >> b;
    int current=0;

    ans=max(b-a, 0);
    current+=(b-a);

    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        current+=(b-a);
        ans=max(ans, current+b-a);
    }

    cout << ans;

}