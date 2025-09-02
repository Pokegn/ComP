#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    string s; cin >>s;
    vector<int> a(2, 0);
    a[1] = 0;
    a[0] = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1') a[1]+=1;
        else a[0]+=1;
    }

    int x = (a[1]>a[0] ? a[1]-a[0]:a[0]-a[1] );
    int ans=0;

    if(a[0]>a[1]){
        for(int i=s.size()-1; i>=0; i--){

            ans+=1;
            if(s[i] == '0') x-=1;
            if(x == 0){
                cout << ans << '\n';
                return;
            }
        }


    }
    else if(a[0]<a[1]){
        for(int i=s.size()-1; i>=0; i--){
            ans+=1;
            if(s[i] == '1')x-=1;
            if(x == 0){
                cout << ans << '\n';
                return;
            }
        }

    }
    else{
        cout << 0 << '\n';
        return;
    }

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}