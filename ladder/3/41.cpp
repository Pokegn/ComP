#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int s, n; cin >> s >> n;
    vector<pair<int,int>> x(n);
    vector<int> y(n);
    bool z=true;

    for(int i=0; i<n; i++){
        cin >> x[i].first >> y[i];
        x[i].second=i;
    }

    sort(x.begin(), x.end());

    for(int i=0; i<n; i++){
        if(s>x[i].first){
            s+=y[x[i].second];
        }
        else z=false;
    }

    if(z) cout << "YES";
    else cout << "NO";
}