#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector<pair<int,int>> a(n);
    int x;

    for(int i=0; i<n; i++){
        cin >> x;

        a[i]={x,i+1};
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++) cout << a[i].second << ' ';
}
